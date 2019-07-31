#include <stdio.h>
#include <ctype.h>
#include<stdlib.h>
#include<conio.h>
typedef struct jugador{
    char *nombre;
    int partidas_ganadas;
    int partidas_perdidas;
    float promedio;
}player;
player jugadores[100];
int n_jugadores=0;
char tablero[8][8];
int agregar_jugador();
void score();
void juego_nombre();
char *leer_string();
void inicializar_arreglo();
void posicion_inicial();
void menu();
void juego();
void imprimir_tablero();
int validar_(int i_inicial,int j_inicial,int i_final,int j_final,int turno);
void imprimir_jugador(int turno);
void leer_jugada(int *i_inicial, int *j_inicial,int *i_final,int *j_final,char turno);
void mover_pieza(int i_inicial, int j_inicial, int i_final, int j_final);
int confirmar_peon_blanco(int i_inicial,int j_inicial,int i_final,int j_final);
int confirmar_peon_negro(int i_inicial,int j_inicial,int i_final,int j_final);
int confirmar_rey_blanco(int i_inicial,int j_inicial,int i_final,int j_final);
int confirmar_rey_negro(int i_inicial,int j_inicial,int i_final,int j_final);
int confirmar_caballo_negro(int i_inicial,int j_inicial,int i_final,int j_final);
int confirmar_caballo_blanco(int i_inicial,int j_inicial,int i_final,int j_final);
int confirmar_torre_blanca(int i_inicial,int j_inicial,int i_final,int j_final);
int confirmar_torre_negra(int i_inicial,int j_inicial,int i_final,int j_final);
int confirmar_alfil_negro(int i_inicial,int j_inicial,int i_final,int j_final);
int confirmar_alfil_blanco(int i_inicial,int j_inicial,int i_final,int j_final);
int confirmar_dama_blanca(int i_inicial,int j_inicial,int i_final,int j_final);
int confirmar_dama_negra(int i_inicial,int j_inicial,int i_final,int j_final);

int cal_izq_negras(int i_inicial,int j_inicial);
int cal_izq_arr_negra(int i_inicial,int j_inicial);
int cal_izq_abj_negra(int i_inicial,int j_inicial);
int cal_derecha_negras(int i_inicial,int j_inicial);
int cal_dere_arr_negra(int i_inicial,int j_inicial);
int cal_dere_abj_negra(int i_inicial,int j_inicial);
int cal_arriba_negras(int i_inicial,int j_inicial);
int cal_abajo_negras(int i_inicial,int j_inicial);

int cal_izq_blancas(int i_inicial,int j_inicial);
int cal_izq_arr_blanca(int i_inicial,int j_inicial);
int cal_izq_abj_blanca(int i_inicial,int j_inicial);
int cal_derecha_blancas(int i_inicial,int j_inicial);
int cal_dere_arr_blanca(int i_inicial,int j_inicial);
int cal_dere_abj_blanca(int i_inicial,int j_inicial);
int cal_arriba_blancas(int i_inicial,int j_inicial);
int cal_abajo_blancas(int i_inicial,int j_inicial);

int lee_ganador();

int contador_movi_rey_blanco=0;
int contador_movi_torre_blanco=0;

int contador_movi_rey_negro=0;
int contador_movi_torre_negro=0;
int main()
{
    inicializar_arreglo();
    posicion_inicial();
    menu();

}
void menu()
{
    printf("\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\ \n ");
    printf("\\\\                                              \\\\\n");
    printf("\\\\         BIENVENIDO AL AJEDREZ                \\\\\n");
    printf("\\\\   Menu:                                      \\\\\n");
    printf("\\\\   A)Partida Rapida.                          \\\\\n");
    printf("\\\\   B)Partidas Toneo.                          \\\\\n");
    printf("\\\\   C)Mejores 100.                             \\\\\n");
    printf("\\\\   D)Continuar Partidas                       \\\\\n");
    printf("\\\\   E)Agregar jugador.                         \\\\\n");
    printf("\\\\                                              \\\\\n");
    printf("\\\\                                              \\\\\n");
    printf("\\\\                                              \\\\\n");
    printf("\\\\                                              \\\\\n");
    printf("\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\ \n ");
    char x;
    scanf(" %c",&x);
    system("cls");
    switch(x)
    {
    case 'a':
        {
            juego();
            break;
        }
    case 'b':
        {
            juego_nombre();
            break;

        }
    case 'c':
        {
            score();
            break;

        }
    case 'd':
        {
            juego();
            break;


        }
    case 'e':
        {
            agregar_jugador();
            break;

        }

    }
}
int agregar_jugador()
{
    system("cls");
    printf("Digite el nombre del jugador \n");
    scanf("%s",jugadores[n_jugadores].nombre);
    guardar_archivo_texto(jugadores,n_jugadores);
    printf("Jugador registrado \n");
    system("pause");
    system("cls");
    n_jugadores++;
    menu();

}
void juego_nombre()
{
    int i_inicial, j_inicial,turno=0;
    int i_final,j_final,aux,ganar;
    char help;
    do
    {
        imprimir_tablero();
        imprimir_jugador(turno);
        leer_jugada(&i_inicial,&j_inicial,&i_final,&j_final,turno);
        aux=validar_(i_inicial,j_inicial,i_final,j_final,turno);
        if(aux==1)
        {
            mover_pieza(i_inicial,j_inicial,i_final,j_final);
            ganar=lee_ganador();
            if(ganar==1)
                turno=2;
            if(ganar==0)
                turno=1-turno;

        }
        else if((aux==-1)&&(turno==0))
        {
            do
            {
                printf("\nDigite la pieza por la que desea sustituir \n");
                scanf(" %c",&help);
                if(help=='t'||help=='c'||help=='a'||help=='r'||help=='d'||help=='c')
                {
                    tablero[i_final][j_final]=help;
                    turno=1-turno;
                    break;
                }
            }
            while(help!='t'||help!='c'||help!='a'||help!='r'||help!='d'||help!='c');

        }
        else if((aux==-1)&&(turno==1))
        {
            do
            {
                printf("\nDigite la pieza por la que desea sustituir \n");
                scanf(" %c",&help);
                if(help=='T'||help=='C'||help=='A'||help=='R'||help=='D')
                {
                    tablero[i_final][j_final]=help;
                    turno=1-turno;
                    break;
                }
            }
            while(help!='T'||help!='C'||help!='A'||help!='R'||help!='D');

        }
        else if(aux==0)
        {
            printf("\njugada no valida");
        }

    }
    while(turno!=2);
}
void juego()
{
    int i_inicial, j_inicial,turno=0;
    int i_final,j_final,aux,ganar;
    char help;
    do
    {
        imprimir_tablero();
        imprimir_jugador(turno);
        leer_jugada(&i_inicial,&j_inicial,&i_final,&j_final,turno);
        aux=validar_(i_inicial,j_inicial,i_final,j_final,turno);
        if(aux==1)
        {
            mover_pieza(i_inicial,j_inicial,i_final,j_final);
            ganar=lee_ganador();
            if(ganar==1)
                turno=2;
            if(ganar==0)
                turno=1-turno;

        }
        else if((aux==-1)&&(turno==0))
        {
            do
            {
                printf("\nDigite la pieza por la que desea sustituir \n");
                scanf(" %c",&help);
                if(help=='t'||help=='c'||help=='a'||help=='r'||help=='d'||help=='c')
                {
                    tablero[i_final][j_final]=help;
                    turno=1-turno;
                    break;
                }
            }
            while(help!='t'||help!='c'||help!='a'||help!='r'||help!='d'||help!='c');

        }
        else if((aux==-1)&&(turno==1))
        {
            do
            {
                printf("\nDigite la pieza por la que desea sustituir \n");
                scanf(" %c",&help);
                if(help=='T'||help=='C'||help=='A'||help=='R'||help=='D')
                {
                    tablero[i_final][j_final]=help;
                    turno=1-turno;
                    break;
                }
            }
            while(help!='T'||help!='C'||help!='A'||help!='R'||help!='D');

        }
        else if(aux==0)
        {
            printf("\njugada no valida");
        }

    }
    while(turno!=2);
}

int validar_(int i_inicial,int j_inicial,int i_final,int j_final,int turno)
{
    if((i_inicial>7)||(i_inicial<0)||(j_inicial>7)||(j_inicial<0)||(i_final>7)|| (i_final<0)||(j_final>7)||(j_final<0))
        return 0;
    if((tablero[i_inicial][j_inicial]=='d')&&(turno==0))
        return confirmar_dama_blanca(i_inicial,j_inicial,i_final,j_final);

    if((tablero[i_inicial][j_inicial]=='D')&&(turno==1))
        return confirmar_dama_negra(i_inicial,j_inicial,i_final,j_final);

    if((tablero[i_inicial][j_inicial]=='t')&&(turno==0))
        return confirmar_torre_blanca(i_inicial,j_inicial,i_final,j_final);

    if((tablero[i_inicial][j_inicial]=='T')&&(turno==1))
        return confirmar_torre_negra(i_inicial,j_inicial,i_final,j_final);

    if((tablero[i_inicial][j_inicial]=='A')&&(turno==1))
        return confirmar_alfil_negro(i_inicial,j_inicial,i_final,j_final);

    if((tablero[i_inicial][j_inicial]=='a')&&(turno==0))
        return confirmar_alfil_blanco(i_inicial,j_inicial,i_final,j_final);


    if((tablero[i_inicial][j_inicial]=='c')&&(turno==0))
        return confirmar_caballo_blanco(i_inicial,j_inicial,i_final,j_final);

    if((tablero[i_inicial][j_inicial]=='C')&&(turno==1))
        return confirmar_caballo_negro(i_inicial,j_inicial,i_final,j_final);



    if((tablero[i_inicial][j_inicial]=='r')&&(turno==0))
        return confirmar_rey_blanco(i_inicial,j_inicial,i_final,j_final);

    if((tablero[i_inicial][j_inicial]=='R')&&(turno==1))
        return confirmar_rey_negro(i_inicial,j_inicial,i_final,j_final);


    if((tablero[i_inicial][j_inicial]=='p')&&(turno==0))
        return confirmar_peon_blanco(i_inicial,j_inicial,i_final,j_final);

    if((tablero[i_inicial][j_inicial]=='P')&&(turno==1))
        return confirmar_peon_negro(i_inicial,j_inicial,i_final,j_final);
    return 0;

}

