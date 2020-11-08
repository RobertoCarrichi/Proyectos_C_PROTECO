#ifndef comandos
#define comandos
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "comandos.h"
#define pf printf 
#define sf scanf 
void ayuda();
int ejecutarComando(char *comando,float *arreglo,int *tamanioInicial);
void n(float *arreglo, int *tamanioInicial);
void datos(float *arreglo, int tamanioInicial);
void cambiar(float *arreglo, int tamanioInicial);
int vacio(float *arreglo, int tamanioInicial);
void ordenar(float *arreglo,int tamanioInicial);
void imprimir(float *arreglo, int tamanioInicial);
float media(float *arreglo, int tamanioInicial);
float* mediana(float *arreglo, int tamanioInicial);
float moda(float arreglo[], int tamanioInicial,int repeticion);
float varianza(float *arreglo, int tamanioInicial);
float desvest(float *arreglo, int tamanioInicial);
float cuartil_1(float *arreglo, int tamanioInicial);
float cuartil_3(float *arreglo, int tamanioInicial);
float rango(float *arreglo, int tamanioInicial);
float ric(float *arreglo, int tamanioInicial);
void todos(float *arreglo, int tamanioInicial);
#endif