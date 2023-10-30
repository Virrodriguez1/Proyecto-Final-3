
#ifndef PROYECTOFINAL_PROGRAMACION_3_LISTA_H
#define PROYECTOFINAL_PROGRAMACION_3_LISTA_H
#include <iostream>
#include "nodo.h"
using namespace std;
/**
 * Clase que implementa una Lista Enlasada generica, ya que puede
 * almacenar cualquier tipo de dato T
 * @tparam T cualquier tipo de dato
 **/
template <class T> class Lista {
private:
    Nodo<T> *inicio;
    T dato;
public:
    Lista();

    Lista(const Lista<T> &li);

    ~Lista();

    bool esVacia();

    int getTamanio();

    void insertar(int pos, T dato);

    void insertarPrimero(T dato);

    void insertarUltimo(T dato);

    void remover(int pos);

    T getDato(int pos);

    void reemplazar(int pos, T dato);

    void vaciar();

    void imprimir();

    void fnInvierte();

    void insertAfterN(int oldValue, int newValue, int n);
};

/**
 * Constructor de la clase Lista
 * @tparam T
 **/
template <class T> Lista<T>::Lista() {
    inicio = nullptr;
}

/**
 * Constructor por copia de la clase Lista
 * @tparam T
 * @param li
 **/
template <class T> Lista<T>::Lista(const Lista<T> &li) {
    inicio = nullptr;
}

/**
 * Destructor de la clase Lista, se encarga de liberar la memoria de todos los
 * nodos utilizados en la lista
 * @tparam T
 **/
template <class T> Lista<T>::~Lista() {}

/**
 * Metodo para saber si la lista esta vacia
 * @tparam T
 * @return true si la lista esta vacia, sino false
 **/
template <class T> bool Lista<T>::esVacia() {
    return inicio == nullptr;
}

/**
 * Metodo para obtener la cantidad de nodos de la lista
 * @tparam T
 * @return la cantidad de nodos de la lista
 **/
template <class T> int Lista<T>::getTamanio() {
    Nodo<T> *aux = inicio;
    int tam = 0;

    while (aux != nullptr) {
        aux = aux->getSiguiente();
        tam++;
    }
    return tam;
}

/**
 * Inserta un nodo con el dato en la posicion pos
 * @tparam T
 * @param pos lugar donde serÃƒÂ¡ insertado el dato
 * @param dato  dato a insertar
 **/
template <class T> void Lista<T>::insertar(int pos, T dato) {
    Nodo<T> *aux=inicio;
    int posActual=0;
    Nodo<T> *nuevo= new Nodo<T>;

    if (pos==0){
        nuevo -> setSiguiente(inicio);

    }

    while (aux!= nullptr && posActual < pos-1){
        aux=aux->getSiguiente();
        posActual++;
    }

    if (aux== nullptr){
        throw 404;
    }
    nuevo->setSiguiente(aux->getSiguiente());
    aux->setSiguiente(nuevo);
}

/**
 * Inserta un nodo con el dato en la primera posicion
 * @tparam T
 * @param dato dato a insertar
 **/
template <class T> void Lista<T>::insertarPrimero(T dato) {
    insertar(0, dato);
}

/**
 * Inserta un nodo con el dato en la ultima posicion
 * @tparam T
 * @param dato dato a insertar
 **/

template <class T> void Lista<T>::insertarUltimo(T dato) {
    Nodo<T> *aux=inicio;
    Nodo<T> *nuevo= new Nodo<T>;
    nuevo->setDato(dato);
    if(aux== nullptr){
        nuevo->setSiguiente(inicio);
        inicio = nuevo;
        return;
    }

    while (aux->getSiguiente()!= nullptr){
        aux=aux->getSiguiente();
    }
    nuevo->setSiguiente(aux->getSiguiente());
    aux->setSiguiente(nuevo);

}

/**
 * Elimina el nodo en la posicion 'pos' de la lista enlasada
 * @tparam T
 * @param pos posicion del nodo a eliminar
 */

