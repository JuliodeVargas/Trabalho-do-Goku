#include <stdio.h>

int main(void) {
    int v[5];

    printf("Questao 2\n");
    printf("Digite 5 numeros inteiros:\n");
    for (int i = 0; i < 5; i++) {
        printf("v[%d] = ", i);
        scanf("%d", &v[i]);
    }

    printf("Vetor na ordem inversa: ");
    for (int i = 4; i >= 0; i--) {
        printf("%d", v[i]);
        if (i != 0) printf(" ");
    }
    printf("\n");

    return 0;
}
