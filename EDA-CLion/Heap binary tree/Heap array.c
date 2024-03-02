#include <stdio.h>
#include <stdlib.h>

int *mixArray(int arr1[], int tam1, int arr2[], int tam2, int *tamFinal){
    *tamFinal = tam1 + tam2;
    int *arrResult = (int*)malloc((*tamFinal) * sizeof(int));
    int i, j;
    for(i = 0; i<tam1; i++){
        arrResult[i] = arr1[i];
    }
    for(j = 0; j<tam2; j++){
        arrResult[tam1 + j] = arr2[j];
    }
    return arrResult;
}

void trocar(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int arr[], int tamanho, int indice, int tipoHeap) {
    int alvo = indice;  // Inicializa o nó atual como o alvo
    int filhoEsquerda = 2 * indice + 1;
    int filhoDireita = 2 * indice + 2;

    // Verifica se o filho à esquerda é maior (max-heap) ou menor (min-heap) que o nó atual
    if (tipoHeap == 1 && filhoEsquerda < tamanho && arr[filhoEsquerda] > arr[alvo]) {
        alvo = filhoEsquerda;  // max-heap
    } else if (tipoHeap == 2 && filhoEsquerda < tamanho && arr[filhoEsquerda] < arr[alvo]) {
        alvo = filhoEsquerda;  // min-heap
    }

    // Verifica se o filho à direita é maior (max-heap) ou menor (min-heap) que o nó atual
    if (tipoHeap == 1 && filhoDireita < tamanho && arr[filhoDireita] > arr[alvo]) {
        alvo = filhoDireita;  // max-heap
    } else if (tipoHeap == 2 && filhoDireita < tamanho && arr[filhoDireita] < arr[alvo]) {
        alvo = filhoDireita;  // min-heap
    }

    // Se o alvo não é o nó atual, troca-os e chama recursivamente o heapify
    if (alvo != indice) {
        trocar(&arr[indice], &arr[alvo]);
        heapify(arr, tamanho, alvo, tipoHeap);
    }
}

// Função para transformar um array em um heap (max-heap ou min-heap)
void construirHeap(int arr[], int tamanho, int tipoHeap) {
    // Inicia o heapify do último nó não folha até a raiz
    for (int i = tamanho / 2 - 1; i >= 0; i--) {
        heapify(arr, tamanho, i, tipoHeap);
    }
}

    int heapArray() {
        int arr1[100] = {};
        int arr2[100] = {};
        int i = 0;
        int j, h;
        int num;
        int tipoHeap;

        // Preenche o primeiro array
        for (i = 0; i < 100; i++) {
            printf("\nAdicione um elemento para o array1(pressione 0 para sair): ");
            scanf("%d", &num);
            if (num == 0) {
                break;
            }
            arr1[i] = num;
        }

        // Preenche o segundo array
        for (j = 0; j < 100; j++) {
            printf("\nAdicione um elemento para o array2(pressione 0 para sair): ");
            scanf("%d", &num);
            if (num == 0) {
                break;
            }
            arr2[j] = num;
        }

        int tamFinal;
        int *arrMixed = mixArray(arr1, i, arr2, j, &tamFinal);
        printf("\nElementos do Array Resultante:\n");

        for (h = 0; h < tamFinal; h++) {
            printf("%d\n", arrMixed[h]);
        }

        // Escolhe o tipo de heap (1 para max-heap, 2 para min-heap)
        printf("Escolha o tipo de heap (1 para Max-Heap, 2 para Min-Heap): ");
        scanf("%d", &tipoHeap);

        // Constrói o heap com o array resultante
        construirHeap(arrMixed, tamFinal, tipoHeap);

        // Imprime os elementos do array resultante (agora em forma de heap)
        printf("Elementos do Heap Resultante:\n");
        for (int j = 0; j < tamFinal; j++) {
            printf("%d\n", arrMixed[j]);
        }

        // Libera a memória alocada dinamicamente
        free(arrMixed);
}