int confirmar_dama_negra(int i_inicial,int j_inicial,int i_final,int j_final)
{
    int i,arriba,abajo,izq,dere;
    int izq_arr,izq_abj,dere_arr,dere_abajo;

    izq_arr=cal_izq_arr_negra(i_inicial,j_inicial);
    izq_abj=cal_izq_abj_negra(i_inicial,j_inicial);
    dere_arr=cal_dere_arr_negra(i_inicial,j_inicial);
    dere_abajo=cal_dere_abj_negra(i_inicial,j_inicial);

    arriba=cal_arriba_negras(i_inicial, j_inicial);
    dere=cal_derecha_negras(i_inicial,j_inicial);
    izq=cal_izq_negras(i_inicial,j_inicial);
    abajo=cal_abajo_negras(i_inicial,j_inicial);


    for(i=1; i<izq; i++)
    {
        if(((i_inicial)==(i_final)&&((j_inicial-i)==j_final))&&(tablero[i_final][j_final]=='P'))
            return 0;
        if(((i_inicial)==(i_final)&&((j_inicial-i)==j_final))&&(tablero[i_final][j_final]=='R'))
            return 0;
        if(((i_inicial)==(i_final)&&((j_inicial-i)==j_final))&&(tablero[i_final][j_final]=='T'))
            return 0;
        if(((i_inicial)==(i_final)&&((j_inicial-i)==j_final))&&(tablero[i_final][j_final]=='A'))
            return 0;
        if(((i_inicial)==(i_final)&&((j_inicial-i)==j_final))&&(tablero[i_final][j_final]=='C'))
            return 0;
        if(((i_inicial)==(i_final)&&((j_inicial-i)==j_final))&&(tablero[i_final][j_final]=='D'))
            return 0;
    }
    for(i=1; i<dere; i++)
    {
        if(((i_inicial)==(i_final)&&((j_inicial+i)==j_final))&&(tablero[i_final][j_final]=='P'))
            return 0;
        if(((i_inicial)==(i_final)&&((j_inicial+i)==j_final))&&(tablero[i_final][j_final]=='R'))
            return 0;
        if(((i_inicial)==(i_final)&&((j_inicial+i)==j_final))&&(tablero[i_final][j_final]=='T'))
            return 0;
        if(((i_inicial)==(i_final)&&((j_inicial+i)==j_final))&&(tablero[i_final][j_final]=='A'))
            return 0;
        if(((i_inicial)==(i_final)&&((j_inicial+i)==j_final))&&(tablero[i_final][j_final]=='C'))
            return 0;
        if(((i_inicial)==(i_final)&&((j_inicial+i)==j_final))&&(tablero[i_final][j_final]=='D'))
            return 0;
    }

    for(i=1; i<arriba; i++)
    {
        if(((i_inicial-i)==(i_final)&&(j_inicial==j_final))&&(tablero[i_final][j_final]=='P'))
            return 0;
        if(((i_inicial-i)==(i_final)&&(j_inicial==j_final))&&(tablero[i_final][j_final]=='R'))
            return 0;
        if(((i_inicial-i)==(i_final)&&(j_inicial==j_final))&&(tablero[i_final][j_final]=='T'))
            return 0;
        if(((i_inicial-i)==(i_final)&&(j_inicial==j_final))&&(tablero[i_final][j_final]=='A'))
            return 0;
        if(((i_inicial-i)==(i_final)&&(j_inicial==j_final))&&(tablero[i_final][j_final]=='C'))
            return 0;
        if(((i_inicial-i)==(i_final)&&(j_inicial==j_final))&&(tablero[i_final][j_final]=='D'))
            return 0;
    }
    for(i=1; i<abajo; i++)
    {
        if(((i_inicial+i)==(i_final)&&(j_inicial==j_final))&&(tablero[i_final][j_final]=='P'))
            return 0;
        if(((i_inicial+i)==(i_final)&&(j_inicial==j_final))&&(tablero[i_final][j_final]=='R'))
            return 0;
        if(((i_inicial+i)==(i_final)&&(j_inicial==j_final))&&(tablero[i_final][j_final]=='T'))
            return 0;
        if(((i_inicial+i)==(i_final)&&(j_inicial==j_final))&&(tablero[i_final][j_final]=='A'))
            return 0;
        if(((i_inicial+i)==(i_final)&&(j_inicial==j_final))&&(tablero[i_final][j_final]=='C'))
            return 0;
        if(((i_inicial+i)==(i_final)&&(j_inicial==j_final))&&(tablero[i_final][j_final]=='D'))
            return 0;
    }
    for(i=1; i<izq; i++)
    {
        if((i_inicial)==(i_final)&&((j_inicial-i)==j_final))
            return 1;
    }
    for(i=1; i<dere; i++)
    {
        if((i_inicial)==(i_final)&&((j_inicial+i)==j_final))
            return 1;
    }
    for(i=1; i<arriba; i++)
    {
        if((i_inicial-i)==(i_final)&&((j_inicial)==j_final))
            return 1;
    }
    for(i=1; i<abajo; i++)
    {
        if((i_inicial+i)==(i_final)&&((j_inicial)==j_final))
            return 1;
    }


    for(i=1; i<dere_abajo; i++)
    {
        if(((i_inicial+i)==(i_final)&&(j_inicial+i)==j_final)&&(tablero[i_final][j_final]=='P'))
            return 0;
        if(((i_inicial+i)==(i_final)&&(j_inicial+i)==j_final)&&(tablero[i_final][j_final]=='R'))
            return 0;
        if(((i_inicial+i)==(i_final)&&(j_inicial+i)==j_final)&&(tablero[i_final][j_final]=='T'))
            return 0;
        if(((i_inicial+i)==(i_final)&&(j_inicial+i)==j_final)&&(tablero[i_final][j_final]=='A'))
            return 0;
        if(((i_inicial+i)==(i_final)&&(j_inicial+i)==j_final)&&(tablero[i_final][j_final]=='C'))
            return 0;
        if(((i_inicial+i)==(i_final)&&(j_inicial+i)==j_final)&&(tablero[i_final][j_final]=='D'))
            return 0;
    }
    for(i=1; i<izq_arr; i++)
    {
        if(((i_inicial-i)==(i_final)&&(j_inicial-i)==j_final)&&(tablero[i_final][j_final]=='P'))
            return 0;
        if(((i_inicial-i)==(i_final)&&(j_inicial-i)==j_final)&&(tablero[i_final][j_final]=='R'))
            return 0;
        if(((i_inicial-i)==(i_final)&&(j_inicial-i)==j_final)&&(tablero[i_final][j_final]=='T'))
            return 0;
        if(((i_inicial-i)==(i_final)&&(j_inicial-i)==j_final)&&(tablero[i_final][j_final]=='A'))
            return 0;
        if(((i_inicial-i)==(i_final)&&(j_inicial-i)==j_final)&&(tablero[i_final][j_final]=='C'))
            return 0;
        if(((i_inicial-i)==(i_final)&&(j_inicial-i)==j_final)&&(tablero[i_final][j_final]=='D'))
            return 0;
    }
    for(i=1; i<dere_arr; i++)
    {
        if(((i_inicial-i)==(i_final)&&(j_inicial+i)==j_final)&&(tablero[i_final][j_final]=='P'))
            return 0;
        if(((i_inicial-i)==(i_final)&&(j_inicial+i)==j_final)&&(tablero[i_final][j_final]=='R'))
            return 0;
        if(((i_inicial-i)==(i_final)&&(j_inicial+i)==j_final)&&(tablero[i_final][j_final]=='T'))
            return 0;
        if(((i_inicial-i)==(i_final)&&(j_inicial+i)==j_final)&&(tablero[i_final][j_final]=='A'))
            return 0;
        if(((i_inicial-i)==(i_final)&&(j_inicial+i)==j_final)&&(tablero[i_final][j_final]=='C'))
            return 0;
        if(((i_inicial-i)==(i_final)&&(j_inicial+i)==j_final)&&(tablero[i_final][j_final]=='D'))
            return 0;
    }
    for( i=1; i<izq_abj; i++)
    {
        if(((i_inicial+i)==(i_final)&&(j_inicial-i)==j_final)&&(tablero[i_final][j_final]=='P'))
            return 0;
        if(((i_inicial+i)==(i_final)&&(j_inicial-i)==j_final)&&(tablero[i_final][j_final]=='R'))
            return 0;
        if(((i_inicial+i)==(i_final)&&(j_inicial-i)==j_final)&&(tablero[i_final][j_final]=='T'))
            return 0;
        if(((i_inicial+i)==(i_final)&&(j_inicial-i)==j_final)&&(tablero[i_final][j_final]=='A'))
            return 0;
        if(((i_inicial+i)==(i_final)&&(j_inicial-i)==j_final)&&(tablero[i_final][j_final]=='C'))
            return 0;
        if(((i_inicial+i)==(i_final)&&(j_inicial-i)==j_final)&&(tablero[i_final][j_final]=='D'))
            return 0;
    }
    for(i=1; i<izq_arr; i++)
    {
        if((i_inicial-i)==(i_final)&&(j_inicial-i)==j_final)
            return 1;
    }
    for(i=1; i<dere_abajo; i++)
    {
        if((i_inicial+i)==i_final&&(j_inicial+i)==j_final)
            return 1;
    }
    for(i=1; i<izq_abj; i++)
    {
        if((i_inicial+i)==(i_final)&&(j_inicial-i)==j_final)
            return 1;
    }
    for(i=1; i<dere_arr; i++)
    {
        if((i_inicial-i)==i_final&&(j_inicial+i)==j_final)
            return 1;
    }

    return i;
}
int cal_izq_negras(int i_inicial,int j_inicial)
{
    //pocicion del limite conseguir
    int i;
    for(i=1; i<7; i++)
    {
        if(tablero[i_inicial][j_inicial-i]=='P')
            return i;
        if(tablero[i_inicial][j_inicial-i]=='A')
            return i;
        if(tablero[i_inicial][j_inicial-i]=='R')
            return i;
        if(tablero[i_inicial][j_inicial-i]=='D')
            return i;
        if(tablero[i_inicial][j_inicial-i]=='T')
            return i;
        if(tablero[i_inicial][j_inicial-i]=='C')
            return i;

        if(tablero[i_inicial][j_inicial-i]=='p')
            return i+1;
        if(tablero[i_inicial][j_inicial-i]=='a')
            return i+1;
        if(tablero[i_inicial][j_inicial-i]=='r')
            return i+1;
        if(tablero[i_inicial][j_inicial-i]=='d')
            return i+1;
        if(tablero[i_inicial][j_inicial-i]=='t')
            return i+1;
        if(tablero[i_inicial][j_inicial-i]=='c')
            return i+1;
    }
    return i;
}
int cal_derecha_negras(int i_inicial,int j_inicial)
{
    //pocicion del limite conseguir
    int i;
    for(i=1; i<7; i++)
    {
        if(tablero[i_inicial][j_inicial+i]=='P')
            return i;
        if(tablero[i_inicial][j_inicial+i]=='A')
            return i;
        if(tablero[i_inicial][j_inicial+i]=='R')
            return i;
        if(tablero[i_inicial][j_inicial+i]=='D')
            return i;
        if(tablero[i_inicial][j_inicial+i]=='T')
            return i;
        if(tablero[i_inicial][j_inicial+i]=='C')
            return i;

        if(tablero[i_inicial][j_inicial+i]=='p')
            return i+1;
        if(tablero[i_inicial][j_inicial+i]=='a')
            return i+1;
        if(tablero[i_inicial][j_inicial+i]=='r')
            return i+1;
        if(tablero[i_inicial][j_inicial+i]=='d')
            return i+1;
        if(tablero[i_inicial][j_inicial+i]=='t')
            return i+1;
        if(tablero[i_inicial][j_inicial+i]=='c')
            return i+1;
    }
    return i;
}
int cal_izq_blancas(int i_inicial,int j_inicial)
{
    //pocicion del limite conseguir
    int i;
    for(i=1; i<7; i++)
    {
        if(tablero[i_inicial][j_inicial-i]=='p')
            return i;
        if(tablero[i_inicial][j_inicial-i]=='a')
            return i;
        if(tablero[i_inicial][j_inicial-i]=='r')
            return i;
        if(tablero[i_inicial][j_inicial-i]=='d')
            return i;
        if(tablero[i_inicial][j_inicial-i]=='t')
            return i;
        if(tablero[i_inicial][j_inicial-i]=='c')
            return i;

        if(tablero[i_inicial][j_inicial-i]=='P')
            return i+1;
        if(tablero[i_inicial][j_inicial-i]=='A')
            return i+1;
        if(tablero[i_inicial][j_inicial-i]=='R')
            return i+1;
        if(tablero[i_inicial][j_inicial-i]=='D')
            return i+1;
        if(tablero[i_inicial][j_inicial-i]=='T')
            return i+1;
        if(tablero[i_inicial][j_inicial-i]=='C')
            return i+1;
    }
    return i;
}
int cal_derecha_blancas(int i_inicial,int j_inicial)
{
    //pocicion del limite conseguir
    int i;
    for(i=1; i<7; i++)
    {
        if(tablero[i_inicial][j_inicial+i]=='p')
            return i;
        if(tablero[i_inicial][j_inicial+i]=='a')
            return i;
        if(tablero[i_inicial][j_inicial+i]=='r')
            return i;
        if(tablero[i_inicial][j_inicial+i]=='d')
            return i;
        if(tablero[i_inicial][j_inicial+i]=='t')
            return i;
        if(tablero[i_inicial][j_inicial+i]=='c')
            return i;

        if(tablero[i_inicial][j_inicial+i]=='P')
            return i+1;
        if(tablero[i_inicial][j_inicial+i]=='A')
            return i+1;
        if(tablero[i_inicial][j_inicial+i]=='R')
            return i+1;
        if(tablero[i_inicial][j_inicial+i]=='D')
            return i+1;
        if(tablero[i_inicial][j_inicial+i]=='T')
            return i+1;
        if(tablero[i_inicial][j_inicial+i]=='C')
            return i+1;
    }
    return i;
}
int cal_abajo_blancas(int i_inicial,int j_inicial)
{
    //pocicion del limite conseguir
    int i;
    for(i=1; i<7; i++)
    {
        if(tablero[i_inicial+i][j_inicial]=='p')
            return i;
        if(tablero[i_inicial+i][j_inicial]=='a')
            return i;
        if(tablero[i_inicial+i][j_inicial]=='r')
            return i;
        if(tablero[i_inicial+i][j_inicial]=='d')
            return i;
        if(tablero[i_inicial+i][j_inicial]=='t')
            return i;
        if(tablero[i_inicial+i][j_inicial]=='c')
            return i;

        if(tablero[i_inicial+i][j_inicial]=='P')
            return i+1;
        if(tablero[i_inicial+i][j_inicial]=='A')
            return i+1;
        if(tablero[i_inicial+i][j_inicial]=='R')
            return i+1;
        if(tablero[i_inicial+i][j_inicial]=='D')
            return i+1;
        if(tablero[i_inicial+i][j_inicial]=='T')
            return i+1;
        if(tablero[i_inicial+i][j_inicial]=='C')
            return i+1;
    }
    return i;
}
int cal_arriba_blancas(int i_inicial,int j_inicial)
{
    int i;
    for( i=1; i<7; i++)
    {
        if(tablero[i_inicial-i][j_inicial]=='p')
            return i;
        if(tablero[i_inicial-i][j_inicial]=='a')
            return i;
        if(tablero[i_inicial-i][j_inicial]=='r')
            return i;
        if(tablero[i_inicial-i][j_inicial]=='d')
            return i;
        if(tablero[i_inicial-i][j_inicial]=='t')
            return i;
        if(tablero[i_inicial-i][j_inicial]=='c')
            return i;

        if(tablero[i_inicial-i][j_inicial]=='P')
            return i+1;
        if(tablero[i_inicial-i][j_inicial]=='A')
            return i+1;
        if(tablero[i_inicial-i][j_inicial]=='R')
            return i+1;
        if(tablero[i_inicial-i][j_inicial]=='D')
            return i+1;
        if(tablero[i_inicial-i][j_inicial]=='T')
            return i+1;
        if(tablero[i_inicial-i][j_inicial]=='C')
            return i+1;
    }
    return i;
}
int cal_abajo_negras(int i_inicial,int j_inicial)
{
    //pocicion del limite conseguir
    int i;
    for( i=1; i<7; i++)
    {
        if(tablero[i_inicial+i][j_inicial]=='P')
            return i-1;
        if(tablero[i_inicial+i][j_inicial]=='A')
            return i-1;
        if(tablero[i_inicial+i][j_inicial]=='R')
            return i-1;
        if(tablero[i_inicial+i][j_inicial]=='D')
            return i-1;
        if(tablero[i_inicial+i][j_inicial]=='T')
            return i-1;
        if(tablero[i_inicial+i][j_inicial]=='C')
            return i-1;

        if(tablero[i_inicial+i][j_inicial]=='p')
            return i;
        if(tablero[i_inicial+i][j_inicial]=='a')
            return i;
        if(tablero[i_inicial+i][j_inicial]=='r')
            return i;
        if(tablero[i_inicial+i][j_inicial]=='d')
            return i;
        if(tablero[i_inicial+i][j_inicial]=='t')
            return i;
        if(tablero[i_inicial+i][j_inicial]=='c')
            return i;
    }
    return i;
}

