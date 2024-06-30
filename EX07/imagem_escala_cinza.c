#include <stdio.h>

int main() {
    // Definir as dimensões da imagem
    const int IMAGE_WIDTH = 100;
    const int IMAGE_HEIGHT = 256;

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
    for (int y = 0; y < IMAGE_HEIGHT; y++) {
        for (int x = 0; x < IMAGE_WIDTH; x++) {
            // Escrever valores sequenciais de 0 a 255 para cada pixel
            fprintf(file, "%d ", y);
        }
        fprintf(file, "\n");
    }

    // Fechar o arquivo
    fclose(file);

    printf("Arquivo 'imagem_escala_cinza.pgm' gerado com sucesso.\n");
    return 0;
}