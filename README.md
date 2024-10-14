# Taller-1-estructura-de-datos
Integrantes:
* Vincenzo Porzio, 21.369.897-4, vincenzo.porzio@alumnos.ucn.cl, paralelo C2
* Diego Ignacio Parga Meza, 21.621.105-7, diego.parga@alumnos.ucn.cl , paralelo C2


# Proyecto de Sistema de Gestión de Material Bibliográfico

## Descripción
Este proyecto es un sistema de gestión de material bibliográfico que permite a los usuarios interactuar con libros y otros materiales, filtrarlos y mostrarlos en pantalla. El sistema incluye funcionalidades básicas como filtrar materiales por nombre o autor y mostrar información sobre los mismos.

El programa está diseñado para compilar con `g++` en un entorno que soporte MinGW o utilizando el Codespace de GitHub.

## Funciones
   * Gestion de materiales (agregar, prestar, devolver, buscar y mostrar su información) (libros o revistas)
   * Gestión de usuarios (agregar, buscar, eliminar y mostrar su información)

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
## Estructura 
   * Sistema (.cpp y .h) : controla la lógica de la biblioteca y el manejo de materiales bibliograficos y usuarios
   * MaterialBibliografico (.cpp y .h) : clase padre de las subclases libro y revista, donde se expone los parámetros que tienen en común junto a métodos virtuales
   * Libro y revista (.cpp y .h) : subclases de MaterialBibliografico, las cuales tienen su propios parámetros extras
   * Usuario (.cpp y .h) : clase indepentiende que maneja la información de los usuarios
   * Main.cpp : apartado donde se maneja la lógica general del programa (lectura de archivos, menú e interacciones con la consola)

## Objetos creados
   * sistema: se crea 1 sistema que maneja la lógica y la memoria. 
   * libro: subclase de MaterialBibliografico. Admite parámetros string nombre/isbn/autor/(bool)prestado/fechaPublicacion/resumen
   * revista: subclase de MaterialBibliografico. Admite parámetros string nombre/isbn/autor/(bool)prestado/numeroEdicion/mesPublicacion

## Notas
   * El sistema utiliza archivos de texto para resguardar información previa y posterior a su manejo
   * El formato de los usuarios en archivo .txt es el siguiente:  nombre/id
   * El formato de los materiales bibliograficos en archivo .txt es el siguiente:  TIPO/nombre/isbn/autor/disponible_o_prestado/parametro_1/parametro_2/usuario_contenedor , donde parametros 1 y 2 son respectivos a subclases Libro y Revista.
