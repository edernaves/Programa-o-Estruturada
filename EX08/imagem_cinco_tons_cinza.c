#include <stdio.h>

int main() {
    FILE *file;
    int i, j, k;
    int tones[5] = {0, 64, 128, 192, 255}; // Tons de cinza

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
    for (k = 0; k < 5; k++) { // Para cada tom de cinza
        for (i = 0; i < 20; i++) { // 20 linhas por tom
            for (j = 0; j < 60; j++) { // 60 colunas por linha
                fprintf(file, "%d ", tones[k]);
            }
            fprintf(file, "\n");
        }
    }

    // Fecha o arquivo
    fclose(file);

    printf("Imagem gerada com sucesso!\n");

    return 0;
}
