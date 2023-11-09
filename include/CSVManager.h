
#ifndef CSVMANAGER_H
#define CSVMANAGER_H

#include <string>
#include <fstream>
#include <list>
#include <stdexcept>
#include <iostream>
#include <sstream>
#include "Article.h"

using namespace std;

/**
 * @class CSVManager
 * @brief Clase encargada de manejar la lectura y escritura de archivos CSV.
 *
 * Esta clase provee funcionalidades para interactuar con archivos CSV, permitiendo leer y escribir datos,
 * y mapearlos a objetos de la clase Article. Además, incluye validación de datos y manejo de errores.
 */
class CSVManager {
private:
    string filePath; ///< Ruta al archivo CSV.
    char delimiter; ///< Delimitador utilizado en el archivo CSV.
    bool hasHeaders; ///< Indica si el CSV tiene encabezados.
    ifstream fileStream; ///< Flujo del archivo para leer/escribir.




public:
    /**
     * @brief Constructor por defecto de CSVManager.
     */
    CSVManager() : delimiter(','), hasHeaders(true) {}

    explicit CSVManager(const string &filePath) : filePath(filePath), delimiter(','), hasHeaders(true) {}

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
        if(hasHeaders){
            getline(fileStream, line);
        }
        // Leer líneas del archivo CSV
        while (getline(fileStream, line)) {
            // Validar y mapear la línea a un objeto Article
            if (validateData(line)) {
                //etireamos de esta forma ya que en cada linea puede haber mas de un deposito, mapToArticle los procesa
                //y develve una lista de articulos, que iteramos para guardar uno por uno en la lista definitiva.

                    articles.push_back(mapToArticle(line));
            }
        }
        fileStream.close();
        return articles;
    }

    /**
     * @brief Convierte un objeto Article en una línea de CSV.
     * @param article Objeto Article a convertir.
     * @return String que representa la línea de CSV del artículo.
     * ?privado??
     */
    std::string articleToCSVLine(Article article) const {

        std::string csvLine = article.getCategory() + delimiter +
                              article.getCode() + delimiter +
                              article.getName() + delimiter +
                              article.getWarehousesPlainText();

        string str = "";
        for(const auto warehouse: article.getWarehouses()){
            str += warehouse + delimiter;
        }

        // Agregar más campos si son necesarios
        return csvLine + str;
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
    /**
    * @brief Convierte una línea de CSV en una lista de objetos Article.
    * @param csvLine Línea de texto del archivo CSV.
    * @return Lista de objetos Article.
    */
    Article mapToArticle(const std::string& csvLine) const {
        // Crear una lista para almacenar los artículos
        std::list<Article> articles;
        vector<int> warehouses;

        // Crear un stringstream de csvLine
        std::stringstream ss(csvLine);

        // Asumir que los primeros tres tokens son la categoría, el código de barras y el nombre del artículo
        std::string category, barcode, name, token;
        std::getline(ss, category, delimiter);
        std::getline(ss, barcode, delimiter);
        std::getline(ss, name, delimiter);

        // El resto de los tokens son las cantidades en cada depósito
        // Usar un bucle para leer cada cantidad y crear un objeto Article si la cantidad > 0
        int depositNumber = 1;  // Inicializar el número de depósito
        string str;
        while (std::getline(ss, token, delimiter)) {
            if (!token.empty()) {
                int quantity = std::stoi(token);
                if (quantity > 0) {
                    // El número de depósito se calcula con base en la posición actual en la línea
                    // teniendo en cuenta que las primeras tres columnas son fijas.
                    warehouses.push_back(quantity);
                }
            } else{
                warehouses.push_back(0);
            }
            depositNumber++; // Incrementar el número de depósito para la siguiente columna
        }if(token.empty()){
            warehouses.push_back(0);
        }
        return Article(barcode, name, warehouses);
    }
};

#endif // CSVMANAGER_H
