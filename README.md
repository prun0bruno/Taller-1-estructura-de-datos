# Taller-1-estructura-de-datos
Integrantes:
* Vincenzo Porzio, RUT, correo, paralelo C2
* Diego Parga, 21.621.105-7, diego.parga@alumnos.ucn.cl , paralelo C2


# Proyecto de Sistema de Gestión de Material Bibliográfico

## Descripción
Este proyecto es un sistema de gestión de material bibliográfico que permite a los usuarios interactuar con libros y otros materiales, filtrarlos y mostrarlos en pantalla. El sistema incluye funcionalidades básicas como filtrar materiales por nombre o autor y mostrar información sobre los mismos.

El programa está diseñado para compilar con `g++` en un entorno que soporte MinGW o utilizando el Codespace de GitHub.

## Compilación e Instalación

### Requisitos
- MinGW o cualquier compilador `g++` que pueda ejecutarse en su entorno de desarrollo.
- Alternativamente, puede utilizar **Codespaces** en GitHub.

### Compilación
Utilizando MinGW:
1. Tener MinGW instalado. Instrucciones en: [https://sourceforge.net/projects/mingw/](https://sourceforge.net/projects/mingw/)
2. Abrir la terminal y navegar al directorio donde está el código fuente del proyecto.
3. Compilar el proyecto con el siguiente comando:

   ```bash
   g++ -o sistema Sistema.cpp Libro.cpp Usuario.cpp MaterialBibliografico.cpp -std=c++11
4. Ejecutar el programa:
   
   ```bash
   ./main
