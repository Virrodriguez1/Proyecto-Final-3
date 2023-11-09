#ifndef PROYECTOFINAL_PROGRAMACION_III_ARTICLE_H
#define PROYECTOFINAL_PROGRAMACION_III_ARTICLE_H

#include <string>
#include <iostream>
#include <vector>
#include <sstream>

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
    string category;
public:
    const string &getCategory() const {
        return category;
    }

    void setCategory(const string &category) {
        Article::category = category;
    }

private:
    string code;      ///< Código único del artículo.
    string name;      ///< Nombre descriptivo del artículo.
    vector<int> warehouses; ///< Nombre del depósito donde se almacena el artículo.

public:
    /**
     * @brief Constructor para crear un nuevo artículo.
     * @param code Código del artículo.
     * @param name Nombre del artículo.
     * @param quantity Cantidad en stock.
     * @param warehouse Depósito donde se encuentra el artículo.
     */
    Article(const string& code, const string& name, const vector<int>& warehouse)
            : code(code), name(name), warehouses(warehouse) {}

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
     * @brief Obtiene el depósito donde se almacena el artículo.
     * @return Nombre del depósito como string.
     */
    vector<int> getWarehouses() const { return warehouses; }

    // Puedes agregar más funciones miembro según sea necesario
    string getWarehousesPlainText() const {
        ostringstream os;
        // Convertir la lista de almacenes en un string, separado por comas.
        string warehousesStr;
        for (auto it = warehouses.begin(); it != warehouses.end(); ++it) {
            if (it != warehouses.begin()) {
                warehousesStr += ", ";
            }
            warehousesStr += to_string(*it);
        }
        os << "Total Stock: " << getTotalStock() << endl;
        os << "Warehouses: [" << warehousesStr << "]" << endl;
        return os.str();
    }

    size_t getTotalStock() const {
        size_t size = 0;
        for(auto const &warehouse:warehouses){
            size += warehouse;
        }
        return size;
    }

    string toStringStock() const {
        ostringstream os;
        os << "----------------------------------------"<<endl;
        os << "Article Details:" << endl;
        os << "Category: " << getCategory() << endl;
        os << "Name: " << getName() << endl;
        os << "Total Stock: " << getTotalStock() << endl;
        os << "----------------------------------------"<<endl<<endl<<endl<<endl;


        return os.str();
    }

    string toStringStockByWarehouse()const {
        ostringstream os;
        os << "----------------------------------------"<<endl;
        os << "Article Details:" << endl;
        os << "Category: " << getCategory() << endl;
        os << "Name: " << getName() << endl;
        os << getWarehousesPlainText();
        os << "----------------------------------------"<<endl<<endl<<endl<<endl;
        return os.str();

    }

};

#endif //PROYECTOFINAL_PROGRAMACION_III_ARTICLE_H
