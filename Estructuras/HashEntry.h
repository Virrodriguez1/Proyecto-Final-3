//
// Created by virrr on 10/27/2023.
//

#ifndef PROYECTOFINAL_PROGRAMACION_III_HASHENTRY_H
#define PROYECTOFINAL_PROGRAMACION_III_HASHENTRY_H

template <class K, class T>
class HashEntry {
private:
    K clave;
    T valor;
    HashEntry<K, T> *next;  // Puntero al siguiente HashEntry en caso de colisión

public:
    HashEntry(K c, T v) : clave(c), valor(v), next(nullptr) {}

    K getClave() {
        return clave;
    }

    T getValor() {
        return valor;
    }

    HashEntry<K, T>* getNext() {
        return next;
    }

    void setNext(HashEntry<K, T>* siguiente) {
        next = siguiente;
    }
    void setValor(const T& nuevoValor) {
        valor = nuevoValor;
    }
};


#endif //PROYECTOFINAL_PROGRAMACION_III_HASHENTRY_H
