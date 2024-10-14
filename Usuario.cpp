#include "MaterialBibliografico.h"
#include "Usuario.h"

Usuario::Usuario(std::string nombre,std::string id) {
    this -> nombre = nombre;
    this -> id = id;
    for(int i=0; i<5; i++) {
        materialesPrestados[i] = nullptr;
    }
}

bool Usuario::prestarMaterial(MaterialBibliografico *material) {

    if(material->getPrestado()==true) return false;

    int count = 0;
    for(int i = 0; i<5; i++) {
        if(materialesPrestados[i]!=nullptr) {
            count++;
            
        }
    }
    if(count<5) {
        for(int i = 0; i<5; i++) {
            if(materialesPrestados[i]==nullptr) {
                materialesPrestados[i] = material;
                material->setPrestado(true);
                material->setUser(this);
                return true;
            }
        }
    return true;
    } else return false;
    
}

bool Usuario::devolverMaterial(MaterialBibliografico *material) {
    for(int i = 0; i<5; i++){
        if(materialesPrestados[i]!=nullptr) {
            if(materialesPrestados[i]==material) {
                materialesPrestados[i]->setPrestado(false);
                materialesPrestados[i]->setUser(nullptr);
                materialesPrestados[i]=nullptr;
                return true;
            }
            
        }
    }
    return false;
}

void Usuario::devolverTodo() {
    for(int i = 0; i<5; i++){
        if(materialesPrestados[i]!=nullptr) {
            materialesPrestados[i]->setPrestado(false);
            materialesPrestados[i]->setUser(nullptr);
            materialesPrestados[i]=nullptr;  
        }
    }
    return;
}

void Usuario::mostrarMaterialesPrestados() {
    std::cout << "Materiales asociados:" << std::endl;
    int count = 0;
    for(MaterialBibliografico*m : materialesPrestados) {
        if(m!=nullptr) {
            std::cout << "Nombre:" << m->getNombre() << " || ISBN:" << m->getIsbn() << std::endl;
            count++;
        }
        
    }
    if(count == 0) { std::cout << "No hay materiales prestados asociados a este usuario."<< std::endl; }
    return;
}

std::string Usuario::getId() {
    return id;
}

std::string Usuario::toString() {
    return nombre + "/" + id;
}

Usuario::~Usuario() {}