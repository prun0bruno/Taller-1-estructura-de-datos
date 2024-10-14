 #include "Libro.h"

 Libro::Libro(std::string nombre, std::string isbn, std::string autor, bool prestado, std::string fechaPublicacion, std::string resumen):MaterialBibliografico(nombre, isbn, autor, prestado) {
    this -> fechaPublicacion = fechaPublicacion;
    this -> resumen = resumen;
 }

 void Libro::mostrarInformacion() {

    std::string estado;
    if(this->getPrestado()){ 
        estado = "prestado";
    } else estado = "disponible";
    std::cout <<"Nombre: " << this->getNombre() << std::endl;
    std::cout << "ISBN: " << this->getIsbn() <<std::endl;
    std::cout << "Autor: " << this->getAutor() <<std::endl;
    std::cout << "Estado: " << estado<<std::endl;

    
    
    std::cout << "Fecha de publicación: " << fechaPublicacion <<std::endl;
    std::cout << "Resumen: " << resumen <<std::endl;
    
 }

 std::string Libro::toString() {
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
    return "LIBRO/" + this->getNombre() + "/" + this->getIsbn() + "/" + this-> getAutor() + "/" + estado + "/" + fechaPublicacion + "/" + resumen + "/" + theUser;

 }



 Libro::~Libro() {}