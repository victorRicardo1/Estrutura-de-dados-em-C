#include <stdlib.h>
#include <stdio.h>
#include <string.h>


typedef struct No{
    int num;
    char nomeAluno[50];
    struct No *prox;
    struct No *ant;
}Nodo;

void inserirInicioDeque(Nodo **inicio, Nodo **final, int num, char *aluno){
    Nodo *novo = malloc(sizeof (Nodo));
    novo->num = num;
    strcpy(novo->nomeAluno, aluno);
    if(*inicio == NULL){
        *inicio = novo;
        *final = novo;
        novo->prox = NULL;
        novo->ant = NULL;
    }else{
        novo->prox = *inicio;
        novo->ant = NULL;
        (*inicio)->ant = novo;
        *inicio = novo;
    }
}

void inserirFinalDeque(Nodo **final, Nodo **inicio, int num, char *nome){
    Nodo *novo = malloc(sizeof (Nodo));
    strcpy(novo->nomeAluno, nome);
    novo->num = num;
    novo->prox = NULL;

    if(*final == NULL){
        *inicio = novo;
        *final = novo;
        novo->ant = NULL;
    }else{
        Nodo *aux = *inicio;
        while(aux->prox){
            aux = aux->prox;
        }
        aux->prox = novo;
        novo->ant = aux;
        *final = novo;
    }
}

void removerInicioDeque(Nodo **inicio, Nodo **final) {
    if (*inicio == NULL) {
        return;
    }
    Nodo *removido = *inicio;
    if (*inicio == *final) {
        *inicio = NULL;
        *final = NULL;
    }else{
        *inicio = (*inicio)->prox;
        (*inicio)->ant = NULL;
    }
    free(removido);
}

void removerFinalDeque(Nodo **inicio, Nodo **final) {
    if (*final == NULL) {
        printf("A fila esta vazia");
        return;
    }
    Nodo *removido = *final;
    if (*inicio == *final){
        *inicio = NULL;
        *final = NULL;
    }else{
        *final = (*final)->ant;
        (*final)->prox = NULL;
    }
    free(removido);
}

void imprimirDeque(Nodo **nodo){
    Nodo *aux = *nodo;
    while(aux){
        printf("%s ", aux->nomeAluno);
        aux = aux->prox;
    }
}

void swap(Nodo *a, Nodo *b) {
    int temp = a->num;
    a->num = b->num;
    b->num = temp;
    char tempNome[50];
    strcpy(tempNome, a->nomeAluno);
    strcpy(a->nomeAluno, b->nomeAluno);
    strcpy(b->nomeAluno, tempNome);
}

void ordenarDeque(Nodo **inicio) {
    int swapped;
    Nodo *ptr1;
    Nodo *lptr = NULL;
    if (*inicio == NULL)
        return;
    do {
        swapped = 0;
        ptr1 = *inicio;
        while (ptr1->prox != lptr) {
            if (ptr1->num > ptr1->prox->num) {
                swap(ptr1, ptr1->prox);
                swapped = 1;
            }
            ptr1 = ptr1->prox;
        }
        lptr = ptr1;
    } while (swapped);
}


void exibe(Nodo *inicio, int pos, char ordem) {
    if (inicio == NULL) {
        printf("A lista está vazia.\n");
        return;
    }
    Nodo *atual = NULL;
    if (ordem == 'd') {
        atual = inicio;
        for (int i = 1; i < pos && atual != NULL; i++) {
            atual = atual->prox;
        }
        if (atual == NULL) {
            printf("A posição %d não existe na lista.\n", pos);
            return;
        }
        while (atual != NULL) {
            printf("%s ", atual->nomeAluno);
            atual = atual->prox;
        }
    } else if (ordem == 'i') {
        atual = inicio;
        int count = 1;
        while (atual != NULL && count < pos) {
            atual = atual->prox;
            count++;
        }
        if (atual == NULL) {
            printf("A posição %d não existe na lista.\n", pos);
            return;
        }
        while (atual != NULL) {
            printf("%s ", atual->nomeAluno);
            atual = atual->ant;
        }
    } else {
        printf("A ordem deve ser 'd' (direta) ou 'i' (inversa).\n");
    }
}

int exercicio2(){
    Nodo *inicio = NULL;
    Nodo *Fim = NULL;
    int i, posi, ponto;
    char nome[50], n;

    for(i=0; i<5; i++){
        printf("\nnome do aluno: ");
        scanf("%s", &nome);
        printf("\nInforme a posicao de %s: ", nome);
        scanf("%d", &posi);
        inserirInicioDeque(&inicio, &Fim, posi, nome);
    }
    getchar();
    printf("Informe pra que lado imprimir: ");
    scanf(" %c", &n);
    if (n == 'd') {
        printf("Qual o ponto de partida a ser imprimido: ");
        scanf("%d", &ponto);
        printf("\n");
        exibe(inicio, ponto, 'd');
    } else if (n == 'i') {
        printf("Qual o ponto de partida a ser imprimido: ");
        scanf("%d", &ponto);
        printf("\n");
        exibe(inicio, ponto, 'i');
    }
    printf("\n");
    printf("Lista: ");
    imprimirDeque(&inicio);

//    inserirInicioDeque(&inicio, &Fim, 5, "Desmond");
//    inserirInicioDeque(&inicio, &Fim, 6, "Richard");
//    inserirInicioDeque(&inicio, &Fim, 3, "CARL");
//    inserirInicioDeque(&inicio, &Fim, 2, "Zap");
//    inserirFinalDeque(&Fim, &inicio, 1, "Matthews");
//    ordenarDeque(&inicio);
//
//    exibe(inicio, 3, 'd');
//    printf("\n");
//    imprimirDeque(&inicio);
}