int cal_arriba_negras(int i_inicial,int j_inicial)
{
    //pocicion del limite conseguir
    int i;
    for( i=1; i<7; i++)
    {
        if(tablero[i_inicial-i][j_inicial]=='P')
            return i;
        if(tablero[i_inicial-i][j_inicial]=='A')
            return i;
        if(tablero[i_inicial-i][j_inicial]=='R')
            return i;
        if(tablero[i_inicial-i][j_inicial]=='D')
            return i;
        if(tablero[i_inicial-i][j_inicial]=='T')
            return i;
        if(tablero[i_inicial-i][j_inicial]=='C')
            return i;

        if(tablero[i_inicial][j_inicial-i]=='p')
            return i+1;
        if(tablero[i_inicial][j_inicial-i]=='a')
            return i+1;
        if(tablero[i_inicial][j_inicial-i]=='r')
            return i+1;
        if(tablero[i_inicial][j_inicial-i]=='d')
            return i+1;
        if(tablero[i_inicial][j_inicial-i]=='t')
            return i+1;
        if(tablero[i_inicial][j_inicial-i]=='c')
            return i+1;
    }
    return i;
}
void enroque_corto_blanco()
{
    tablero[0][0]='.';
    tablero[0][1]='r';
    tablero[0][2]='t';
    tablero[0][4]='.';

}
void enroque_largo_blanco()
{
    tablero[0][7]='.';
    tablero[0][6]='.';
    tablero[0][5]='r';
    tablero[0][4]='t';

}
void enroque_corto_negro()
{
    tablero[7][0]='.';
    tablero[7][1]='R';
    tablero[7][2]='T';
    tablero[7][4]='.';

}
void enroque_largo_negro()
{
    tablero[7][7]='.';
    tablero[7][6]='.';
    tablero[7][5]='R';
    tablero[7][4]='T';

}
int confirmar_torre_blanca(int i_inicial,int j_inicial,int i_final,int j_final)
{
    int i,arriba,abajo,izq,dere;
    arriba=cal_arriba_blancas(i_inicial, j_inicial);
    dere=cal_derecha_blancas(i_inicial,j_inicial);
    izq=cal_izq_blancas(i_inicial,j_inicial);
    abajo=cal_abajo_blancas(i_inicial,j_inicial);

    for(i=1; i<izq; i++)
    {
        if(((i_inicial)==(i_final)&&((j_inicial-i)==j_final))&&(tablero[i_final][j_final]=='p'))
            return 0;
        if(((i_inicial)==(i_final)&&((j_inicial-i)==j_final))&&(tablero[i_final][j_final]=='r'))
            return 0;
        if(((i_inicial)==(i_final)&&((j_inicial-i)==j_final))&&(tablero[i_final][j_final]=='t'))
            return 0;
        if(((i_inicial)==(i_final)&&((j_inicial-i)==j_final))&&(tablero[i_final][j_final]=='a'))
            return 0;
        if(((i_inicial)==(i_final)&&((j_inicial-i)==j_final))&&(tablero[i_final][j_final]=='c'))
            return 0;
        if(((i_inicial)==(i_final)&&((j_inicial-i)==j_final))&&(tablero[i_final][j_final]=='d'))
            return 0;
    }
    for(i=1; i<dere; i++)
    {
        if(((i_inicial)==(i_final)&&((j_inicial+i)==j_final))&&(tablero[i_final][j_final]=='p'))
            return 0;
        if(((i_inicial)==(i_final)&&((j_inicial+i)==j_final))&&(tablero[i_final][j_final]=='r'))
            return 0;
        if(((i_inicial)==(i_final)&&((j_inicial+i)==j_final))&&(tablero[i_final][j_final]=='t'))
            return 0;
        if(((i_inicial)==(i_final)&&((j_inicial+i)==j_final))&&(tablero[i_final][j_final]=='a'))
            return 0;
        if(((i_inicial)==(i_final)&&((j_inicial+i)==j_final))&&(tablero[i_final][j_final]=='c'))
            return 0;
        if(((i_inicial)==(i_final)&&((j_inicial+i)==j_final))&&(tablero[i_final][j_final]=='d'))
            return 0;
    }

    for(i=1; i<arriba; i++)
    {
        if(((i_inicial-i)==(i_final)&&(j_inicial==j_final))&&(tablero[i_final][j_final]=='p'))
            return 0;
        if(((i_inicial-i)==(i_final)&&(j_inicial==j_final))&&(tablero[i_final][j_final]=='r'))
            return 0;
        if(((i_inicial-i)==(i_final)&&(j_inicial==j_final))&&(tablero[i_final][j_final]=='t'))
            return 0;
        if(((i_inicial-i)==(i_final)&&(j_inicial==j_final))&&(tablero[i_final][j_final]=='a'))
            return 0;
        if(((i_inicial-i)==(i_final)&&(j_inicial==j_final))&&(tablero[i_final][j_final]=='c'))
            return 0;
        if(((i_inicial-i)==(i_final)&&(j_inicial==j_final))&&(tablero[i_final][j_final]=='d'))
            return 0;
    }
    for(i=1; i<abajo; i++)
    {
        if(((i_inicial+i)==(i_final)&&(j_inicial==j_final))&&(tablero[i_final][j_final]=='p'))
            return 0;
        if(((i_inicial+i)==(i_final)&&(j_inicial==j_final))&&(tablero[i_final][j_final]=='r'))
            return 0;
        if(((i_inicial+i)==(i_final)&&(j_inicial==j_final))&&(tablero[i_final][j_final]=='t'))
            return 0;
        if(((i_inicial+i)==(i_final)&&(j_inicial==j_final))&&(tablero[i_final][j_final]=='a'))
            return 0;
        if(((i_inicial+i)==(i_final)&&(j_inicial==j_final))&&(tablero[i_final][j_final]=='c'))
            return 0;
        if(((i_inicial+i)==(i_final)&&(j_inicial==j_final))&&(tablero[i_final][j_final]=='d'))
            return 0;
    }
    for(i=1; i<izq; i++)
    {
        if((i_inicial)==(i_final)&&((j_inicial-i)==j_final))
            return 1;
    }
    for(i=1; i<dere; i++)
    {
        if((i_inicial)==(i_final)&&((j_inicial+i)==j_final))
            return 1;
    }
    for(i=1; i<arriba; i++)
    {
        if((i_inicial-i)==(i_final)&&((j_inicial)==j_final))
            return 1;
    }
    for(i=1; i<abajo; i++)
    {
        if((i_inicial+i)==(i_final)&&((j_inicial)==j_final))
            return 1;
    }
    return 0;
}
int confirmar_torre_negra(int i_inicial,int j_inicial,int i_final,int j_final)
{
    int i,arriba,abajo,izq,dere;
    arriba=cal_arriba_negras(i_inicial, j_inicial);
    dere=cal_derecha_negras(i_inicial,j_inicial);
    izq=cal_izq_negras(i_inicial,j_inicial);
    abajo=cal_abajo_negras(i_inicial,j_inicial);

    for(i=1; i<izq; i++)
    {
        if(((i_inicial)==(i_final)&&((j_inicial-i)==j_final))&&(tablero[i_final][j_final]=='P'))
            return 0;
        if(((i_inicial)==(i_final)&&((j_inicial-i)==j_final))&&(tablero[i_final][j_final]=='R'))
            return 0;
        if(((i_inicial)==(i_final)&&((j_inicial-i)==j_final))&&(tablero[i_final][j_final]=='T'))
            return 0;
        if(((i_inicial)==(i_final)&&((j_inicial-i)==j_final))&&(tablero[i_final][j_final]=='A'))
            return 0;
        if(((i_inicial)==(i_final)&&((j_inicial-i)==j_final))&&(tablero[i_final][j_final]=='C'))
            return 0;
        if(((i_inicial)==(i_final)&&((j_inicial-i)==j_final))&&(tablero[i_final][j_final]=='D'))
            return 0;
    }
    for(i=1; i<dere; i++)
    {
        if(((i_inicial)==(i_final)&&((j_inicial+i)==j_final))&&(tablero[i_final][j_final]=='P'))
            return 0;
        if(((i_inicial)==(i_final)&&((j_inicial+i)==j_final))&&(tablero[i_final][j_final]=='R'))
            return 0;
        if(((i_inicial)==(i_final)&&((j_inicial+i)==j_final))&&(tablero[i_final][j_final]=='T'))
            return 0;
        if(((i_inicial)==(i_final)&&((j_inicial+i)==j_final))&&(tablero[i_final][j_final]=='A'))
            return 0;
        if(((i_inicial)==(i_final)&&((j_inicial+i)==j_final))&&(tablero[i_final][j_final]=='C'))
            return 0;
        if(((i_inicial)==(i_final)&&((j_inicial+i)==j_final))&&(tablero[i_final][j_final]=='D'))
            return 0;
    }

    for(i=1; i<arriba; i++)
    {
        if(((i_inicial-i)==(i_final)&&(j_inicial==j_final))&&(tablero[i_final][j_final]=='P'))
            return 0;
        if(((i_inicial-i)==(i_final)&&(j_inicial==j_final))&&(tablero[i_final][j_final]=='R'))
            return 0;
        if(((i_inicial-i)==(i_final)&&(j_inicial==j_final))&&(tablero[i_final][j_final]=='T'))
            return 0;
        if(((i_inicial-i)==(i_final)&&(j_inicial==j_final))&&(tablero[i_final][j_final]=='A'))
            return 0;
        if(((i_inicial-i)==(i_final)&&(j_inicial==j_final))&&(tablero[i_final][j_final]=='C'))
            return 0;
        if(((i_inicial-i)==(i_final)&&(j_inicial==j_final))&&(tablero[i_final][j_final]=='D'))
            return 0;
    }
    for(i=1; i<abajo; i++)
    {
        if(((i_inicial+i)==(i_final)&&(j_inicial==j_final))&&(tablero[i_final][j_final]=='P'))
            return 0;
        if(((i_inicial+i)==(i_final)&&(j_inicial==j_final))&&(tablero[i_final][j_final]=='R'))
            return 0;
        if(((i_inicial+i)==(i_final)&&(j_inicial==j_final))&&(tablero[i_final][j_final]=='T'))
            return 0;
        if(((i_inicial+i)==(i_final)&&(j_inicial==j_final))&&(tablero[i_final][j_final]=='A'))
            return 0;
        if(((i_inicial+i)==(i_final)&&(j_inicial==j_final))&&(tablero[i_final][j_final]=='C'))
            return 0;
        if(((i_inicial+i)==(i_final)&&(j_inicial==j_final))&&(tablero[i_final][j_final]=='D'))
            return 0;
    }
    for(i=1; i<izq; i++)
    {
        if((i_inicial)==(i_final)&&((j_inicial-i)==j_final))
            return 1;
    }
    for(i=1; i<dere; i++)
    {
        if((i_inicial)==(i_final)&&((j_inicial+i)==j_final))
            return 1;
    }
    for(i=1; i<arriba; i++)
    {
        if((i_inicial-i)==(i_final)&&((j_inicial)==j_final))
            return 1;
    }
    for(i=1; i<abajo; i++)
    {
        if((i_inicial+i)==(i_final)&&((j_inicial)==j_final))
            return 1;
    }
    return 0;
}
int cal_dere_abj_negra(int i_inicial,int j_inicial)
{
    int i;
    for(i=1; i<7; i++)
    {
        if(tablero[i_inicial+i][j_inicial+i]=='P')
            return i;
        if(tablero[i_inicial+i][j_inicial+i]=='A')
            return i;
        if(tablero[i_inicial+i][j_inicial+i]=='R')
            return i;
        if(tablero[i_inicial+i][j_inicial+i]=='D')
            return i;
        if(tablero[i_inicial+i][j_inicial+i]=='T')
            return i;
        if(tablero[i_inicial+i][j_inicial+i]=='C')
            return i;

        if(tablero[i_inicial+i][j_inicial+i]=='p')
            return i+1;
        if(tablero[i_inicial+i][j_inicial+i]=='a')
            return i+1;
        if(tablero[i_inicial+i][j_inicial+i]=='r')
            return i+1;
        if(tablero[i_inicial+i][j_inicial+i]=='d')
            return i+1;
        if(tablero[i_inicial+i][j_inicial+i]=='t')
            return i+1;
        if(tablero[i_inicial+i][j_inicial+i]=='c')
            return i+1;
    }
    return i;
}
int cal_dere_arr_negra(int i_inicial,int j_inicial)
{
    int i;
    for( i=1; i<7; i++)
    {
        if(tablero[i_inicial-i][j_inicial+i]=='P')
            return i;
        if(tablero[i_inicial-i][j_inicial+i]=='A')
            return i;
        if(tablero[i_inicial-i][j_inicial+i]=='R')
            return i;
        if(tablero[i_inicial-i][j_inicial+i]=='D')
            return i;
        if(tablero[i_inicial-i][j_inicial+i]=='T')
            return i;
        if(tablero[i_inicial-i][j_inicial+i]=='C')
            return i;

        if(tablero[i_inicial-i][j_inicial+i]=='p')
            return i+1;
        if(tablero[i_inicial-i][j_inicial+i]=='a')
            return i+1;
        if(tablero[i_inicial-i][j_inicial+i]=='r')
            return i+1;
        if(tablero[i_inicial-i][j_inicial+i]=='d')
            return i+1;
        if(tablero[i_inicial-i][j_inicial+i]=='t')
            return i+1;
        if(tablero[i_inicial-i][j_inicial+i]=='c')
            return i+1;
    }
    return i;
}
int cal_izq_abj_negra(int i_inicial,int j_inicial)
{
    int i;
    for(i=1; i<7; i++)
    {
        if(tablero[i_inicial+i][j_inicial-i]=='P')
            return i;
        if(tablero[i_inicial+i][j_inicial-i]=='A')
            return i;
        if(tablero[i_inicial+i][j_inicial-i]=='R')
            return i;
        if(tablero[i_inicial+i][j_inicial-i]=='D')
            return i;
        if(tablero[i_inicial+i][j_inicial-i]=='T')
            return i;
        if(tablero[i_inicial+i][j_inicial-i]=='C')
            return i;

        if(tablero[i_inicial+i][j_inicial-i]=='p')
            return i+1;
        if(tablero[i_inicial+i][j_inicial-i]=='a')
            return i+1;
        if(tablero[i_inicial+i][j_inicial-i]=='r')
            return i+1;
        if(tablero[i_inicial+i][j_inicial-i]=='d')
            return i+1;
        if(tablero[i_inicial+i][j_inicial-i]=='t')
            return i+1;
        if(tablero[i_inicial+i][j_inicial-i]=='c')
            return i+1;
    }
    return i;
}
int cal_izq_arr_negra(int i_inicial,int j_inicial)
{
    int i;
    for(i=1; i<7; i++)
    {
        if(tablero[i_inicial-i][j_inicial-i]=='P')
            return i;
        if(tablero[i_inicial-i][j_inicial-i]=='A')
            return i;
        if(tablero[i_inicial-i][j_inicial-i]=='R')
            return i;
        if(tablero[i_inicial-i][j_inicial-i]=='D')
            return i;
        if(tablero[i_inicial-i][j_inicial-i]=='T')
            return i;
        if(tablero[i_inicial-i][j_inicial-i]=='C')
            return i;

        if(tablero[i_inicial-i][j_inicial-i]=='p')
            return i+1;
        if(tablero[i_inicial-i][j_inicial-i]=='a')
            return i+1;
        if(tablero[i_inicial-i][j_inicial-i]=='r')
            return i+1;
        if(tablero[i_inicial-i][j_inicial-i]=='d')
            return i+1;
        if(tablero[i_inicial-i][j_inicial-i]=='t')
            return i+1;
        if(tablero[i_inicial-i][j_inicial-i]=='c')
            return i+1;
    }
    return i;
}

