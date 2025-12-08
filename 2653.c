// EXERCÍCIO 2653 DO BEEDROWD - FLÁVIO GALLO CAJAZEIRA
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRINGS 1000005

char *list[MAX_STRINGS];

int compare(const void *a, const void *b) {
    return strcmp(*(const char **)a, *(const char **)b);
}

int main() {
    static char buffer[1000005]; 
    int n = 0;

    while (scanf("%s", buffer) != EOF) {
        list[n] = (char *)malloc((strlen(buffer) + 1) * sizeof(char));
        strcpy(list[n], buffer);
        n++;
    }

    if (n == 0) {
        printf("0\n");
        return 0;
    }

    qsort(list, n, sizeof(char *), compare);

    int distinct = 1;
    for (int i = 1; i < n; i++) {
        if (strcmp(list[i], list[i - 1]) != 0) {
            distinct++;
        }
    }

    printf("%d\n", distinct);

    return 0;
}
