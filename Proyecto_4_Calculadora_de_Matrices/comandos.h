#include <string>
#include "matriz.h"
#ifndef COMANDOS_H
#define COMANDOS_H
    void ayuda();             // Función dedicada a imprimir en pantalla los comandos disponibles al usuario.
    int ejecutarComando(std::string);    // Función capaz de identificar el comando que quiere ejecutar el usuario.
#endif
