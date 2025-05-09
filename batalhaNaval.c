#include <stdio.h>

#define TAM 10
#define NAVIO 3
#define OCUPADO 3
#define AGUA 0

// Função auxiliar para verificar se posições estão livres
int estaLivre(int tabuleiro[TAM][TAM], int linha[], int coluna[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        if (tabuleiro[linha[i]][coluna[i]] != AGUA) {
            return 0; // Ocupado
        }
    }
    return 1; // Livre
}

// Função auxiliar para posicionar o navio
void posicionarNavio(int tabuleiro[TAM][TAM], int linha[], int coluna[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        tabuleiro[linha[i]][coluna[i]] = OCUPADO;
    }
}

int main() {
    int tabuleiro[TAM][TAM];

    // Inicializar o tabuleiro com 0
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }

    // Navio 1 - Horizontal (linha 1, colunas 2,3,4)
    int navio1_linha[NAVIO] = {1, 1, 1};
    int navio1_coluna[NAVIO] = {2, 3, 4};

    if (estaLivre(tabuleiro, navio1_linha, navio1_coluna, NAVIO)) {
        posicionarNavio(tabuleiro, navio1_linha, navio1_coluna, NAVIO);
    }

    // Navio 2 - Vertical (coluna 6, linhas 4,5,6)
    int navio2_linha[NAVIO] = {4, 5, 6};
    int navio2_coluna[NAVIO] = {6, 6, 6};

    if (estaLivre(tabuleiro, navio2_linha, navio2_coluna, NAVIO)) {
        posicionarNavio(tabuleiro, navio2_linha, navio2_coluna, NAVIO);
    }

    // Navio 3 - Diagonal principal (linhas/colunas 0,1,2)
    int navio3_linha[NAVIO] = {0, 1, 2};
    int navio3_coluna[NAVIO] = {0, 1, 2};

    if (estaLivre(tabuleiro, navio3_linha, navio3_coluna, NAVIO)) {
        posicionarNavio(tabuleiro, navio3_linha, navio3_coluna, NAVIO);
    }

    // Navio 4 - Diagonal secundária (linhas 7,8,9 / colunas 2,1,0)
    int navio4_linha[NAVIO] = {7, 8, 9};
    int navio4_coluna[NAVIO] = {2, 1, 0};

    if (estaLivre(tabuleiro, navio4_linha, navio4_coluna, NAVIO)) {
        posicionarNavio(tabuleiro, navio4_linha, navio4_coluna, NAVIO);
    }

    // Exibir o tabuleiro
    printf("Tabuleiro Batalha Naval (0 = água, 3 = navio):\n\n");

    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
