#ifndef INVENTARIO_H
#define INVENTARIO_H

#include "Articulo.h"
#include "HashMap.h"
#include "CSVManager.h"
#include <string>
#include <iostream>

class Inventario {
private:
    HashMap<std::string, Articulo> articulos;
    CSVManager csvManager;

public:
    Inventario() : articulos(100, hashFuncionParaStrings) {}// Usamos el constructor de HashMap que no requiere función hash

    void cargarDesdeCSV(const std::string& nombreArchivo) {
        // Implementar lógica para cargar los artículos desde un archivo CSV
    }

    void guardarEnCSV(const std::string& nombreArchivo) {
        // Implementar lógica para guardar los artículos en un archivo CSV
    }


    void mostrarCantidadTotalArticulos() {

    }

    void mostrarArticulosMinimoStock() {
        // Este método mostrará los artículos que estén en su stock mínimo
        // Implementación pendiente
    }

    void mostrarArticulosMinimoStockPorDeposito() {
        // Este método mostrará los artículos que estén en su stock mínimo, agrupados por depósito
        // Implementación pendiente
    }

    void mostrarStockIndividualArticulos() {
        // Este método mostrará el stock individual de cada artículo
        // Implementación pendiente
    }

    void mostrarStockIndividualArticulosPorDeposito() {
        // Este método mostrará el stock individual de cada artículo, agrupado por depósito
        // Implementación pendiente
    }

    void mostrarArticulosStockSuperior() {
        // Este método mostrará los artículos cuyo stock es igual o superior a un número n
        // Implementación pendiente
    }
};

#endif // INVENTARIO_H