template <class T> void Lista<T>::remover(int pos) {
    Nodo<T> *aux=inicio, *aBorrar;
    int posActual=0;
    if(pos==0){
        inicio=inicio->setSiguiente();
        delete aux;
        return;
    }

    while(aux!=nullptr && posActual<pos-1){
        aux=aux->getSiguiente();
        posActual++;
    }

    if (aux==nullptr){
        throw 404;
    }

    aBorrar=aux->setSiguiente();
    aux->setSiguiente(aBorrar->getSiguiente());
    delete aBorrar;

}

/**
 * Obtener el dato del nodo en la posicion pos
 * @tparam T
 * @param pos posicion del dato
 * @return dato almacenado en el nodo
 */

template <class T> T Lista<T>::getDato(int pos) {
    Nodo<T> *aux=inicio;
    int posActual=0;

    while(aux!=nullptr && posActual<pos-1){
        aux=aux->getSiguiente();
        posActual++;
    }

    if (aux==nullptr){
        throw 404;
    }

    aux->setdato(dato);
}

/**
 * Reemplaza el dato almacenado en un nodo por este otro
 * @tparam T
 * @param pos posicion donde se desea reemplazar
 * @param dato nuevo dato a almacenar
 **/
template <class T> void Lista<T>::reemplazar(int pos, T dato) {}

/**
 * FunciÃƒÂ³n que vacia la lista enlazada
 * @tparam T
 **/

template <class T> void Lista<T>::vaciar() {
    Nodo<T> *aux=inicio, *aBorrar;
    int posActual=0;

    while(aux!=nullptr){
        aBorrar=aux;
        aux=aux->getSiguiente();
        delete aBorrar;
    }
    if (aux==nullptr){
        throw 404;
    }
    inicio=nullptr;

}

/*
 * Implementar la funciÃƒÂ³n fnInvierte(lista).
 * Esta funciÃƒÂ³n invertirÃƒÂ¡ el orden original de los elementos en la lista,
 * de tal forma que el ÃƒÂºltimo elemento serÃƒÂ¡ ahora el primero, el penÃƒÂºltimo serÃƒÂ¡ el segundo,
 * y asÃƒÂ­ hasta que el primero sea el ÃƒÂºltimo. Considere que la lista no estÃƒÂ¡ vacÃƒÂ­a y que no se construirÃƒÂ¡ una nueva,
 * sÃƒÂ³lo se invertirÃƒÂ¡ el orden de los elementos de la lista original.
 */

template <class T>
void Lista<T>::fnInvierte() {
    Nodo<T> *aux= inicio, *anterior= nullptr, *siguiente=inicio;

    if (esVacia()){
        return;
    }
    siguiente=siguiente->getSiguiente();

    while (siguiente != nullptr){
        aux->setSiguiente(anterior);
        anterior=aux;
        aux=siguiente;
        siguiente=siguiente->getSiguiente();
    }
    aux->setSiguiente(anterior);
    inicio=aux;
}

template <class T> void Lista<T>::imprimir(){
    Nodo<T> *aux=inicio;
    while(aux != nullptr){
        cout<<aux->getDato()<<"->";
        aux=aux->getSiguiente();
    }
    cout<<"NULL"<<endl;
}

template<class T>
void Lista<T>::insertAfterN(int oldValue, int newValue, int n){
    Nodo<T> *aux=inicio;
    int contador =0;

    while(aux != nullptr){
        if(aux->getDato() == oldValue){
            contador++;
        }
        if (contador==n){
            break;
        }
        aux=aux->getSiguiente();
    }
    if(aux== nullptr){
        throw 404;
    }
    Nodo<T> *nuevo=new Nodo<T>;
    nuevo->setDato(newValue);
    nuevo->setSiguiente(aux->getSiguiente());
    aux->setSiguiente(nuevo);
}
#endif //PROYECTOFINAL_PROGRAMACION_3_LISTA_H
