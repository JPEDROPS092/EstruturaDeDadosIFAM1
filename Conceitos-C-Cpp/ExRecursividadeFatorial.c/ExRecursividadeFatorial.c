#include <stdio.h>
#include <stdlib.h>
#include <string.h>
long int fatorial(long int n){
    
    if(n == 0 || n == 1){
        return 1 ;
    }else{
        return n * fatorial(n - 1); // n *(n-1)!
    }

}


int main(void)
{
    long int N;
    printf("Entre com valor para fatorial:\n");
    scanf("%ld",&N);
    if(N <= 0){
        printf("Nao E possivel calcualr Fatorial de zero\n");
    } 
    else{
        printf("o fatorial  de %d = %ld",N, fatorial(N));
    }
}


