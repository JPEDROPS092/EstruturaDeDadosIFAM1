#include <stdio.h>

struct Lista
{
    int elementos[100];
    int quantidade;
};

void entradadedados(struct Lista *lista) {
    int i;
    printf("Digite a quantidade de elementos para armazenar na lista:\n");
    scanf("%d", &lista->quantidade);

    for (i = 1; i <= lista->quantidade; i++)
    {
        printf("Digite o elemento %d:\n", i);
        scanf("%d", &lista->elementos[i]);
    }
}

void saidadedados(struct Lista *lista) {
    int i;
    for (i = 1; i <= lista->quantidade; i++) {
        printf("O valor do elemento %d: %d\n", i, lista->elementos[i]);
    }
}

int main() {
    struct Lista minhaLista; // Crie uma instância da estrutura
    entradadedados(&minhaLista); // Passe um ponteiro para a instância
    saidadedados(&minhaLista);
    return 0;
}
