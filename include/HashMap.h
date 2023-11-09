// HashMap.h
#ifndef PROYECTOFINAL_PROGRAMACION_III_HASHMAP_H
#define PROYECTOFINAL_PROGRAMACION_III_HASHMAP_H

#include <vector>
#include <list>
#include <string>
#include <algorithm>
#include <functional>
#include <iostream>
#include <Article.h>

using namespace std;

/**
 * @class HashNode
 * @brief Nodo de la tabla hash que contiene un par clave-valor.
 *
 * Esta clase define la estructura de un nodo utilizado en la tabla hash,
 * que almacena un par clave-valor.
 *
 * @tparam T Tipo del valor almacenado en el nodo.
 */
template <typename T>
class HashNode {
public:
    string key;   ///< La clave del nodo hash.
    T value;      ///< El valor asociado con la clave.

    /**
     * @brief Constructor que inicializa un nodo hash con una clave y un valor dados.
     * @param key Clave del nodo.
     * @param value Valor asociado con la clave.
     */
    HashNode(const string& key, const T& value) : key(key), value(value) {}

    // Destructor por defecto
    ~HashNode() = default;
};

/**
 * @class HashMap
 * @brief Clase que representa un mapa hash genérico.
 *
 * Implementa un mapa hash genérico que mapea claves de tipo string a valores de tipo T.
 * La colisión de hash se maneja mediante encadenamiento.
 *
 * @tparam T Tipo del valor almacenado en el mapa hash.
 */
template <typename T>
class HashMap {
private:
    // La tabla hash será un vector de listas para manejar colisiones mediante encadenamiento.
    vector<list<HashNode<T>>> table;
    size_t capacity; ///< Capacidad inicial de la tabla hash.
    size_t size;     ///< Tamaño actual de la tabla hash.

    /**
     * @brief Función de hash para calcular el hash de la clave.
     * @param key La clave para la cual calcular el hash.
     * @return El índice basado en el hash para la clave.
     */
    size_t hashFunction(const string& key) const {
        hash<string> hasher;
        return hasher(key) % capacity;
    }

public:
    /**
     * @brief Constructor para inicializar la tabla hash con una capacidad fija.
     * @param cap Capacidad inicial de la tabla hash.
     */
    explicit HashMap(size_t cap = 101) : capacity(cap), size(0) {
        table.resize(capacity);
    }

    /**
     * @brief Función para agregar un par clave-valor al mapa hash.
     * @param key La clave del elemento a agregar.
     * @param value El valor asociado con la clave.
     */
    void insert(const string& key, const T& value) {
        size_t index = hashFunction(key);
        auto& list = table[index];

        // Comprobar si la clave ya existe en el mapa
        for (auto& node : list) {
            if (node.key == key) {
                node.value = value;
                return;
            }
        }

        // Insertar el nuevo nodo si la clave no existe
        list.emplace_back(key, value);
        ++size;
    }

    /**
     * @brief Función para obtener el valor asociado con una clave.
     * @param key La clave del elemento a obtener.
     * @return Puntero al valor asociado o nullptr si la clave no se encuentra.
     */
    T* get(const string& key) {
        size_t index = hashFunction(key);
        auto& list = table[index];

        // Encontrar el nodo con la clave dada
        auto it = find_if(list.begin(), list.end(), [&key](const HashNode<T>& node) {
            return node.key == key;
        });

        if (it != list.end()) {
            return &(it->value);
        }

        // Si la clave no se encuentra, retornar nullptr
        cout<< "Key Not Found: "<< key <<endl;
        return nullptr;
    }

    /**
     * @brief Función para verificar si el mapa hash contiene una clave.
     * @param key La clave a verificar.
     * @return Verdadero si la clave existe, falso en caso contrario.
     */
    bool contains(const string& key) const {
        size_t index = hashFunction(key);
        const auto& list = table[index];

        // Verificar si algún nodo en la lista tiene la clave
        return any_of(list.begin(), list.end(), [&key](const HashNode<T>& node) {
            return node.key == key;
        });
    }

    /**
     * @brief Función para eliminar un par clave-valor del mapa hash.
     * @param key La clave del elemento a eliminar.
     * @return Verdadero si el elemento fue eliminado, falso en caso contrario.
     */
    bool remove(const string& key) {
        size_t index = hashFunction(key);
        auto& list = table[index];

        auto it = find_if(list.begin(), list.end(), [&key](const HashNode<T>& node) {
            return node.key == key;
        });

        if (it != list.end()) {
            list.erase(it);
            --size;
            return true;
        }

        return false;
    }

    /**
     * @brief Función para obtener el tamaño actual del mapa hash.
     * @return El tamaño del mapa hash.
     */
    size_t getSize() const {
        return size;
    }

    // Destructor por defecto
    ~HashMap() = default;
};

#endif //PROYECTOFINAL_PROGRAMACION_III_HASHMAP_H
