#include <stdio.h>
#include <stdlib.h>

typedef struct Cliente {
    int id;
    int tempoAtendimento;
    struct Cliente* prox;
} Cliente;

typedef struct {
    Cliente* inicio;
    Cliente* fim;
} Fila;

void inicializarFila(Fila* f) {
    f->inicio = NULL;
    f->fim = NULL;
}

void enqueue(Fila* f, int id, int tempo) {
    Cliente* novo = (Cliente*) malloc(sizeof(Cliente));
    novo->id = id;
    novo->tempoAtendimento = tempo;
    novo->prox = NULL;

    if (f->fim == NULL) {
        f->inicio = novo;
        f->fim = novo;
    } else {
        f->fim->prox = novo;
        f->fim = novo;
    }
}

Cliente* dequeue(Fila* f) {
    if (f->inicio == NULL) return NULL;

    Cliente* temp = f->inicio;
    f->inicio = f->inicio->prox;

    if (f->inicio == NULL) {
        f->fim = NULL;
    }

    return temp;
}

void simularAtendimento(Fila* f) {
    int tempoEspera = 0;
    Cliente* atual;

    while ((atual = dequeue(f)) != NULL) {
        printf("Cliente ID: %d\n", atual->id);
        printf("Tempo de espera: %d minutos\n\n", tempoEspera);

        tempoEspera += atual->tempoAtendimento;

        free(atual);
    }
}

int main() {
    Fila fila;
    inicializarFila(&fila);

    int n;
    printf("Quantos clientes? ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int id, tempo;
        printf("Cliente %d - ID: ", i + 1);
        scanf("%d", &id);

        printf("Tempo de atendimento (min): ");
        scanf("%d", &tempo);

        enqueue(&fila, id, tempo);
    }

    printf("\n--- Simulacao de Atendimento ---\n\n");
    simularAtendimento(&fila);

    return 0;
}