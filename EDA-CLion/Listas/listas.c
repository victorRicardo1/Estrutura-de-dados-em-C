#include <stdlib.h>
#include <stdio.h>

typedef struct No{
    int valor;
    struct No *Prox;
}Nodo;

void inserirInicioLista(Nodo **lista, int num){
    Nodo *novo = malloc(sizeof(Nodo));
    if(novo){
        novo->valor = num;
        novo->Prox = *lista;
        *lista = novo;
    }else{
        printf("Erro ao alocar memoria");
    }
}

void inserirFinalLista(Nodo **lista, int num){
    Nodo *novo = malloc(sizeof(Nodo));
    if(novo){
        novo->valor = num;
        novo->Prox = NULL;

        if(*lista == NULL){
            *lista = novo;
        }else{
            Nodo *aux = *lista;
            while(aux->Prox != NULL){
                aux = aux->Prox;
            }
            aux->Prox = novo;

        }
    }
}

void inserirMeio(Nodo **lista, int num, int ant){
    Nodo *novo = malloc(sizeof(Nodo));
    if (novo){
        novo->valor = num;

        if(*lista == NULL){
            novo->Prox = NULL;
            *lista = novo;
        }else{
            Nodo *aux = *lista;
            while (aux->valor != ant && aux->Prox){
                aux = aux->Prox;
            }
            novo->Prox = aux->Prox;
            aux->Prox = novo;
        }
    }
}

void removerLista(Nodo **head, int valor){
    Nodo *remover = NULL;
    if (*head){
        if((*head)->valor == valor){
            remover = *head;
            *head = remover->Prox;
        }else{
            Nodo *aux = *head;
            while (aux->Prox && aux->Prox->valor != valor){
                aux = aux->Prox;
            }
            if(aux->Prox){
                remover = aux->Prox;
                aux->Prox = remover->Prox;
            }
        }
    }
    free(remover);
}

void imprimirLista(Nodo *no) {
    while (no) {
        printf("%d ", no->valor);
        no = no->Prox;
    }
    printf("\n\n");
}
int lista(){
    Nodo *head = NULL;
    inserirInicioLista(&head, 5);
    inserirInicioLista(&head, 10);
    inserirFinalLista(&head, 20);
    inserirMeio(&head, 30, 5);
    removerLista(&head, 30);


    imprimirLista(head);
}
