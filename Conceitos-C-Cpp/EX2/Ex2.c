#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Definindo constante através de diretiva de compilação
#define TAMANHO 30

struct Lista {
    int elementos[TAMANHO];
    int tamanho;
}; 

void preencheraleatorio(struct Lista *lista) {
    int i;
    srand(time(NULL));
    lista->tamanho = 10;
    
    for (i = 0; i < lista->tamanho; i++) {
        lista->elementos[i] = rand() % 100;
    }
}

void ImprimirLista(struct Lista *lista) {
    int i;
    for (i = 0; i < lista->tamanho; i++) {
        printf("O elemento %d da lista tem o valor de: %d\n", i + 1, lista->elementos[i]);
    }   
    printf("\n");
}

void AdicionarValor(struct Lista *lista, int Valor) {
    if (lista->tamanho < TAMANHO) {
        lista->elementos[lista->tamanho++] = Valor;
    } else {
        printf("A lista está cheia e não se pode adicionar número.\n");
    }
}

void RemoverValor(struct Lista *lista) {
    if (lista->tamanho > 0) {
        lista->tamanho--;
    } else {
        printf("Não foi possível retirar valor, a lista está vazia.\n");
    }    
}

int main(void) {
    struct Lista ListaEX;
    preencheraleatorio(&ListaEX);
   
    int valor, opcao;

    do {
        system("clear");
        ImprimirLista(&ListaEX);
        printf("\nMenu\n");
        printf("1.Inserir Valor\n");
        printf("2.Remover Valor\n");
        printf("0.Sair:\n");
        printf("Digite a opção desejada:\n");

        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                printf("Digite o valor a ser inserido na lista:\n");
                scanf("%d", &valor);
                AdicionarValor(&ListaEX, valor);
                break;

            case 2: 
                RemoverValor(&ListaEX);
                break;
            
            case 0:
                break;

            default:
                printf("Opção inválida. Tente novamente.\n");
        }
      
    } while (opcao != 0);

    return 0;
}
