// EXERCÍCIO 1298 DO BEECROWD - FLÁVIO GALLO CAJAZEIRA
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX 1205

bool dir[MAX][MAX], esq[MAX][MAX], cima[MAX][MAX], baixo[MAX][MAX];
bool visited[MAX][MAX];
int st_x[MAX * MAX];
int st_y[MAX * MAX];
int N;

void dfs_iterative(int start_i, int start_j) {
    int top = 0;
    st_x[top] = start_i;
    st_y[top] = start_j;
    top++;
    visited[start_i][start_j] = true;

    while (top > 0) {
        top--;
        int i = st_x[top];
        int j = st_y[top];

        if (i > 1 && !visited[i - 1][j] && cima[i][j]) {
            visited[i - 1][j] = true;
            st_x[top] = i - 1;
            st_y[top] = j;
            top++;
        }

        if (i < 2 * N && !visited[i + 1][j] && baixo[i][j]) {
            visited[i + 1][j] = true;
            st_x[top] = i + 1;
            st_y[top] = j;
            top++;
        }

        if (j > 1 && !visited[i][j - 1] && esq[i][j]) {
            visited[i][j - 1] = true;
            st_x[top] = i;
            st_y[top] = j - 1;
            top++;
        }

        if (j < 2 * N + 1 && !visited[i][j + 1] && dir[i][j]) {
            visited[i][j + 1] = true;
            st_x[top] = i;
            st_y[top] = j + 1;
            top++;
        }
    }
}

int main() {
    int x, y, res;
    char c;

    while (scanf("%d", &N) != EOF) {
        for (int i = 1; i <= 2 * N; i++) {
            memset(visited[i], 0, (2 * N + 2) * sizeof(bool)); 
            for (int j = 1; j <= 2 * N + 1; j++) {
                dir[i][j] = (j < 2 * N + 1);
                esq[i][j] = (j > 1);
                cima[i][j] = (i > 1);
                baixo[i][j] = (i < 2 * N);
            }
        }

        for (int i = 1; i <= 2 * N - 1; i++) {
            for (int j = 1; j <= N; j++) {
                scanf(" %c", &c);
                x = i;
                if (i % 2 == 0) y = 2 * j;
                else y = 2 * j - 1;

                bool isH = (c == 'H');
                bool isV = (c == 'V');

                dir[x][y] = dir[x + 1][y] = esq[x][y + 1] = esq[x + 1][y + 1] = isH;
                cima[x + 1][y] = cima[x + 1][y + 1] = baixo[x][y] = baixo[x][y + 1] = isV;
            }
        }

        res = 0;
        for (int i = 1; i <= 2 * N; i++) {
            for (int j = 1; j <= 2 * N + 1; j++) {
                if (!visited[i][j]) {
                    res++;
                    dfs_iterative(i, j);
                }
            }
        }
      
        printf("%d\n", res - 1);
    }

    return 0;
}
