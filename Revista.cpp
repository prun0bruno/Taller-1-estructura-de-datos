#include <iostream>
#include "Revista.h"

Revista::Revista(std::string nombre, std::string isbn, std::string autor, bool prestado,std::string numeroEdicion,std::string mesPublicacion):MaterialBibliografico(nombre, isbn, autor, prestado){

    this -> numeroEdicion = numeroEdicion;
    this -> mesPublicacion = mesPublicacion;

}
void Revista::mostrarInformacion() {
    
    std::string estado;
    if(this->getPrestado()){ 
        estado = "prestado";
    } else estado = "disponible";
    std::cout <<"Nombre: " << this->getNombre() << std::endl;
    std::cout << "ISBN: " << this->getIsbn() <<std::endl;
    std::cout << "Autor: " << this->getAutor() <<std::endl;
    std::cout << "Estado: " << estado<<std::endl;

    std::cout <<"Número de edición: " << numeroEdicion <<std::endl;
    std::cout <<"Mes de publicación :" << mesPublicacion<<std::endl;
    
}

std::string Revista::toString() {
   std::string estado;
   std::string theUser;
   if(this->getUser()==nullptr) {
    theUser = "noTiene";
   } else {
    theUser = this->getUser()->getId();
   }
    if(this->getPrestado()){ 
        estado = "prestado";
    } else estado = "disponible";
    return "REVISTA/" + this->getNombre() + "/" + this->getIsbn() + "/" + this-> getAutor() + "/" + estado + "/" + numeroEdicion + "/" + mesPublicacion + "/" + theUser;

 }

Revista::~Revista() {}