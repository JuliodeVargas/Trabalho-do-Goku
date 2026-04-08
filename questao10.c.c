#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Aluno {
    char nome[50];
    float nota;
};


struct Aluno* maiorNota(struct Aluno *alunos, int n) {
    struct Aluno *maior = alunos; 

    for (int i = 1; i < n; i++) {
        if ((alunos + i)->nota > maior->nota) {
            maior = (alunos + i);
        }
    }

    return maior;
}

int main() {
    int n;

    printf("Digite a quantidade de alunos: ");
    scanf("%d", &n);

    
    struct Aluno *alunos = (struct Aluno*) malloc(n * sizeof(struct Aluno));

    if (alunos == NULL) {
        printf("Erro de alocacao de memoria!\n");
        return 1;
    }

  
    for (int i = 0; i < n; i++) {
        printf("\nAluno %d:\n", i + 1);

        printf("Nome: ");
        scanf(" %[^\n]", (alunos + i)->nome);

        printf("Nota: ");
        scanf("%f", &((alunos + i)->nota));
    }

    
    struct Aluno *melhor = maiorNota(alunos, n);

   
    printf("\nAluno com maior nota:\n");
    printf("Nome: %s\n", melhor->nome);
    printf("Nota: %.2f\n", melhor->nota);

    
    free(alunos);

    return 0;
}
