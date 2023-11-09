
#include "InventoryManager.h"

void InventoryManager::loadInventory() {
    try {
        // Leer el archivo CSV utilizando CSVManager
        auto articlesList = csvManager.readCSV(fileName);

        // Reinicializar el inventario para limpiarlo antes de cargar nuevos datos
        inventory = HashMap<Article>();  // Esto asume que la clase HashMap puede ser reinicializada así.

        // Iterar sobre la lista de artículos y añadir cada uno al inventario
        for (Article article : articlesList) {
            // Insertar el artículo en el inventario usando el código de barras como clave
            articlesTMP.push_back(article);

            if(article.getTotalStock() <= MINIMUM_STOCK){
                lowStock.push_back(article);
            } else{
                if(article.getTotalStock()>= MAX_STOCK){
                    highStock.push_back(article);
                }
            }
            inventory.insert(article.getCode(), article);
//            cout<< "La key es: "<< article.getCode() + "-" + article.getWarehouse() << endl;

        }

        cout<< "La carga fue exitosa."<< endl;

        string code = "CF-TURBOTRO-3716";
        Article art = *inventory.get(code);

        if(art.getCode().empty()){
            cout << "Not Found for code: " << code << endl;
        }

        cout << "Code: " << art.getCode()<< endl;
        cout << "Name: " << art.getName()<< endl;
        cout << "Warehouse: " << art.getWarehousesPlainText()<< endl;

    } catch (const std::runtime_error& e) {
        std::cerr << "Error al cargar el inventario: " << e.what() << std::endl;
        // Aquí podríamos decidir lanzar de nuevo la excepción o manejarla de alguna otra manera.
    }
}

size_t InventoryManager::showTotalDifferentArticles() {
    return inventory.getSize();
}
size_t InventoryManager::showTotalArticles() {
    size_t size = 0;
    for(auto &article:articlesTMP){
        size += article.getTotalStock();
    }

    return size;
}

void InventoryManager::saveInventory() {

}

void InventoryManager::displayMainMenu() {

}

void InventoryManager::listArticlesAtMinimumStock() {
    for(auto &article:lowStock){
        cout<< article.toString();
    }
}

void InventoryManager::listArticlesAtMinimumStockByWarehouse() {

}

void InventoryManager::showIndividualArticleStock() {
    for(auto &article:articlesTMP){
        cout<< article.toStringOnlyStock();
    }

}

void InventoryManager::listArticlesAboveThreshold() {
    for(auto & article:highStock){
        cout << article.toString();
    }
}
