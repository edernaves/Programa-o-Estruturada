#include <stdio.h>

void gerar_labirinto(int labirinto[11][11]) {
    // Labirinto de exemplo (11x11)
    int exemplo[11][11] = {
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, //1
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, //2 
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1}, //3 
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, //4
        {1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1}, //5
        {0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0}, //6
        {1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1}, //7
        {1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1}, //8
        {1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1}, //9
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, //10
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}  //11
    };

    // Copia o exemplo para o labirinto
    for (int i = 0; i < 11; i++) {
        for (int j = 0; j < 11; j++) {
            labirinto[i][j] = exemplo[i][j];
        }
    }
}

void salvar_labirinto_pbm(const char *filename, int labirinto[11][11]) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    // Cabeçalho do PBM
    fprintf(file, "P1\n");
    fprintf(file, "11 11\n");

    // Dados da imagem
    for (int i = 0; i < 11; i++) {
        for (int j = 0; j < 11; j++) {
            fprintf(file, "%d ", labirinto[i][j]);
        }
        fprintf(file, "\n");
    }

    fclose(file);
}

int main() {
    int labirinto[11][11];
    gerar_labirinto(labirinto);
    salvar_labirinto_pbm("labirinto.pbm", labirinto);
    printf("Labirinto salvo em 'labirinto.pbm'\n");
    return 0;
}
