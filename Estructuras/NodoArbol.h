
#ifndef PROYECTOFINAL_PROGRAMACION_3_NODOARBOL_H
#define PROYECTOFINAL_PROGRAMACION_3_NODOARBOL_H


#include <iostream>
using namespace std;

template <class T>
class NodoArbol {
private:
    T data;
    NodoArbol *left, *right;
public:
    NodoArbol() : left(nullptr), right(nullptr) {}

    NodoArbol(T d) : left(nullptr), right(nullptr), data(d) {}

    T getData() const {
        return data;
    }

    void setData(T d) {
        this->data = d;
    }

    NodoArbol *getRight() const {
        return right;
    }

    void setRight(NodoArbol *r) {
        this->right = r;
    }

    NodoArbol *getLeft() const {
        return left;
    }

    void setLeft(NodoArbol *l) {
        this->left = l;
    }

    void print(bool esDerecho, string identacion) {
        if (right != nullptr) {
            right->print(true, identacion + (esDerecho ? "     " : "|    "));
        }
        cout << identacion;
        if (esDerecho) {
            cout << " /";
        } else {
            cout << " \\";
        }
        cout << "-- " << data << endl;
        if (left != nullptr) {
            left->print(false, identacion + (esDerecho ? "|    " : "     "));
        }
    }
};

#endif //PROYECTOFINAL_PROGRAMACION_3_NODOARBOL_H
