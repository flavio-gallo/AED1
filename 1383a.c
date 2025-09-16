#include <stdio.h>
#include <stdlib.h>

int validaLinhas(int matriz[9][9]) {
    for (int i = 0; i < 9; i++) {
        int vistos[10] = {0};
        for (int j = 0; j < 9; j++) {
            int num = matriz[i][j];
            if (num < 1 || num > 9 || vistos[num] == 1) {
                return 0;
            }
            vistos[num] = 1;
        }
    }
    return 1;
}

int validaColunas(int matriz[9][9]) {
    for (int j = 0; j < 9; j++) {
        int vistos[10] = {0};
        for (int i = 0; i < 9; i++) {
            int num = matriz[i][j];
            if (num < 1 || num > 9 || vistos[num] == 1) {
                return 0;
            }
            vistos[num] = 1;
        }
    }
    return 1;
}

int validaSubgrids(int matriz[9][9]) {
    for (int startRow = 0; startRow < 9; startRow += 3) {
        for (int startCol = 0; startCol < 9; startCol += 3) {
            int vistos[10] = {0};
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    int num = matriz[startRow + i][startCol + j];
                    if (num < 1 || num > 9 || vistos[num] == 1) {
                        return 0;
                    }
                    vistos[num] = 1;
                }
            }
        }
    }
    return 1;
}

int main() {
    int n, i, j, k;

    scanf("%d", &n);

    for (k = 1; k <= n; k++) {
        int sudoku[9][9];

        for (i = 0; i < 9; i++) {
            for (j = 0; j < 9; j++) {
                scanf("%d", &sudoku[i][j]);
            }
        }

        printf("Instancia %d\n", k);

        if (validaLinhas(sudoku) && validaColunas(sudoku) && validaSubgrids(sudoku)) {
            printf("SIM\n");
        } else {
            printf("NAO\n");
        }
        
        printf("\n");

    }

    return 0;
}
