
#include "utilidades.h"
/*
    Biblioteca com as funções utilizadas para
    ordenação pelo método Merge Sort.

    Recebe como argumento o endereço para um vetor
    de inteiros, e a quantidade de elementos nesse vetor.
*/

// Estrutura utilizada para armazenar cada instância.
typedef struct obj Pessoa;

void mergeSort(Pessoa *arr, int inicio, int fim);
