cmake_minimum_required(VERSION 3.26)
project(EDA_CLion C)

set(CMAKE_C_STANDARD 11)

add_executable(EDA_CLion
        Exercicios/questao1-pilhas.c
        main.c
        Filas/fila.c
        Listas/listas.c
        Pilhas/pilha.c
        deques/deque.c
        deques/exercicio1-deque.c
        quicksort.c
)
