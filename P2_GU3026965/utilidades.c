#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include "utilidades.h"
#include "radixSort.h"

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

Pessoa *ler(char *arquivo){

    Pessoa *lista = (Pessoa*) calloc(sizeof(Pessoa), TAMANHO);
    FILE *arquivoOriginal = fopen(arquivo, "rb");

    if(lista == NULL || arquivoOriginal == NULL){ return NULL; }

    Pessoa pessoa;
    char *registro = (char *) calloc(sizeof(char), 100);
    int index = 0;

    while(fgets(registro, 100, arquivoOriginal)){

        lista[index].codigo = atoi(strtok(registro, ";"));

        char *nome =  strtok(NULL, ";");
        lista[index].nome = (char *) calloc(sizeof(char), 50);
        strcpy(lista[index].nome, nome);

        lista[index].idade = atoi(strtok(NULL, ";"));

        char *empresa =  strtok(NULL, ";");
        lista[index].empresa = (char *) calloc(sizeof(char), 50);
        strcpy(lista[index].empresa, empresa);

        char *depto =  strtok(NULL, ";");
        lista[index].departamento = (char *) calloc(sizeof(char), 50);
        strcpy(lista[index].departamento, depto);

        lista[index].salario = atof(strtok(NULL, ";"));

        index++;

    }

    fclose(arquivoOriginal);
    return lista;

}

void ordenar(Pessoa *lista, char *arquivo){

    Pessoa *vetorOrdenado = (Pessoa *) calloc(sizeof(Pessoa), TAMANHO);
    int *codigos = (int *) calloc(sizeof(int), TAMANHO);
    int indice = 0;

    for(int i = 0; i < TAMANHO; i++){

        codigos[i] = lista[i].codigo;

    }

    radixSort(codigos, TAMANHO -1);

    for(int i = 0; i < TAMANHO; i++){

        indice = 0;
        while(lista[indice].codigo != codigos[i]){
            indice++;
        }
        vetorOrdenado[i] = lista[indice];
    }

    system("pause");

    //for(int i = 0; i < 100; i++){ printf(" aaa %d - %s aaa\n", vetorOrdenado[i].codigo, vetorOrdenado[i].nome); }

    system("pause");
}

double medirIntervalo(struct timeval Tempo_inicial, struct timeval Tempo_final){

    double deltaT = (Tempo_final.tv_sec + Tempo_final.tv_usec/1000000.0) - (Tempo_inicial.tv_sec + Tempo_inicial.tv_usec/1000000.0);
    return deltaT;

}

void amostrar(int *lista, char *descr){

    printf("    > Amostra: %s\n\n", descr);

    for(int i = 0; i < 50; i++){

        printf(" %5d |", lista[i] );
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


