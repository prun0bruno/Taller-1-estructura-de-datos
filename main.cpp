#include <iostream>
#include <fstream>
#include <vector>

#include "Sistema.h"

#include "MaterialBibliografico.h"
#include "Libro.h"
#include "Revista.h"



std::string readLine() {
    std::string line;
    std::cin >> line;
    return line;
}

std::vector<std::string> split(const std::string& str, char delim) {
    std::vector<std::string> tokens;
    std::string token;
    
    for (char ch : str) {
        if (ch == delim) {
            if (!token.empty()) {
                tokens.push_back(token);  
            }
            token.clear();  
        } else {
            token += ch;  
        }
    }
    if (!token.empty()) {
        tokens.push_back(token);  
    }
    
    return tokens;
}


void readFile(Sistema* sistema, std::string archivo) {
    std::ifstream file(archivo); 
    std::string linea;

    if (file) {
        if(archivo=="Usuarios.txt") {
            while (getline(file, linea)) {
                std::vector<std::string> partes = split(linea,'/');
                
                sistema->crearUsuario(new Usuario(partes[0], partes[1]));
                std::cout << linea << std::endl; 
                 
            }
            file.close();
        }
        if(archivo=="Materiales.txt") {
            int count = 0;
            while(getline(file, linea)) {
                std::vector<std::string> partes = split(linea,'/');
                if(partes[0]=="LIBRO") {
                    
                    sistema->agregarMaterial(new Libro(partes[1],partes[2],partes[3],false,partes[5],partes[6]));
                    count++;
                    if(partes[4]=="prestado"){
                        MaterialBibliografico* m = sistema->buscarMaterial(partes[2]);
                        sistema->prestarMaterial(sistema->buscarUsuario(partes[7]),m);
                        


                    }

                }
                if(partes[0]=="REVISTA") {
                    sistema->agregarMaterial(new Revista(partes[1],partes[2],partes[3],false,partes[5],partes[6]));
                    count++;
                    if(partes[4]=="prestado"){
                        MaterialBibliografico* m = sistema->buscarMaterial(partes[2]);
                        sistema->prestarMaterial(sistema->buscarUsuario(partes[7]),m);
                        


                    }

                }
                
            }
            file.close();
            std::cout << "Ha(n) sido cargado(s) " << count << " material(es)." << std::endl;
        }
        
    } else {
        std::cout << "No se pudo abrir el archivo." << std::endl;
    }
    

}