int cal_dere_abj_blanca(int i_inicial,int j_inicial)
{
    int i;
    for(i=1; i<7; i++)
    {
        if(tablero[i_inicial+i][j_inicial+i]=='p')
            return i;
        if(tablero[i_inicial+i][j_inicial+i]=='a')
            return i;
        if(tablero[i_inicial+i][j_inicial+i]=='r')
            return i;
        if(tablero[i_inicial+i][j_inicial+i]=='d')
            return i;
        if(tablero[i_inicial+i][j_inicial+i]=='t')
            return i;
        if(tablero[i_inicial+i][j_inicial+i]=='c')
            return i;

        if(tablero[i_inicial+i][j_inicial+i]=='P')
            return i+1;
        if(tablero[i_inicial+i][j_inicial+i]=='A')
            return i+1;
        if(tablero[i_inicial+i][j_inicial+i]=='R')
            return i+1;
        if(tablero[i_inicial+i][j_inicial+i]=='D')
            return i+1;
        if(tablero[i_inicial+i][j_inicial+i]=='T')
            return i+1;
        if(tablero[i_inicial+i][j_inicial+i]=='C')
            return i+1;
    }
    return i;
}
int cal_dere_arr_blanca(int i_inicial,int j_inicial)
{
    int i;
    for( i=1; i<7; i++)
    {
        if(tablero[i_inicial-i][j_inicial+i]=='p')
            return i;
        if(tablero[i_inicial-i][j_inicial+i]=='a')
            return i;
        if(tablero[i_inicial-i][j_inicial+i]=='r')
            return i;
        if(tablero[i_inicial-i][j_inicial+i]=='d')
            return i;
        if(tablero[i_inicial-i][j_inicial+i]=='t')
            return i;
        if(tablero[i_inicial-i][j_inicial+i]=='c')
            return i;

        if(tablero[i_inicial-i][j_inicial+i]=='P')
            return i+1;
        if(tablero[i_inicial-i][j_inicial+i]=='A')
            return i+1;
        if(tablero[i_inicial-i][j_inicial+i]=='R')
            return i+1;
        if(tablero[i_inicial-i][j_inicial+i]=='D')
            return i+1;
        if(tablero[i_inicial-i][j_inicial+i]=='T')
            return i+1;
        if(tablero[i_inicial-i][j_inicial+i]=='C')
            return i+1;
    }
    return i;
}
int cal_izq_abj_blanca(int i_inicial,int j_inicial)
{
    int i;
    for( i=1; i<7; i++)
    {
        if(tablero[i_inicial+i][j_inicial-i]=='p')
            return i;
        if(tablero[i_inicial+i][j_inicial-i]=='a')
            return i;
        if(tablero[i_inicial+i][j_inicial-i]=='r')
            return i;
        if(tablero[i_inicial+i][j_inicial-i]=='d')
            return i;
        if(tablero[i_inicial+i][j_inicial-i]=='t')
            return i;
        if(tablero[i_inicial+i][j_inicial-i]=='c')
            return i;

        if(tablero[i_inicial+i][j_inicial-i]=='P')
            return i+1;
        if(tablero[i_inicial+i][j_inicial-i]=='A')
            return i+1;
        if(tablero[i_inicial+i][j_inicial-i]=='R')
            return i+1;
        if(tablero[i_inicial+i][j_inicial-i]=='D')
            return i+1;
        if(tablero[i_inicial+i][j_inicial-i]=='T')
            return i+1;
        if(tablero[i_inicial+i][j_inicial-i]=='C')
            return i+1;
    }
    return i;
}

int cal_izq_arr_blanca(int i_inicial,int j_inicial)
{
    int i;
    for( i=1; i<7; i++)
    {
        if(tablero[i_inicial-i][j_inicial-i]=='p')
            return i;
        if(tablero[i_inicial-i][j_inicial-i]=='a')
            return i;
        if(tablero[i_inicial-i][j_inicial-i]=='r')
            return i;
        if(tablero[i_inicial-i][j_inicial-i]=='d')
            return i;
        if(tablero[i_inicial-i][j_inicial-i]=='t')
            return i;
        if(tablero[i_inicial-i][j_inicial-i]=='c')
            return i;

        if(tablero[i_inicial-i][j_inicial-i]=='P')
            return i+1;
        if(tablero[i_inicial-i][j_inicial-i]=='A')
            return i+1;
        if(tablero[i_inicial-i][j_inicial-i]=='R')
            return i+1;
        if(tablero[i_inicial-i][j_inicial-i]=='D')
            return i+1;
        if(tablero[i_inicial-i][j_inicial-i]=='T')
            return i+1;
        if(tablero[i_inicial-i][j_inicial-i]=='C')
            return i+1;
    }
    return i;
}

int confirmar_alfil_negro(int i_inicial,int j_inicial,int i_final,int j_final)
{
    int i,izq_arr,izq_abj,dere_arr,dere_abajo;
    izq_arr=cal_izq_arr_negra(i_inicial,j_inicial);
    izq_abj=cal_izq_abj_negra(i_inicial,j_inicial);
    dere_arr=cal_dere_arr_negra(i_inicial,j_inicial);
    dere_abajo=cal_dere_abj_negra(i_inicial,j_inicial);

    for(i=1; i<dere_abajo; i++)
    {
        if(((i_inicial+i)==(i_final)&&(j_inicial+i)==j_final)&&(tablero[i_final][j_final]=='P'))
            return 0;
        if(((i_inicial+i)==(i_final)&&(j_inicial+i)==j_final)&&(tablero[i_final][j_final]=='R'))
            return 0;
        if(((i_inicial+i)==(i_final)&&(j_inicial+i)==j_final)&&(tablero[i_final][j_final]=='T'))
            return 0;
        if(((i_inicial+i)==(i_final)&&(j_inicial+i)==j_final)&&(tablero[i_final][j_final]=='A'))
            return 0;
        if(((i_inicial+i)==(i_final)&&(j_inicial+i)==j_final)&&(tablero[i_final][j_final]=='C'))
            return 0;
        if(((i_inicial+i)==(i_final)&&(j_inicial+i)==j_final)&&(tablero[i_final][j_final]=='D'))
            return 0;
    }
    for(i=1; i<izq_arr; i++)
    {
        if(((i_inicial-i)==(i_final)&&(j_inicial-i)==j_final)&&(tablero[i_final][j_final]=='P'))
            return 0;
        if(((i_inicial-i)==(i_final)&&(j_inicial-i)==j_final)&&(tablero[i_final][j_final]=='R'))
            return 0;
        if(((i_inicial-i)==(i_final)&&(j_inicial-i)==j_final)&&(tablero[i_final][j_final]=='T'))
            return 0;
        if(((i_inicial-i)==(i_final)&&(j_inicial-i)==j_final)&&(tablero[i_final][j_final]=='A'))
            return 0;
        if(((i_inicial-i)==(i_final)&&(j_inicial-i)==j_final)&&(tablero[i_final][j_final]=='C'))
            return 0;
        if(((i_inicial-i)==(i_final)&&(j_inicial-i)==j_final)&&(tablero[i_final][j_final]=='D'))
            return 0;
    }
    for(i=1; i<dere_arr; i++)
    {
        if(((i_inicial-i)==(i_final)&&(j_inicial+i)==j_final)&&(tablero[i_final][j_final]=='P'))
            return 0;
        if(((i_inicial-i)==(i_final)&&(j_inicial+i)==j_final)&&(tablero[i_final][j_final]=='R'))
            return 0;
        if(((i_inicial-i)==(i_final)&&(j_inicial+i)==j_final)&&(tablero[i_final][j_final]=='T'))
            return 0;
        if(((i_inicial-i)==(i_final)&&(j_inicial+i)==j_final)&&(tablero[i_final][j_final]=='A'))
            return 0;
        if(((i_inicial-i)==(i_final)&&(j_inicial+i)==j_final)&&(tablero[i_final][j_final]=='C'))
            return 0;
        if(((i_inicial-i)==(i_final)&&(j_inicial+i)==j_final)&&(tablero[i_final][j_final]=='D'))
            return 0;
    }
    for( i=1; i<izq_abj; i++)
    {
        if(((i_inicial+i)==(i_final)&&(j_inicial-i)==j_final)&&(tablero[i_final][j_final]=='P'))
            return 0;
        if(((i_inicial+i)==(i_final)&&(j_inicial-i)==j_final)&&(tablero[i_final][j_final]=='R'))
            return 0;
        if(((i_inicial+i)==(i_final)&&(j_inicial-i)==j_final)&&(tablero[i_final][j_final]=='T'))
            return 0;
        if(((i_inicial+i)==(i_final)&&(j_inicial-i)==j_final)&&(tablero[i_final][j_final]=='A'))
            return 0;
        if(((i_inicial+i)==(i_final)&&(j_inicial-i)==j_final)&&(tablero[i_final][j_final]=='C'))
            return 0;
        if(((i_inicial+i)==(i_final)&&(j_inicial-i)==j_final)&&(tablero[i_final][j_final]=='D'))
            return 0;
    }
    for(i=1; i<izq_arr; i++)
    {
        if((i_inicial-i)==(i_final)&&(j_inicial-i)==j_final)
            return 1;
    }
    for(i=1; i<dere_abajo; i++)
    {
        if((i_inicial+i)==i_final&&(j_inicial+i)==j_final)
            return 1;
    }
    for(i=1; i<izq_abj; i++)
    {
        if((i_inicial+i)==(i_final)&&(j_inicial-i)==j_final)
            return 1;
    }
    for(i=1; i<dere_arr; i++)
    {
        if((i_inicial-i)==i_final&&(j_inicial+i)==j_final)
            return 1;
    }
    return 0;
}

