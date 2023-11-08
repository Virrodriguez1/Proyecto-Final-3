
#include <list>
#include <fstream>
#include "Article.h"

using namespace std;

/**
 * @class CSVHandler
 * @brief Clase encargada de manejar la lectura y escritura de archivos CSV.
 *
 * Esta clase provee funcionalidades para interactuar con archivos CSV, permitiendo leer y escribir datos,
 * y mapearlos a objetos de la clase Article. Además, incluye validación de datos y manejo de errores.
 * @todo Implementar todos los métodos y manejo de errores.
 */
class CSVHandler {
private:
    string filePath; ///< Ruta al archivo CSV.
    ifstream fileStream; ///< Flujo del archivo para leer/escribir.
    char delimiter; ///< Delimitador utilizado en el archivo CSV.
    bool hasHeaders; ///< Indica si el CSV tiene encabezados.
    string currentLine; ///< Línea actual del archivo CSV.

public:
    /**
     * @brief Constructor por defecto de CSVHandler.
     * @todo Implementar el constructor.
     */
    CSVHandler();

    /**
     * @brief Lee un archivo CSV y devuelve los artículos contenidos.
     * @param filePath Ruta al archivo CSV.
     * @return Lista de objetos Article.
     * @exception runtime_error Si no se puede abrir el archivo.
     * @todo Implementar la lectura de archivos CSV.
     */
    list<Article> readCSV(const string& filePath);

    /**
     * @brief Escribe una lista de artículos en un archivo CSV.
     * @param articles Lista de objetos Article para escribir en el archivo.
     * @param filePath Ruta al archivo CSV.
     * @exception runtime_error Si no se puede escribir en el archivo.
     * @todo Implementar la escritura en archivos CSV.
     */
    void writeCSV(const list<Article>& articles, const string& filePath);

    /**
     * @brief Convierte una línea de CSV en un objeto Article.
     * @param csvLine Línea de texto del archivo CSV.
     * @return Objeto Article.
     * @exception invalid_argument Si la línea no tiene el formato correcto.
     * @todo Implementar el mapeo de datos CSV a objetos Article.
     */
    Article mapToArticle(const string& csvLine);

    /**
     * @brief Valida una línea de CSV para determinar si puede convertirse en un objeto Article.
     * @param csvLine Línea de texto del archivo CSV.
     * @return Verdadero si la línea es válida, falso en caso contrario.
     * @todo Implementar la validación de la línea CSV.
     */
    bool validateData(const string& csvLine);

    /**
     * @brief Maneja errores que puedan surgir durante la lectura o escritura de archivos CSV.
     * @param errorCode Código de error específico del problema que ocurrió.
     * @param errorMessage Mensaje descriptivo del error.
     * @todo Implementar el manejo de errores.
     */
    void handleError(int errorCode, const string& errorMessage);

    /**
     * @brief Cierra un archivo CSV abierto.
     * @param fileStream Flujo del archivo CSV.
     * @todo Implementar el cierre seguro de archivos CSV.
     */
    void closeFile(ifstream& fileStream);
};
