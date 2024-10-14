
#include <iostream>
#include "MaterialBibliografico.h"

MaterialBibliografico::MaterialBibliografico(std::string nombre, std::string isbn, std::string autor, bool prestado){
    this -> nombre = nombre;
    this -> isbn = isbn;
    this -> autor = autor;
    this -> prestado = false;
    this -> user = nullptr;
}


std::string MaterialBibliografico::getNombre() {
    
    return this->nombre;}

std::string MaterialBibliografico::getIsbn() {
    return this->isbn;
}
std::string MaterialBibliografico::getAutor() {
    return this->autor;
}
bool MaterialBibliografico::getPrestado() {
    return this->prestado;
}
void MaterialBibliografico::setPrestado(bool prestado) {
    this -> prestado = prestado;
}

void MaterialBibliografico::setUser(Usuario* usuario) {
    this -> user = usuario;
}

Usuario* MaterialBibliografico::getUser() {
    return this->user;
}

void MaterialBibliografico::mostrarInformacion() {
    std::string estado;
    if(prestado){ 
        estado = "prestado";
    } else estado = "disponible";


    std::cout <<"Nombre: " << nombre << std::endl;
    std::cout << "ISBN: " << isbn <<std::endl;
    std::cout << "Autor: " << autor <<std::endl;
    std::cout << "Estado: " << estado<<std::endl;
}

//std::string getTipo() {}

std::string MaterialBibliografico::toString() {
    std::string estado;
    if(prestado){ 
        estado = "prestado";
    } else estado = "disponible";

    return nombre + "/" + isbn + "/" + autor + "/" + estado;
}

MaterialBibliografico::~MaterialBibliografico() {}

