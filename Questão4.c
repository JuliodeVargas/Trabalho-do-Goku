#include <stdio.h>

static void imprimeMatriz3x3(const int X[3][3], const char *titulo) {
    printf("%s\n", titulo);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d", X[i][j]);
            if (j < 2) printf(" ");
        }
        printf("\n");
    }
}

int main(void) {
    int A[3][3], I[3][3], R[3][3];

    printf("Questao 4\n");
    printf("Digite os 9 elementos da matriz A (3x3), linha por linha:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("A[%d][%d] = ", i, j);
            scanf("%d", &A[i][j]);
        }
    }

    // Monta identidade I
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            I[i][j] = (i == j) ? 1 : 0;

    imprimeMatriz3x3(I, "Matriz identidade I (3x3):");

    // R = A * I
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            int soma = 0;
            for (int k = 0; k < 3; k++) {
                soma += A[i][k] * I[k][j];
            }
            R[i][j] = soma;
        }
    }

    imprimeMatriz3x3(A, "Matriz A informada:");
    imprimeMatriz3x3(R, "Resultado R = A * I (deve ser igual a A):");

    return 0;
}
