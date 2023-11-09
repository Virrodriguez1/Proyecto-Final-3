// main.cpp
#include "HashMap.h"
#include "CSVManager.h"
#include "InventoryManager.h"
#include <iostream>
#include <Article.h>

// Definir un objeto personalizado para almacenar en el hashmap
struct CustomObject {
    /*
    int attr1;
    double attr2;
    string attr3;
    char attr4;

    // Constructor
    CustomObject(int a1, double a2, string a3, char a4) : attr1(a1), attr2(a2), attr3(std::move(a3)), attr4(a4) {}

    // Un constructor simple para poder inicializar sin parámetros
    CustomObject() : attr1(0), attr2(0.0), attr3(""), attr4('\0') {}

    // Destructor
    ~CustomObject() = default;
     */
};



int main() {

    InventoryManager inventory = InventoryManager("../data/Inventariado.csv");
    inventory.loadInventory();

    cout<< "Hola Mundo" << endl;

//    cout << "Cantidad total de articulos ditintos: "<< inventory.showTotalDifferentArticles() << endl;

//    cout << "Cantidad total de articulos: " << inventory.showTotalArticles() << endl;

    cout << "Lista los artículos que están en el mínimo de stock."  << endl;
    inventory.listArticlesAtMinimumStock();




/*
    string csvLine = "AMOBLAMIENTO,AMLM-AM-U61-B,BANQUETA TAPIZADA COST BCO  BASE PINTADA NEGRO,,,1,,";

    CSVManager csvManager = CSVManager();
    list<Article> articles = csvManager.mapToArticle(csvLine);



    // Crear un hashmap para string keys y CustomObject values
    HashMap<CustomObject> map;
    HashMap<Article> map2;

    Article article("ORANAFE-065120","ANAFE VITROCERAMICO VITRO COOK 4", 1, "Deposito 4");

    map2.insert("ORANAFE-065120-4",article);

    // Obtener el valor usando la clave
    Article* articleStored = map2.get("ORANAFE-065120-4");
    if (articleStored != nullptr) {
        cout << "Object found:" << endl;
        cout << "Code: " << articleStored->getCode() << endl;
        cout << "Name: " << articleStored->getName() << endl;
        cout << "Quantity: " << articleStored->getQuantity() << endl;
        cout << "Warehouse: " << articleStored->getWarehouse() << endl;
    } else {
        cout << "Object not found." << endl;
    }

    // Output the size of the map
    cout << "The size of the map is: " << map.getSize() << endl;

    return 0;*/
}
