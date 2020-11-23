#include <string>
#ifndef MATRIZ_H
#define MATRIZ_H
	class Matriz
	{
	public:
		// Atributos
		std::string nombre; // Un atributo generico para la impresión de la matriz.
		int orden; // Esta variable guardará el orden de la matriz.
		float **contenido; // Este doble apuntador representa un arreglo de arreglos de tipo float.

		// En este constuctor se indicará el orden por defecto que tendrá la matriz.
		Matriz(std::string nombre){
			this->nombre = nombre;
			// EL ORDEN POR DEFECTO ES DE 3.
			this->orden = 3;
			// Ya que se expresó un orden, se almacenará espacio en RENGLONES.
	    	this->contenido = new float*[this->orden];
	    	// Este ciclo será para que se reserve espacio para cada COLUMNA de cada renglón.
		    for (int i = 0; i < this->orden; i++) {
		        this->contenido[i] = new float[this->orden];
		    }
		};

		// Métodos
		void setOrden(int);
		void llenar();
		void trasponer();
		void imprimir();
		void borrar();

		// Sobrecarga de operadores 
		Matriz operator + (Matriz matriz){
			// El parámetro que recibe es la matriz con la que será sumada la
			// matriz actual. Los resultados de las sumas estarán guardándose 
			// en una matriz auxiliar que tendrá por nombre "C".
	    	Matriz AUX("C");
	    	AUX.setOrden(this->orden);
	    	for (int i=0;i<this->orden;i++){
	            for (int j=0;j<this->orden;j++){
	                AUX.contenido[i][j]=this->contenido[i][j]+matriz.contenido[i][j];
	            }
        	}
        	return AUX;
    	};
    	Matriz operator - (Matriz matriz){
			// El parámetro que recibe es la matriz con la que será restada la
			// matriz actual. Los resultados estarán guardándose 
			// en una matriz auxiliar.
	    	Matriz AUX("C");
	    	AUX.setOrden(this->orden);
	    	for (int i=0;i<this->orden;i++){
	            for (int j=0;j<this->orden;j++){
	                AUX.contenido[i][j]=this->contenido[i][j]-matriz.contenido[i][j];
	            }
        	}
        	return AUX;
    	};
    	Matriz operator * (Matriz matriz){
			// El parámetro que recibe es la matriz con la que será restada la
			// matriz actual. Los resultados estarán guardándose 
			// en una matriz auxiliar.
	    	Matriz AUX("C");
	    	AUX.setOrden(this->orden);
        	for (int i=0;i<this->orden;i++){
        	    for(int j=0;j<this->orden;j++){
        	        float auxiliar=0;
        	        for (int k=0;k<this->orden;k++){
        	            auxiliar=auxiliar+this->contenido[i][k]*matriz.contenido[k][j];
        	            AUX.contenido[i][j]=auxiliar;
        	        }
        	    }
        	}
        	return AUX;
    	};
	};
#endif