#include "Articulo.h"
#include "Inventario.h"
#include "CSVManager.h"
#include <iostream>
#include <string>

int main() {
    Inventario inventario;
    CSVManager csvManager;
    std::string archivoCSV;
    int opcion;

    std::cout << "Ingrese el nombre del archivo CSV para cargar el inventario: ";
    std::cin >> archivoCSV;
    inventario.cargarDesdeCSV(archivoCSV);

    do {
        std::cout << "\nMenu de opciones:\n";
        std::cout << "1. Mostrar cantidad total de articulos diferentes.\n";
        std::cout << "2. Mostrar cantidad total de articulos.\n";
        std::cout << "3. Listado de articulos en el minimo de stock.\n";
        std::cout << "4. Listado de articulos en el minimo de stock por deposito.\n";
        std::cout << "5. Stock individual de cada articulo.\n";
        std::cout << "6. Stock individual de cada articulo por deposito.\n";
        std::cout << "7. Articulos cuyo stock iguala o supera un numero n.\n";
        std::cout << "8. Guardar inventario en archivo CSV.\n";
        std::cout << "0. Salir\n";
        std::cout << "Seleccione una opcion: ";
        std::cin >> opcion;

        switch (opcion) {
            case 1:
               // inventario.mostrarCantidadArticulosDiferentes();
                break;
            case 2:
                inventario.mostrarCantidadTotalArticulos();
                break;
            case 3:
                inventario.mostrarArticulosMinimoStock();
                break;
            case 4:
                inventario.mostrarArticulosMinimoStockPorDeposito();
                break;
            case 5:
                inventario.mostrarStockIndividualArticulos();
                break;
            case 6:
                inventario.mostrarStockIndividualArticulosPorDeposito();
                break;
            case 7:
                inventario.mostrarArticulosStockSuperior();
                break;
            case 8:
                std::cout << "Ingrese el nombre del archivo CSV para guardar el inventario: ";
                std::cin >> archivoCSV;
                inventario.guardarEnCSV(archivoCSV);
                break;
            case 0:
                std::cout << "Saliendo...\n";
                break;
            default:
                std::cout << "Opcion no valida, por favor intente nuevamente.\n";
        }
    } while (opcion != 0);

    return 0;
}
