#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int valor;
    struct no *prox;
}Nodo;

Nodo *criarPilha(int valor){
    Nodo *novo = malloc(sizeof(Nodo));
    novo->valor = valor;
    novo->prox = NULL;
    return novo;
}

void push(Nodo **topo, Nodo *no){
    if(*topo!=NULL){
        no->prox = *topo;
        *topo = no;
    }else{
        *topo = no;
    }
}

void pop(Nodo **topo){
    Nodo *remover = *topo;
    if(remover == NULL){
        printf("Pilha vazia!!!");
    }else{
        *topo = remover->prox;
        free(remover);
    }
}

void imprimir(Nodo *topo){
    Nodo *aux = topo;
    while(aux != NULL){
        printf(" %d ", aux->valor);
        aux = aux -> prox;
    }
}

int pilhas(){
    Nodo *topo = NULL;
    //criando No
    Nodo *pilha1 = criarPilha(5);
    Nodo *pilha2 = criarPilha(10);
    Nodo *pilha3 = criarPilha(20);

    //Puxando os Nós para a pilha
    push(&topo, pilha1);
    push(&topo, pilha2);
    push(&topo, pilha3);
    imprimir(topo);
}

