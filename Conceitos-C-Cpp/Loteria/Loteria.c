#include<stdio.h>
#include <time.h>
#define Jogos 50
#define N 6



int main(void){
    //Geração de semente de Numero aleatorio.
    srand(time(NULL));
    
    //Criação de Array de duas dimenções e váriaveis para percorre-los.
    int Array[Jogos][N], i, j;
    //Preenchimento de array atraves de numeros aleatorios 
    for(i= 0; i<=Jogos ; i++){
        for(j=0;j <=N;j++ ){
            Array[i][j] = rand() % 60;
        }
    }
    //Impressão de jogos da loteria .
    for(i= 0; i<=Jogos ; i++){
        printf("Jogo Numero %d:\t",i );
        for(j=0;j <=N;j++ ){
            printf("%d\t",Array[i][j]) ;
        }
        puts("");
    }



}