int confirmar_alfil_blanco(int i_inicial,int j_inicial,int i_final,int j_final)
{
    int i,izq_arr,izq_abj,dere_arr,dere_abajo;
    izq_arr=cal_izq_arr_blanca(i_inicial,j_inicial);
    izq_abj=cal_izq_abj_blanca(i_inicial,j_inicial);
    dere_arr=cal_dere_arr_blanca(i_inicial,j_inicial);
    dere_abajo=cal_dere_abj_blanca(i_inicial,j_inicial);

    for(i=1; i<dere_abajo; i++)
    {
        if(((i_inicial+i)==(i_final)&&(j_inicial+i)==j_final)&&(tablero[i_final][j_final]=='p'))
            return 0;
        if(((i_inicial+i)==(i_final)&&(j_inicial+i)==j_final)&&(tablero[i_final][j_final]=='r'))
            return 0;
        if(((i_inicial+i)==(i_final)&&(j_inicial+i)==j_final)&&(tablero[i_final][j_final]=='t'))
            return 0;
        if(((i_inicial+i)==(i_final)&&(j_inicial+i)==j_final)&&(tablero[i_final][j_final]=='a'))
            return 0;
        if(((i_inicial+i)==(i_final)&&(j_inicial+i)==j_final)&&(tablero[i_final][j_final]=='c'))
            return 0;
        if(((i_inicial+i)==(i_final)&&(j_inicial+i)==j_final)&&(tablero[i_final][j_final]=='d'))
            return 0;
    }
    for(i=1; i<izq_arr; i++)
    {
        if(((i_inicial-i)==(i_final)&&(j_inicial-i)==j_final)&&(tablero[i_final][j_final]=='p'))
            return 0;
        if(((i_inicial-i)==(i_final)&&(j_inicial-i)==j_final)&&(tablero[i_final][j_final]=='r'))
            return 0;
        if(((i_inicial-i)==(i_final)&&(j_inicial-i)==j_final)&&(tablero[i_final][j_final]=='t'))
            return 0;
        if(((i_inicial-i)==(i_final)&&(j_inicial-i)==j_final)&&(tablero[i_final][j_final]=='a'))
            return 0;
        if(((i_inicial-i)==(i_final)&&(j_inicial-i)==j_final)&&(tablero[i_final][j_final]=='c'))
            return 0;
        if(((i_inicial-i)==(i_final)&&(j_inicial-i)==j_final)&&(tablero[i_final][j_final]=='d'))
            return 0;
    }

    for(i=1; i<dere_arr; i++)
    {
        if(((i_inicial-i)==(i_final)&&(j_inicial+i)==j_final)&&(tablero[i_final][j_final]=='p'))
            return 0;
        if(((i_inicial-i)==(i_final)&&(j_inicial+i)==j_final)&&(tablero[i_final][j_final]=='r'))
            return 0;
        if(((i_inicial-i)==(i_final)&&(j_inicial+i)==j_final)&&(tablero[i_final][j_final]=='t'))
            return 0;
        if(((i_inicial-i)==(i_final)&&(j_inicial+i)==j_final)&&(tablero[i_final][j_final]=='a'))
            return 0;
        if(((i_inicial-i)==(i_final)&&(j_inicial+i)==j_final)&&(tablero[i_final][j_final]=='c'))
            return 0;
        if(((i_inicial-i)==(i_final)&&(j_inicial+i)==j_final)&&(tablero[i_final][j_final]=='d'))
            return 0;
    }
    for(i=1; i<izq_abj; i++)
    {
        if(((i_inicial+i)==(i_final)&&(j_inicial-i)==j_final)&&(tablero[i_final][j_final]=='p'))
            return 0;
        if(((i_inicial+i)==(i_final)&&(j_inicial-i)==j_final)&&(tablero[i_final][j_final]=='r'))
            return 0;
        if(((i_inicial+i)==(i_final)&&(j_inicial-i)==j_final)&&(tablero[i_final][j_final]=='t'))
            return 0;
        if(((i_inicial+i)==(i_final)&&(j_inicial-i)==j_final)&&(tablero[i_final][j_final]=='a'))
            return 0;
        if(((i_inicial+i)==(i_final)&&(j_inicial-i)==j_final)&&(tablero[i_final][j_final]=='c'))
            return 0;
        if(((i_inicial+i)==(i_final)&&(j_inicial-i)==j_final)&&(tablero[i_final][j_final]=='d'))
            return 0;
    }
    for(i=0; i<dere_abajo; i++)
    {
        if((i_inicial+i)==(i_final)&&(j_inicial+i)==j_final)
            return 1;
    }
    for(i=0; i<izq_arr; i++)
    {
        if((i_inicial-i)==(i_final)&&(j_inicial-i)==j_final)
            return 1;
    }
    for(i=0; i<izq_abj; i++)
    {
        if((i_inicial+i)==(i_final)&&(j_inicial-i)==j_final)
            return 1;
    }
    for(i=0; i<dere_arr; i++)
    {
        if((i_inicial-i)==(i_final)&&(j_inicial+i)==j_final)
            return 1;
    }
    return 0;


}
int confirmar_caballo_negro(int i_inicial,int j_inicial,int i_final,int j_final)
{

    if(((i_inicial-2)==i_final&&(j_inicial+1)==j_final)&&(tablero[i_final][j_final]=='T'))
        return 0;
    if(((i_inicial-2)==i_final&&(j_inicial+1)==j_final)&&(tablero[i_final][j_final]=='A'))
        return 0;
    if(((i_inicial-2)==i_final&&(j_inicial+1)==j_final)&&(tablero[i_final][j_final]=='R'))
        return 0;
    if(((i_inicial-2)==i_final&&(j_inicial+1)==j_final)&&(tablero[i_final][j_final]=='C'))
        return 0;
    if(((i_inicial-2)==i_final&&(j_inicial+1)==j_final)&&(tablero[i_final][j_final]=='P'))
        return 0;
    if(((i_inicial-2)==i_final&&(j_inicial+1)==j_final)&&(tablero[i_final][j_final]=='D'))
        return 0;

    if(((i_inicial-2)==i_final&&(j_inicial-1)==j_final)&&(tablero[i_final][j_final]=='T'))
        return 0;
    if(((i_inicial-2)==i_final&&(j_inicial-1)==j_final)&&(tablero[i_final][j_final]=='A'))
        return 0;
    if(((i_inicial-2)==i_final&&(j_inicial-1)==j_final)&&(tablero[i_final][j_final]=='R'))
        return 0;
    if(((i_inicial-2)==i_final&&(j_inicial-1)==j_final)&&(tablero[i_final][j_final]=='C'))
        return 0;
    if(((i_inicial-2)==i_final&&(j_inicial-1)==j_final)&&(tablero[i_final][j_final]=='P'))
        return 0;
    if(((i_inicial-2)==i_final&&(j_inicial-1)==j_final)&&(tablero[i_final][j_final]=='D'))
        return 0;

    if(((i_inicial-1)==i_final&&(j_inicial+2)==j_final)&&(tablero[i_final][j_final]=='T'))
        return 0;
    if(((i_inicial-1)==i_final&&(j_inicial+2)==j_final)&&(tablero[i_final][j_final]=='A'))
        return 0;
    if(((i_inicial-1)==i_final&&(j_inicial+2)==j_final)&&(tablero[i_final][j_final]=='R'))
        return 0;
    if(((i_inicial-1)==i_final&&(j_inicial+2)==j_final)&&(tablero[i_final][j_final]=='C'))
        return 0;
    if(((i_inicial-1)==i_final&&(j_inicial+2)==j_final)&&(tablero[i_final][j_final]=='P'))
        return 0;
    if(((i_inicial-1)==i_final&&(j_inicial+2)==j_final)&&(tablero[i_final][j_final]=='D'))
        return 0;

    if(((i_inicial-1)==i_final&&(j_inicial-2)==j_final)&&(tablero[i_final][j_final]=='T'))
        return 0;
    if(((i_inicial-1)==i_final&&(j_inicial-2)==j_final)&&(tablero[i_final][j_final]=='A'))
        return 0;
    if(((i_inicial-1)==i_final&&(j_inicial-2)==j_final)&&(tablero[i_final][j_final]=='R'))
        return 0;
    if(((i_inicial-1)==i_final&&(j_inicial-2)==j_final)&&(tablero[i_final][j_final]=='C'))
        return 0;
    if(((i_inicial-1)==i_final&&(j_inicial-2)==j_final)&&(tablero[i_final][j_final]=='P'))
        return 0;
    if(((i_inicial-1)==i_final&&(j_inicial-2)==j_final)&&(tablero[i_final][j_final]=='D'))
        return 0;

    if(((i_inicial+2)==i_final&&(j_inicial-1)==j_final)&&(tablero[i_final][j_final]=='T'))
        return 0;
    if(((i_inicial+2)==i_final&&(j_inicial-1)==j_final)&&(tablero[i_final][j_final]=='A'))
        return 0;
    if(((i_inicial+2)==i_final&&(j_inicial-1)==j_final)&&(tablero[i_final][j_final]=='R'))
        return 0;
    if(((i_inicial+2)==i_final&&(j_inicial-1)==j_final)&&(tablero[i_final][j_final]=='C'))
        return 0;
    if(((i_inicial+2)==i_final&&(j_inicial-1)==j_final)&&(tablero[i_final][j_final]=='P'))
        return 0;
    if(((i_inicial+2)==i_final&&(j_inicial-1)==j_final)&&(tablero[i_final][j_final]=='D'))
        return 0;

    if(((i_inicial+2)==i_final&&(j_inicial+1)==j_final)&&(tablero[i_final][j_final]=='T'))
        return 0;
    if(((i_inicial+2)==i_final&&(j_inicial+1)==j_final)&&(tablero[i_final][j_final]=='A'))
        return 0;
    if(((i_inicial+2)==i_final&&(j_inicial+1)==j_final)&&(tablero[i_final][j_final]=='R'))
        return 0;
    if(((i_inicial+2)==i_final&&(j_inicial+1)==j_final)&&(tablero[i_final][j_final]=='C'))
        return 0;
    if(((i_inicial+2)==i_final&&(j_inicial+1)==j_final)&&(tablero[i_final][j_final]=='P'))
        return 0;
    if(((i_inicial+2)==i_final&&(j_inicial+1)==j_final)&&(tablero[i_final][j_final]=='D'))
        return 0;

    if(((i_inicial+1)==i_final&&(j_inicial-2)==j_final)&&(tablero[i_final][j_final]=='T'))
        return 0;
    if(((i_inicial+1)==i_final&&(j_inicial-2)==j_final)&&(tablero[i_final][j_final]=='A'))
        return 0;
    if(((i_inicial+1)==i_final&&(j_inicial-2)==j_final)&&(tablero[i_final][j_final]=='R'))
        return 0;
    if(((i_inicial+1)==i_final&&(j_inicial-2)==j_final)&&(tablero[i_final][j_final]=='C'))
        return 0;
    if(((i_inicial+1)==i_final&&(j_inicial-2)==j_final)&&(tablero[i_final][j_final]=='P'))
        return 0;
    if(((i_inicial+1)==i_final&&(j_inicial-2)==j_final)&&(tablero[i_final][j_final]=='D'))
        return 0;

    if(((i_inicial+1)==i_final&&(j_inicial+2)==j_final)&&(tablero[i_final][j_final]=='T'))
        return 0;
    if(((i_inicial+1)==i_final&&(j_inicial+2)==j_final)&&(tablero[i_final][j_final]=='A'))
        return 0;
    if(((i_inicial+1)==i_final&&(j_inicial+2)==j_final)&&(tablero[i_final][j_final]=='R'))
        return 0;
    if(((i_inicial+1)==i_final&&(j_inicial+2)==j_final)&&(tablero[i_final][j_final]=='C'))
        return 0;
    if(((i_inicial+1)==i_final&&(j_inicial+2)==j_final)&&(tablero[i_final][j_final]=='P'))
        return 0;
    if(((i_inicial+1)==i_final&&(j_inicial+2)==j_final)&&(tablero[i_final][j_final]=='D'))
        return 0;

    if((i_inicial-2)==i_final&&(j_inicial+1)==j_final)
        return 1;
    if((i_inicial-2)==i_final&&(j_inicial-1)==j_final)
        return 1;
    if((i_inicial-1)==i_final&&(j_inicial+2)==j_final)
        return 1;
    if((i_inicial-1)==i_final&&(j_inicial-2)==j_final)
        return 1;

    if((i_inicial+2)==i_final&&(j_inicial-1)==j_final)
        return 1;
    if((i_inicial+2)==i_final&&(j_inicial+1)==j_final)
        return 1;
    if((i_inicial+1)==i_final&&(j_inicial-2)==j_final)
        return 1;
    if((i_inicial+1)==i_final&&(j_inicial+2)==j_final)
        return 1;
    return 0;
}
int confirmar_caballo_blanco(int i_inicial,int j_inicial,int i_final,int j_final)
{
    if(((i_inicial-2)==i_final&&(j_inicial+1)==j_final)&&(tablero[i_final][j_final]=='t'))
        return 0;
    if(((i_inicial-2)==i_final&&(j_inicial+1)==j_final)&&(tablero[i_final][j_final]=='a'))
        return 0;
    if(((i_inicial-2)==i_final&&(j_inicial+1)==j_final)&&(tablero[i_final][j_final]=='r'))
        return 0;
    if(((i_inicial-2)==i_final&&(j_inicial+1)==j_final)&&(tablero[i_final][j_final]=='c'))
        return 0;
    if(((i_inicial-2)==i_final&&(j_inicial+1)==j_final)&&(tablero[i_final][j_final]=='p'))
        return 0;
    if(((i_inicial-2)==i_final&&(j_inicial+1)==j_final)&&(tablero[i_final][j_final]=='d'))
        return 0;

    if(((i_inicial-2)==i_final&&(j_inicial-1)==j_final)&&(tablero[i_final][j_final]=='t'))
        return 0;
    if(((i_inicial-2)==i_final&&(j_inicial-1)==j_final)&&(tablero[i_final][j_final]=='a'))
        return 0;
    if(((i_inicial-2)==i_final&&(j_inicial-1)==j_final)&&(tablero[i_final][j_final]=='r'))
        return 0;
    if(((i_inicial-2)==i_final&&(j_inicial-1)==j_final)&&(tablero[i_final][j_final]=='c'))
        return 0;
    if(((i_inicial-2)==i_final&&(j_inicial-1)==j_final)&&(tablero[i_final][j_final]=='p'))
        return 0;
    if(((i_inicial-2)==i_final&&(j_inicial-1)==j_final)&&(tablero[i_final][j_final]=='d'))
        return 0;

    if(((i_inicial-1)==i_final&&(j_inicial+2)==j_final)&&(tablero[i_final][j_final]=='t'))
        return 0;
    if(((i_inicial-1)==i_final&&(j_inicial+2)==j_final)&&(tablero[i_final][j_final]=='a'))
        return 0;
    if(((i_inicial-1)==i_final&&(j_inicial+2)==j_final)&&(tablero[i_final][j_final]=='r'))
        return 0;
    if(((i_inicial-1)==i_final&&(j_inicial+2)==j_final)&&(tablero[i_final][j_final]=='c'))
        return 0;
    if(((i_inicial-1)==i_final&&(j_inicial+2)==j_final)&&(tablero[i_final][j_final]=='p'))
        return 0;
    if(((i_inicial-1)==i_final&&(j_inicial+2)==j_final)&&(tablero[i_final][j_final]=='d'))
        return 0;

    if(((i_inicial-1)==i_final&&(j_inicial-2)==j_final)&&(tablero[i_final][j_final]=='t'))
        return 0;
    if(((i_inicial-1)==i_final&&(j_inicial-2)==j_final)&&(tablero[i_final][j_final]=='a'))
        return 0;
    if(((i_inicial-1)==i_final&&(j_inicial-2)==j_final)&&(tablero[i_final][j_final]=='r'))
        return 0;
    if(((i_inicial-1)==i_final&&(j_inicial-2)==j_final)&&(tablero[i_final][j_final]=='c'))
        return 0;
    if(((i_inicial-1)==i_final&&(j_inicial-2)==j_final)&&(tablero[i_final][j_final]=='p'))
        return 0;
    if(((i_inicial-1)==i_final&&(j_inicial-2)==j_final)&&(tablero[i_final][j_final]=='d'))
        return 0;

    if(((i_inicial+2)==i_final&&(j_inicial-1)==j_final)&&(tablero[i_final][j_final]=='t'))
        return 0;
    if(((i_inicial+2)==i_final&&(j_inicial-1)==j_final)&&(tablero[i_final][j_final]=='a'))
        return 0;
    if(((i_inicial+2)==i_final&&(j_inicial-1)==j_final)&&(tablero[i_final][j_final]=='r'))
        return 0;
    if(((i_inicial+2)==i_final&&(j_inicial-1)==j_final)&&(tablero[i_final][j_final]=='c'))
        return 0;
    if(((i_inicial+2)==i_final&&(j_inicial-1)==j_final)&&(tablero[i_final][j_final]=='p'))
        return 0;
    if(((i_inicial+2)==i_final&&(j_inicial-1)==j_final)&&(tablero[i_final][j_final]=='d'))
        return 0;

    if(((i_inicial+2)==i_final&&(j_inicial+1)==j_final)&&(tablero[i_final][j_final]=='t'))
        return 0;
    if(((i_inicial+2)==i_final&&(j_inicial+1)==j_final)&&(tablero[i_final][j_final]=='a'))
        return 0;
    if(((i_inicial+2)==i_final&&(j_inicial+1)==j_final)&&(tablero[i_final][j_final]=='r'))
        return 0;
    if(((i_inicial+2)==i_final&&(j_inicial+1)==j_final)&&(tablero[i_final][j_final]=='c'))
        return 0;
    if(((i_inicial+2)==i_final&&(j_inicial+1)==j_final)&&(tablero[i_final][j_final]=='p'))
        return 0;
    if(((i_inicial+2)==i_final&&(j_inicial+1)==j_final)&&(tablero[i_final][j_final]=='d'))
        return 0;

    if(((i_inicial+1)==i_final&&(j_inicial-2)==j_final)&&(tablero[i_final][j_final]=='t'))
        return 0;
    if(((i_inicial+1)==i_final&&(j_inicial-2)==j_final)&&(tablero[i_final][j_final]=='a'))
        return 0;
    if(((i_inicial+1)==i_final&&(j_inicial-2)==j_final)&&(tablero[i_final][j_final]=='r'))
        return 0;
    if(((i_inicial+1)==i_final&&(j_inicial-2)==j_final)&&(tablero[i_final][j_final]=='c'))
        return 0;
    if(((i_inicial+1)==i_final&&(j_inicial-2)==j_final)&&(tablero[i_final][j_final]=='p'))
        return 0;
    if(((i_inicial+1)==i_final&&(j_inicial-2)==j_final)&&(tablero[i_final][j_final]=='d'))
        return 0;

    if(((i_inicial+1)==i_final&&(j_inicial+2)==j_final)&&(tablero[i_final][j_final]=='t'))
        return 0;
    if(((i_inicial+1)==i_final&&(j_inicial+2)==j_final)&&(tablero[i_final][j_final]=='a'))
        return 0;
    if(((i_inicial+1)==i_final&&(j_inicial+2)==j_final)&&(tablero[i_final][j_final]=='r'))
        return 0;
    if(((i_inicial+1)==i_final&&(j_inicial+2)==j_final)&&(tablero[i_final][j_final]=='c'))
        return 0;
    if(((i_inicial+1)==i_final&&(j_inicial+2)==j_final)&&(tablero[i_final][j_final]=='p'))
        return 0;
    if(((i_inicial+1)==i_final&&(j_inicial+2)==j_final)&&(tablero[i_final][j_final]=='d'))
        return 0;

    if((i_inicial-2)==i_final&&(j_inicial+1)==j_final)
        return 1;
    if((i_inicial-2)==i_final&&(j_inicial-1)==j_final)
        return 1;
    if((i_inicial-1)==i_final&&(j_inicial+2)==j_final)
        return 1;
    if((i_inicial-1)==i_final&&(j_inicial-2)==j_final)
        return 1;

    if((i_inicial+2)==i_final&&(j_inicial-1)==j_final)
        return 1;
    if((i_inicial+2)==i_final&&(j_inicial+1)==j_final)
        return 1;
    if((i_inicial+1)==i_final&&(j_inicial-2)==j_final)
        return 1;
    if((i_inicial+1)==i_final&&(j_inicial+2)==j_final)
        return 1;
    return 0;
}
int confirmar_dama_blanca(int i_inicial,int j_inicial,int i_final,int j_final)
{
    int i,arriba,abajo,izq,dere;
    int izq_arr,izq_abj,dere_arr,dere_abajo;

    izq_arr=cal_izq_arr_blanca(i_inicial,j_inicial);
    izq_abj=cal_izq_abj_blanca(i_inicial,j_inicial);
    dere_arr=cal_dere_arr_blanca(i_inicial,j_inicial);
    dere_abajo=cal_dere_abj_blanca(i_inicial,j_inicial);

    arriba=cal_arriba_blancas(i_inicial, j_inicial);
    dere=cal_derecha_blancas(i_inicial,j_inicial);
    izq=cal_izq_blancas(i_inicial,j_inicial);
    abajo=cal_abajo_blancas(i_inicial,j_inicial);

    for(i=1; i<dere_abajo; i++)
    {
        if(((i_inicial+i)==(i_final)&&(j_inicial+i)==j_final)&&(tablero[i_final][j_final]=='p'))
            return 0;
        if(((i_inicial+i)==(i_final)&&(j_inicial+i)==j_final)&&(tablero[i_final][j_final]=='r'))
            return 0;
        if(((i_inicial+i)==(i_final)&&(j_inicial+i)==j_final)&&(tablero[i_final][j_final]=='t'))
            return 0;
        if(((i_inicial+i)==(i_final)&&(j_inicial+i)==j_final)&&(tablero[i_final][j_final]=='a'))
            return 0;
        if(((i_inicial+i)==(i_final)&&(j_inicial+i)==j_final)&&(tablero[i_final][j_final]=='c'))
            return 0;
        if(((i_inicial+i)==(i_final)&&(j_inicial+i)==j_final)&&(tablero[i_final][j_final]=='d'))
            return 0;
    }
    for(i=1; i<izq_arr; i++)
    {
        if(((i_inicial-i)==(i_final)&&(j_inicial-i)==j_final)&&(tablero[i_final][j_final]=='p'))
            return 0;
        if(((i_inicial-i)==(i_final)&&(j_inicial-i)==j_final)&&(tablero[i_final][j_final]=='r'))
            return 0;
        if(((i_inicial-i)==(i_final)&&(j_inicial-i)==j_final)&&(tablero[i_final][j_final]=='t'))
            return 0;
        if(((i_inicial-i)==(i_final)&&(j_inicial-i)==j_final)&&(tablero[i_final][j_final]=='a'))
            return 0;
        if(((i_inicial-i)==(i_final)&&(j_inicial-i)==j_final)&&(tablero[i_final][j_final]=='c'))
            return 0;
        if(((i_inicial-i)==(i_final)&&(j_inicial-i)==j_final)&&(tablero[i_final][j_final]=='d'))
            return 0;
    }

    for(i=1; i<dere_arr; i++)
    {
        if(((i_inicial-i)==(i_final)&&(j_inicial+i)==j_final)&&(tablero[i_final][j_final]=='p'))
            return 0;
        if(((i_inicial-i)==(i_final)&&(j_inicial+i)==j_final)&&(tablero[i_final][j_final]=='r'))
            return 0;
        if(((i_inicial-i)==(i_final)&&(j_inicial+i)==j_final)&&(tablero[i_final][j_final]=='t'))
            return 0;
        if(((i_inicial-i)==(i_final)&&(j_inicial+i)==j_final)&&(tablero[i_final][j_final]=='a'))
            return 0;
        if(((i_inicial-i)==(i_final)&&(j_inicial+i)==j_final)&&(tablero[i_final][j_final]=='c'))
            return 0;
        if(((i_inicial-i)==(i_final)&&(j_inicial+i)==j_final)&&(tablero[i_final][j_final]=='d'))
            return 0;
    }
    for(i=1; i<izq_abj; i++)
    {
        if(((i_inicial+i)==(i_final)&&(j_inicial-i)==j_final)&&(tablero[i_final][j_final]=='p'))
            return 0;
        if(((i_inicial+i)==(i_final)&&(j_inicial-i)==j_final)&&(tablero[i_final][j_final]=='r'))
            return 0;
        if(((i_inicial+i)==(i_final)&&(j_inicial-i)==j_final)&&(tablero[i_final][j_final]=='t'))
            return 0;
        if(((i_inicial+i)==(i_final)&&(j_inicial-i)==j_final)&&(tablero[i_final][j_final]=='a'))
            return 0;
        if(((i_inicial+i)==(i_final)&&(j_inicial-i)==j_final)&&(tablero[i_final][j_final]=='c'))
            return 0;
        if(((i_inicial+i)==(i_final)&&(j_inicial-i)==j_final)&&(tablero[i_final][j_final]=='d'))
            return 0;
    }
    for(i=0; i<dere_abajo; i++)
    {
        if((i_inicial+i)==(i_final)&&(j_inicial+i)==j_final)
            return 1;
    }
    for(i=0; i<izq_arr; i++)
    {
        if((i_inicial-i)==(i_final)&&(j_inicial-i)==j_final)
            return 1;
    }
    for(i=0; i<izq_abj; i++)
    {
        if((i_inicial+i)==(i_final)&&(j_inicial-i)==j_final)
            return 1;
    }
    for(i=0; i<dere_arr; i++)
    {
        if((i_inicial-i)==(i_final)&&(j_inicial+i)==j_final)
            return 1;
    }
    for(i=1; i<izq; i++)
    {
        if(((i_inicial)==(i_final)&&((j_inicial-i)==j_final))&&(tablero[i_final][j_final]=='p'))
            return 0;
        if(((i_inicial)==(i_final)&&((j_inicial-i)==j_final))&&(tablero[i_final][j_final]=='r'))
            return 0;
        if(((i_inicial)==(i_final)&&((j_inicial-i)==j_final))&&(tablero[i_final][j_final]=='t'))
            return 0;
        if(((i_inicial)==(i_final)&&((j_inicial-i)==j_final))&&(tablero[i_final][j_final]=='a'))
            return 0;
        if(((i_inicial)==(i_final)&&((j_inicial-i)==j_final))&&(tablero[i_final][j_final]=='c'))
            return 0;
        if(((i_inicial)==(i_final)&&((j_inicial-i)==j_final))&&(tablero[i_final][j_final]=='d'))
            return 0;
    }
    for(i=1; i<dere; i++)
    {
        if(((i_inicial)==(i_final)&&((j_inicial+i)==j_final))&&(tablero[i_final][j_final]=='p'))
            return 0;
        if(((i_inicial)==(i_final)&&((j_inicial+i)==j_final))&&(tablero[i_final][j_final]=='r'))
            return 0;
        if(((i_inicial)==(i_final)&&((j_inicial+i)==j_final))&&(tablero[i_final][j_final]=='t'))
            return 0;
        if(((i_inicial)==(i_final)&&((j_inicial+i)==j_final))&&(tablero[i_final][j_final]=='a'))
            return 0;
        if(((i_inicial)==(i_final)&&((j_inicial+i)==j_final))&&(tablero[i_final][j_final]=='c'))
            return 0;
        if(((i_inicial)==(i_final)&&((j_inicial+i)==j_final))&&(tablero[i_final][j_final]=='d'))
            return 0;
    }

    for(i=1; i<arriba; i++)
    {
        if(((i_inicial-i)==(i_final)&&(j_inicial==j_final))&&(tablero[i_final][j_final]=='p'))
            return 0;
        if(((i_inicial-i)==(i_final)&&(j_inicial==j_final))&&(tablero[i_final][j_final]=='r'))
            return 0;
        if(((i_inicial-i)==(i_final)&&(j_inicial==j_final))&&(tablero[i_final][j_final]=='t'))
            return 0;
        if(((i_inicial-i)==(i_final)&&(j_inicial==j_final))&&(tablero[i_final][j_final]=='a'))
            return 0;
        if(((i_inicial-i)==(i_final)&&(j_inicial==j_final))&&(tablero[i_final][j_final]=='c'))
            return 0;
        if(((i_inicial-i)==(i_final)&&(j_inicial==j_final))&&(tablero[i_final][j_final]=='d'))
            return 0;
    }
    for(i=1; i<abajo; i++)
    {
        if(((i_inicial+i)==(i_final)&&(j_inicial==j_final))&&(tablero[i_final][j_final]=='p'))
            return 0;
        if(((i_inicial+i)==(i_final)&&(j_inicial==j_final))&&(tablero[i_final][j_final]=='r'))
            return 0;
        if(((i_inicial+i)==(i_final)&&(j_inicial==j_final))&&(tablero[i_final][j_final]=='t'))
            return 0;
        if(((i_inicial+i)==(i_final)&&(j_inicial==j_final))&&(tablero[i_final][j_final]=='a'))
            return 0;
        if(((i_inicial+i)==(i_final)&&(j_inicial==j_final))&&(tablero[i_final][j_final]=='c'))
            return 0;
        if(((i_inicial+i)==(i_final)&&(j_inicial==j_final))&&(tablero[i_final][j_final]=='d'))
            return 0;
    }
    for(i=1; i<izq; i++)
    {
        if((i_inicial)==(i_final)&&((j_inicial-i)==j_final))
            return 1;
    }
    for(i=1; i<dere; i++)
    {
        if((i_inicial)==(i_final)&&((j_inicial+i)==j_final))
            return 1;
    }
    for(i=1; i<arriba; i++)
    {
        if((i_inicial-i)==(i_final)&&((j_inicial)==j_final))
            return 1;
    }
    for(i=1; i<abajo; i++)
    {
        if((i_inicial+i)==(i_final)&&((j_inicial)==j_final))
            return 1;
    }
    return 0;
}
int confirmar_rey_blanco(int i_inicial,int j_inicial,int i_final,int j_final)
{
     if((contador_movi_torre_blanco==0)&&(tablero[0][1]=='.')&&(tablero[0][2]=='.')&&(contador_movi_rey_blanco==0)&&(i_final==0)&&(j_final==1))
        enroque_corto_blanco();
    if((contador_movi_torre_blanco==0)&&(tablero[0][6]=='.')&&(tablero[0][5]=='.')&&(tablero[0][4]=='.')&&(contador_movi_rey_blanco==0)&&(i_final==0)&&(j_final==5))
        enroque_largo_blanco();
    if(((i_inicial+1)==i_final)&&(j_inicial==j_final)&&((tablero[i_final][j_final]=='a')))
        return 0;
    if(((i_inicial+1)==i_final)&&(j_inicial==j_final)&&((tablero[i_final][j_final]=='p')))
        return 0;
    if(((i_inicial+1)==i_final)&&(j_inicial==j_final)&&((tablero[i_final][j_final]=='c')))
        return 0;
    if(((i_inicial+1)==i_final)&&(j_inicial==j_final)&&((tablero[i_final][j_final]=='d')))
        return 0;
    if(((i_inicial+1)==i_final)&&(j_inicial==j_final)&&((tablero[i_final][j_final]=='t')))
        return 0;

    if(((i_inicial-1)==i_final)&&(j_inicial==j_final)&&((tablero[i_final][j_final]=='a')))
        return 0;
    if(((i_inicial-1)==i_final)&&(j_inicial==j_final)&&((tablero[i_final][j_final]=='p')))
        return 0;
    if(((i_inicial-1)==i_final)&&(j_inicial==j_final)&&((tablero[i_final][j_final]=='c')))
        return 0;
    if(((i_inicial-1)==i_final)&&(j_inicial==j_final)&&((tablero[i_final][j_final]=='d')))
        return 0;
    if(((i_inicial-1)==i_final)&&(j_inicial==j_final)&&((tablero[i_final][j_final]=='t')))
        return 0;

    if(((i_inicial)==i_final)&&((j_inicial+1)==j_final)&&((tablero[i_final][j_final]=='a')))
        return 0;
    if(((i_inicial)==i_final)&&((j_inicial+1)==j_final)&&((tablero[i_final][j_final]=='p')))
        return 0;
    if(((i_inicial)==i_final)&&((j_inicial+1)==j_final)&&((tablero[i_final][j_final]=='c')))
        return 0;
    if(((i_inicial)==i_final)&&((j_inicial+1)==j_final)&&((tablero[i_final][j_final]=='d')))
        return 0;
    if(((i_inicial)==i_final)&&((j_inicial+1)==j_final)&&((tablero[i_final][j_final]=='t')))
        return 0;

    if(((i_inicial)==i_final)&&((j_inicial-1)==j_final)&&((tablero[i_final][j_final]=='a')))
        return 0;
    if(((i_inicial)==i_final)&&((j_inicial-1)==j_final)&&((tablero[i_final][j_final]=='p')))
        return 0;
    if(((i_inicial)==i_final)&&((j_inicial-1)==j_final)&&((tablero[i_final][j_final]=='c')))
        return 0;
    if(((i_inicial)==i_final)&&((j_inicial-1)==j_final)&&((tablero[i_final][j_final]=='d')))
        return 0;
    if(((i_inicial)==i_final)&&((j_inicial-1)==j_final)&&((tablero[i_final][j_final]=='t')))
        return 0;

    if(((i_inicial-1)==i_final)&&((j_inicial-1)==j_final)&&((tablero[i_final][j_final]=='a')))
        return 0;
    if(((i_inicial-1)==i_final)&&((j_inicial-1)==j_final)&&((tablero[i_final][j_final]=='p')))
        return 0;
    if(((i_inicial-1)==i_final)&&((j_inicial-1)==j_final)&&((tablero[i_final][j_final]=='c')))
        return 0;
    if(((i_inicial-1)==i_final)&&((j_inicial-1)==j_final)&&((tablero[i_final][j_final]=='d')))
        return 0;
    if(((i_inicial-1)==i_final)&&((j_inicial-1)==j_final)&&((tablero[i_final][j_final]=='t')))
        return 0;
    //
    if(((i_inicial+1)==i_final)&&((j_inicial+1)==j_final)&&((tablero[i_final][j_final]=='a')))
        return 0;
    if(((i_inicial+1)==i_final)&&((j_inicial+1)==j_final)&&((tablero[i_final][j_final]=='p')))
        return 0;
    if(((i_inicial+1)==i_final)&&((j_inicial+1)==j_final)&&((tablero[i_final][j_final]=='c')))
        return 0;
    if(((i_inicial+1)==i_final)&&((j_inicial+1)==j_final)&&((tablero[i_final][j_final]=='d')))
        return 0;
    if(((i_inicial+1)==i_final)&&((j_inicial+1)==j_final)&&((tablero[i_final][j_final]=='t')))
        return 0;

    if(((i_inicial+1)==i_final)&&((j_inicial+1)==j_final)&&((tablero[i_final][j_final]=='a')))
        return 0;
    if(((i_inicial+1)==i_final)&&((j_inicial+1)==j_final)&&((tablero[i_final][j_final]=='p')))
        return 0;
    if(((i_inicial+1)==i_final)&&((j_inicial+1)==j_final)&&((tablero[i_final][j_final]=='c')))
        return 0;
    if(((i_inicial+1)==i_final)&&((j_inicial+1)==j_final)&&((tablero[i_final][j_final]=='d')))
        return 0;
    if(((i_inicial+1)==i_final)&&((j_inicial+1)==j_final)&&((tablero[i_final][j_final]=='t')))
        return 0;

    if(((i_inicial-1)==i_final)&&((j_inicial+1)==j_final)&&((tablero[i_final][j_final]=='a')))
        return 0;
    if(((i_inicial-1)==i_final)&&((j_inicial+1)==j_final)&&((tablero[i_final][j_final]=='p')))
        return 0;
    if(((i_inicial-1)==i_final)&&((j_inicial+1)==j_final)&&((tablero[i_final][j_final]=='c')))
        return 0;
    if(((i_inicial-1)==i_final)&&((j_inicial+1)==j_final)&&((tablero[i_final][j_final]=='d')))
        return 0;
    if(((i_inicial-1)==i_final)&&((j_inicial+1)==j_final)&&((tablero[i_final][j_final]=='t')))
        return 0;

    if(((i_inicial+1)==i_final)&&((j_inicial-1)==j_final)&&((tablero[i_final][j_final]=='a')))
        return 0;
    if(((i_inicial+1)==i_final)&&((j_inicial-1)==j_final)&&((tablero[i_final][j_final]=='p')))
        return 0;
    if(((i_inicial+1)==i_final)&&((j_inicial-1)==j_final)&&((tablero[i_final][j_final]=='c')))
        return 0;
    if(((i_inicial+1)==i_final)&&((j_inicial-1)==j_final)&&((tablero[i_final][j_final]=='d')))
        return 0;
    if(((i_inicial+1)==i_final)&&((j_inicial-1)==j_final)&&((tablero[i_final][j_final]=='t')))
        return 0;


    if( ((i_inicial+1)==i_final)&&(j_inicial==j_final))
        return 1;
    if( ((i_inicial-1)==i_final)&&(j_inicial==j_final))
        return 1;
    if( ((i_inicial)==i_final)&&((j_inicial+1)==j_final))
        return 1;

    if( ((i_inicial)==i_final)&&((j_inicial-1)==j_final))
        return 1;

    if( ((i_inicial-1)==i_final)&&((j_inicial-1)==j_final))
        return 1;
    if( ((i_inicial+1)==i_final)&&((j_inicial+1)==j_final))
        return 1;
    if( ((i_inicial-1)==i_final)&&((j_inicial+1)==j_final))
        return 1;
    if( ((i_inicial+1)==i_final)&&((j_inicial-1)==j_final))
        return 1;
    return 0;
}
int confirmar_rey_negro(int i_inicial,int j_inicial,int i_final,int j_final)
{
     if((contador_movi_torre_negro==0)&&(tablero[7][1]=='.')&&(tablero[7][2]=='.')&&(contador_movi_rey_negro==0)&&(i_final==7)&&(j_final==1))
        enroque_corto_negro();
    if((contador_movi_torre_negro==0)&&(tablero[7][6]=='.')&&(tablero[7][5]=='.')&&(tablero[7][4]=='.')&&(contador_movi_rey_negro==0)&&(i_final==7)&&(j_final==5))
        enroque_largo_negro();


    if(((i_inicial+1)==i_final)&&(j_inicial==j_final)&&((tablero[i_final][j_final]=='A')))
        return 0;
    if(((i_inicial+1)==i_final)&&(j_inicial==j_final)&&((tablero[i_final][j_final]=='P')))
        return 0;
    if(((i_inicial+1)==i_final)&&(j_inicial==j_final)&&((tablero[i_final][j_final]=='C')))
        return 0;
    if(((i_inicial+1)==i_final)&&(j_inicial==j_final)&&((tablero[i_final][j_final]=='D')))
        return 0;
    if(((i_inicial+1)==i_final)&&(j_inicial==j_final)&&((tablero[i_final][j_final]=='T')))
        return 0;

    if(((i_inicial-1)==i_final)&&(j_inicial==j_final)&&((tablero[i_final][j_final]=='A')))
        return 0;
    if(((i_inicial-1)==i_final)&&(j_inicial==j_final)&&((tablero[i_final][j_final]=='P')))
        return 0;
    if(((i_inicial-1)==i_final)&&(j_inicial==j_final)&&((tablero[i_final][j_final]=='C')))
        return 0;
    if(((i_inicial-1)==i_final)&&(j_inicial==j_final)&&((tablero[i_final][j_final]=='D')))
        return 0;
    if(((i_inicial-1)==i_final)&&(j_inicial==j_final)&&((tablero[i_final][j_final]=='T')))
        return 0;

    if(((i_inicial)==i_final)&&((j_inicial+1)==j_final)&&((tablero[i_final][j_final]=='A')))
        return 0;
    if(((i_inicial)==i_final)&&((j_inicial+1)==j_final)&&((tablero[i_final][j_final]=='P')))
        return 0;
    if(((i_inicial)==i_final)&&((j_inicial+1)==j_final)&&((tablero[i_final][j_final]=='C')))
        return 0;
    if(((i_inicial)==i_final)&&((j_inicial+1)==j_final)&&((tablero[i_final][j_final]=='D')))
        return 0;
    if(((i_inicial)==i_final)&&((j_inicial+1)==j_final)&&((tablero[i_final][j_final]=='T')))
        return 0;

    if(((i_inicial)==i_final)&&((j_inicial-1)==j_final)&&((tablero[i_final][j_final]=='A')))
        return 0;
    if(((i_inicial)==i_final)&&((j_inicial-1)==j_final)&&((tablero[i_final][j_final]=='P')))
        return 0;
    if(((i_inicial)==i_final)&&((j_inicial-1)==j_final)&&((tablero[i_final][j_final]=='C')))
        return 0;
    if(((i_inicial)==i_final)&&((j_inicial-1)==j_final)&&((tablero[i_final][j_final]=='D')))
        return 0;
    if(((i_inicial)==i_final)&&((j_inicial-1)==j_final)&&((tablero[i_final][j_final]=='T')))
        return 0;

    if(((i_inicial-1)==i_final)&&((j_inicial-1)==j_final)&&((tablero[i_final][j_final]=='A')))
        return 0;
    if(((i_inicial-1)==i_final)&&((j_inicial-1)==j_final)&&((tablero[i_final][j_final]=='P')))
        return 0;
    if(((i_inicial-1)==i_final)&&((j_inicial-1)==j_final)&&((tablero[i_final][j_final]=='C')))
        return 0;
    if(((i_inicial-1)==i_final)&&((j_inicial-1)==j_final)&&((tablero[i_final][j_final]=='D')))
        return 0;
    if(((i_inicial-1)==i_final)&&((j_inicial-1)==j_final)&&((tablero[i_final][j_final]=='T')))
        return 0;

    if(((i_inicial+1)==i_final)&&((j_inicial+1)==j_final)&&((tablero[i_final][j_final]=='A')))
        return 0;
    if(((i_inicial+1)==i_final)&&((j_inicial+1)==j_final)&&((tablero[i_final][j_final]=='P')))
        return 0;
    if(((i_inicial+1)==i_final)&&((j_inicial+1)==j_final)&&((tablero[i_final][j_final]=='C')))
        return 0;
    if(((i_inicial+1)==i_final)&&((j_inicial+1)==j_final)&&((tablero[i_final][j_final]=='D')))
        return 0;
    if(((i_inicial+1)==i_final)&&((j_inicial+1)==j_final)&&((tablero[i_final][j_final]=='T')))
        return 0;

    if(((i_inicial+1)==i_final)&&((j_inicial+1)==j_final)&&((tablero[i_final][j_final]=='A')))
        return 0;
    if(((i_inicial+1)==i_final)&&((j_inicial+1)==j_final)&&((tablero[i_final][j_final]=='P')))
        return 0;
    if(((i_inicial+1)==i_final)&&((j_inicial+1)==j_final)&&((tablero[i_final][j_final]=='C')))
        return 0;
    if(((i_inicial+1)==i_final)&&((j_inicial+1)==j_final)&&((tablero[i_final][j_final]=='D')))
        return 0;
    if(((i_inicial+1)==i_final)&&((j_inicial+1)==j_final)&&((tablero[i_final][j_final]=='T')))
        return 0;

    if(((i_inicial-1)==i_final)&&((j_inicial+1)==j_final)&&((tablero[i_final][j_final]=='A')))
        return 0;
    if(((i_inicial-1)==i_final)&&((j_inicial+1)==j_final)&&((tablero[i_final][j_final]=='P')))
        return 0;
    if(((i_inicial-1)==i_final)&&((j_inicial+1)==j_final)&&((tablero[i_final][j_final]=='C')))
        return 0;
    if(((i_inicial-1)==i_final)&&((j_inicial+1)==j_final)&&((tablero[i_final][j_final]=='D')))
        return 0;
    if(((i_inicial-1)==i_final)&&((j_inicial+1)==j_final)&&((tablero[i_final][j_final]=='T')))
        return 0;

    if(((i_inicial+1)==i_final)&&((j_inicial-1)==j_final)&&((tablero[i_final][j_final]=='A')))
        return 0;
    if(((i_inicial+1)==i_final)&&((j_inicial-1)==j_final)&&((tablero[i_final][j_final]=='P')))
        return 0;
    if(((i_inicial+1)==i_final)&&((j_inicial-1)==j_final)&&((tablero[i_final][j_final]=='C')))
        return 0;
    if(((i_inicial+1)==i_final)&&((j_inicial-1)==j_final)&&((tablero[i_final][j_final]=='D')))
        return 0;
    if(((i_inicial+1)==i_final)&&((j_inicial-1)==j_final)&&((tablero[i_final][j_final]=='T')))
        return 0;
    if( ((i_inicial+1)==i_final)&&(j_inicial==j_final))
        return 1;
    if( ((i_inicial-1)==i_final)&&(j_inicial==j_final))
        return 1;
    if( ((i_inicial)==i_final)&&((j_inicial+1)==j_final))
        return 1;
    if( ((i_inicial)==i_final)&&((j_inicial-1)==j_final))
        return 1;

    if( ((i_inicial-1)==i_final)&&((j_inicial-1)==j_final))
        return 1;
    if( ((i_inicial+1)==i_final)&&((j_inicial+1)==j_final))
        return 1;
    if( ((i_inicial-1)==i_final)&&((j_inicial+1)==j_final))
        return 1;
    if( ((i_inicial+1)==i_final)&&((j_inicial-1)==j_final))
        return 1;
    return 0;
}
int confirmar_peon_blanco(int i_inicial,int j_inicial,int i_final,int j_final)
{

    int aux=i_inicial+1,aux2=i_inicial+2;
    if((aux)==(i_final)&&(j_inicial==j_final)&&(i_final==7))
        return -1;
    if((tablero[i_final][j_final]=='A')&&((i_inicial+1)==i_final) &&(((j_inicial-1)==j_final)||(j_inicial+1)==j_final)&&(i_final==7))
        return -1;
    if((tablero[i_final][j_final]=='D')&&((i_inicial+1)==i_final) &&(((j_inicial-1)==j_final)||(j_inicial+1)==j_final)&&(i_final==7))
        return -1;
    if((tablero[i_final][j_final]=='C')&&((i_inicial+1)==i_final) &&(((j_inicial-1)==j_final)||(j_inicial+1)==j_final)&&(i_final==7))
        return -1;
    if((tablero[i_final][j_final]=='T')&&((i_inicial+1)==i_final) &&(((j_inicial-1)==j_final)||(j_inicial+1)==j_final)&&(i_final==7))
        return -1;

    if((tablero[i_final][j_final]=='P')&&((i_inicial+1)==i_final) &&(((j_inicial-1)==j_final)||(j_inicial+1)==j_final))
        return 1;
    if((tablero[i_final][j_final]=='A')&&((i_inicial+1)==i_final) &&(((j_inicial-1)==j_final)||(j_inicial+1)==j_final))
        return 1;
    if((tablero[i_final][j_final]=='C')&&((i_inicial+1)==i_final) &&(((j_inicial-1)==j_final)||(j_inicial+1)==j_final))
        return 1;
    if((tablero[i_final][j_final]=='R')&&((i_inicial+1)==i_final) &&(((j_inicial-1)==j_final)||(j_inicial+1)==j_final))
        return 1;
    if((tablero[i_final][j_final]=='D')&&((i_inicial+1)==i_final) &&(((j_inicial-1)==j_final)||(j_inicial+1)==j_final))
        return 1;
    if((tablero[i_final][j_final]=='T')&&((i_inicial+1)==i_final) &&(((j_inicial-1)==j_final)||(j_inicial+1)==j_final))
        return 1;


    if((aux)==(i_final)&&(j_inicial==j_final))
        return 1;

    if ((i_inicial==1)&&(aux2==i_final)&&(j_inicial==j_final))
        return 1;

    return 0;
}
int confirmar_peon_negro(int i_inicial,int j_inicial,int i_final,int j_final)
{
    int aux=i_inicial-1,aux2=i_inicial-2;
    if((aux)==(i_final)&&(j_inicial==j_final)&&(i_final==0))
        return -1;
    if((tablero[i_final][j_final]=='a')&&((i_inicial-1)==i_final) &&(((j_inicial-1)==j_final)||(j_inicial+1)==j_final)&&(i_final==0))
        return -1;
    if((tablero[i_final][j_final]=='d')&&((i_inicial-1)==i_final) &&(((j_inicial-1)==j_final)||(j_inicial+1)==j_final)&&(i_final==0))
        return -1;
    if((tablero[i_final][j_final]=='c')&&((i_inicial-1)==i_final) &&(((j_inicial-1)==j_final)||(j_inicial+1)==j_final)&&(i_final==0))
        return -1;
    if((tablero[i_final][j_final]=='t')&&((i_inicial-1)==i_final) &&(((j_inicial-1)==j_final)||(j_inicial+1)==j_final)&&(i_final==0))
        return -1;

    if((tablero[i_final][j_final]=='p')&&((i_inicial-1)==i_final) &&(((j_inicial-1)==j_final)||(j_inicial+1)==j_final))
        return 1;
    if((tablero[i_final][j_final]=='a')&&((i_inicial-1)==i_final) &&(((j_inicial-1)==j_final)||(j_inicial+1)==j_final))
        return 1;
    if((tablero[i_final][j_final]=='c')&&((i_inicial-1)==i_final) &&(((j_inicial-1)==j_final)||(j_inicial+1)==j_final))
        return 1;
    if((tablero[i_final][j_final]=='r')&&((i_inicial-1)==i_final) &&(((j_inicial-1)==j_final)||(j_inicial+1)==j_final))
        return 1;
    if((tablero[i_final][j_final]=='d')&&((i_inicial-1)==i_final) &&(((j_inicial-1)==j_final)||(j_inicial+1)==j_final))
        return 1;
    if((tablero[i_final][j_final]=='t')&&((i_inicial-1)==i_final) &&(((j_inicial-1)==j_final)||(j_inicial+1)==j_final))
        return 1;
    if((aux)==(i_final)&&(j_inicial==j_final))
        return 1;
    if ((i_inicial==6)&&(aux2)==(i_final)&&(j_inicial==j_final))
        return 1;
    return 0;
}
void imprimir_jugador(int turno)
{
    if (turno == 0)
        printf("Juega blanco: ");
    else if (turno == 1)
        printf("Juega negro \n");
}

