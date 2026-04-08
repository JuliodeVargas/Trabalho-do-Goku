#include <stdio.h>


int ordenarVerificar(int *a, int *b, int *c) {
    int temp;
 
    if (*a > *b) { temp = *a; *a = *b; *b = temp; }
    if (*a > *c) { temp = *a; *a = *c; *c = temp; }
    if (*b > *c) { temp = *b; *b = *c; *c = temp; }

   
    if (*a == *b && *b == *c) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    int v1, v2, v3, iguais;

    printf("Digite 3 valores inteiros:\n");
    scanf("%d %d %d", &v1, &v2, &v3);

    iguais = ordenarVerificar(&v1, &v2, &v3);

    printf("Valores ordenados: %d, %d, %d\n", v1, v2, v3);
    
    if (iguais) {
        printf("Os 3 valores são iguais.\n");
    } else {
        printf("Os valores são diferentes.\n");
    }

    return 0;
}