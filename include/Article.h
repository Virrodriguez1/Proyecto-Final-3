#ifndef PROYECTOFINAL_PROGRAMACION_III_ARTICLE_H
#define PROYECTOFINAL_PROGRAMACION_III_ARTICLE_H

#include <string>
#include <iostream>

using namespace std;
/**
 * @class Article
 * @brief Clase que representa un artículo en el inventario.
 *
 * Encapsula los detalles de un artículo, incluyendo su código, nombre,
 * cantidad en stock y el depósito donde se encuentra.
 */
class Article {
private:
    string code;      ///< Código único del artículo.
    string name;      ///< Nombre descriptivo del artículo.
    int quantity;     ///< Cantidad del artículo en stock.
    string warehouse; ///< Nombre del depósito donde se almacena el artículo.

public:
    /**
     * @brief Constructor para crear un nuevo artículo.
     * @param code Código del artículo.
     * @param name Nombre del artículo.
     * @param quantity Cantidad en stock.
     * @param warehouse Depósito donde se encuentra el artículo.
     */
    Article(const string& code, const string& name, int quantity, const string& warehouse)
            : code(code), name(name), quantity(quantity), warehouse(warehouse) {}

    // Getters y setters para cada atributo.

    /**
     * @brief Obtiene el código del artículo.
     * @return Código del artículo como string.
     */
    string getCode() const { return code; }

    /**
     * @brief Obtiene el nombre del artículo.
     * @return Nombre del artículo como string.
     */
    string getName() const { return name; }

    /**
     * @brief Obtiene la cantidad en stock del artículo.
     * @return Cantidad del artículo como entero.
     */
    int getQuantity() const { return quantity; }

    /**
     * @brief Obtiene el depósito donde se almacena el artículo.
     * @return Nombre del depósito como string.
     */
    string getWarehouse() const { return warehouse; }

    /**
     * @brief Establece una nueva cantidad en stock para el artículo.
     * @param newQuantity La nueva cantidad en stock.
     */
    void setQuantity(int newQuantity) { quantity = newQuantity; }

    // Puedes agregar más funciones miembro según sea necesario
};

#endif //PROYECTOFINAL_PROGRAMACION_III_ARTICLE_H
