//
// Created by virrr on 10/27/2023.
//

#ifndef PROYECTOFINAL_PROGRAMACION_III_HASHENTRY_H
#define PROYECTOFINAL_PROGRAMACION_III_HASHENTRY_H


template <class K, class T>
class HashEntry
{
private:
    K clave;
    T valor;
public:
    HashEntry(K c, T v){
        clave = c;
        valor = v;
    }

    K getClave(){
        return clave;
    }
    void setClave(K c){
        clave = c;
    }

    T getValor(){
        return valor;
    }
    void setValor(T v){
        valor = v;
    }
};

#endif //PROYECTOFINAL_PROGRAMACION_III_HASHENTRY_H
