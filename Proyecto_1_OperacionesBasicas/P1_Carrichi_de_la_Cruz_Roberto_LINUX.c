#include <stdio.h>
#include <stdlib.h>
#define pf printf
#define sf scanf

int main(){
    /************************************/ 
    /*          VERSIÓN LINUX           */ 
    /*       */system("clear");/*       */
    /************************************/ 

    float valores[2];
    pf("\t##################################\n");
    pf("\t### ¡BIENVENIDO AL PROYECTO 1! ###\n");
    pf("\t##################################\n");
    pf("\n Ingresa dos números\n");
    for(int i=0; i<2; i++){
    	pf(" > ");
    	sf("%f",&valores[i]);
    }
    pf("\n###################################################\n");
    pf("#            Estos son tus resultados:            #\n");
    pf("\n\tHas ingresado: %.4f y %.4f\n\n", valores[0], valores[1]);
    
    pf("Ahora se te presentará una tabla con los resultados\nde las  4 operaciones básicas entre los dos números\nque elegiste.\n\n");
    pf("\t||¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯||¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯||\n");
    pf("\t||   OPERACIÓN   ||   RESULTADO   ||\n");
    pf("\t||---------------||---------------||\n");
    pf("\t||Suma           ||%15.4f||\n", (valores[0]+valores[1]));
    pf("\t||Resta          ||%15.4f||\n", (valores[0]-valores[1]));
    pf("\t||Multiplicación ||%15.4f||\n", (valores[0]*valores[1]));
    if(valores[1]==0){
        pf("\t||División       ||   INDEFINIDO  ||\n");        
        pf("\t||_______________||_______________||\n\n");
        pf("\t * No hay división entre cero.\n");
    }else{
        pf("\t||División       ||%15.4f||\n", (valores[0]+valores[1]));
        pf("\t||_______________||_______________||\n\n");
    }

    pf("###################################################\n");
    pf("#  Hecho por: Roberto Carlos Carrichi de la Cruz  #\n");
    pf("###################################################\n\n");
   
    return 0;
}