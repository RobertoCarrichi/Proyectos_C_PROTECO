#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "contador.h"
#include <string.h>
#define fpf fprintf 

void limpiar_palabra(char *palabra){
	// El proceso de limpieza de una palabra dependerá totalmente de sus últimos caracteress
	// ya que en estos es donde se podrían encontrar los caracteres 's', ',' o '.'

	// Se comenzará identificando el índice del último caracter que contiene la cadena
	// esto se lográ recorriendo la cadena hasta encontrar el caracter de fin de cadena '\0'.

	int fin = 0; 
	while(palabra[fin] != '\0'){
		fin=fin+1;
	}

	// Ya que se sabe la cantidad de caracteres, se verificará si en el último tiene un
	// caracter que sobrará.
	if (palabra[fin-1]==','||palabra[fin-1]=='.')
	{
		// Si el último caracter es una coma o un punto este pasará a ser el nuevo fin
		// de cadena.
		palabra[fin-1]='\0';
		// Si se cambia el final de la cadena, el contador tamién lo hace.
		fin=fin-1;
	}

	// Hasta el momento, ya se trataría de una palabrá válida para análisis, pero 
	// para tener mejores resultados, deberá convertirse cada uno de los caracteres
	// a minúscula y trasformarla a una palabra singular eliminando las 's'.
	if(palabra[fin-1]=='s'){
		// Si se encuentra una 's' en el último caractér de la cadena, este vuelve el
		// nuevo caracter de fin de cadena y el contador también se reduce.
		palabra[fin-1]='\0';
	}
	// Ya solo restaría hacer cada uno de los caracteres válidos en minúsulas.
	
	fin = 0; /*Se reinicializará para funcionar que sea la primera referencia dentro del while.*/
	while(palabra[fin]!='\0'){
		palabra[fin]=tolower(palabra[fin]);
		fin=fin+1;
	}
	// ¡La palabra está lista!
}

int buscar_palabra(const char *palabra, Nodo *palabras){
	// El proceso de búsqueda de una palabra se realizará comparando las palabras
	// que ya están ingresadas con la nueva. Si se encuentra, se retornará un 1.

	// Primero se calculará la cantidad de elementos que tiene el conjunto "palabras"
	// para eso se divide el tamaño de la colección entera entre el tamaño del tipo de dato.

	// printf("\n\t\tSe va a buscar %s\n",palabra);
	for (int i = 0; i < totalPalabras; i++){
		// printf("\n\tSe comparó |'%s'| y '%s'\n",palabras[i].palabra,palabra);
		if(strcmp(palabras[i].palabra,palabra)==0){
			// printf("SE ENCONTRÓ EN EL CONJUNTO!\n");
			return 1;
		}
	}	
	// Si llega aquí es que no se encontró
	// printf("\nNO SE ENCONTRÓ\n");
	return 0;
}

int buscar_indice(const char *palabra,Nodo *palabras){
	for (int i = 0; i < totalPalabras; ++i)
	{
		if (strcmp(palabras[i].palabra,palabra)==0)
		{
			// printf("SE ENCONTRÓ EL ÍNDICE! %d\n",i);
			return i;
		}
	}
	// printf("\nNO SE ENCONTRÓ EL ÍNDICE \n");
	// Si llega aquí es que no se encontró
	return -1;
}


Nodo * contar_palabra(const char *palabra, Nodo *palabras,int encontrado){
	if (encontrado==1){
		// Ya que si se encontró, solo se aumentará la frecuencia de la palabra
		int indice = buscar_indice(palabra,palabras);
		palabras[indice].frecuencia = palabras[indice].frecuencia + 1; 
	}else{
		// Si no se encontró se guardará en el último nodo posible.
		strcpy(palabras[totalPalabras-1].palabra,palabra);
		palabras[totalPalabras-1].frecuencia=1;
	}
	return palabras;
}
void imprimir2(Nodo *palabras){
	printf("\n");
	for (int i = 0; i < totalPalabras; i++)
	{
		printf("[%d] ",palabras[i].frecuencia);
	}
}

Nodo * ordenar_palabras(Nodo *palabras){
	// EL proceso de ordenamiento estárá basado en la FRECUENCIA
	// El método que se implementará bubble sort.
    for(int i=0;i<totalPalabras;i++){ 
        for(int j=i+1;j<totalPalabras;j++){ 
            if(palabras[j].frecuencia>palabras[i].frecuencia){
    			Nodo auxiliar;
            	auxiliar.frecuencia=palabras[j].frecuencia; 
                strcpy(auxiliar.palabra,palabras[j].palabra);
                palabras[j].frecuencia = palabras[i].frecuencia;
                strcpy(palabras[j].palabra,palabras[i].palabra);        
                palabras[i].frecuencia = auxiliar.frecuencia;
                strcpy(palabras[i].palabra,auxiliar.palabra); 
            } 
        } 
    }
}

void guardar_palabras(const Nodo *palabras, FILE *resultados){
	for (int i = 0; i < totalPalabras; ++i)
	{
		fpf(resultados,"%26s\t%d\n",palabras[i].palabra,palabras[i].frecuencia);
	}


}
