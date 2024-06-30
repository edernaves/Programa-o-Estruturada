#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Inicializa o gerador de números aleatórios
    srand(time(NULL));

    // Abre o arquivo "imagem2.pgm" em modo de escrita
    FILE *file = fopen("imagem2.pgm", "w");

    // Verifica se o arquivo foi aberto corretamente
    if (file == NULL) {
        printf("Erro ao criar o arquivo 'imagem2.pgm'.\n");
        return 1;
    }

    // Escreve as primeiras quatro linhas do arquivo
    fprintf(file, "P2\n");
    fprintf(file, "#imagem2.pgm\n");
    fprintf(file, "100 100\n");
    fprintf(file, "255\n");

    // Gera a matriz 100x100 com números aleatórios entre 0 e 255
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            fprintf(file, "%d ", rand() % 256);
        }
        fprintf(file, "\n");
    }

    // Fecha o arquivo
    fclose(file);

    printf("Arquivo 'imagem2.pgm' criado com sucesso!\n");

    return 0;
}