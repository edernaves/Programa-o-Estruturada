#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Definir as dimensões da imagem
    const int IMAGE_WIDTH = 100;
    const int IMAGE_HEIGHT = 100;

    // Abrir o arquivo de saída
    FILE *file = fopen("imagem_escala_cinza.pgm", "w");
    if (file == NULL) {
        printf("Erro ao criar o arquivo.\n");
        return 1;
    }

    // Escrever o cabeçalho do arquivo .pgm
    fprintf(file, "P2\n");
    fprintf(file, "%d %d\n", IMAGE_WIDTH, IMAGE_HEIGHT);
    fprintf(file, "255\n");

    // Gerar a imagem em escala de cinza
    srand(time(NULL)); // Inicializar o gerador de números aleatórios
    for (int y = 0; y < IMAGE_HEIGHT; y++) {
        for (int x = 0; x < IMAGE_WIDTH; x++) {
            // Gerar um valor aleatório entre 0 e 255 para cada pixel
            int value = rand() % 256;
            fprintf(file, "%d ", value);
        }
        fprintf(file, "\n");
    }

    // Fechar o arquivo
    fclose(file);

    printf("Arquivo 'imagem_escala_cinza.pgm' gerado com sucesso.\n");
    return 0;
}