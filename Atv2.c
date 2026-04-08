#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
========================================================
ESTRUTURA DA PILHA (DINÂMICA)
========================================================

Cada elemento da pilha é um "nó" que guarda:
- um caractere (data)
- um ponteiro para o próximo elemento (next)

A pilha funciona no modelo LIFO:
Last In, First Out (último que entra, primeiro que sai)
*/

typedef struct Node {
    char data;
    struct Node* next;
} Node;

/*
========================================================
FUNÇÃO PUSH (EMPILHAR)
========================================================

Adiciona um elemento no topo da pilha
*/
void push(Node** top, char value) {
    Node* newNode = (Node*) malloc(sizeof(Node));

    newNode->data = value;     // guarda o valor
    newNode->next = *top;      // aponta para o topo atual
    *top = newNode;            // atualiza o topo
}

/*
========================================================
FUNÇÃO POP (DESEMPILHAR)
========================================================

Remove o elemento do topo da pilha
*/
char pop(Node** top) {
    if (*top == NULL) return '\0';

    Node* temp = *top;
    char value = temp->data;

    *top = temp->next; // move o topo
    free(temp);        // libera memória

    return value;
}

/*
========================================================
VERIFICA SE A PILHA ESTÁ VAZIA
========================================================
*/
int isEmpty(Node* top) {
    return top == NULL;
}

/*
========================================================
QUESTÃO 1 - VERIFICAR EXPRESSÃO BALANCEADA
========================================================

Exemplo de entrada esperada:
{[()]}  -> válida
{[(])}  -> inválida

Regras:
- Todo símbolo aberto deve ser fechado corretamente
- A ordem deve ser respeitada
*/
int isBalanced(char* exp) {
    Node* stack = NULL;

    for (int i = 0; i < strlen(exp); i++) {
        char c = exp[i];

        // Se for abertura → empilha
        if (c == '(' || c == '{' || c == '[') {
            push(&stack, c);
        }

        // Se for fechamento → verifica
        else if (c == ')' || c == '}' || c == ']') {

            if (isEmpty(stack)) return 0;

            char top = pop(&stack);

            // Verifica se corresponde corretamente
            if ((c == ')' && top != '(') ||
                (c == '}' && top != '{') ||
                (c == ']' && top != '[')) {
                return 0;
            }
        }
    }

    // Se a pilha estiver vazia → válido
    return isEmpty(stack);
}

/*
========================================================
QUESTÃO 2 - INVERTER STRING
========================================================

Exemplo:
Entrada:  casa
Saída:    asac

Funcionamento:
- Empilha todos os caracteres
- Depois desempilha substituindo na string
*/
void reverseString(char* str) {
    Node* stack = NULL;

    // Empilha cada caractere
    for (int i = 0; i < strlen(str); i++) {
        push(&stack, str[i]);
    }

    // Desempilha e sobrescreve
    for (int i = 0; i < strlen(str); i++) {
        str[i] = pop(&stack);
    }
}

/*
========================================================
FUNÇÃO PRINCIPAL
========================================================
*/

int main() {
    char exp[100];
    char str[100];

    printf("========================================\n");
    printf("      ATIVIDADE AVALIATIVA 2\n");
    printf("========================================\n\n");

    /*
    ------------------------------
    QUESTÃO 1
    ------------------------------
    */
    printf("QUESTAO 1 - Verificar Expressao Balanceada\n");
    printf("Digite uma expressao contendo:\n");
    printf("(), {} e []\n");
    printf("Exemplo valido: {[()]}\n");
    printf("Exemplo invalido: {[(])}\n\n");

    printf("Digite a expressao: ");
    scanf("%s", exp);

    if (isBalanced(exp)) {
        printf("Resultado: Expressao VALIDA\n");
    } else {
        printf("Resultado: Expressao INVALIDA\n");
    }

    printf("\n----------------------------------------\n\n");

    /*
    ------------------------------
    QUESTÃO 2
    ------------------------------
    */
    printf("QUESTAO 2 - Inverter String\n");
    printf("Digite uma palavra (sem espacos): ");
    scanf("%s", str);

    reverseString(str);

    printf("String invertida: %s\n", str);

    printf("\n========================================\n");

    return 0;
}