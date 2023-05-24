#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include "utilidades.h"

struct obj{
    int codigo;
    char *nome;
    int idade;
    char *empresa;
    char *departamento;
    float salario;

};

void linha(char formato, int tamanho){

    printf("\n ");
    for(int i = 0; i < tamanho; i++){
        printf("%c", formato);
    }
    printf("\n");

}

void gerarHeader(){

        system("cls");
        linha('#', 41);
        printf(" # Desempenho de Árvores de Dados #");
        linha('#', 41);

}

int checkResposta(int resposta, int valorMin, int valorMax){

    if(resposta >= valorMin && resposta <= valorMax){
        return 1;
    }
    return 0;

}

int *gerarLista(int tamanho){

    srand((unsigned) time(NULL));

    int *lista = (int*) calloc(tamanho, sizeof(int));

    for(int i = 0; i < tamanho; i++){
        lista[i] = rand();
    }

    return lista;
}

int *copiarLista(int *lista, int tamanho){

    int *listaCopiada = (int*) calloc(tamanho, sizeof(int));

    for(int i = 0; i < tamanho; i++){

        listaCopiada[i] = lista[i];

    }

    return listaCopiada;
}

double medirIntervalo(struct timeval Tempo_inicial, struct timeval Tempo_final){

    double deltaT = (Tempo_final.tv_sec + Tempo_final.tv_usec/1000000.0) - (Tempo_inicial.tv_sec + Tempo_inicial.tv_usec/1000000.0);
    return deltaT;

}

void amostrar(int *lista, char *descr){

    printf("    > Amostra: %s\n\n", descr);

    for(int i = 0; i < 50; i++){

        printf(" %6d |", lista[i] );
        if(i != 0 && !((i + 1) % 10)){printf("\n");}

    }
    printf("\n\n");
}

int executar(int metodo){

    struct timeval antes, depois;
    double tempo;
    double tempo_listaOrganizada, tempo_listaOriginal;

    switch(metodo){
        case 2:

            gettimeofday(&antes, NULL);


                //avl(listaOriginal);

            gettimeofday(&depois, NULL);
            tempo_listaOriginal = medirIntervalo(antes, depois);

            gettimeofday(&antes, NULL);

            //avl(listaOrdenada);

            gettimeofday(&depois, NULL);

        break;
        case 3:

            gettimeofday(&antes, NULL);

            //rn(listaOriginal);

            gettimeofday(&depois, NULL);
            tempo_listaOrganizada = medirIntervalo(antes, depois);

            gettimeofday(&antes, NULL);

            //rn(listaOrdenada);

            gettimeofday(&depois, NULL);

        break;
    }
}
