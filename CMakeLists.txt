# Establece la versión mínima requerida de CMake para este proyecto.
cmake_minimum_required(VERSION 3.15)

# Define el nombre del proyecto y la versión.
project(Inventario VERSION 1.0)

# Especifica el estándar de C++ a utilizar.
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Opcional: incluye la carpeta donde CMake buscará archivos .cmake adicionales.
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

# Agrega los directorios donde CMake buscará los archivos de cabecera.
include_directories(${PROJECT_SOURCE_DIR}/include)

# Especifica el directorio donde se deben colocar los ejecutables compilados.
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

# Agrega el directorio donde CMake buscará archivos fuente adicionales.
#add_subdirectory(src)

# Opcional: Si tienes tests, descomenta la siguiente línea.
# add_subdirectory(test)

# Opcional: Si tienes documentación, descomenta la siguiente línea.
# add_subdirectory(doc)

# Opcional: Si tienes estructuras de datos personalizadas en una carpeta separada, descomenta la siguiente línea.
# include_directories(${PROJECT_SOURCE_DIR}/Estructuras)

# Agrega el ejecutable principal del proyecto.
add_executable(Inventario src/main.cpp src/main.cpp include/Menu.h
        include/CSVManager.h
        src/InventoryManager.cpp
        include/InventoryManager.h)

# Enlaza las bibliotecas necesarias con tu ejecutable.
# target_link_libraries(Inventario nombre_de_la_biblioteca)
