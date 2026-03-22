#include <stdio.h>

// Desafio Batalha Naval - MateCheck

int main() {
    // Tabuleiro 10x10 inicializado com 0 (água)
    int tabuleiro[10][10] = {0};

    // Tamanho dos navios para o nível novato
    const int tamanhoNavio = 3;

    // Navio horizontal (vetor unidimensional de tamanho 3) e coordenadas iniciaisb
    int navioHorizontal[3] = {3, 3, 3};
    int linhaH = 2; // índice de linha (0 a 9)
    int colunaH = 4; // índice da coluna inicial (0 a 9)

    // Navio vertical (vetor unidimensional de tamanho 3) e coordenadas iniciais
    int navioVertical[3] = {3, 3, 3};
    int linhaV = 6; // índice de linha inicial (0 a 9)
    int colunaV = 1; // índice da coluna (0 a 9)

    // Validação do posicionamento horizontal: dentro dos limites
    if (colunaH < 0 || colunaH + tamanhoNavio > 10 || linhaH < 0 || linhaH >= 10) {
        printf("Erro: navio horizontal fora dos limites do tabuleiro.\n");
        return 1;
    }

    // Validação do posicionamento vertical: dentro dos limites
    if (linhaV < 0 || linhaV + tamanhoNavio > 10 || colunaV < 0 || colunaV >= 10) {
        printf("Erro: navio vertical fora dos limites do tabuleiro.\n");
        return 1;
    }

    // Validação de sobreposição: verifica se alguma posição já está ocupada
    for (int i = 0; i < tamanhoNavio; i++) {
        if (tabuleiro[linhaH][colunaH + i] != 0) {
            printf("Erro: sobreposição detectada no navio horizontal na posição (%d, %d).\n", linhaH, colunaH + i);
            return 1;
        }
        if (tabuleiro[linhaV + i][colunaV] != 0) {
            printf("Erro: sobreposição detectada no navio vertical na posição (%d, %d).\n", linhaV + i, colunaV);
            return 1;
        }
    }

    // Posiciona navio horizontal no tabuleiro como valor 3
    for (int i = 0; i < tamanhoNavio; i++) {
        tabuleiro[linhaH][colunaH + i] = navioHorizontal[i];
    }

    // Posiciona navio vertical no tabuleiro como valor 3
    for (int i = 0; i < tamanhoNavio; i++) {
        tabuleiro[linhaV + i][colunaV] = navioVertical[i];
    }

    // Exibe o tabuleiro completo
    printf("Tabuleiro de Batalha Naval (0 = água, 3 = navio)\n");
    printf("   ");
    for (int c = 0; c < 10; c++) {
        printf(" %c", ('A' + c));
    }
    printf("\n");

    for (int linha = 0; linha < 10; linha++) {
        printf("%2d ", linha);
        for (int coluna = 0; coluna < 10; coluna++) {
            printf(" %d", tabuleiro[linha][coluna]);
        }
        printf("\n");
    }

    printf("\n");

    return 0;
}