void menu(Sistema * sistema) {
    int opcion;
    int op1;
    std::string linea;
    std::string codigo;
    std::string arg3;
    std::string arg4;
    std::string arg5;
    std::cout << "¿Desea cargar memoria?"<<std::endl;
    std::cout << "(No: 0/Sí: 1)"<< std::endl;
    do {
        std::cin >> op1;
        switch(op1){
            case 0:
                std::cout << "Iniciando sistema . . ." << std::endl;
                std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~ ◈ ~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
                break;

            case 1:
                readFile(sistema,"Usuarios.txt");
                readFile(sistema,"Materiales.txt");

                std::cout << "Iniciando sistema . . ." << std::endl;
                std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~ ◈ ~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;

                break;

            default:
                std::cout << "Opción no válida. Intente nuevamente."<< std::endl;
                break;

        }

    } while(op1!=1 && op1!=0);
    do {
        std::cout << "---------MENÚ---------\n";
        std::cout << "Seleccione una opción:\n";
        std::cout << "1. Agregar libro\n";
        std::cout << "2. Agregar revista\n";
        std::cout << "3. Mostrar Información de los materiales\n";
        std::cout << "4. Buscar material\n";
        std::cout << "5. Prestar Material\n";
        std::cout << "6. Devolver Material\n";
        std::cout << "7. Crear usuario\n";
        std::cout << "8. Buscar usuario\n";
        std::cout << "9. Eliminar usuario\n";
        std::cout << "10. Salir\n";
        std::cout << "-----------------------\n";
        std::cin >> opcion;

        switch(opcion) {
            case 1:
                std::cout << "Ingrese el título del libro" << std::endl;
                linea = readLine();
                std::cout << "Ingrese el código ISBN del libro" << std::endl;
                codigo = readLine();
                std::cout << "Ingrese el autor del libro" << std::endl;
                arg3 = readLine();
                std::cout << "Ingrese fecha de publicación" << std::endl;
                arg4 = readLine();
                std::cout << "Ingrese resumen" << std::endl;
                arg5 = readLine();
                if(sistema->agregarMaterial(new Libro(linea,codigo,arg3,false,arg4,arg5))) {
                    std::cout << "Libro agregado con éxito" << std::endl;
                }  else std::cout << "Ha ocurrido un problema: biblioteca llena" << std::endl;
                break;
            case 2:
                std::cout << "Ingrese el título de la revista" << std::endl;
                linea = readLine();
                std::cout << "Ingrese el código ISBN de la revista" << std::endl;
                codigo = readLine();
                std::cout << "Ingrese el autor de la revista" << std::endl;
                arg3 = readLine();
                std::cout << "Ingrese numero de edición" << std::endl;
                arg4 = readLine();
                std::cout << "Ingrese mes de publicación" << std::endl;
                arg5 = readLine();
                if(sistema->agregarMaterial(new Revista(linea,codigo,arg3,false,arg4,arg5))) {
                    std::cout << "Revista agregado con éxito" << std::endl;
                }  else std::cout << "Ha ocurrido un problema: biblioteca llena" << std::endl;
                break;
            case 3:
                sistema -> mostrarMateriales();
                break;
            case 4:
                std::cout << "Ingrese título o autor para filtrar el material" << std::endl;
                linea = readLine();
                sistema -> filtrarMaterial(linea);
            case 5:
                std::cout << "Ingrese ID de usuario:" << std::endl;
                linea = readLine();
                std::cout << "Ingrese código ISBN del material a prestar:" << std::endl;
                codigo = readLine();
                if(sistema->buscarUsuario(linea)==nullptr) {
                    std::cout << "Usuario no existente"<< std::endl;
                    break;}
                if(sistema->buscarMaterial(codigo)==nullptr) {
                    std::cout << "Material no existente"<< std::endl;
                    break;}
                if(sistema->prestarMaterial(sistema->buscarUsuario(linea),sistema->buscarMaterial(codigo))) {
                    std::cout << "Material prestado con éxito" << std::endl;
                } else std::cout << "Ha ocurrido un error al prestar el material" << std::endl;
                break;
            case 6:
                std::cout << "Ingrese código ISBN del material a devolver:" << std::endl;
                codigo = readLine();
                if(sistema->buscarMaterial(codigo)==nullptr) {
                    std::cout << "Material no existente"<< std::endl;
                    break;}
                if(sistema->devolverMaterial(sistema->buscarMaterial(codigo))) {
                    std::cout << "Material devuelto con éxito" << std::endl;
                } else std::cout << "Ha ocurrido un error al devolver el material"<< std::endl;
                break;
            case 7: 
                std::cout << "Ingrese el nombre del usuario" << std::endl;
                linea = readLine();
                std::cout << "Ingrese ID de usuario" << std::endl;
                codigo = readLine();
                if(sistema->crearUsuario(new Usuario(linea,codigo))) {
                    std::cout << "Usuario creado con éxito" << std::endl;
                } else std::cout << "Ha ocurrido un error al crear el usuario: capacidad máxima alcanzada." << std::endl;
                break;
            case 8:
                std::cout << "Ingrese ID del usuario a buscar" << std::endl;
                linea = readLine();
                if(sistema->buscarUsuario(linea)==nullptr) {
                    std::cout << "Usuario no existente"<< std::endl;
                    break;
                }
                sistema->buscarUsuario(linea)->mostrarMaterialesPrestados();
                break;
            case 9:
                std::cout << "Ingrese ID del usuario a eliminar" << std::endl;
                linea = readLine();
                if(sistema->eliminarUsuario(sistema->buscarUsuario(linea))==true) {
                    
                    std::cout << "Usuario eliminado con éxito" << std::endl; 
                } else std::cout << "Usuario no encontrado" << std::endl;
                break;
            case 10:
                std::cout << "Guardando . . ." << std::endl;
                sistema->updateTxt("Usuarios.txt");
                sistema->updateTxt("Materiales.txt");
                std::cout << "¡Gracias por preferirnos!"<< std::endl;
                break;
            default:
                std::cout << "Opción no válida. Intente nuevamente."<< std::endl;
                break;
        }
    } while(opcion != 10); 
}


int main() {
    Sistema* sistema = new Sistema();

    
    menu(sistema);

    







    return 0;
}



