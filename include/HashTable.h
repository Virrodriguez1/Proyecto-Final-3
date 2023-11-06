#ifndef HASHTABLE_H
#define HASHTABLE_H

/**
 * @class HashEntry
 * @brief Representa una entrada en la tabla hash.
 *
 * Contiene una clave y un valor, y un puntero al siguiente HashEntry
 * para manejar las colisiones mediante encadenamiento.
 */
class HashEntry {
private:
    int key; ///< Clave de la entrada.
    int value; ///< Valor de la entrada.
    HashEntry *next; ///< Puntero al siguiente HashEntry en la lista.

public:
    /**
     * @brief Constructor que inicializa una entrada con una clave y un valor.
     * @param key Clave de la entrada.
     * @param value Valor de la entrada.
     */
    HashEntry(int key, int value);
    
    /**
     * @brief Obtiene la clave de la entrada.
     * @return La clave de la entrada.
     */
    int getKey() const;
    
    /**
     * @brief Obtiene el valor de la entrada.
     * @return El valor de la entrada.
     */
    int getValue() const;
    
    /**
     * @brief Obtiene el siguiente HashEntry en la lista.
     * @return Puntero al siguiente HashEntry en la lista.
     */
    HashEntry *getNext() const;
    
    /**
     * @brief Establece el valor de la entrada.
     * @param value Nuevo valor para esta entrada.
     */
    void setValue(int value);
    
    /**
     * @brief Establece el siguiente HashEntry en la lista.
     * @param next Puntero al siguiente HashEntry en la lista.
     */
    void setNext(HashEntry *next);
};

/**
 * @class HashTable
 * @brief Implementa una tabla hash con encadenamiento para resolver colisiones.
 */
class HashTable {
private:
    static const int TABLE_SIZE = 128; ///< Tamaño de la tabla hash.
    HashEntry **table; ///< Arreglo de punteros a HashEntry.

    /**
     * @brief Función de hash privada que calcula el índice de una clave.
     * @param key Clave para calcular el índice.
     * @return Índice calculado para la clave.
     */
    int hashFunction(int key) const;

public:
    HashTable(); ///< Constructor de la tabla hash.
    ~HashTable(); ///< Destructor de la tabla hash.
    
    /**
     * @brief Inserta un par clave-valor en la tabla hash.
     * @param key Clave para el nuevo valor.
     * @param value Valor a insertar asociado a la clave.
     */
    void insert(int key, int value);
    
    /**
     * @brief Elimina una entrada con la clave dada de la tabla hash.
     * @param key Clave de la entrada a eliminar.
     */
    void remove(int key);
    
    /**
     * @brief Obtiene el valor asociado con la clave dada.
     * @param key Clave de la entrada a buscar.
     * @return Valor asociado con la clave, o -1 si la clave no se encuentra.
     */
    int get(int key) const;
};

#endif // HASHTABLE_H
