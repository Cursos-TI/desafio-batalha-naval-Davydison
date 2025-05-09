#include <stdio.h>

#define TAM 10
#define H 5 // Tamanho da matriz da habilidade (5x5)
#define AGUA 0
#define NAVIO 3
#define AFETADO 5

// Inicializa o tabuleiro 10x10 com água (0)
void inicializarTabuleiro(int tabuleiro[TAM][TAM]) {
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }
}

// Coloca navios fixos para exemplo
void posicionarNavios(int tabuleiro[TAM][TAM]) {
    // Horizontal
    tabuleiro[2][3] = NAVIO;
    tabuleiro[2][4] = NAVIO;
    tabuleiro[2][5] = NAVIO;

    // Vertical
    tabuleiro[5][7] = NAVIO;
    tabuleiro[6][7] = NAVIO;
    tabuleiro[7][7] = NAVIO;
}

// Constrói uma matriz cone (forma de V invertido)
void construirCone(int matriz[H][H]) {
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < H; j++) {
            if (j >= (H / 2 - i) && j <= (H / 2 + i)) {
                matriz[i][j] = 1;
            } else {
                matriz[i][j] = 0;
            }
        }
    }
}

// Constrói matriz cruz (linha e coluna central)
void construirCruz(int matriz[H][H]) {
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < H; j++) {
            if (i == H / 2 || j == H / 2) {
                matriz[i][j] = 1;
            } else {
                matriz[i][j] = 0;
            }
        }
    }
}

// Constrói matriz octaedro (forma de losango)
void construirOctaedro(int matriz[H][H]) {
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < H; j++) {
            if (abs(i - H / 2) + abs(j - H / 2) <= H / 2) {
                matriz[i][j] = 1;
            } else {
                matriz[i][j] = 0;
            }
        }
    }
}

// Aplica matriz de habilidade no tabuleiro em ponto (linha, coluna)
void aplicarHabilidade(int tabuleiro[TAM][TAM], int matriz[H][H], int linha, int coluna) {
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < H; j++) {
            int tLinha = linha - H / 2 + i;
            int tColuna = coluna - H / 2 + j;

            // Verifica se está dentro dos limites
            if (tLinha >= 0 && tLinha < TAM && tColuna >= 0 && tColuna < TAM) {
                if (matriz[i][j] == 1 && tabuleiro[tLinha][tColuna] == AGUA) {
                    tabuleiro[tLinha][tColuna] = AFETADO;
                }
            }
        }
    }
}

// Imprime o tabuleiro com representação
void imprimirTabuleiro(int tabuleiro[TAM][TAM]) {
    printf("\nTabuleiro:\n");
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            if (tabuleiro[i][j] == AGUA)
                printf("~ ");  // Água
            else if (tabuleiro[i][j] == NAVIO)
                printf("N ");  // Navio
            else if (tabuleiro[i][j] == AFETADO)
                printf("* ");  // Área afetada
        }
        printf("\n");
    }
}

int main() {
    int tabuleiro[TAM][TAM];
    int cone[H][H], cruz[H][H], octaedro[H][H];

    inicializarTabuleiro(tabuleiro);
    posicionarNavios(tabuleiro);

    construirCone(cone);
    construirCruz(cruz);
    construirOctaedro(octaedro);

    // Aplica as habilidades com pontos de origem definidos
    aplicarHabilidade(tabuleiro, cone, 4, 4);
    aplicarHabilidade(tabuleiro, cruz, 6, 2);
    aplicarHabilidade(tabuleiro, octaedro, 7, 7);

    imprimirTabuleiro(tabuleiro);

    return 0;
}
