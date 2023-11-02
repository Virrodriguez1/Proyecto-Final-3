// CSVManager.h

#ifndef CSV_MANAGER_H
#define CSV_MANAGER_H

#include "Articulo.h"
#include "HashMap.h"
#include <string>
#include <iostream>
#include <fstream>
#include <vector>

class Inventario;  // Declaración adelantada

class CSVManager {
public:
    static void leerCSV(const std::string& rutaArchivo, HashMap<std::string, Articulo>& articulos) {
        std::ifstream archivo(rutaArchivo);
        if (!archivo.is_open()) {
            std::cerr << "Error al abrir el archivo: " << rutaArchivo << std::endl;
            return;
        }

        std::string linea;
        while (std::getline(archivo, linea)) {
            // Parsear la línea y crear un objeto Articulo
            // Añadir el artículo a la tabla hash 'articulos'
            // Por simplicidad, omito la implementación detallada
        }
        archivo.close();
    }

    static void escribirCSV(const std::string& rutaArchivo, const HashMap<std::string, Articulo>& articulos) {
        std::ofstream archivo(rutaArchivo);
        if (!archivo.is_open()) {
            std::cerr << "Error al abrir el archivo: " << rutaArchivo << std::endl;
            return;
        }

        // Implementar la lógica para escribir los datos de 'articulos' en el archivo CSV
        // Por simplicidad, omito la implementación detallada

        archivo.close();
    }
};

#endif // CSV_MANAGER_H