void leer_jugada(int *i_inicial, int *j_inicial,int *i_final,int *j_final,char turno)
{
    char desde[5], hasta[5];
    scanf("%s", desde);
    scanf("%s", hasta);

    *j_inicial = 'h' - desde[0];
    *i_inicial = desde[1] - '1';
    *j_final   = 'h' - hasta[0];
    *i_final   = hasta[1] - '1';


}
void mover_pieza(int i_inicial, int j_inicial, int i_final, int j_final)
{
    tablero[i_final][j_final] = tablero[i_inicial][j_inicial];
    tablero[i_inicial][j_inicial] ='.';

    if(tablero[i_inicial][j_inicial] =='r')
        contador_movi_rey_blanco++;
    if(tablero[i_inicial][j_inicial] =='R')
        contador_movi_rey_negro++;
    if(tablero[i_inicial][j_inicial] =='t')
        contador_movi_torre_blanco++;
    if(tablero[i_inicial][j_inicial] =='T')
        contador_movi_rey_negro++;
}
void imprimir_tablero()
{
    printf("\n");
        printf("   ");
    for(int f=0; f<8; f++)
    {
        printf(" %c  ", 'h' - f);
    }

      printf("\n");
    printf("  +-------------------------------+\n");
    for(int i=0; i<8; i++)
    {
        printf("%c ", '1' + i);
        printf("|");
        for(int j=0; j<8; j++)
        {
            printf(" %c  ",tablero[i][j]);
            printf("\b|");

        }

        printf("\n");
    }
    printf("  +-------------------------------+\n");


    printf("\n");
}
void posicion_inicial()
{
    tablero[0][0]='t';
    tablero[0][7]='t';
    tablero[7][0]='T';
    tablero[7][7]='T';

    tablero[0][5]='a';
    tablero[0][1]='c';

    tablero[7][5]='A';
    tablero[7][1]='C';

    tablero[0][2]='a';
    tablero[0][6]='c';

    tablero[7][2]='A';
    tablero[7][6]='C';

    tablero[0][3]='r';
    tablero[0][4]='d';

    tablero[7][4]='D';
    tablero[7][3]='R';

    tablero[1][0]='p';
    tablero[1][1]='p';
    tablero[1][2]='p';
    tablero[1][3]='p';
    tablero[1][4]='p';
    tablero[1][5]='p';
    tablero[1][6]='p';
    tablero[1][7]='p';

    tablero[6][0]='P';
    tablero[6][1]='P';
    tablero[6][2]='P';
    tablero[6][3]='P';
    tablero[6][4]='P';
    tablero[6][5]='P';
    tablero[6][6]='P';
    tablero[6][7]='P';
    for(int i=2; i<6; i++)
    {
        for(int j=0; j<8; j++)
        {
            tablero[i][j]='.';
        }
    }

}
int lee_ganador(int i_negro,int i_blanco)
{
    int rb=0,rn=0;
    char x;
    for(int i=0; i<8; i++)
    {
        for(int j=0; j<8; j++)
        {
            if (tablero[j][i]=='r')
                rb++;
            if (tablero[j][i]=='R')
                rn++;
        }
    }
    if(rb>rn)
    {
        printf("\nBlancas Gana");
        printf("pause");
        system("cls");
        printf("Digite 1 volver al menu");
        printf("Digite cualquier otra tecla para salir del juego");
        scanf(" %c",&x);
        if (x=='1')
            menu();
        return 1;
    }
    if(rn>rb)
    {
        printf("\nNegro Gana");
        printf("pause");
        system("cls");
        printf("Digite 1 volver al menu");
        printf("Digite cualquier otra tecla para salir del juego");
        scanf(" %c",&x);
        if (x=='1')
            menu();

        return 1;
    }
    return 0;
}
int lee_ganador_jugadores(int i_negro,int i_blanco)
{
    int rb=0,rn=0;
    char x;
    for(int i=0; i<8; i++)
    {
        for(int j=0; j<8; j++)
        {
            if (tablero[j][i]=='r')
                rb++;
            if (tablero[j][i]=='R')
                rn++;
        }
    }
    if(rb>rn)
    {
        printf("\n%s Gana",jugadores[i_blanco].nombre);
        jugadores[i_blanco].partidas_ganadas=++(jugadores[i_blanco].partidas_ganadas);
        printf("pause");
        system("cls");
        printf("Digite 1 volver al menu");
        printf("Digite cualquier otra tecla para salir del juego");
        scanf(" %c",&x);
        if (x=='1')
            menu();
        printf("Digite cualquier otra tecla para salir del juego");
        return 1;
    }
    if(rn>rb)
    {
        printf("\n%s Gana");
        jugadores[i_negro].partidas_ganadas=++(jugadores[i_negro].partidas_ganadas);

        printf("pause");
        system("cls");
        printf("Digite 1 volver al menu");
        printf("Digite cualquier otra tecla para salir del juego");
        scanf(" %c",&x);
        if (x=='1')
            menu();

        return 1;
    }
    return 0;
}
void leer_jugador(int n_jugadores,player jugadores[100])
{
    printf("\n");
    printf("Digite el nombre del Jugador");
    printf("\n");
    jugadores[n_jugadores].nombre=leer_string();
    guardar_archivo_texto(jugadores,n_jugadores);
}

