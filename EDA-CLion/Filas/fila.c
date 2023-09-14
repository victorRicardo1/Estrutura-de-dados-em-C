#include <stdlib.h>
#include <stdio.h>

typedef struct no{
    int valor;
    struct no *prox;
}No;

typedef struct {
    No *inicio;
    No *fim;
    int tam;
}Fila;

void criarFila(Fila *fila){
    fila->inicio = NULL;
    fila->fim = NULL;
    fila->tam = 0;
}

void inserirFila(Fila *fila, int num){
    No *aux ,*novo = malloc(sizeof(No));
    if(novo){
        novo->valor = num;
        novo->prox = NULL;
        if(fila->inicio == NULL){
            fila->inicio = novo;
            fila->fim = novo;
        }else{
            fila->fim->prox = novo;
            fila->fim = novo;
        }
        fila->tam++;
    }else{
        printf("\nErro ao alocar memoria\n");
    }
}

No *removerFila(Fila *fila){
    No *remover = NULL;
    if(fila->inicio){
        remover = fila->inicio;
        fila->inicio = remover->prox;
        fila->tam--;
    }else{
        printf("Fila vazia");
    }
    return remover;
}

void imprimirFila(Fila *fila){
    No *aux = fila->inicio;
    while(aux){
        printf("%d ", aux->valor);
        aux = aux->prox;
    }
}

int fila(){
    No *r;
    Fila fila;
    criarFila(&fila);
    inserirFila(&fila, 5);
    inserirFila(&fila, 10);
    inserirFila(&fila, 15);
    r = removerFila(&fila);
    imprimirFila(&fila);
}
