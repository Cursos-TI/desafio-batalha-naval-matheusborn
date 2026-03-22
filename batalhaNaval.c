#include <stdio.h>

// Desafio Batalha Naval - MateCheck

int main() {
    // Tabuleiro 10x10 inicializado com 0 (água)
    int tabuleiro[10][10] = {0};

    // Constante para tamanho dos navios (nível aventureiro mantém tamanho 3)
    const int tamanhoNavio = 3;

    // ==================================================
    // DEFINIÇÃO DOS NAVIOS - NÍVEL AVENTUREIRO
    // ==================================================

    // Navio 1: Horizontal (linha 2, colunas 4 a 6)
    int navioHorizontal[3] = {3, 3, 3};
    int linhaH = 2;
    int colunaH = 4;

    // Navio 2: Vertical (coluna 1, linhas 6 a 8)
    int navioVertical[3] = {3, 3, 3};
    int linhaV = 6;
    int colunaV = 1;

    // Navio 3: Diagonal principal (\ - linha e coluna aumentam simultaneamente)
    // Posição inicial: (0, 5) -> (1, 6) -> (2, 7)
    int navioDiagonal1[3] = {3, 3, 3};
    int linhaD1 = 0;
    int colunaD1 = 5;

    // Navio 4: Diagonal secundária (/ - linha aumenta, coluna diminui)
    // Posição inicial: (3, 8) -> (4, 7) -> (5, 6)
    int navioDiagonal2[3] = {3, 3, 3};
    int linhaD2 = 3;
    int colunaD2 = 8;

    // ==================================================
    // VALIDAÇÃO DOS NAVIOS
    // ==================================================

    // Validação horizontal: dentro dos limites
    if (colunaH < 0 || colunaH + tamanhoNavio > 10 || linhaH < 0 || linhaH >= 10) {
        printf("Erro: navio horizontal fora dos limites do tabuleiro.\n");
        return 1;
    }

    // Validação vertical: dentro dos limites
    if (linhaV < 0 || linhaV + tamanhoNavio > 10 || colunaV < 0 || colunaV >= 10) {
        printf("Erro: navio vertical fora dos limites do tabuleiro.\n");
        return 1;
    }

    // Validação diagonal principal: dentro dos limites
    if (linhaD1 < 0 || linhaD1 + tamanhoNavio > 10 || colunaD1 < 0 || colunaD1 + tamanhoNavio > 10) {
        printf("Erro: navio diagonal principal fora dos limites do tabuleiro.\n");
        return 1;
    }

    // Validação diagonal secundária: dentro dos limites
    if (linhaD2 < 0 || linhaD2 + tamanhoNavio > 10 || colunaD2 - tamanhoNavio + 1 < 0 || colunaD2 >= 10) {
        printf("Erro: navio diagonal secundária fora dos limites do tabuleiro.\n");
        return 1;
    }

    // ==================================================
    // VERIFICAÇÃO DE SOBREPOSIÇÃO
    // ==================================================

    // Função auxiliar: verifica se uma posição já está ocupada antes de posicionar
    // Navio horizontal
    for (int i = 0; i < tamanhoNavio; i++) {
        if (tabuleiro[linhaH][colunaH + i] != 0) {
            printf("Erro: sobreposição no navio horizontal na posição (%d, %d).\n", linhaH, colunaH + i);
            return 1;
        }
    }

    // Navio vertical
    for (int i = 0; i < tamanhoNavio; i++) {
        if (tabuleiro[linhaV + i][colunaV] != 0) {
            printf("Erro: sobreposição no navio vertical na posição (%d, %d).\n", linhaV + i, colunaV);
            return 1;
        }
    }

    // Navio diagonal principal
    for (int i = 0; i < tamanhoNavio; i++) {
        if (tabuleiro[linhaD1 + i][colunaD1 + i] != 0) {
            printf("Erro: sobreposição no navio diagonal principal na posição (%d, %d).\n", linhaD1 + i, colunaD1 + i);
            return 1;
        }
    }

    // Navio diagonal secundária
    for (int i = 0; i < tamanhoNavio; i++) {
        if (tabuleiro[linhaD2 + i][colunaD2 - i] != 0) {
            printf("Erro: sobreposição no navio diagonal secundária na posição (%d, %d).\n", linhaD2 + i, colunaD2 - i);
            return 1;
        }
    }

    // ==================================================
    // POSICIONAMENTO DOS NAVIOS
    // ==================================================

    // Posiciona navio horizontal
    for (int i = 0; i < tamanhoNavio; i++) {
        tabuleiro[linhaH][colunaH + i] = navioHorizontal[i];
    }

    // Posiciona navio vertical
    for (int i = 0; i < tamanhoNavio; i++) {
        tabuleiro[linhaV + i][colunaV] = navioVertical[i];
    }

    // Posiciona navio diagonal principal
    for (int i = 0; i < tamanhoNavio; i++) {
        tabuleiro[linhaD1 + i][colunaD1 + i] = navioDiagonal1[i];
    }

    // Posiciona navio diagonal secundária
    for (int i = 0; i < tamanhoNavio; i++) {
        tabuleiro[linhaD2 + i][colunaD2 - i] = navioDiagonal2[i];
    }

    // ==================================================
    // EXIBIÇÃO DO TABULEIRO
    // ==================================================

    printf("Tabuleiro de Batalha Naval - Nível Aventureiro\n");
    printf("(0 = água, 3 = navio)\n\n");

    // Exibe cabeçalho com colunas
    printf("    ");
    for (int c = 0; c < 10; c++) {
        printf(" %c", ('A' + c));
    }
    printf("\n");

    // Exibe linhas e colunas
    for (int linha = 0; linha < 10; linha++) {
        printf("%2d  ", linha);
        for (int coluna = 0; coluna < 10; coluna++) {
            printf(" %d", tabuleiro[linha][coluna]);
        }
        printf("\n");
    }

    printf("\n");

    return 0;
}
