
/**
 * @file HashEntry.h
 * @brief Archivo de cabecera para la clase HashEntry.
 *
 * Define la clase HashEntry que se utiliza para almacenar pares de clave-valor
 * en una estructura de tabla hash con encadenamiento para resolver colisiones.
 *
 * @author virrr
 * @date 10/27/2023
 */

#ifndef PROYECTOFINAL_PROGRAMACION_III_HASHENTRY_H
#define PROYECTOFINAL_PROGRAMACION_III_HASHENTRY_H

/**
 * @class HashEntry
 * @brief Representa una entrada individual para una tabla hash.
 *
 * Esta clase mantiene una clave y un valor, y un puntero a otro HashEntry
 * para manejar colisiones mediante encadenamiento.
 *
 * @tparam K Tipo de dato de la clave.
 * @tparam T Tipo de dato del valor.
 */
template <class K, class T>
class HashEntry {
private:
    K key;   ///< Clave de la entrada hash.
    T value; ///< Valor asociado a la clave.
    HashEntry<K, T> *next; ///< Puntero al siguiente HashEntry en caso de colisión.

public:
    /**
     * @brief Constructor que inicializa una entrada con una clave y un valor.
     * @param key La clave de la entrada.
     * @param value El valor asociado a la clave.
     */
    HashEntry(K key, T value) : key(key), value(value), next(nullptr) {}

    /**
     * @brief Obtiene la clave de la entrada.
     * @return La clave actual de la entrada.
     */
    K getKey() const {
        return key;
    }

    /**
     * @brief Obtiene el valor de la entrada.
     * @return El valor actual de la entrada.
     */
    T getValue() const {
        return value;
    }

    /**
     * @brief Obtiene el puntero al siguiente HashEntry en caso de colisión.
     * @return Puntero al siguiente HashEntry si existe, de lo contrario nullptr.
     */
    HashEntry<K, T>* getNext() const {
        return next;
    }

    /**
     * @brief Establece el puntero al siguiente HashEntry en caso de colisión.
     * @param nextEntry Puntero al siguiente HashEntry.
     */
    void setNext(HashEntry<K, T>* nextEntry) {
        next = nextEntry;
    }

    /**
     * @brief Establece un nuevo valor para esta entrada.
     * @param newValue Nuevo valor para asociar con la clave actual.
     */
    void setValue(const T& newValue) {
        value = newValue;
    }
};

#endif //PROYECTOFINAL_PROGRAMACION_III_HASHENTRY_H
