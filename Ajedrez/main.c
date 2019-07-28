#include <stdio.h>
#include <ctype.h>
char tablero[8][8];
void posicion_inicial();
void juego();
void imprimir_tablero();
void leer_jugada(int *i_inicial, int *j_inicial,int *i_final,int *j_final,char turno);
void mover_pieza(int i_inicial, int j_inicial, int i_final, int j_final);
int main() {
    posicion_inicial();
    juego();
}
void juego()
{
    int i_inicial, j_inicial,turno=0;
    int i_final,j_final,aux;
    do
    {
        imprimir_tablero();
        imprimir_jugador(turno);
        leer_jugada(&i_inicial,&j_inicial,&i_final,&j_final,turno);
        aux=validar_(i_inicial,j_inicial,i_final,j_final);
        if(aux==1)
        {
            mover_pieza(i_inicial,j_inicial,i_final,j_final);
            turno=1-turno;
        }
        else if(aux==0)
        {
            printf("\njugada no valida");
        }

    }while(turno!=2);
}
int validar_(int i_inicial,int j_inicial,int i_final,int j_final)
{
//    if(tablero[i_inicial][j_inicial]=='t'||tablero[i_inicial][j_inicial]=='T')
//    return confirmar_torre(i_inicial,j_inicial,i_final,j_final);
//
//    if(tablero[i_inicial][j_inicial]=='a'||tablero[i_inicial][j_inicial]=='A')
//    return confirmar_alfil(i_inicial,j_inicial,i_final,j_final);
//
//    if(tablero[i_inicial][j_inicial]=='c'||tablero[i_inicial][j_inicial]=='C')
//    return confirmar_caballo(i_inicial,j_inicial,i_final,j_final);
//
//    if(tablero[i_inicial][j_inicial]=='d'||tablero[i_inicial][j_inicial]=='D')
//    return confirmar_dama(i_inicial,j_inicial,i_final,j_final);
//
//    if(tablero[i_inicial][j_inicial]=='r'||tablero[i_inicial][j_inicial]=='R')
//    return confirmar_rey(i_inicial,j_inicial,i_final,j_final);

    if(tablero[i_inicial][j_inicial]=='p')
    return confirmar_peon_blanco(i_inicial,j_inicial,i_final,j_final);
    if(tablero[i_inicial][j_inicial]=='P')
    return confirmar_peon_negro(i_inicial,j_inicial,i_final,j_final);

}
int confirmar_peon_blanco(int i_inicial,int j_inicial,int i_final,int j_final)
{
    int aux=i_inicial+1;
    if((aux)==(i_final))
        return 1;
    return 0;
}
int confirmar_peon_negro(int i_inicial,int j_inicial,int i_final,int j_final)
{
    int aux=i_inicial-1;
    if((aux)==(i_final))
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

void leer_jugada(int *i_inicial, int *j_inicial,int *i_final,int *j_final,char turno) {
    char desde[5], hasta[5];
    scanf("%s", desde);
    scanf("%s", hasta);

    *j_inicial = desde[0] - 'a';
    *i_inicial = desde[1] - '1';
    *j_final   = hasta[0] - 'a';
    *i_final   = hasta[1] - '1';


}
void mover_pieza(int i_inicial, int j_inicial, int i_final, int j_final) {
    tablero[i_final][j_final] = tablero[i_inicial][j_inicial];
    tablero[i_inicial][j_inicial] = '.';
}
void imprimir_tablero()
{
    printf("\n");
    printf("  +-------------------------------+\n");
    for(int i=0; i<8;i++)
    {
        printf("%c ", '1' + i);
        printf("|");
        for(int j=0;j<8;j++)
        {
            printf(" %c  ",tablero[i][j]);
            printf("\b|");

        }

        printf("\n");
    }
    printf("  +-------------------------------+\n");
    printf("   ");
    for(int f=0;f<8;f++)
    {
      printf(" %c  ", 'a' + f);
    }

    printf("\n");
}
void posicion_inicial()
{
    tablero[0][0]='t';
    tablero[0][7]='t';
    tablero[7][0]='T';
    tablero[7][7]='T';

    tablero[0][5]='a';
    tablero[0][1]='a';
    tablero[7][5]='A';
    tablero[7][1]='A';

    tablero[0][2]='c';
    tablero[0][6]='c';
    tablero[7][2]='C';
    tablero[7][6]='C';

    tablero[0][3]='d';
    tablero[0][4]='r';

    tablero[7][4]='R';
    tablero[7][3]='D';

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
    for(int i=2;i<6;i++)
    {
        for(int j=0;j<8;j++)
        {
            tablero[i][j]='.';
        }
    }

}
