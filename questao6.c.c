#include <stdio.h>
#include <string.h>

struct Aluno {
    char nome[50];
    int matricula;
    float mediaFinal;
};

int main() {
    struct Aluno alunos[10];
    struct Aluno aprovados[10];
    struct Aluno reprovados[10];
    int i, ap = 0, rep = 0;

   
    printf("Digite os dados de 10 alunos:\n");
    for(i = 0; i < 10; i++) {
        printf("\nAluno %d:\n", i + 1);
        printf("Nome: ");
        scanf(" %[^\n]", alunos[i].nome); 
        printf("Matricula: ");
        scanf("%d", &alunos[i].matricula);
        printf("Media Final: ");
        scanf("%f", &alunos[i].mediaFinal);


        if(alunos[i].mediaFinal >= 5.0) {
            aprovados[ap] = alunos[i];
            ap++;
        } else {
            reprovados[rep] = alunos[i];
            rep++;
        }
    }


    printf("\n--- APROVADOS ---\n");
    for(i = 0; i < ap; i++) {
        printf("Nome: %s | Mat: %d | Media: %.2f\n", 
               aprovados[i].nome, aprovados[i].matricula, aprovados[i].mediaFinal);
    }

    
    printf("\n--- REPROVADOS ---\n");
    for(i = 0; i < rep; i++) {
        printf("Nome: %s | Mat: %d | Media: %.2f\n", 
               reprovados[i].nome, reprovados[i].matricula, reprovados[i].mediaFinal);
    }

    return 0;
}
