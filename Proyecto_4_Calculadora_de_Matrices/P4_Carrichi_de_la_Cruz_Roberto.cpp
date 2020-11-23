/*
  ##############################################################
  #           UNIVERSIDAD NACIONAL AUTÓNOMA DE MÉXICO          #
  #                   FACULTAD DE INGENIERÍA                   #
  #             PROTECO - Curso prebecarios: C y C++           #
  #                         PROYECTO 4                         #
  #         Calculadora de matrices por línea de comandos      #
  #  Hecho por:                                                #
  #     -> Roberto Carlos Carrichi de la Cruz.                 # 
  ##############################################################
*/
#include <iostream> // Biblioteca para manejo de flujos estándar.
#include <string>
#include "comandos.h"

using namespace std;

int main(void)
{
    ayuda(); // Comando que imprime las opciones que tiene el usuario al entrar al programa.
    int salir; // Variable que indicará si el ciclo se rompe o si no.
    string comando; /*Arreglo de caracteres que guardará el comando que está eligiendo el usuario.*/
    do{
        do{
           cout << "\n ~> "; // Cadena que representa el prompt.
            getline(cin,comando);  // Lectura del comando
            if (comando == "")
            {
                cout << "\n\tIngresa un comando por favor. Puedes escribir \"ayuda\" en caso de requerirla." << endl;
            }
        }while(comando=="");
        // Función dedicada a encontrar el comando que quiere utilizar
        salir = ejecutarComando(comando);
    }while(salir>0);
    cout << "\n";
    cout << "   _______________________________________________________________________________ \n";
    cout << "  |                                                                               |\n";
    cout << "  |  Gracias por hacer uso de este programa.                                      |\n";
    cout << "  |                                                                               |\n";
    cout << "  |  Hecho por: Roberto Carlos Carrichi de la Cruz                                |\n";
    cout << "  |  Estudiante de la Facultad de Ingeniería, UNAM.                               |\n";
    cout << "  |                                                                               |\n";
    cout << "  |  Programa de Tecnologia en Computo, PROTECO.                                  |\n";
    cout << "  |  Noviembre 22, 2020.                                                          |\n";
    cout << "  |_______________________________________________________________________________|\n\n";
    
    return 0;
}
