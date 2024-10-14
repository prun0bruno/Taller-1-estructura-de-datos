
#include "Sistema.h" 

Sistema::Sistema() {
    for (int i = 0; i < 100; i++) {
                biblioteca[i] = nullptr; 
                usuarios[i] = nullptr;  
            }
}

bool Sistema::agregarMaterial(MaterialBibliografico*material){
    for(int i = 0; i<100; i++){
        if(biblioteca[i]==nullptr) {
            biblioteca[i] = material;
            return true;
        }
    }
    return false;
}
void Sistema::mostrarMateriales() {
    for (int i = 0; i < 100; i++) {
        if (biblioteca[i] != nullptr) {  
            biblioteca[i]->mostrarInformacion();
            std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~ ◈ ~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
        }
    }
}

MaterialBibliografico* Sistema::buscarMaterial(std::string isbn){
    for(MaterialBibliografico*m : biblioteca) {
        if(m!=nullptr) {
            if(m->getIsbn()==isbn) {
                return m;
            }
            
        }
    } return nullptr;
}

void Sistema::filtrarMaterial(std::string filtro) {
    for (int i = 0; i < 100; i++) {
        if (biblioteca[i] != nullptr) {  
            if (biblioteca[i]->getAutor() == filtro || biblioteca[i]->getNombre() == filtro) {
                biblioteca[i]->mostrarInformacion();
                std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~ ◈ ~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
            }
        }
    }
}

bool Sistema::prestarMaterial(Usuario* user, MaterialBibliografico* material) {
    
    return user->prestarMaterial(material);

}

bool Sistema::devolverMaterial(MaterialBibliografico* material) {
    Usuario* user = material->getUser();
    return user->devolverMaterial(material);
}

bool Sistema::crearUsuario(Usuario* user) {
    for(int i = 0; i < 100; i++) {
        if(usuarios[i]==nullptr) {
            usuarios[i] = user;
            return true;
        }
    }
    return false;

}

Usuario* Sistema::buscarUsuario(std::string id){
    for(Usuario*u : usuarios) {
        if(u!=nullptr) {
            if(u->getId()==id) {
                return u;
            }
            
        }
    } return nullptr;
}

bool Sistema::eliminarUsuario(Usuario* user) {
    for(int i = 0; i<100 ; i++) {
        if(usuarios[i]!= nullptr) {
            if(usuarios[i] == user) {
                usuarios[i] -> devolverTodo();
                usuarios[i] = nullptr;
                delete user;
                delete usuarios[i];
                return true;
            }
        }
    }
    return false;
}

void Sistema::updateTxt(std::string archivo) {
    std::ofstream file(archivo); 
    
    if (file) {
        
        if(archivo=="Usuarios.txt") {
            for(int i = 0; i<100; i++) {
                if(usuarios[i]!=nullptr){
                    file << usuarios[i]->toString() << std::endl;
                }
            }
            std::cout << "Usuarios guardados con éxito" <<std::endl;

        }
        if(archivo=="Materiales.txt") {
            for(int i = 0; i<100; i++) {
                if(biblioteca[i]!=nullptr) {
                    file << biblioteca[i]->toString() << std::endl;
                }
            }
            std::cout << "Materiales bibliográficos guardados con éxito" <<std::endl;

        }
    } else {
        std::cout << "No se pudo abrir el archivo." << std::endl;
    }

}

Sistema::~Sistema() {}