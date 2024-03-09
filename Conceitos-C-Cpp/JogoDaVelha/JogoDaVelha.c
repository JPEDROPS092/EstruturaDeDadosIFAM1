#include<stdio.h>
#include<stdlib.h>

#define linha 3
#define coluna 3
const int VERDADE = 1;
const char O = 'o', X = 'x';

void GerarTabuleiro(unsigned char Tab[linha][coluna]) {
    int i, j;
    printf("Tabuleio:\n");

    // Corrigido: Mudar a condição para i < linha
    for (i = 0; i < linha; i++) {
        // Corrigido: Mudar a condição para j < coluna
        for (j = 0; j < coluna; j++) {
            printf("[ ]");
        }
        printf("\n");
    }
}

// Imprimir Tabuleiro
void ImprimirTabuleiro(unsigned char Tab[linha][coluna]) {
    // Corrigido: Mudar a condição para i < linha
    for (int i = 0; i < linha; i++) {
        // Corrigido: Mudar a condição para j < coluna
        for (int j = 0; j < coluna; j++) {
            // Corrigido: Imprimir o caractere correto
            printf("[ %c ]", Tab[i][j]);
        }
        // Nova linha após cada linha do tabuleiro
        printf("\n");
    }
}

// Verificar vitoria 
int VerificarVitoria(unsigned char Tab[linha][coluna], unsigned char jogador) {
    return (
        // Corrigido: Índices corretos para verificação de vitória
        (Tab[0][0] == jogador && Tab[1][1] == jogador && Tab[2][2] == jogador) ||
        (Tab[0][0] == jogador && Tab[0][1] == jogador && Tab[0][2] == jogador) ||
        (Tab[2][0] == jogador && Tab[2][1] == jogador && Tab[2][2] == jogador) ||
        (Tab[1][0] == jogador && Tab[1][1] == jogador && Tab[1][2] == jogador) ||
        (Tab[0][2] == jogador && Tab[1][2] == jogador && Tab[2][2] == jogador) ||
        (Tab[2][0] == jogador && Tab[1][1] == jogador && Tab[0][2] == jogador) ||
        (Tab[0][1] == jogador && Tab[1][1] == jogador && Tab[2][1] == jogador) ||
        (Tab[0][0] == jogador && Tab[1][0] == jogador && Tab[2][0] == jogador));
}

void jogar(unsigned char Tab[linha][coluna], unsigned char jogador, int *jogadas) {
    int linhaEscolhida, colunaEscolhida;

    printf("Informe a linha (1 a 3) e a coluna (1 a 3) para jogar (separadas por espaço): ");
    scanf("%d %d", &linhaEscolhida, &colunaEscolhida);

    // Verificar se a posição escolhida é válida
    if (linhaEscolhida < 1 || linhaEscolhida > linha || colunaEscolhida < 1 || colunaEscolhida > coluna || Tab[linhaEscolhida - 1][colunaEscolhida - 1] != ' ') {
        printf("Posição inválida. Tente novamente.\n");
        return;  // Sair da função sem incrementar o número de jogadas
    }

    // Preencher a posição escolhida com o caractere do jogador
    Tab[linhaEscolhida - 1][colunaEscolhida - 1] = jogador;

    // Incrementar corretamente o número de jogadas
    (*jogadas)++;
}

int main() {
    int Jogadas = 0;
    unsigned char Tab[linha][coluna];
    // Corrigido: Remover índices específicos, passar a matriz como argumento
    GerarTabuleiro(Tab);

    while (1) {
        if (VerificarVitoria(Tab, O)) {
            printf("Parabens, o Jogador numero 1 ganhou\n");
            break;
        }
        if (VerificarVitoria(Tab, X)) {
            printf("Parabens, o Jogador numero 2 ganhou\n");
            break;
        }
        // Corrigido: Mudar a condição para Jogadas >= 8
        if (Jogadas >= 9) {
            printf("Partida empatada\n");
            break;
        }
        if (Jogadas % 2 == 0) {
            printf("Vez do jogador 1\n");
            jogar(Tab, O, &Jogadas);
        } else {
            puts("Vez do jogador 2");
            jogar(Tab, X, &Jogadas);
        }
    }

    return 0;
}
