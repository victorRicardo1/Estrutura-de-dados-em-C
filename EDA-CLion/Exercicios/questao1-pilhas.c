#include <stdio.h>
#include <stdlib.h>

typedef struct No{
    int valor;
    struct No *prox;
}Nodo;

void empilhar(Nodo **topo, int valor){
    Nodo *novo = malloc(sizeof(Nodo));
    novo->valor = valor;
    if(*topo == NULL){
        novo->prox = *topo;
        *topo = novo;
    }else{
        novo->prox = *topo;
        *topo = novo;
    }
}

void desempilhar(Nodo **topo){
    Nodo *remover = *topo;
    if(remover){
        remover = *topo;
        *topo = remover->prox;
        free(remover);
    }
}

void imprimirPil(Nodo *topo){
    Nodo *aux = topo;
    while(aux){
        printf(" %d ", aux->valor);
        aux = aux->prox;
    }
}

void imprimirPares(Nodo *topo){
    Nodo *aux = topo;
    while(aux){
        if(aux->valor % 2 == 0){
            printf(" %d ", aux->valor);
        }
        aux = aux->prox;
    }
}


int questao1Pilha(){
    int n, num;
    Nodo *topo = NULL;
    do {
        printf("\n--------MENU--------");
        printf("\n1-Cadastrar numero \n2-Mostrar numeros pares \n3-Excluir numero \n4-Sair");
        printf("\nEscolha uma opcao: ");
        scanf("%d", &n);
        switch (n) {
            case 1:
                printf("Informe o numero para empilhar: ");
                scanf("%d", &num);
                empilhar(&topo, num);
                printf("\nImpressao: \n");
                imprimirPil(topo);
                break;
            case 2:
                printf("\nOs numeros pares sao: ");
                imprimirPares(topo);
                break;
            case 3:
                desempilhar(&topo);
                imprimirPil(topo);
                break;
            default:
                printf("/nNumero nao reconhecido!");
        }
    } while (n!=4);
}