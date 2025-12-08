// EXERCÍCIO 1100 DO BEECROWD - FLÁVIO GALLO CAJAZEIRA
#include <stdio.h>
#include <string.h>

typedef struct {
    int x, y, moves;
} State;

int main() {
    char s1[5], s2[5];
    int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
    int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};

    while (scanf("%s %s", s1, s2) != EOF) {
        int startX = s1[0] - 'a';
        int startY = s1[1] - '1';
        int endX = s2[0] - 'a';
        int endY = s2[1] - '1';

        if (startX == endX && startY == endY) {
            printf("To get from %s to %s takes 0 knight moves.\n", s1, s2);
            continue;
        }

        int visited[8][8];
        memset(visited, 0, sizeof(visited));

        State queue[100];
        int front = 0, rear = 0;

        queue[rear].x = startX;
        queue[rear].y = startY;
        queue[rear].moves = 0;
        rear++;
        visited[startX][startY] = 1;

        int found = 0;
        int result = 0;

        while (front < rear) {
            State current = queue[front++];

            if (current.x == endX && current.y == endY) {
                result = current.moves;
                found = 1;
                break;
            }

            for (int i = 0; i < 8; i++) {
                int nx = current.x + dx[i];
                int ny = current.y + dy[i];

                if (nx >= 0 && nx < 8 && ny >= 0 && ny < 8 && !visited[nx][ny]) {
                    visited[nx][ny] = 1;
                    queue[rear].x = nx;
                    queue[rear].y = ny;
                    queue[rear].moves = current.moves + 1;
                    rear++;
                }
            }
        }

        if (found) {
            printf("To get from %s to %s takes %d knight moves.\n", s1, s2, result);
        }
    }

    return 0;
}
