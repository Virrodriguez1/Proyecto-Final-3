#include "HashTable.h"

// Constructor de HashEntry
HashEntry::HashEntry(int key, int value) : key(key), value(value), next(nullptr) {
}

// Obtiene la clave de la entrada.
int HashEntry::getKey() const { return key; }

// Obtiene el valor de la entrada.
int HashEntry::getValue() const { return value; }

// Obtiene el siguiente HashEntry en la lista.
HashEntry* HashEntry::getNext() const { return next; }

// Establece el valor de la entrada.
void HashEntry::setValue(int value) { this->value = value; }

// Establece el siguiente HashEntry en la lista.
void HashEntry::setNext(HashEntry* next) { this->next = next; }

// Constructor de HashTable
HashTable::HashTable() : table(new HashEntry*[TABLE_SIZE]()) {
}

// Destructor de HashTable
HashTable::~HashTable() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        HashEntry *entry = table[i];
        while (entry != nullptr) {
            HashEntry *prev = entry;
            entry = entry->getNext();
            delete prev;
        }
    }
    delete[] table;
}

// Función de hash que calcula el índice de una clave.
int HashTable::hashFunction(int key) const {
    return key % TABLE_SIZE;
}

/**
 * Inserta un par clave-valor en la tabla hash. Si la clave ya existe, actualiza
 * el valor. Si no, agrega una nueva entrada al inicio de la lista enlazada en
 * esa posición de la tabla.
 * 
 * @param key Clave para el nuevo valor.
 * @param value Valor a insertar asociado a la clave.
 */
void HashTable::insert(int key, int value) {
    int hash = hashFunction(key);
    HashEntry *prev = nullptr;
    HashEntry *entry = table[hash];

    while (entry != nullptr && entry->getKey() != key) {
        prev = entry;
        entry = entry->getNext();
    }

    if (entry == nullptr) {
        entry = new HashEntry(key, value);
        if (prev == nullptr) {
            table[hash] = entry;
        } else {
            prev->setNext(entry);
        }
    } else {
        entry->setValue(value);
    }
}

/**
 * Elimina la entrada con la clave dada de la tabla hash. Si la entrada está en
 * medio de la lista enlazada, reconecta la lista después de la eliminación.
 * 
 * @param key Clave de la entrada a eliminar.
 */
void HashTable::remove(int key) {
    int hash = hashFunction(key);
    HashEntry *prev = nullptr;
    HashEntry *entry = table[hash];

    while (entry != nullptr && entry->getKey() != key) {
        prev = entry;
        entry = entry->getNext();
    }

    if (entry == nullptr) {
        // La clave no fue encontrada.
        return;
    } else {
        if (prev == nullptr) {
            // Eliminar la primera entrada.
            table[hash] = entry->getNext();
        } else {
            // Reconectar la lista enlazada después de la entrada eliminada.
            prev->setNext(entry->getNext());
        }
        delete entry;
    }
}

/**
 * Obtiene el valor asociado con la clave dada. Si la clave no se encuentra,
 * devuelve -1.
 * 
 * @param key Clave de la entrada a buscar.
 * @return Valor asociado con la clave, o -1 si la clave no se encuentra.
 */
int HashTable::get(int key) const {
    int hash = hashFunction(key);
    HashEntry *entry = table[hash];

    while (entry != nullptr) {
        if (entry->getKey() == key) {
            return entry->getValue();
        }
        entry = entry->getNext();
    }

    return -1; // Si no se encuentra la clave.
}
