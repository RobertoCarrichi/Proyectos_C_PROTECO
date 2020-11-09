#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define pf printf 
#define sf scanf 

void ayuda();
void cambiar(float *arreglo, int tamanioInicial);
float cuartil_1(float *arreglo, int tamanioInicial);
float cuartil_3(float *arreglo, int tamanioInicial);
void datos(float *arreglo, int tamanioInicial);
float desvest(float *arreglo, int tamanioInicial);
void imprimir(float *arreglo, int tamanioInicial);
float media(float *arreglo, int tamanioInicial);
float* mediana(float *arreglo, int tamanioInicial);
float moda(float arreglo[], int tamanioInicial,int repeticion);
void n(float *arreglo, int *tamanioInicial);
float rango(float *arreglo, int tamanioInicial);
float ric(float *arreglo, int tamanioInicial);
void todos(float *arreglo, int tamanioInicial);
float varianza(float *arreglo, int tamanioInicial);
int ejecutarComando(char *comando,float *arreglo,int *tamanioInicial);
int main(int argc, char const *argv[])
{
	/*
                          ***********************************
                          *        VERSIÓN WINDOWS          * 
                          */        system("cls");            
    //                    *********************************** 

	// Se crea un arreglo que tendrá una dimensión por defecto de 100 elementos.
	int tamanioInicial=100;
	float *arreglo; 
	arreglo = (float *) malloc(tamanioInicial * sizeof(float));
    if (arreglo == NULL) {
        printf("La ejecuci%cn del programa no es soportada para el equipo, lo sentimos.",162);
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
	pf(" |  Estudiante de la Facultad de Ingenier%ca, UNAM.                               |\n",161);
	pf(" |                                                                               |\n");
	pf(" |  Programa de Tecnolog%ca en C%cmputo, PROTECO.                                  |\n",161,162);
	pf(" |  Noviembre 8, 2020.                                                           |\n");
	pf(" |_______________________________________________________________________________|\n\n");
	
	return 0;
}

// El comando se busca en orden alfabético.
int ejecutarComando(char *comando,float *arreglo,int *tamanioInicial){
	float resultado;
	// La función strcmp() permite comparar cadenas de caracteres.
	if(strcmp(comando,"ayuda")==0){
		ayuda();
	}else if(strcmp(comando,"cambiar")==0){
		cambiar(arreglo,*tamanioInicial);
	}else if(strcmp(comando,"cuartil-1")==0){
		resultado = cuartil_1(arreglo,*tamanioInicial);
		pf("\n El valor que representa el primer cuartil (25%) es: %0.4f \n",resultado);
	}else if(strcmp(comando,"cuartil-3")==0){
		resultado = cuartil_3(arreglo,*tamanioInicial);
		pf("\n El valor que representa el tercer cuartil (75%) es: %0.4f \n",resultado);
	}else if(strcmp(comando,"datos")==0){
		datos(arreglo,*tamanioInicial);
	}else if(strcmp(comando,"desvest")==0){
		resultado = desvest(arreglo,*tamanioInicial);
		pf("\nEl valor de la desviaci%cn estándar es de: %0.4f. \n",162,resultado);	
	}else if(strcmp(comando,"imprimir")==0){
		imprimir(arreglo,*tamanioInicial);
	}else if(strcmp(comando,"media")==0){
		resultado = media(arreglo,*tamanioInicial);
		pf("\n El resultado de la media de los valores del arreglo es de: %0.4f \n",resultado);
	}else if(strcmp(comando,"mediana")==0){
		float *resultados; 
		resultados = mediana(arreglo,*tamanioInicial);
		pf("\n El valor de la mediana es de: %0.4f \n",resultados[1]);
	}else if(strcmp(comando,"moda")==0){
		// El tercer argumento expresa si está disponible la opción de imprimir MÚLTIPLES
		// VALORES DE MODA.
		resultado = moda(arreglo,*tamanioInicial,1);
		if(resultado>0){
			pf("\nEl valor de la moda será de: %0.4f.\n",resultado);
		}else if(resultado==-100){
			pf("\nAl parecer no has a%cadido valores al arreglo. Vuelve a intentarlo escribiendo el comando \"datos\".\n",164);
		}
		// Si no se imprime lo anterior significa que había más de una moda, por lo que ya
		// fue impresa desde el método principal.
	}else if(strcmp(comando,"n")==0){
		n(arreglo,tamanioInicial);
	}else if(strcmp(comando,"rango")==0){
		resultado = rango(arreglo,*tamanioInicial);
		pf("\n El valor del rango es de : %0.4f \n",resultado);
	}else if(strcmp(comando,"ric")==0){
		resultado = ric(arreglo,*tamanioInicial);
		pf("\n El valor del rango intercuartil es: %0.4f \n",resultado);
	}else if(strcmp(comando,"salir")==0){
		return -1; /*Ya no tiene nada más que hacer, solo enviar un valor que rompa el ciclo.*/
	}else if(strcmp(comando,"todos")==0){
		todos(arreglo,*tamanioInicial);
	}else if(strcmp(comando,"varianza")==0){
		resultado = varianza(arreglo,*tamanioInicial);
		pf("\nEl resultado de la varianza es de: %0.4f \n",resultado);
	}else{
		pf("\n %cFATAL! Has tenido un error al elegir el comando, por favor, intenta otra vez.\n",173);
		pf(" Escribe \"ayuda\" para volver a desplegar el men%c de inicio.\n",163);
	}
	return 1; // Mientras el valor sea positivo se estará pidiendo comandos.
}
void ayuda(){
	pf("\n");
	pf(" ################################################################################\n");
	pf(" ----------- CALCULADORA DE MEDIDAS DE TENDENCIA CENTRAL Y DISPERSI%cN -----------\n",224);	
	pf("                                                                                 \n");
	pf(" INSTRUCCIONES : Cuando aparezca el s%cmbolo '>', puedes teclear cualquiera de los\n",161);	
	pf("                 comandos que se muestran en la siguiente tabla.                 \n");	
	pf("  ______________________________________________________________________________ \n");
	pf(" |           |                                                                  |\n");	
	pf(" | COMANDO   | FUNCI%cN                                                          |\n",224);
	pf(" |------------------------------------------------------------------------------|\n");
	pf(" |   ayuda   | Imprimir nuevamente esta tabla de ayuda.                         |\n");
	pf(" |   salir   | Terminar el programa.                                            |\n");
	pf(" |     n     | Cambiar la cantidad de datos (por defecto, n=100).               |\n");
	pf(" |   datos   | Cambiar todos los datos con los que se desea trabajar.           |\n");
	pf(" |  cambiar  | Cambiar un dato en una posici%cn espec%cfica.                      |\n",162,161);
	pf(" |  imprimir | Imprimir los datos ordenados con los que se trabaja actualmente. |\n");
	pf(" |   media   | Calcular la media aritm%ctica del conjunto de datos.              |\n",130);
	pf(" |  mediana  | Calcular la mediana del conjunto de datos.                       |\n");
	pf(" |   moda    | Calcular la moda del conjunto de datos.                          |\n");
	pf(" |  varianza | Calcular la varianza del conjunto de datos.                      |\n");
	pf(" |  desvest  | Calcular la desviaci%cn est%cndar del conjunto de datos.           |\n",162,160);
	pf(" | cuartil-1 | Calcular el primer cuartil del conjunto de datos.                |\n");
	pf(" | cuartil-3 | Caluclar el primer cuartil del conjunto de datos.                |\n");
	pf(" |    ric    | Calcular el rango intercuartilico del conjunto de datos.         |\n");
	pf(" |   rango   | Calcular el rango del conjunto de datos.                         |\n");
	pf(" |   todos   | Calcular todas las medidas sobre el conjunto de datos.           |\n");
	pf(" |___________|__________________________________________________________________|\n");
}
void n(float *arreglo, int *tamanioInicial){
	pf("\n El arreglo actualmente tiene la capacidad de %d datos.\n",*tamanioInicial);
	pf("Indica el nuevo tama%co del arreglo: ",164);
	int nuevoTamanio;
	sf("%d",&nuevoTamanio);
	arreglo = (float *) realloc(arreglo, nuevoTamanio * sizeof(float));
    *tamanioInicial=nuevoTamanio;
    pf("\n %cSe ha cambiado el tama%co del arreglo exitosamente! \n",173,164);
}
void datos(float *arreglo, int tamanioInicial){
	
	for (int i = 0; i < tamanioInicial; ++i)
	{
		pf("\nIngresa el valor que tendr%c la posici%cn %d: ",160,162,i);
		float valor;
		sf("%f",&valor);
		arreglo[i]=valor;
		pf("%cValor a%cadido exitosamente!(%d/%d)\n",173,164,(i+1),tamanioInicial);
	}
}
void cambiar(float *arreglo, int tamanioInicial){
	int indice;
	float nuevoValor;
	do{
		pf("Escribe el %cndice que quieres cambiar, elige un n%cmero entre 0 y %d: ",161,163,tamanioInicial-1);
		sf("%d",&indice);
		if(indice<0||indice>tamanioInicial-1){
			pf(" %cOH NO! Has elegido un %cndice fuera de rango, intenta otra vez.\n",173,161);
		}
	}while(indice<0||indice>tamanioInicial-1);
	pf("Escribe el nuevo valor para el %cndice %d: ",161,indice);
	sf("%f",&nuevoValor);
	arreglo[indice]=nuevoValor;
	pf("\n %cSe cambi%c el valor del indice %d por un %0.4f exitosamente!\n",173,162,indice,nuevoValor);
}
int vacio(float *arreglo, int tamanioInicial){
	int error = 0;
	for(int i=0;i<tamanioInicial;i++){
		if(arreglo[i]>0){
			error = 0;
			break;
		}
		error = 1;
	}
	return error;
}
void ordenar(float *arreglo,int tamanioInicial){

	// Algoritmo de ordenamiento conocido como InsertionSort.
	// La implementación de este algoritmo puede encontrarse en:
	// https://www.geeksforgeeks.org/insertion-sort/

	// Este método parte de aceptar que todo lo que se encuentra a la izquierda
	// ya se encuentra ordenado, por lo tanto, se estará verificando si la posición siguiente
	// es menor, en dado caso que si lo sea, hay un intercambio.

    for (int i = 1; i < tamanioInicial; i++) { 
        float key = arreglo[i]; 
        int j = i - 1; 
        while (j >= 0 && arreglo[j] > key) { 
            arreglo[j + 1] = arreglo[j]; 
            j = j - 1; 
        } 
        arreglo[j + 1] = key; 
    }
}
void imprimir(float *arreglo, int tamanioInicial){

	ordenar(arreglo,tamanioInicial);
	pf("  _____________________ \n");
	pf(" |        |            |\n");	
	pf(" | %cNDICE |   VALOR    |\n",214);
	pf(" |---------------------|\n");
	for (int i = 0; i < tamanioInicial; i++)
	{
		pf(" |  %5d | %10.4f |\n",i,arreglo[i]);	
	}
	pf(" |________|____________|\n");
}
float media(float *arreglo, int tamanioInicial){

	float promedio=0;
	for(int i=0;i<tamanioInicial;i++){
		promedio = promedio + arreglo[i];
	}
	promedio = promedio/tamanioInicial;
	return promedio;
}
float* mediana(float *arreglo, int tamanioInicial){

	// Para determinar la mediana se requiere de un arreglo ordenado.
	ordenar(arreglo,tamanioInicial);	

	// Los resultados se guardarán en un arreglo. 
	float *resultados;
	resultados = (float *) malloc(2 * sizeof(float));
	float aux=0.0001;/*Es un valor flotante que forzará un casting con el valor intermedio*/

	// Se indican determinan los indices iniciales y los finales.
	int inicio = 0;
	int fin = tamanioInicial-1;
	int intermedio = (int)((inicio + fin)/2);
	float mediana = 0;
	// Se verifica si el arreglo contiene un tamaño de número par
	if(tamanioInicial%2==0){
		// Dado que es par, se toman los dos valores centrales, en este caso será
		// el valor intermedio y su posterior. Después se tomará el promedio entre estos
		// dos números.
		mediana = (arreglo[intermedio]+arreglo[intermedio+1])/2;
	}else{
		mediana = arreglo[intermedio];
	}
	resultados[0] = intermedio+aux;
	resultados[1] = mediana;
	return resultados;
}
float moda(float arreglo[], int tamanioInicial, int conRepeticion){
	// Este comando solo requerirá de una copia del arreglo inicial
	float valores[tamanioInicial];
	
	// Verificar que no se trata de un arreglo vacío
	int error = vacio(arreglo,tamanioInicial);

	if(error == 1){
		return -100; //Se trata de un arreglo vacío.
	}

	// Copiar todos los valores del arreglo principal a un arreglo auxiliar.
	for(int i=0;i<tamanioInicial;i++){
		valores[i]=arreglo[i];
	}

	float repeticionesGlobales[tamanioInicial]; /*Arreglo que contendrá las veces que se repite cada número del arreglo.*/

	float valorModa; /*Almacenará los posibles resultados de la moda.*/
	for(int i = 0; i<tamanioInicial; i++){
		valorModa = valores[i];
		int repeticiones = 0; /*Almacenará cantidad de veces que se repite el posible valor de la moda.*/
		for(int j=0;j<tamanioInicial;j++){
			if(valorModa==valores[j]&&valores[j]!=0){
				repeticiones=repeticiones+1;
				valores[j]=0;
			}
		}
		// pf("%0.4f se repitió %d veces.\n",valorModa,repeticiones);
		repeticionesGlobales[i]=repeticiones;
	}
	int modaFinal=0; /*Estará haciendo referencia al índice que tenga la
	 mayor cantidad de repeticiones, por defecto se comenzará con el primer índice.*/
	for(int i=0;i<tamanioInicial;i++){
		if(repeticionesGlobales[modaFinal]<repeticionesGlobales[i]){
			// Si la cantidad de repeticiones es menor a otra en el arreglo
			// el índice cambiará.
			modaFinal=i;
		}
	}
		
	float *indicesConModa;
	int modas=1;/*Se espera que al menos exista una moda, en un caso estándar.*/
	indicesConModa = (float *) calloc(modas, sizeof(float));
	indicesConModa[0]=modaFinal;
	for (int i = 0; i < tamanioInicial; i++){
		if(repeticionesGlobales[modaFinal]==repeticionesGlobales[i]&&modaFinal!=i){
			// Si la cantidad de repeticiones es la misma y se trata de índices diferentes
			// quiere decir que hay más de una moda.
			modas=modas+1;
			indicesConModa=(float *) realloc(indicesConModa, modas * sizeof(float));
			indicesConModa[modas-1]=i;
		}
	}
	if(modas>1){
		if(conRepeticion==1){
			pf("\n%cTenemos m%cs de una moda!\n",173,160);
			// pf("\nLos %cndices que tendrán valores de moda son: ",161);
			// for(int i=0;i<modas;i++){
			// 	pf("[%0.0f] ",indicesConModa[i]);
			// }
			pf("\nEl valor de las modas ser%c de: ",160);
			for(int i=0;i<modas;i++){
				// Aquí se presenta un casting para que el valor de "indicesConModa" sea un valor entero.
				pf("[%0.4f] ",arreglo[(int) indicesConModa[i]]);
			}
			pf("\n");
			return 0;
		}else{
			return -1; /*Se manda un resultado final que represente que 
		            'no se encontró UNA SOLA MODA', se encontró más de una. */
		}
	}else{
		// pf("El %cndice que tiene la moda es: %d.\n",161,modaFinal);
		return arreglo[modaFinal];
	}
}
float varianza(float *arreglo, int tamanioInicial){
 /* La varianza estará dada por el cuadrado de la sumatoria de los residuos del
    elemento del arreglo menos su promedio, el resultado se dividirá entre la cantidad
    de elementos del arreglo.

             (arreglo[0] - promedio)^2 + (arreglo[1] - promedio)^2 + ... + (arreglo[indiceFinal] - promedio)^2
 Varianza = ------------------------------------------------------------------------------------------
                                        cantidad de elementos del arreglo
 */
	float promedio = media(arreglo,tamanioInicial);
	float resultado=0;
	for(int i=0;i<tamanioInicial;i++){
		resultado = resultado + ((arreglo[i] - promedio)*(arreglo[i] - promedio));
	}
	resultado = (resultado/tamanioInicial);
	return resultado;
}
float desvest(float *arreglo, int tamanioInicial){
 /* La desviación estándar (DE) será el resultado de la raíz cuadrada de una división,
    esta estará dada por la varianza y la cantidad de elementos del arreglo.
           ___________________________________________
          /               varianza   
 DE = \  / -------------------------------------------
       \/       cantidad de elementos del arreglo
 */
	float valorVarianza = varianza(arreglo,tamanioInicial);
	float resultado=0;
	resultado = sqrt(valorVarianza/tamanioInicial);
	return resultado;
}
float cuartil_1(float *arreglo, int tamanioInicial){
	
	// Para determinar el valor del primer cuartil se requerirá de ordenar el arreglo.
	ordenar(arreglo,tamanioInicial);
	// También se requerirá de encontrar la mediana para después encontrar el valor medio
	// de los valores a la izquierda de la mediana y de los valores a la derecha.
	float *valoresMediana;
	valoresMediana = mediana(arreglo,tamanioInicial); 
	
	int tamSubLista;
	if(tamanioInicial%2!=0){
		tamSubLista = ((int) valoresMediana[0]);
	}else{
		tamSubLista = ((int) valoresMediana[0])+1;
	}
	// Se hará una sublista con los valores izquierdos al índice intermedio.
	float valoresIzquierdos[tamSubLista];
	for (int i = 0; i < tamSubLista; i++){
		valoresIzquierdos[i]=arreglo[i];
	}

	// Se volverá a tomar la mediana pero de la sublista creada.
	float *resultadosFinales;
	resultadosFinales = mediana(valoresIzquierdos,tamSubLista);
	return resultadosFinales[1];
}
float cuartil_3(float *arreglo, int tamanioInicial){
	// A diferencia con el Cuartil 1, el Cuartil 3 hace el mismo proceso, pero para
	// una sub lista DERECHA.
	
	ordenar(arreglo,tamanioInicial);
	
	// Se obtendrán los valores del arreglo principal.
	float *valoresMediana;
	valoresMediana = mediana(arreglo,tamanioInicial); 

	int tamSubLista;
	if(tamanioInicial%2!=0){
		tamSubLista = ((int) valoresMediana[0]);
	}else{
		tamSubLista = ((int) valoresMediana[0]+1);
	}

	// Se hará una sublista con los valores derechos al índice intermedio.
	float valoresDerechos[tamSubLista];
	if(tamanioInicial%2!=0){
		int indiceSubLista=0;
		for (int i = tamSubLista+1; i < tamanioInicial; i++){
			valoresDerechos[indiceSubLista]=arreglo[i];
			indiceSubLista=indiceSubLista+1;
		}
	}else{
		for (int i = tamSubLista; i < tamanioInicial; i++){
			int indiceSubLista = i-tamSubLista;
			valoresDerechos[indiceSubLista]=arreglo[i];
		}
	}

	// Se volverá a tomar la mediana pero de la sublista creada.
	float *resultadosFinales;
	resultadosFinales = mediana(valoresDerechos,tamSubLista);
	return resultadosFinales[1];
}
float rango(float *arreglo, int tamanioInicial){
	// EL cálculo del rango será la cantidad de valores que existe entre el número más
	// pequeño del conjunto y del más grande.

	// Se comenzará organizando el conjunto de datos.
	ordenar(arreglo,tamanioInicial);
	float menor = arreglo[0];
	float mayor = arreglo[tamanioInicial-1];
	return mayor-menor; /*Se retorna la diferencia de los dos números.*/
}
float ric(float *arreglo, int tamanioInicial){
	// EL cálculo del rango intercuartil está dado por la diferencia de el cuartil 3 
	// menos el cuartil 1.
	float cuartil1 = cuartil_1(arreglo,tamanioInicial);
	float cuartil3 = cuartil_3(arreglo,tamanioInicial);
	float rango = cuartil3-cuartil1;
	return rango;
}
void todos(float *arreglo, int tamanioInicial){
	float resultado;
	pf("  __________________________________________\n");
	pf(" |                 |                        |\n");	
	pf(" |    MEDIDA       | RESULTADO              |\n");
	pf(" |------------------------------------------|\n");
	resultado = media(arreglo,tamanioInicial);
	pf(" |      MEDIA      |%23.4f |\n",resultado);
	pf(" |-----------------|------------------------|\n");
	float *resultadoMediana = mediana(arreglo,tamanioInicial);
	// resultado = mediana(arreglo,tamanioInicial);
	pf(" |     MEDIANA     |%23.4f |\n",resultadoMediana[1]);
	pf(" |-----------------|------------------------|\n");
	resultado = moda(arreglo,tamanioInicial,0);
	if(resultado>0){
	pf(" |      MODA       |%23.4f |\n",resultado);
	}else if(resultado=-100){
	pf(" |      MODA       | El conjunto de datos   |\n");
	pf(" |                 | se encuentra vac%co.    |\n",161,resultado);		
	}else{
	pf(" |      MODA       | El conjunto de datos   |\n");
	pf(" |                 | tiene m%cs de una moda. |\n",160,resultado);
	}
	pf(" |-----------------|------------------------|\n");
	resultado = varianza(arreglo,tamanioInicial);
	pf(" |     VARIANZA    |%23.4f |\n",resultado);
	pf(" |-----------------|------------------------|\n");
	resultado = desvest(arreglo,tamanioInicial);
	pf(" |   DESVIACI%cN    |%23.4f |\n",224,resultado);
	pf(" |    EST%cNDAR     |                        |\n",181);
	pf(" |-----------------|------------------------|\n");
	resultado = cuartil_1(arreglo,tamanioInicial);
	pf(" |    CUARTIL 1    |%23.4f |\n",resultado);
	pf(" |-----------------|------------------------|\n");
	resultado = cuartil_3(arreglo,tamanioInicial);
	pf(" |    CUARTIL 3    |%23.4f |\n",resultado);
	pf(" |-----------------|------------------------|\n");
	resultado = ric(arreglo,tamanioInicial);
	pf(" |      RANGO      |%23.4f |\n",resultado);
	pf(" | INTERCUART%cLICO |                        |\n",214);
	pf(" |_________________|________________________|\n");
	resultado = moda(arreglo,tamanioInicial,0);
	if(resultado==-1){
		pf("\n * Si quieres consultar los valores de MODA,\n   deber%cs escribir el comando \"moda\"\n   individualmente.\n",160);
	}
}