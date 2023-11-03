
/**
 * @file HashMap.h
 * @brief Archivo de cabecera para la clase HashMap.
 *
 * Define la clase HashMap que implementa una tabla hash genérica con encadenamiento
 * para la resolución de colisiones, utilizando la clase HashEntry para almacenar los elementos.
 *
 * @author virrr
 * @date 10/27/2023
 */

#ifndef PROYECTOFINAL_PROGRAMACION_III_HASHMAP_H
#define PROYECTOFINAL_PROGRAMACION_III_HASHMAP_H

#include "HashEntry.h"
#include <iostream>
#include <stdexcept>
#include <functional>

/**
 * @class HashMap
 * @brief Implementa una tabla hash con encadenamiento.
 *
 * Esta clase utiliza un arreglo de punteros a HashEntry para almacenar los pares clave-valor.
 * Permite la inserción, búsqueda y eliminación de elementos.
 *
 * @tparam K Tipo de dato de la clave.
 * @tparam T Tipo de dato del valor.
 */
template <class K, class T>
class HashMap {
private:
    HashEntry<K, T> **table; ///< Arreglo de punteros a HashEntry que almacena los elementos.
    unsigned int size;    ///< Tamaño del arreglo de punteros a HashEntry.
    std::function<unsigned int(const K&)> hashFunc; ///< Función hash para calcular el índice del arreglo.

    /**
     * @brief Función hash predeterminada para cadenas.
     * @param clave Clave de tipo string para calcular su valor hash.
     * @return Valor hash calculado para la clave.
     */
    unsigned int hashFunctionForStrings(const std::string &clave) {
        unsigned int hash = 0;
        for (char c : clave) {
            hash = hash * 101 + c;
        }
        return hash;
    }

public:
    /**
     * @brief Constructor que inicializa el HashMap con un tamaño específico.
     * @param size Tamaño del arreglo de HashEntry.
     */
    explicit HashMap(unsigned int size) : size(size), table(new HashEntry<K, T>*[size]()), hashFunc(hashFunctionForStrings) {
        for (unsigned int i = 0; i < size; ++i) {
            table[i] = nullptr;
        }
    }

    /**
     * @brief Constructor que inicializa el HashMap con un tamaño y función hash específicos.
     * @param size Tamaño del arreglo de HashEntry.
     * @param func Función hash personalizada.
     */
    HashMap(unsigned int size, std::function<unsigned int(const K&)> func) : size(size), hashFunc(func), table(new HashEntry<K, T>*[size]()) {
        for (unsigned int i = 0; i < size; ++i) {
            table[i] = nullptr;
        }
    }

    // Additional methods will be included here with detailed documentation.

};

#endif //PROYECTOFINAL_PROGRAMACION_III_HASHMAP_H
