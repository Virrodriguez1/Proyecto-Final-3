#include <iostream>
#include <vector>
#include "HashTable.h"

using namespace std;


int main() {
    // Crear una tabla hash e insertar valores
    HashTable hashTable;
    hashTable.insert(1, 260);
    hashTable.insert(1, 2540);

    // Obtener un valor
    cout << "El valor para la clave 1 es: " << hashTable.get(1) << std::endl;
    cout << "El valor para la clave 11 es: " << hashTable.get(11) << std::endl;
    cout << "El valor para la clave 12 es: " << hashTable.get(12) << std::endl;
    cout << "El valor para la clave 13 es: " << hashTable.get(13) << std::endl;
    cout << "El valor para la clave 14 es: " << hashTable.get(14) << std::endl;
    cout << "El valor para la clave 15 es: " << hashTable.get(15) << std::endl;
    cout << "El valor para la clave 61 es: " << hashTable.get(61) << std::endl;
    cout << "El valor para la clave 62 es: " << hashTable.get(62) << std::endl;


    cout << "Eliminando el valor para la clave 15 es: " << std::endl;
    hashTable.remove(15);

    cout << "El valor para la clave 15 es: " << hashTable.get(15) << std::endl;



    return 0;
}
