#include <stdio.h>
#include <string.h>

struct Livro {
    char titulo[31];
    char autor[16];
    int ano;
};

int main () {
    struct Livro biblioteca[5];
    char buscaTitulo[31];
    int i, encontrado = 0;
    
    printf("Digite os dados de 5 livros:\n");
    for(i = 0; i < 5; i++) {
        printf("\nLivro %d:\n", i + 1);

        printf("Titulo: ");
        scanf(" %[^\n]", biblioteca[i].titulo);

        printf("Autor: ");
        scanf(" %[^\n]", biblioteca[i].autor);

        printf("Ano: ");
        scanf("%d", &biblioteca[i].ano);
        
    }
    printf("Digite o titulo para buscar: ");
    scanf(" %30[^\n]", buscaTitulo);
    

    printf("\n--- Livros Encontrados ---\n");
    for (i = 0; i < 5; i++) {
      
        if (strcmp(biblioteca[i].titulo, buscaTitulo) == 0) {
            printf("Titulo: %s\n", biblioteca[i].titulo);
            printf("Autor: %s\n", biblioteca[i].autor);
            printf("Ano: %d\n", biblioteca[i].ano);
            encontrado = 1;
        }
    }

    if (!encontrado) {
        printf("Nenhum livro encontrado com o titulo: %s\n", buscaTitulo);
    }

    return 0;
}