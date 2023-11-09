
#ifndef INVENTORY_MANAGER_H
#define INVENTORY_MANAGER_H

#include "CSVManager.h"
#include "Article.h"
#include "HashMap.h"
#include <string>

/**
 * @class InventoryManager
 * @brief Gestiona el inventario de artículos.
 * 
 * Esta clase es responsable de cargar, actualizar y guardar el inventario
 * de artículos a partir de un archivo CSV. Interactúa con la clase CSVManager
 * para realizar operaciones relacionadas con archivos CSV.
 */
class InventoryManager {
private:
    HashMap<Article> inventory; //!< Estructura para almacenar el inventario.
    CSVManager csvManager;      //!< Utilidad para manejar operaciones relacionadas con CSV.
    std::string fileName;       //!< Nombre del archivo CSV en el directorio /data.
    list<Article> articlesTMP;
    list<Article> lowStock;
    list<Article> highStock;
    size_t MINIMUM_STOCK = 5;
    size_t MAX_STOCK = 20;

public:
    /**
     * @brief Constructor que inicializa el manejador con el nombre del archivo CSV.
     * @param csvFileName Nombre del archivo CSV.
     */
    explicit InventoryManager(const std::string& csvFileName)
        : fileName(csvFileName), csvManager("../data/" + csvFileName) {}

    /**
     * @brief Carga el inventario desde el archivo CSV.
     * 
     * Lee el archivo CSV especificado y carga los artículos en la estructura
     * de inventario.
     */
    void loadInventory();

    /**
     * @brief Guarda el inventario en el archivo CSV.
     * 
     * Escribe los cambios en el inventario actual en el archivo CSV especificado.
     */
    void saveInventory();

    /**
     * @brief Muestra el menú principal y maneja la selección del menú.
     * 
     * Presenta las opciones del menú al usuario y ejecuta las acciones
     * seleccionadas para la gestión del inventario.
     */
    void displayMainMenu();

    size_t showTotalDifferentArticles();

    size_t showTotalArticles();

    void listArticlesAtMinimumStock();
    void listArticlesAtMinimumStockByWarehouse();
    void showIndividualArticleStock();
    void listArticlesAboveThreshold();
    void showIndividualArticleStockByWarehouse();

    // Métodos adicionales para las operaciones de inventario...
    // Y así sucesivamente...
};

#endif // INVENTORY_MANAGER_H
