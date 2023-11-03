#ifndef PROYECTOFINAL_PROGRAMACION_III_HASHMAP_H
#define PROYECTOFINAL_PROGRAMACION_III_HASHMAP_H

#include "HashEntry.h"
#include <iostream>
#include <stdexcept>
#include <functional>

template <class K, class T>
class HashMap {
private:
    HashEntry<K, T> **tabla;
    unsigned int tamanio;
    std::function<unsigned int(const K&)> hashFunc;

public:
    unsigned int hashFuncionParaStrings(const std::string &clave) {
        unsigned int hash = 0;
        for (char c : clave) {
            hash = hash * 101 + c;
        }
        return hash;
    }

    explicit HashMap(unsigned int tamanio) : tamanio(tamanio), tabla(new HashEntry<K, T>*[tamanio]()), hashFunc(hashFuncionParaStrings) {
        for (unsigned int i = 0; i < tamanio; ++i) {
            tabla[i] = nullptr;
        }
    }

    HashMap(unsigned int tamanio, std::function<unsigned int(const K&)> func) : tamanio(tamanio), hashFunc(func), tabla(new HashEntry<K, T>*[tamanio]()) {
        for (unsigned int i = 0; i < tamanio; ++i) {
            tabla[i] = nullptr;
        }
    }

    T get(const K& clave) {
        unsigned int pos = hashFunc(clave) % tamanio;
        HashEntry<K, T> *entry = tabla[pos];
        while (entry != nullptr) {
            if (entry->getClave() == clave) {
                return entry->getValor();
            }
            entry = entry->getNext();
        }
        throw std::runtime_error("Clave no encontrada");
    }

    void put(const K& clave, const T& valor) {
        unsigned int pos = hashFunc(clave) % tamanio;
        HashEntry<K, T> *prevEntry = nullptr;
        HashEntry<K, T> *entry = tabla[pos];
        while (entry != nullptr && entry->getClave() != clave) {
            prevEntry = entry;
            entry = entry->getNext();
        }
        if (entry == nullptr) {
            entry = new HashEntry<K, T>(clave, valor);
            if (prevEntry == nullptr) {
                tabla[pos] = entry;
            } else {
                prevEntry->setNext(entry);
            }
        } else {
            entry->setValor(valor);
        }
    }

    void remove(const K& clave) {
        unsigned int pos = hashFunc(clave) % tamanio;
        HashEntry<K, T> *prevEntry = nullptr;
        HashEntry<K, T> *entry = tabla[pos];
        while (entry != nullptr && entry->getClave() != clave) {
            prevEntry = entry;
            entry = entry->getNext();
        }
        if (entry == nullptr) {
            throw std::runtime_error("Clave no encontrada para eliminar");
        } else {
            if (prevEntry == nullptr) {
                tabla[pos] = entry->getNext();
            } else {
                prevEntry->setNext(entry->getNext());
            }
            delete entry;
        }
    }

    ~HashMap() {
        for (unsigned int i = 0; i < tamanio; ++i) {
            HashEntry<K, T> *entry = tabla[i];
            while (entry != nullptr) {
                HashEntry<K, T> *prev = entry;
                entry = entry->getNext();
                delete prev;
            }
        }
        delete[] tabla;
    }

    bool esVacio() {
        for (unsigned int i = 0; i < tamanio; ++i) {
            if (tabla[i] != nullptr) {
                return false;
            }
        }
        return true;
    }
    
};

unsigned int hashFuncionParaStrings(const std::string &clave) {
    unsigned int hash = 0;
    for (char c : clave) {
        hash = hash * 101 + c;
    }
    return hash;
}

#endif //PROYECTOFINAL_PROGRAMACION_III_HASHMAP_H
