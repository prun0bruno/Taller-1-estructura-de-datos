#pragma once 
#include <iostream>
#include "Usuario.h"

class MaterialBibliografico{

    private:

        std::string nombre;
        std::string isbn;
        std::string autor;
        bool prestado = false;
        Usuario* user;

    public:

        MaterialBibliografico(std::string nombre, std::string isbn, std::string autor, bool prestado);

        std::string getNombre();

        std::string getIsbn();

        std::string getAutor();

        bool getPrestado();
        void setPrestado(bool prestado);

        void setUser(Usuario* usuario);

        Usuario* getUser();

        virtual void mostrarInformacion();

        virtual std::string toString();

        ~MaterialBibliografico();

};