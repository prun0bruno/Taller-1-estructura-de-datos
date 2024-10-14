#pragma once
#include <iostream>
#include "MaterialBibliografico.h"

class MaterialBibliografico; 

class Usuario{
    private:
        std::string nombre;
        std::string id;
        MaterialBibliografico* materialesPrestados[5];

    public:
        Usuario(std::string nombre, std::string id);
        bool prestarMaterial(MaterialBibliografico *material);

        bool devolverMaterial(MaterialBibliografico *material);

        void devolverTodo();

        void mostrarMaterialesPrestados();
        
        std::string getId();

        std::string toString();

        ~Usuario();
    
};