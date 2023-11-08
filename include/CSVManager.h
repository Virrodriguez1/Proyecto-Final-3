
#ifndef CSVHANDLER_H
#define CSVHANDLER_H

#include <string>
#include <fstream>
#include <list>
#include <stdexcept>
#include <iostream>
#include <sstream>
#include "Article.h"

using namespace std;

/**
 * @class CSVHandler
 * @brief Clase encargada de manejar la lectura y escritura de archivos CSV.
 *
 * Esta clase provee funcionalidades para interactuar con archivos CSV, permitiendo leer y escribir datos,
 * y mapearlos a objetos de la clase Article. Además, incluye validación de datos y manejo de errores.
 */
class CSVHandler {
private:
    string filePath; ///< Ruta al archivo CSV.
    char delimiter; ///< Delimitador utilizado en el archivo CSV.
    bool hasHeaders; ///< Indica si el CSV tiene encabezados.
    ifstream fileStream; ///< Flujo del archivo para leer/escribir.


    /**
     * @brief Convierte una línea de CSV en una lista de objetos Article.
     * @param csvLine Línea de texto del archivo CSV.
     * @return Lista de objetos Article.
     * @todo Implementar el manejo de múltiples depósitos por línea de CSV.
     */
    std::list<Article> mapToArticle(const std::string& csvLine) {
        std::list<Article> articles;
        std::stringstream ss(csvLine);

        // Asumimos que los primeros tres tokens son la categoría, el código de barras y el nombre del artículo
        std::string category, barcode, name, token;
        std::getline(ss, category, delimiter);
        std::getline(ss, barcode, delimiter);
        std::getline(ss, name, delimiter);

        // Los siguientes tokens son las cantidades en cada depósito
        // todo: estudiar si hay alguna forma de calcular cuantos depositos hay. pista, las 3 primeras columas son fijas, el resto son depositos
        int depositCount = 5;  // Asumimos que hay 5 depósitos.

        for (int i = 0; i < depositCount; ++i) {
            std::getline(ss, token, delimiter);
            if (!token.empty()) {
                int quantity = std::stoi(token);
                if (quantity > 0) {
                    // Creamos un nuevo artículo por cada depósito con cantidad > 0, usamos i + 1 porque empezamos con i = 0
                    //todo hacer chechkeo si existe otro articulo en stock mismo código hash. PENSARLO MAÑANA
                    Article article(barcode, name, quantity, "Depósito" + std::to_string(i + 1));
                    articles.push_back(article);
                }
            }
        }

        return articles;
    }

public:
    /**
     * @brief Constructor por defecto de CSVHandler.
     */
    CSVHandler() : delimiter(','), hasHeaders(true) {}

    /**
     * @brief Lee un archivo CSV y devuelve los artículos contenidos.
     * @param filePath Ruta al archivo CSV.
     * @return Lista de objetos Article.
     * @exception runtime_error Si no se puede abrir el archivo.
     */
    list<Article> readCSV(const string& filePath) {
        list<Article> articles;
        string line;
        // Abrir archivo
        fileStream.open(filePath);
        if (!fileStream.is_open()) {
            throw runtime_error("No se puede abrir el archivo.");
        }
        // Leer líneas del archivo CSV
        while (getline(fileStream, line)) {
            // Validar y mapear la línea a un objeto Article
            if (validateData(line)) {
                /*
                 * todo. Tener en cuenta lo siguiente. Por cada linea, se puede tener hasta 5 depositos.
                 * lo que tenemos que hacer es, tener una lista de todos los articulos.
                 * la primer linea puede tener hasta 5, la segunda puede aportar hasta 5 nuevos articulos, esto quiere
                 * decir que debemos agregar esos "hasta 5 articulos" de la linea 2 a la lista ya creada, y no hacer una lista nueva.
                 * o sea a, list<Article>articles; quiero agregarle todos los articulos que me devuelva el metodo
                 * mapToArticle(line);
                */
                articles = mapToArticle(line);
            }
        }
        fileStream.close();
        return articles;
    }

    /**
     * @brief Escribe una lista de artículos en un archivo CSV.
     * @param articles Lista de objetos Article para escribir en el archivo.
     * @param filePath Ruta al archivo CSV.
     * @exception runtime_error Si no se puede escribir en el archivo.
     */
    
    /**
     * @brief Convierte un objeto Article en una línea de CSV.
     * @param article Objeto Article a convertir.
     * @return String que representa la línea de CSV del artículo.
     */
    std::string articleToCSVLine(const Article& article) const {
        std::string csvLine = article.getCode() + delimiter +
                              article.getName() + delimiter +
                              std::to_string(article.getQuantity()) + delimiter +
                              article.getWarehouse();
        // Agregar más campos si son necesarios
        return csvLine;
    }


    void writeCSV(const list<Article>& articles, const string& filePath) {
        // Abrir archivo
        ofstream outFile(filePath);
        if (!outFile.is_open()) {
            throw runtime_error("No se puede escribir en el archivo.");
        }
        // Escribir cada artículo en el archivo CSV
        for (const auto& article : articles) {
            outFile << articleToCSVLine(article) << endl;
        }
        outFile.close();
    }

    /**
     * @brief Valida una línea de CSV para determinar si puede convertirse en un objeto Article.
     * @param csvLine Línea de texto del archivo CSV.
     * @return Verdadero si la línea es válida, falso en caso contrario.
     */
    bool validateData(const string& csvLine) {
        // Implementación de validación básica
        return !csvLine.empty(); // Simplemente verifica si la línea no está vacía
    }

    /**
     * @brief Maneja errores que puedan surgir durante la lectura o escritura de archivos CSV.
     * @param errorCode Código de error específico del problema que ocurrió.
     * @param errorMessage Mensaje descriptivo del error.
     */
    void handleError(int errorCode, const string& errorMessage) {
        // Implementación básica para manejo de errores
        cerr << "Error " << errorCode << ": " << errorMessage << endl;
    }

    /**
     * @brief Cierra un archivo CSV abierto.
     * @param fileStream Flujo del archivo CSV.
     */
    void closeFile(ifstream& fileStream) {
        if (fileStream.is_open()) {
            fileStream.close();
        }
    }
};

#endif // CSVHANDLER_H
