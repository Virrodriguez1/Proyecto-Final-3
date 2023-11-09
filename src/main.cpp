// main.cpp
#include "InventoryManager.h"
#include <iostream>

int main() {

    InventoryManager inventory = InventoryManager("../data/Inventariado Fisico.csv");
    inventory.loadInventory();

//    cout<< "Hola Mundo" << endl;

//    cout << "Cantidad total de articulos ditintos: "<< inventory.showTotalDifferentArticles() << endl;

//    cout << "Cantidad total de articulos: " << inventory.showTotalArticles() << endl;

//    cout << "Lista los artículos que están en el mínimo de stock."  << endl;
//    inventory.listArticlesAtMinimumStock();

    cout << "Lista los artículos que están en el mínimo de stock por depósito."  << endl;
    inventory.listArticlesAtMinimumStockByWarehouse();

//    cout << "Muestra el stock individual de cada artículo por depósito."  << endl;
//    inventory.showIndividualArticleStockByWarehouse();

//    cout << "Muestra el stock individual de cada artículo."<< endl;
//    inventory.showIndividualArticleStock();

    cout << "Lista los artículos que igualan o superan una cantidad determinada en stock."<< endl;
    inventory.listArticlesAboveThreshold();

}
