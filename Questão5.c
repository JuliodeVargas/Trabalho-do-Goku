#include <stdio.h>

int main(void) {
    int v[3];
    int M[3][3];
    int res[3];

    printf("Questao 5\n");
    printf("Digite os 3 elementos do vetor v:\n");
    for (int i = 0; i < 3; i++) {
        printf("v[%d] = ", i);
        scanf("%d", &v[i]);
    }

    printf("Digite os 9 elementos da matriz M (3x3), linha por linha:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("M[%d][%d] = ", i, j);
            scanf("%d", &M[i][j]);
        }
    }

    // Multiplicando o vetor pelas colunas:
    // res[j] = v[0]*M[0][j] + v[1]*M[1][j] + v[2]*M[2][j]
    for (int j = 0; j < 3; j++) {
        int soma = 0;
        for (int i = 0; i < 3; i++) soma += v[i] * M[i][j];
        res[j] = soma;
    }

    printf("Resultado (vetor v multiplicado pelas colunas de M):\n");
    printf("res = [ %d %d %d ]\n", res[0], res[1], res[2]);

    return 0;
}
