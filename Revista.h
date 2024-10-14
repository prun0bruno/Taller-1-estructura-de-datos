#pragma once
#include <iostream>
#include "MaterialBibliografico.h"

class Revista : public MaterialBibliografico {

    private:
        std::string numeroEdicion;
        std::string mesPublicacion;

    public:
        Revista(std::string nombre, std::string isbn, std::string autor, bool prestado,std::string numeroEdicion,std::string mesPublicacion);
        
        virtual void mostrarInformacion();

        virtual std::string toString();

        ~Revista();


};