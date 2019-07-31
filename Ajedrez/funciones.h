#ifndef funcione_h

#include <stdio.h>
#include <ctype.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>

typedef struct jugador{
    char *nombre;
    int partidas_ganadas;
    int partidas_perdidas;
    float promedio;
}player;
player jugadores[100];
char *leer_usuario();
void imprimir_jugador2(int turno,int i_jugador,int i_jugador2);
char tablero[8][8];
void suap(player jugador,player jugador2);
int guardar_archivo_texto(player jugadores[100],int i);
void agregar_jugador();
void cal_promedio();
void score();
void juego_nombre();
char *leer_string();
void inicializar_arreglo();
void posicion_inicial();
int menu();
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

#endif
