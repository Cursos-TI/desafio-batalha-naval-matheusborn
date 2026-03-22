#include <stdio.h>

// Desafio Batalha Naval - MateCheck

#define AGUA 0
#define PODER_CONE 1
#define PODER_CRUZ 2
#define PODER_OCTAEDRO 5
#define VALOR_NAVIO 3

int main() {
    // Tabuleiro 10x10 inicializado com 0 (água)
    int tabuleiro[10][10] = {AGUA};

    // Constante para tamanho dos navios (nível aventureiro mantém tamanho 3)
    const int tamanhoNavio = 3;

    // ==================================================
    // DEFINIÇÃO DOS NAVIOS - NÍVEL AVENTUREIRO
    // ==================================================

    // Navio 1: Horizontal (linha 2, colunas 4 a 6)
    int navioHorizontal[3] = {VALOR_NAVIO, VALOR_NAVIO, VALOR_NAVIO};
    int linhaH = 2;
    int colunaH = 4;

    // Navio 2: Vertical (coluna 1, linhas 6 a 8)
    int navioVertical[3] = {VALOR_NAVIO, VALOR_NAVIO, VALOR_NAVIO};
    int linhaV = 6;
    int colunaV = 1;

    // Navio 3: Diagonal principal (\ - linha e coluna aumentam simultaneamente)
    // Posição inicial: (0, 5) -> (1, 6) -> (2, 7)
    int navioDiagonal1[3] = {VALOR_NAVIO, VALOR_NAVIO, VALOR_NAVIO};
    int linhaD1 = 0;
    int colunaD1 = 5;

    // Navio 4: Diagonal secundária (/ - linha aumenta, coluna diminui)
    // Posição inicial: (3, 8) -> (4, 7) -> (5, 6)
    int navioDiagonal2[3] = {VALOR_NAVIO, VALOR_NAVIO, VALOR_NAVIO};
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
    // HABILIDADES ESPECIAIS - NÍVEL MESTRE
    // ==================================================

    // Tamanho das matrizes de habilidade (5x5)
    const int tamanhoHab = 5;

    // Matriz de habilidade Cone (apontando para baixo)
    int habCone[5][5] = {0};
    for (int i = 0; i < tamanhoHab; i++) {
        for (int j = 0; j < tamanhoHab; j++) {
            if (i == 0 && j == 2) { // Topo do cone
                habCone[i][j] = 1;
            } else if (i == 1 && (j >= 1 && j <= 3)) { // Linha intermediária
                habCone[i][j] = 1;
            } else if (i == 2 && (j >= 0 && j <= 4)) { // Base do cone
                habCone[i][j] = 1;
            } else {
                habCone[i][j] = 0;
            }
        }
    }

    // Matriz de habilidade Cruz (centro na posição 2,2)
    int habCruz[5][5] = {0};
    for (int i = 0; i < tamanhoHab; i++) {
        for (int j = 0; j < tamanhoHab; j++) {
            if (i == 2 || j == 2) { // Linha ou coluna central
                habCruz[i][j] = 1;
            } else {
                habCruz[i][j] = 0;
            }
        }
    }

    // Matriz de habilidade Octaedro (forma de losango)
    int habOctaedro[5][5] = {0};
    for (int i = 0; i < tamanhoHab; i++) {
        for (int j = 0; j < tamanhoHab; j++) {
            if ((i == 0 || i == 4) && j == 2) { // Pontas superior e inferior
                habOctaedro[i][j] = 1;
            } else if ((i == 1 || i == 3) && (j >= 1 && j <= 3)) { // Linhas intermediárias
                habOctaedro[i][j] = 1;
            } else if (i == 2 && (j >= 0 && j <= 4)) { // Linha do meio
                habOctaedro[i][j] = 1;
            } else {
                habOctaedro[i][j] = 0;
            }
        }
    }

    // Pontos de origem das habilidades no tabuleiro
    int origemConeLinha = 2, origemConeColuna = 2; // Centro da habilidade na linha 2, coluna 2
    int origemCruzLinha = 5, origemCruzColuna = 3; // Centro na linha 5, coluna 3
    int origemOctaedroLinha = 7, origemOctaedroColuna = 7; // Centro na linha 7, coluna 7

    // Sobreposição das habilidades no tabuleiro
    // Para cada habilidade, calcula as posições afetadas e marca com os valores respectivos das habilidades se dentro dos limites

    // Habilidade Cone
    for (int i = 0; i < tamanhoHab; i++) {
        for (int j = 0; j < tamanhoHab; j++) {
            if (habCone[i][j] == 1) {
                int linhaTab = origemConeLinha + i - 2; // Centro na linha 2 da habilidade
                int colunaTab = origemConeColuna + j - 2;
                if (linhaTab >= 0 && linhaTab < 10 && colunaTab >= 0 && colunaTab < 10) {
                    tabuleiro[linhaTab][colunaTab] = PODER_CONE; // Marca área afetada
                }
            }
        }
    }

    // Habilidade Cruz
    for (int i = 0; i < tamanhoHab; i++) {
        for (int j = 0; j < tamanhoHab; j++) {
            if (habCruz[i][j] == 1) {
                int linhaTab = origemCruzLinha + i - 2;
                int colunaTab = origemCruzColuna + j - 2;
                if (linhaTab >= 0 && linhaTab < 10 && colunaTab >= 0 && colunaTab < 10) {
                    tabuleiro[linhaTab][colunaTab] = PODER_CRUZ; // Marca área afetada
                }
            }
        }
    }

    // Habilidade Octaedro
    for (int i = 0; i < tamanhoHab; i++) {
        for (int j = 0; j < tamanhoHab; j++) {
            if (habOctaedro[i][j] == 1) {
                int linhaTab = origemOctaedroLinha + i - 2;
                int colunaTab = origemOctaedroColuna + j - 2;
                if (linhaTab >= 0 && linhaTab < 10 && colunaTab >= 0 && colunaTab < 10) {
                    tabuleiro[linhaTab][colunaTab] = PODER_OCTAEDRO; // Marca área afetada
                }
            }
        }
    }

    // ==================================================
    // EXIBIÇÃO DO TABULEIRO
    // ==================================================

    printf("Tabuleiro de Batalha Naval - Nível Mestre\n");
    printf("(%d = água, %d = navio, %d = área afetada pela habilidade OCTAEDRO, %d = área afetada pela habilidade CRUZ, %d = área afetada pela habilidade CONE)\n\n", AGUA, VALOR_NAVIO, PODER_OCTAEDRO, PODER_CRUZ, PODER_CONE);

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
