#include <stdio.h>

int main(void) {
    int m[3][3];

    printf("Questao 3\n");
    printf("Digite os 9 elementos da matriz 3x3 (linha por linha):\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("m[%d][%d] = ", i, j);
            scanf("%d", &m[i][j]);
        }
    }

    printf("Matriz resultante (cada elemento * 5):\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d", m[i][j] * 5);
            if (j < 2) printf(" ");
        }
        printf("\n");
    }

    return 0;
}
