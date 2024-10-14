#pragma once
#include <iostream>
#include <fstream>
#include "MaterialBibliografico.h"
#include "Usuario.h"

class Sistema {

    private:
        MaterialBibliografico* biblioteca[100];
        Usuario* usuarios[100];

    public:
        Sistema();
        bool agregarMaterial(MaterialBibliografico *material);

        void mostrarMateriales();

        MaterialBibliografico* buscarMaterial(std::string isbn);

        void filtrarMaterial(std::string filtro);

        bool prestarMaterial(Usuario *user, MaterialBibliografico *material);
        bool devolverMaterial(MaterialBibliografico *material);

        bool crearUsuario(Usuario* user);
        Usuario* buscarUsuario(std::string id);
        bool eliminarUsuario(Usuario* user);


        void updateTxt(std::string archivo);

        ~Sistema();

        





};
