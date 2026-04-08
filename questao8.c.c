#include <stdio.h>

int main() {
    int vetor[5];
    int *ptr = vetor; 

    printf("Digite 5 números inteiros:\n");

    for (int i = 0; i < 5; i++) {

        scanf("%d", (ptr + i)); 
    }

    printf("\nO dobro de cada valor é:\n");

  
    for (int i = 0; i < 5; i++) {
        printf("%d ", (*(ptr + i)) * 2);
    }
    printf("\n");

    return 0;
}