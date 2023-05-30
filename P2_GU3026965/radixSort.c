#include <stdio.h>
#include <stdlib.h>
#include "radixSort.h"

int getMax(int *vetor, int n) {

    int max = vetor[0];
    for (int i = 1; i < n; i++) {
        if (vetor[i] > max) {
            max = vetor[i];
        }
    }
    return max;
}
void contar(int *vetor, int n, int exp) {
    int lista[n];
    int contagem[10] = {0};

    for (int i = 0; i < n; i++) {
        contagem[(vetor[i] / exp) % 10]++;
    }

    for (int i = 1; i < 10; i++) {
        contagem[i] += contagem[i - 1];
    }

    for (int i = n - 1; i >= 0; i--) {
        lista[contagem[(vetor[i] / exp) % 10] - 1] = vetor[i];
        contagem[(vetor[i] / exp) % 10]--;
    }

    for (int i = 0; i < n; i++) {
        vetor[i] = lista[i];
    }
}
void radixSort(int *vetor, int n) {

    int max = getMax(vetor, n);

    for (int exp = 1; max / exp > 0; exp *= 10) {
        contar(vetor, n, exp);
    }
}