int leer_archivo_texto(player jugadores[100])
{
    FILE * f,*p,*p1,*p2,*p3;
    char buff[500];
    int i;
    f = fopen("n_jugadores.txt", "r");
    p = fopen("nombre.txt", "r");
    p1 = fopen("ganadas.txt", "r");
    p2 = fopen("perdidas.txt","r");
    p3 = fopen("Promedio.txt", "r");
     if (f==NULL){
        return 0;
    }
    if (p==NULL){
        return 0;
    }
     if (p1==NULL){
        return 0;
    }
     if (p2==NULL){
        return 0;
    }
     if (p3==NULL){
        return 0;
    }
    fgets(buff,1024,f);
    n_jugadores=atoi(buff);

    for(i=0;i<n_jugadores;i++)
    {
        fgets(jugadores[i].nombre,1024,p);
        fgets(buff,1024,p1);
        jugadores[i].partidas_ganadas=atoi(buff);
        fgets(buff,1024,p2);
        jugadores[i].partidas_perdidas=atoi(buff);
        fgets(buff,1024,p3);
        jugadores[i].promedio=atof(buff);
    }

   return 1;
}
int numero_De_jugadores()
{
    FILE * p;
    p = fopen("n_jugadores.txt", "w");
    if (p==NULL){
        return 0;
    }
    fprintf(p,"%d", n_jugadores);
    fclose(p);
    return 1;


}
void score()
{
    cal_promedio();
    for(int i=0;i<n_jugadores;i++)
        {
            if (jugadores[i].promedio<(jugadores[i+1].promedio))
                suap(jugadores[i],jugadores[i+1]);
        }
    printf("\nLos Mejores Score son: \n");
    for(int j=0;j<n_jugadores;j++)
    {
       printf("%s",jugadores[j].nombre);
       printf("%d",jugadores[j].partidas_ganadas);
       printf("%d",jugadores[j].partidas_perdidas);
       printf("%.2f",jugadores[j].promedio);

    }

}
void cal_promedio()
{
    for(int i=0;i<n_jugadores;i++)
        {
            jugadores[i].promedio=jugadores[i].partidas_ganadas/(jugadores[i].partidas_perdidas+jugadores[i].partidas_ganadas);
        }
}
void suap(player jugador,player jugador2)
{
    player aux;
    aux.nombre=jugador.nombre;
    jugador.nombre=jugador2.nombre;
    jugador2.nombre=aux.nombre;

    aux.partidas_ganadas=jugador.partidas_ganadas;
    jugador.partidas_ganadas=jugador2.partidas_ganadas;
    jugador2.partidas_ganadas=aux.partidas_ganadas;


    aux.partidas_perdidas=jugador.partidas_perdidas;
    jugador.partidas_perdidas=jugador2.partidas_perdidas;
    jugador2.partidas_perdidas=aux.partidas_perdidas;


    aux.promedio=jugador.promedio;
    jugador.promedio=jugador2.promedio;
    jugador2.promedio=aux.promedio;
}
int guardar_archivo_texto(player jugadores[100],int i)
{
    FILE * p,*p1,*p2,*p3;
    char *buff;
    buff=(char*)malloc(500*sizeof(char));
    p = fopen("nombre.txt", "a+t");
    p1 = fopen("ganadas.txt", "a+t");
    p2 = fopen("perdidas.txt", "a+t");
    p3 = fopen("Promedio.txt", "a+t");
    if (p==NULL){
        return 0;
    }
    buff=jugadores[i].nombre;
    fputs(buff,p);
    itoa(jugadores[i].partidas_ganadas,buff,1000);
    fputs(buff,p1);
    itoa(jugadores[i].partidas_perdidas,buff,1000);
    fputs(buff,p2);
    itoa(jugadores[i].promedio,buff,1000);
    fputs(buff,p3);
    fclose(p);
    fclose(p1);
    fclose(p2);
    fclose(p3);
    return 1;
}
char *leer_string()
{
    char *nom;
    printf("\n");
    char c=0;
    int i=0;
    nom = (char *) malloc(1 * sizeof(char));
    *nom = '\0';
    while ((c=getch())!='\r')
    {
        printf("%c",c);
        nom = (char*) realloc(nom, (i+2)*sizeof(char));
        nom[i++] = c;
        nom[i]='\0';
    }
    printf("\n");
    return(nom);
}
void inicializar_arreglo()
{
    for(int i=0;i<100;i++)
    {
         jugadores[i].partidas_ganadas=0;
         jugadores[i].partidas_perdidas=0;

    }
    leer_archivo_texto(jugadores);

    return 1;
}
