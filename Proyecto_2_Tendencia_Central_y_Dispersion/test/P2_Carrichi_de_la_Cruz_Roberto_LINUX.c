#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "comandos.h"
#define pf printf 
#define sf scanf 

int main(int argc, char const *argv[])
{
	/*
                          ********************************* 
                          *        VERSIÓN LINUX          * 
                          */      system("clear");       /*   
    /*                    ********************************* 
	   ################################################################################
	   #                           ¡¡¡ATENCIÓN!!!                                     #
	   #  Para el correcto funcionamiento de este programa en un sistema  GNU/LINUX   #
	   #  se requiere compilar el archivo utilizando la estructura:                   #
	   #	                 gcc nombreDelArchivo.c -lm                               #
       #  Es para que pueda se pueda hacer uso de las funciones que otorga Math.h     #
	   ################################################################################
	*/

	// Se crea un arreglo que tendrá una dimensión por defecto de 100 elementos.
	int tamanioInicial=100;
	float *arreglo; 
	arreglo = (float *) malloc(tamanioInicial * sizeof(float));
    if (arreglo == NULL) {
        printf("La ejecución del programa no es soportada para el equipo, lo sentimos.");
        return 1; // Si no hay suficiente memoria se termina el programa.
    }

	ayuda(); // Se muestran las opciones que tiene el usuario al entrar al programa.
	int salir; // Variable que indicará si el ciclo se rompe o si no.
	char comando[10]; /*Arreglo de caracteres que guardará el comando que está eligiendo el usuario.*/
	do{
		/*Lectura del comando que quiere ejecutarse.*/
		pf("\n > ");
		sf("%s",comando);
		
		// Función dedicada a encontrar el comando que quiere utilizar
		// Retorna un valor para saber si termina el ciclo o si no.
		salir = ejecutarComando(comando,arreglo,&tamanioInicial);
	}while(salir>0);

	free(arreglo);	// Se libera la memoria reservada.

	pf("  _______________________________________________________________________________ \n");
	pf(" |                                                                               |\n");
    pf(" |  Has decidido salir, gracias por hacer uso de este programa.                  |\n");
    pf(" |                                                                               |\n");
    pf(" |  Hecho por: Roberto Carlos Carrichi de la Cruz                                |\n");
	pf(" |  Estudiante de la Facultad de Ingeniería, UNAM.                               |\n");
	pf(" |                                                                               |\n");
	pf(" |  Programa de Tecnología en Cómputo, PROTECO.                                  |\n");
	pf(" |  Noviembre 8, 2020.                                                           |\n");
	pf(" |_______________________________________________________________________________|\n\n");
	
	return 0;
}