#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char s[100], *ptr;
    printf("Digite sua string:");
    gets(s);

    //Criação de espaço na memoria para ser alocada copia de string.
    //um ponteiro sempre aponta para um endereço de mémoria
    ptr = (char * ) malloc(strlen(s)+1);/*+ 1 esta sendo colocado pois uma string sempre tem em seu final o valor ‘\0’*/
    if (ptr == NULL){
        printf("Falha na alocação de memória.\n");
    }else{
        strcpy(ptr,s);
        printf("String Origial:%s String cópia: %s\n",s, ptr);
    }

    //Liberação de mémoria
    free(ptr);

    return 0;
}
