//
// Created by virrr on 10/16/2023.
//

#ifndef PROYECTOFINAL_PROGRAMACION_3_NODO_H
#define PROYECTOFINAL_PROGRAMACION_3_NODO_H


template <class T>
class Nodo
{
private:
    T dato;
    Nodo<T> *siguiente;

public:
    T getDato()
    {
        return dato;
    }

    void setDato(T d)
    {
        dato = d;
    }

    Nodo<T> *getSiguiente()
    {
        return siguiente;
    }

    void setSiguiente(Nodo<T> *s)
    {
        this->siguiente = s;
    }
};


#endif //PROYECTOFINAL_PROGRAMACION_3_NODO_H
