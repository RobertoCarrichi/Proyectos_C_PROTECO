#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contador.h"
#define pf printf 
#define fsf fscanf 

int main(int argc, char const *argv[])
{
	// El primer argumento enviado desde la consola se tratará del índice [1], ya que el
	// índice [0] es la misma ruta como tal, por lo tanto el índice [2] hará referencia
	// al archivo donde se imprimirán lo resultados.

	FILE *texto = fopen(argv[1], "r");

	// Se verifica si el archivo a leer se pudo abrir, principalmente porque de este 
	// se basará toda la ejecución.
	if(texto == NULL){
		pf("\n\t Lo sentimos, no se puedo abrir el archivo. \n");
	}else{
		pf("\n\t El archivo se pudo abrir exitosamente.\n");

		// Ya se si pudo abrirse, se procederá a crear el arreglo dinámico que almacenará
		// datos de tipo Nodo.
		
		totalPalabras = 0; // Por el momento no hay palabras en el conjunto.
		Nodo *palabras;
		palabras = (Nodo*) malloc(totalPalabras * sizeof(Nodo));

		char palabra[30];

		// Lo siguiente será leer palabra por palabra hasta llegar al final del archivo.
		while((!feof(texto))){
			// Esta función irá leyendo solo UNA palabra hasta llegar al final
			// del archivo.
			fsf(texto,"%s",palabra); // Este será el caso para UNA palabra.

			// Para poder analizarse, se requerirá que la palabra no contenga ningún otro
			// caracter que no sea alfanumérico (',' o '.'), que sea singular y que todas 
			// sus letras sean minúsculas.
			limpiar_palabra(palabra);

			// Ya teniendo lista una palabra, se verificará si el conjunto 'palabras'
			// ya tiene a la palabra.
			if(buscar_palabra(palabra,palabras)==1){
			/*		^
					|
				  Esta función retornará un 1 en caso que si se haya encontrado.
			     	
			*/	contar_palabra(palabra,palabras,1);
			/*			^						^
						|						|
						|					Indica que si se encontró.
				Esta función ingresará la palabra al conjunto, indicando si se encontró o si no.
			*/							
			}else{
				// Si la palabra no se encuentra en nuestros "registros", entonces
				// se añadirá al conjunto de palabras.
				// Lo cual hará que el contador general aumente y el tamaño de la 
				// colección también.
				totalPalabras=totalPalabras+1;
				palabras = (Nodo *)realloc(palabras, totalPalabras * sizeof(Nodo));
				/*	^        ^       ^       ^           ^                   ^
					|        |       |       |           |                   |				
					|		 |       |       |           |      Indica el tamaño en bits que tiene uno de los elementos de la estructura.
					|		 |		 |		 |		Indica el nuevo tamaño que quiere reservarse y se multiplicará por el tamaño de cada elemento.
					|		 |		 |	  Aquí se menciona la el conjunto que se quiere redimensionar.
					|		 |   Es el nombre de la función que puede cambiar el espacio reservado para un conjunto de elementos.
					|		Se aplica un "casting", para que el resultado de la función se mantenga como un apuntador de tipo "Nodo".
				  Se indica la colección que recibirá el nuevo espacio reservado.
				*/
				contar_palabra(palabra,palabras,0);
			}
		}

		// Si ya no hay palabras que analizar, se requiere acomodarlas e imprimirlas 
		// en el archivo de las palabras.

		printf("\n\t Inicia el ordenamiento.\n");
		ordenar_palabras(palabras);
		printf("\n\t Se han terminado de ordenar.\n");

		// Archivo que almacenará los resultados de la frecuencia de cada palabra
		FILE *resultados;
		resultados = fopen(argv[2],"w+");
		if (resultados==NULL)
		{
			printf("\n\t No se pudieron escribir los resultados en el archivo,\neste no pudo ser abierto, lo siento.");
		}else{
			printf("\n\t Se colocarán los resultados en: %s\n\n",argv[2]);
			guardar_palabras(palabras,resultados);
		}
		free(palabras);
		fclose(resultados);

	}
	fclose(texto);

	return 0;
}