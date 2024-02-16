#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Função que realiza a troca entre dois elementos
void troca(int vet[], int i, int j){
    int aux = vet[i];
    vet[i] = vet[j];
    vet[j] = aux;
}

//Função que particiona e retorna o índice do pivô

int particiona(int vet[], int inicio, int fim){
    int pivo, pivoIndice, i;
    pivo = vet[fim]; //Nesse caso o pivõ será sempre o fim
    pivoIndice = inicio;

    for(i = inicio; i < fim; i++){
        //verificando se o elemento é menor ou igual ao pivõ
        if(vet[i] <= pivo){
            //faz a troca colocando os menores para a esquerda
            troca(vet, i, pivoIndice);
            pivoIndice++;
        }
    }

    //Troca o pivõ para a posição que o pivoIndice parou
    troca(vet, pivoIndice, fim);

    //retorna o índice d pivô
    return pivoIndice;
}

//Escolhe um pivô aleatorio para evitar o pior caso
int particionaRandom(int vet[], int inicio, int fim){
    //seleciona um número entre fim e inicio;
    int pivoIndice = (rand() % (fim - inicio + 1)) + inicio;
    troca(vet, pivoIndice, fim);
    //chama a particiona pra particionar o array com o novo pivô escolhido;
    return particiona(vet, inicio, fim);
}

void quickSort(int vet[], int inicio, int fim){
    if(inicio < fim){
        int pivoIndice = particionaRandom(vet, inicio, fim);

        quickSort(vet, inicio, pivoIndice -1);
        quickSort(vet, pivoIndice + 1, fim);
    }
}

void generateSortedArrayDescending(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = size - i; // Gera números em ordem decrescente
    }
}

void generateHalfSortedArray(int arr[], int size) {
    int half = size / 2;

    for (int i = 0; i < half; i++) {
        arr[i] = i; // Gera a primeira metade ordenada crescentemente
    }

    for (int i = half; i < size; i++) {
        arr[i] = size - (i - half); // Gera a segunda metade ordenada decrescentemente
    }
}

void generateHalfSortedArray2(int arr[], int size) {
    int half = size / 2;

    for (int i = 0; i < half; i++) {
        arr[i] = size - i; // Gera a primeira metade ordenada decrescentemente
    }

    for (int i = half; i < size; i++) {
        arr[i] = i - half; // Gera a segunda metade ordenada crescentemente
    }
}


void generateRandomArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 1000; //Limite do array
    }
}

int quicksortMain() {
    int size = 100000;
    int arr[size], i;
    int arr2[size], arr3[size], arr4[size];

// Vetor totalmente desordenado
    generateRandomArray(arr, size);
    clock_t start = clock();
    quickSort(arr, 0, size - 1);
    clock_t end = clock();
    double cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Tempo de execucao do vetor totalmente desordenado: %f segundos\n", cpu_time_used);

// Vetor ordenado decrescentemente
    generateSortedArrayDescending(arr2, size);
    clock_t start2 = clock();
    quickSort(arr2, 0, size - 1);
    clock_t end2 = clock();
    double cpu_time_used2 = ((double) (end2 - start2)) / CLOCKS_PER_SEC;
    printf("Tempo de execucao do vetor totalmente ordenado decrescentemente: %f segundos\n", cpu_time_used2);

// Vetor com a primeira metade ordenada crescente e segunda metade ordenada decrescentemente
    generateHalfSortedArray(arr3, size);
    clock_t start3 = clock();
    quickSort(arr3, 0, size - 1);
    clock_t end3 = clock();
    double cpu_time_used3 = ((double) (end3 - start3)) / CLOCKS_PER_SEC;
    printf("Tempo de execucao da primeira metade ordenada crescente e segunda metade ordenada decrescentemente: %f segundos\n",cpu_time_used3);

    // Primeira metade ordenada decrescente, segunda metade ordenada crescentemente
    generateHalfSortedArray2(arr4, size);

    clock_t start4 = clock();
    quickSort(arr4, 0, size - 1);
    clock_t end4 = clock();
    double cpu_time_used4 = ((double)(end4 - start4)) / CLOCKS_PER_SEC;
    printf("Tempo de execucao da primeira metade ordenada decrescente e segunda metade ordenada crescentemente: %f segundos\n", cpu_time_used4);
}