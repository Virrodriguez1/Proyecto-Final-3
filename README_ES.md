
# Sistema de Gestión de Inventario

## Descripción del Proyecto
Este proyecto es un sistema de gestión de inventario construido en C++ para una empresa que maneja su inventario físico diario. La aplicación procesa un archivo CSV que contiene una lista de productos con códigos QR y niveles de stock en varios depósitos.

## Características
- Leer datos de un archivo CSV.
- Mostrar el número total de artículos únicos.
- Mostrar el número total de artículos.
- Listar artículos con nivel de stock mínimo.
- Listar artículos con stock mínimo por depósito.
- Mostrar el nivel de stock individual de cada artículo.
- Mostrar el nivel de stock individual de cada artículo por depósito.
- Identificar artículos con stock igual o superior a una cantidad determinada.

## Prerrequisitos
- Compilador de C++ (se recomienda GCC)
- Make (para compilar el proyecto)

## Compilación del Proyecto
Navegue al directorio del proyecto y ejecute:
\`\`\`
make
\`\`\`

## Uso
Ejecute el programa usando el siguiente comando:
\`\`\`
./bin/Procesador_inventario [argumentos] data/inventario_fisico.csv
\`\`\`

## Argumentos
- `-total_art_dif` - Mostrar el número total de artículos diferentes.
- `-total_art` - Mostrar el número total de artículos.
- Más argumentos por definir...

## Estructura de Datos
El programa utiliza tablas de hash para almacenar y gestionar los datos de inventario de forma eficiente.

## Licencia
Este proyecto está bajo la Licencia MIT - vea el archivo LICENSE.md para más detalles.

## Autores
- Virginia Rodriguez

## Agradecimientos
- Gracias al personal del curso de Programación III por proporcionar las pautas y requisitos para este proyecto.
