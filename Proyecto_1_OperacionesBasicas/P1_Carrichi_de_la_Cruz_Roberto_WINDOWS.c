#include <stdio.h>
#include <stdlib.h>
#define pf printf
#define sf scanf

int main(){
    /************************************/ 
    /*          VERSIÓN WINDOWS           */ 
    /*       */system("cls");/*       */
    /************************************/ 

    float valores[2];
    pf("\t##################################\n");
    pf("\t### ¡BIENVENIDO AL PROYECTO 1! ###\n");
    pf("\t##################################\n");
    pf("\n Ingresa dos n%cmeros\n",163);
    for(int i=0; i<2; i++){
    	pf(" > ");
    	sf("%f",&valores[i]);
    }
    pf("\n###################################################\n");
    pf("#            Estos son tus resultados:            #\n");
    pf("\n\tHas ingresado: %.4f y %.4f\n\n", valores[0], valores[1]);
    
    pf("Ahora se te presentar%c una tabla con los resultados\nde las  4 operaciones b%csicas entre los dos n%cmeros\nque elegiste.\n\n",160,160,163);
    pf("\t||¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯||¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯||\n");
    pf("\t||   OPERACI%cN   ||   RESULTADO   ||\n",224);
    pf("\t||---------------||---------------||\n");
    pf("\t||Suma           ||%15.4f||\n", (valores[0]+valores[1]));
    pf("\t||Resta          ||%15.4f||\n", (valores[0]-valores[1]));
    pf("\t||Multiplicaci%cn ||%15.4f||\n", 162, (valores[0]*valores[1]));
    if(valores[1]==0){
        pf("\t||Divisi%cn       ||   INDEFINIDO  ||\n", 162);        
        pf("\t||_______________||_______________||\n\n");
        pf("\t * No hay divisi%cn entre cero.\n",162);
    }else{
        pf("\t||Divisi%cn       ||%15.4f||\n", 162, (valores[0]+valores[1]));
        pf("\t||_______________||_______________||\n\n");
    }

    pf("###################################################\n");
    pf("#  Hecho por: Roberto Carlos Carrichi de la Cruz  #\n");
    pf("###################################################\n\n");
   
    return 0;
}