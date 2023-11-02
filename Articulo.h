// Articulo.h

#ifndef ARTICULO_H
#define ARTICULO_H

#include <string>
#include <iostream>

class Articulo {
public:
    Articulo(std::string codigo = "", std::string nombre = "", int cantidad = 0, std::string deposito = "")
            : codigo(codigo), nombre(nombre), cantidad(cantidad), deposito(deposito) {}

    std::string getCodigo() const { return codigo; }
    std::string getNombre() const { return nombre; }
    int getCantidad() const { return cantidad; }
    std::string getDeposito() const { return deposito; }
    void setCantidad(int cantidad) { this->cantidad = cantidad; }

    void mostrarInfo() const {
        std::cout << "Codigo: " << codigo << ", Nombre: " << nombre
                  << ", Cantidad: " << cantidad << ", Deposito: " << deposito << std::endl;
    }

private:
    std::string codigo;
    std::string nombre;
    int cantidad;
    std::string deposito;
};

#endif // ARTICULO_H

