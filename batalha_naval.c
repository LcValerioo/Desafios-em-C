#include <stdio.h>

#define TAM_PEQ 5  // Tamanho das matrizes pequenas (5x5)
#define TAM_GRANDE 10  // Tamanho da matriz maior (10x10)

void inicializarMatriz(int matriz[TAM_PEQ][TAM_PEQ]) {
    for (int i = 0; i < TAM_PEQ; i++) {
        for (int j = 0; j < TAM_PEQ; j++) {
            matriz[i][j] = 0;  // Preenche com 0
        }
    }
}

void desenharCone(int matriz[TAM_PEQ][TAM_PEQ]) {
    for (int i = 0; i < TAM_PEQ; i++) {
        for (int j = TAM_PEQ / 2 - i; j <= TAM_PEQ / 2 + i && j < TAM_PEQ; j++) {
            matriz[i][j] = 1;
        }
    }
}

void desenharCruz(int matriz[TAM_PEQ][TAM_PEQ]) {
    for (int i = 0; i < TAM_PEQ; i++) {
        matriz[i][TAM_PEQ / 2] = 2;  // Linha vertical
        matriz[TAM_PEQ / 2][i] = 2;  // Linha horizontal
    }
}

void desenharOctaedro(int matriz[TAM_PEQ][TAM_PEQ]) {
    for (int i = 0; i < TAM_PEQ; i++) {
        for (int j = TAM_PEQ / 2 - i; j <= TAM_PEQ / 2 + i && j < TAM_PEQ; j++) {
            if (i <= TAM_PEQ / 2)
                matriz[i][j] = 3;  // Parte superior do octaedro
            else
                matriz[TAM_PEQ - 1 - i][j] = 3;  // Parte inferior
        }
    }
}

void copiarParaMatrizGrande(int grande[TAM_GRANDE][TAM_GRANDE], int pequena[TAM_PEQ][TAM_PEQ], int offsetX, int offsetY) {
    for (int i = 0; i < TAM_PEQ; i++) {
        for (int j = 0; j < TAM_PEQ; j++) {
            if (pequena[i][j] != 0)  // Apenas copia os valores diferentes de 0
                grande[offsetX + i][offsetY + j] = pequena[i][j];
        }
    }
}

void imprimirMatriz(int matriz[TAM_GRANDE][TAM_GRANDE]) {
    char linha[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
    int coluna[10] = {1,2,3,4,5,6,7,8,9,10};
    
    printf("---TABULEIRO DO JOGO---\n");
    printf("  ");

    
    for (int i = 0; i < TAM_GRANDE; i++) {
         printf("%2c ", linha[i]);
        }
        printf("\n");  // Corrigido para quebrar a linha corretamente
        for (int i = 0; i < TAM_GRANDE; i++) {
        // Impressão da coluna numerada
        printf("%2d", coluna[i]);

        for (int j = 0; j < TAM_GRANDE; j++) {
            printf(" %d ", matriz[i][j]);
        }
        printf("\n");  // Para formatar corretamente o tabuleiro
    }
}

int main() {
    int cone[TAM_PEQ][TAM_PEQ], cruz[TAM_PEQ][TAM_PEQ], octaedro[TAM_PEQ][TAM_PEQ];
    int matrizGrande[TAM_GRANDE][TAM_GRANDE] = {0}; // Inicializa toda a matriz com 0

    // Inicializar matrizes pequenas
    inicializarMatriz(cone);
    inicializarMatriz(cruz);
    inicializarMatriz(octaedro);

    // Desenhar figuras
    desenharCone(cone);
    desenharCruz(cruz);
    desenharOctaedro(octaedro);

    // Copiar as matrizes pequenas para a matriz grande
    copiarParaMatrizGrande(matrizGrande, cone, 0, 0);       // Cone no canto superior esquerdo
    copiarParaMatrizGrande(matrizGrande, cruz, 0, 5);       // Cruz no canto superior direito
    copiarParaMatrizGrande(matrizGrande, octaedro, 5, 2);   // Octaedro no centro inferior

    // Imprimir matriz final
    imprimirMatriz(matrizGrande);

    return 0;
}