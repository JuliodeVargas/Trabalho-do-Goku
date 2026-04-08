#include <stdio.h>

int main(void) {
    char p1[101], p2[101], p3[101];

    printf("Questao 1\n");
    printf("Digite 3 palavras (separadas por espaco): ");
    scanf("%100s %100s %100s", p1, p2, p3);

    printf("Ordem inversa: %s %s %s\n", p3, p2, p1);
    return 0;
} 
