#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int getRandom(int min, int max) {
    return min + rand() % (max - min + 1);
}

int main() {
    FILE *file;
    int i, j;

    // Inicializa o gerador de números aleatórios
    srand(time(NULL));

    // Abre o arquivo em modo de escrita
    file = fopen("imagem.pgm", "w");

    // Verifica se o arquivo foi aberto com sucesso
    if (file == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return 1;
    }

    // Escreve o cabeçalho do arquivo PGM
    fprintf(file, "P2\n");
    fprintf(file, "60 100\n"); // 60 colunas e 100 linhas
    fprintf(file, "255\n"); // Valor máximo para o pixel (escala de cinza de 0 a 255)

    // Gera os pixels da imagem
    for (i = 0; i < 100; i++) {
        for (j = 0; j < 60; j++) {
            int pixelValue;
            if (i < 20) {
                pixelValue = getRandom(0, 55);
            } else if (i < 40) {
                pixelValue = getRandom(45, 105);
            } else if (i < 60) {
                pixelValue = getRandom(95, 155);
            } else if (i < 80) {
                pixelValue = getRandom(145, 205);
            } else {
                pixelValue = getRandom(195, 255);
            }
            fprintf(file, "%d ", pixelValue);
        }
        fprintf(file, "\n");
    }

    // Fecha o arquivo
    fclose(file);

    printf("Imagem gerada com sucesso!\n");

    return 0;
}
