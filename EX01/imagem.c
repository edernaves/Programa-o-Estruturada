#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main() {
    // Inicializa o gerador de números aleatórios
    srand(time(NULL));

    // Abre o arquivo "imagem.pbm" em modo de escrita
    FILE *file = fopen("imagem.pbm", "w");

    // Verifica se o arquivo foi aberto corretamente
    if (file == NULL) {
        printf("Erro ao criar o arquivo 'imagem.pbm'.\n");
        return 1;
    }

    // Escreve as primeiras três linhas do arquivo
    fprintf(file, "P1\n");
    fprintf(file, "#imagem.pbm\n");
    fprintf(file, "100 100\n");

    // Gera a matriz 100x100 com números aleatórios entre 0 e 1
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            fprintf(file, "%d ", rand() % 2);
        }
        fprintf(file, "\n");
    }

    // Fecha o arquivo
    fclose(file);

    printf("Arquivo 'imagem.pbm' criado com sucesso!\n");

    return 0;
}