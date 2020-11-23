#include <iostream>
#include "matriz.h"

using namespace std;

/*
  Implementación de los métodos declarados en el archivo "matriz.h"
*/

void Matriz::setOrden(int orden){
	this->orden = orden;
	// Reserva de espacio para RENGLONES.
   	this->contenido = new float*[this->orden];
   	// Ciclo reservar espacio para cada COLUMNA.
    for (int i = 0; i < this->orden; i++) {
        this->contenido[i] = new float[this->orden];
    }		
}

void Matriz::llenar(){
	cout << "\n\t Haz elegido llenar la matriz: " << this->nombre << endl;
	cout << "\n El orden actual de la matriz es de " << this->orden << ", deberas ingresar valores hasta llegar a [" << this->orden << "," << this->orden << "]." << endl; 
	for (int i = 0; i < this->orden; i++) {
       	for (int j = 0; j < this->orden; j++) {
       	    cout << "  Valor para la posicion [" << i+1 <<"," << j+1 << "]: ";
       	    cin >> this->contenido[i][j];
       	}
    }
    cin.ignore();
    cout << "\n\t Has terminado!";
}

void Matriz::trasponer(){
	/*
		El objetivo de este método es mover los valores de la matriz para que los renglones 
		pasen a ser columnas y viceversa.
		Lo que se hace es crear una matriz auxiliar que en todo momento estará guardando los valores
		correspondientes a la transpuesta, al final, los datos obtenidos serán transferidos a la matriz
		original.
	*/
	Matriz AUX("AUX"); // Mediante el constructor, es necesario darle un nombre a la matriz.
	AUX.setOrden(this->orden); // El orden de la matriz auxiliar debe ser igual a la de la matriz origen.
	for (int i = 0; i < this->orden; i++) {
       	for (int j = 0; j < this->orden; j++) {
       		AUX.contenido[j][i] = this->contenido[i][j];
       	}
    }
    this->contenido = AUX.contenido;
}
		
void Matriz::imprimir(){
	cout << "Contenido de la matriz: " << this->nombre << endl;
    for (int i = 0; i < this->orden ; i++) {
      cout << "\t";
      for (int j = 0; j < this->orden ; j++) {
        cout << "[" << this->contenido[i][j] << "]" << " ";
      }
      cout << endl;
    }
}

void Matriz::borrar(){
	// Se libera el espacio reservado para cada columna de la matriz.
	for (int i = 0; i < this->orden; i++) {
	  delete[] this->contenido[i];
	}
	// Se libera el espacio reservado para cada renglón del contenido.
    delete[] this->contenido;
}