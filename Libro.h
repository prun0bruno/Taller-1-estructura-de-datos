#pragma once
#include <iostream>
#include "MaterialBibliografico.h"


class Libro : public MaterialBibliografico {

    private:
        std::string fechaPublicacion;
        std::string resumen;

    public:
        Libro(std::string nombre, std::string isbn, std::string autor, bool prestado, std::string fechaPublicacion, std::string resumen);
        virtual void mostrarInformacion();

        virtual std::string toString();

        ~Libro();

};