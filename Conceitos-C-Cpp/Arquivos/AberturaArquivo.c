#include<stdio.h>

int main(void){

    //Vincular Arquivo
    FILE *Arquivo;
    char NomeArquivo[100];

    puts("Digite o nome do arquivo :");
    gets(NomeArquivo);

    Arquivo = fopen(NomeArquivo,"r");

    if(Arquivo == NULL){

        puts("Nao foi possivel abrir arquivo");
    }else{
        puts("Arquivo aberto com sucesso");
        //Sempre que usar um arquivo fecha-lo.
        fclose(Arquivo);
        /*Utilizando o closeall
        fcloseall();*/

    }

    
    

    
    return 0;

}
