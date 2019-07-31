#include <stdio.h>
#include <ctype.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include"funciones.h"

int main()
{
    inicializar_arreglo();
    posicion_inicial();
    menu();

}

//void intento()
//{
//    FILE* fichero;
//    fichero = fopen("cursoAF1.txt", "wt");
//    fputs("Aprender a programar (linea 1)\n", fichero);
//    fputs("requiere esfuerzo (linea 2)\n", fichero);
//    fputs("y dedicacion (linea 3)", fichero);
//    fclose(fichero);
//    printf("Proceso completado");
//}
