#include <iostream>
#include <string>
#include "comandos.h"
#include "matriz.h"

using namespace std;

// Definición de prototipos de funciones.
void sumar();
void restar();
void multiplicar();
void redimensionar();

// Definición de las matrices que se estarán modificando durante la ejecución
// del programa. Para su construcción se requerirá asignarles un nombre.

Matriz A("A");
Matriz B("B");
Matriz C("C");

/*
	COMANDOS QUE OPERARÁN CON MATRICES
*/

int ejecutarComando(string comando){
	// Deberá identificarse si el comando es de dos palabras, donde la primera
	// indica el comando y el segundo una matriz.
	char matriz=' ';
	for (int i = 0; i < comando.length()-1; ++i)
	{
		if(comando[i]==' '){
			matriz = comando[i+1];
			// Ya que tiene un espacio, el comando general se cortará hasta ese punto
			// guardandose como una subcadena de la original.
			comando = comando.substr(0,i);
		}
	}
	float resultado=0;
	if(comando=="ayuda"){
		ayuda();
	}else if(comando=="redimensionar"){
		redimensionar();
	}else if(comando=="llenar"&&matriz!=' '){
		if (matriz=='A'||matriz=='a'){
			cout << endl;
			A.llenar();
		}else if(matriz=='B'||matriz=='b'){
			cout << endl;
			B.llenar();
		}else if(matriz=='C'||matriz=='c'){
			cout << endl;
			C.llenar();
		}else{
			cout << "No has elegido una matriz valida, elige alguna de las siguientes: 'A', 'B' o 'C'." <<endl;
		}
	}else if(comando=="imprimir"&&matriz!=' '){
		if (matriz=='A'||matriz=='a'){
			cout << endl;
			A.imprimir();
		}else if(matriz=='B'||matriz=='b'){
			cout << endl;
			B.imprimir();
		}else if(matriz=='C'||matriz=='c'){
			cout << endl;
			C.imprimir();
		}else{
			cout << "No has elegido una matriz valida, elige alguna de las siguientes: 'A', 'B' o 'C'." <<endl;
		}
	}else if(comando=="sumar"){
		C = A + B;
	}else if(comando=="restar"){
		C = A - B;
	}else if(comando=="multiplicar"){
		C = A * B;
	}else if(comando=="trasponer"&&matriz!=' '){
		if (matriz=='A'||matriz=='a'){
			cout << endl;
			A.trasponer();
		}else if(matriz=='B'||matriz=='b'){
			cout << endl;
			B.trasponer();
		}else if(matriz=='C'||matriz=='c'){
			cout << endl;
			C.trasponer();
		}else{
			cout << "No has elegido una matriz valida, elige alguna de las siguientes: 'A', 'B' o 'C'." <<endl;
		}
	}else if(comando=="salir"){
		// Antes de cerrar el programa liberará la memoria reservada.
		A.borrar();
		B.borrar();
		C.borrar();
		cout << "\nSe libero la memoria reservada exitosamente." << endl;
		return -1; /*Ya no tiene nada más que hacer, solo enviar un valor que rompa el ciclo.*/
	}else{
		cout << "\n OH NO! Has tenido un error al escribir algun el comando, por favor, intenta otra vez.\n";
		cout << " Escribe \"ayuda\" para volver a desplegar el menu de inicio.\n";
	}
	return 1; // Mientras el valor sea positivo se estará pidiendo comandos.
}

void ayuda(){
	cout << "\n #####################################################################################" << endl;
	cout << " ------------------- CALCULADORA DE MATRICES POR LINEA DE COMANDOS -------------------  " << endl;	
	cout << "                                                                                        " << endl;
	cout << "   INSTRUCCIONES : Cuando aparezca el simbolo '~>', puedes teclear cualquiera de los    " << endl;	
	cout << "                   comandos que se muestran en la siguiente tabla.                      " << endl;	
	cout << "  ___________________________________________________________________________________   " << endl;
	cout << " |     COMANDO     | FUNCION                                                         |  " << endl;
	cout << " |-----------------------------------------------------------------------------------|  " << endl;
	cout << " |      ayuda      | Mostrar esta tabla de comandos y funciones.                     |  " << endl;
	cout << " |  redimensionar  | Cambiar el orden (tamaño) de las matrices a operar.             |  " << endl;
	cout << " |   llenar <mat>  | Llenar con elementos la matriz <mat>.                           |  " << endl;
	cout << " |  imprimir <mat> | Imprimir los elementos de la matriz <mat>.                      |  " << endl;
	cout << " |      sumar      | Realiza la suma: A + B y guarda el resultado en C.              |  " << endl;
	cout << " |     restar      | Realiza la resta: A - B y guarda el resultado en C.             |  " << endl;
	cout << " |   multiplicar   | Hacer la multiplicación de A * B y guardar el resultado en C.   |  " << endl;
	cout << " | trasponer <mat> | Trasponer la matriz <mat> y guardar el resultado en ella misma. |  " << endl;
	cout << " |      salir      | Terminar la ejecución del programa.                             |  " << endl;
	cout << " |_________________|_________________________________________________________________|\n" << endl;
	cout << "  Actualmente tienes a tu disposición 3 matrices llamadas: 'A', 'B' y 'C'. Todas las    " << endl;
	cout << "  matrices mantendrán el mismo orden entre ellas, actualmente el orden es de: " << A.orden << ". " << endl;
	cout << "\n  TEN CUIDADO AL ESCRIBIR! Evita poner espacios (' ') al final de el comando.           " << endl;
}

void redimensionar(){
	int orden;
	cout << "\t Cuidado! Esta accion puede causar perdida de información, tomalo en cuenta.";
	cout << "\n Indica el nuevo orden de las matrices a operar: ";
	cin >> orden;
	cin.ignore(); //Su función será "limpiar" el buffer, es considerado el equivalente a getchar().
	
	/*
		Se asigna el nuevo orden a cada matriz a través de un método "SET" para las tres matrices.
		Este estará encargado de redimensionar el tamaño de la matriz.
	*/
	A.setOrden(orden);
	B.setOrden(orden);
	C.setOrden(orden);
}