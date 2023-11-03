#include "Article.h"
#include <vector>
#include <iostream>

int main() {
    // Crear algunos artículos de prueba
    Article article1("001", "Laptop", 10, "Electronics");
    Article article2("002", "Smartphone", 15, "Mobile");
    Article article3("003", "Headphones", 5, "Accessories");

    // Vector que contiene los artículos
    std::vector<Article> inventory = {article1, article2, article3};

    // Mostrar la información de cada artículo
    for (const Article& article : inventory) {
        std::cout << "Code: " << article.getCode() << std::endl;
        std::cout << "Name: " << article.getName() << std::endl;
        std::cout << "Quantity: " << article.getQuantity() << std::endl;
        std::cout << "Warehouse: " << article.getWarehouse() << std::endl;
        std::cout << "-----------------------------------" << std::endl;
    }

    // Modificar la cantidad en stock de un artículo
    std::cout << "Updating quantity for the first article..." << std::endl;
    inventory[0].setQuantity(20);

    // Verificar la actualización
    std::cout << "Code: " << inventory[0].getCode() << std::endl;
    std::cout << "Updated Quantity: " << inventory[0].getQuantity() << std::endl;

    return 0;
}
