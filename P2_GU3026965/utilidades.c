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

    free(registro);
    fclose(arquivoOriginal);

    return lista;

}

void ordenar(Pessoa *lista){

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

    gravar(vetorOrdenado, "massaDados - Ordenada.csv");

    free(vetorOrdenado);
}

int gravar(Pessoa *lista, char *arquivo){

    FILE *arquivoOrdenado = fopen(arquivo, "wb");
    if(arquivoOrdenado == NULL){ return NULL; }
    int resposta = 0;

    for(int i = 0; i < TAMANHO; i++){

        resposta = fprintf(
            arquivoOrdenado,
            "%d;%s;%d;%s;%s;%.2f\n",
            lista[i].codigo,
            lista[i].nome,
            lista[i].idade,
            lista[i].empresa,
            lista[i].departamento,
            lista[i].salario
        );
        if(resposta <= 0){ printf("\n\n Erro \n\n"); system("pause");}

    }
    return 0;
}

double medirIntervalo(struct timeval Tempo_inicial, struct timeval Tempo_final){

    double deltaT = (Tempo_final.tv_sec + Tempo_final.tv_usec/1000000.0) - (Tempo_inicial.tv_sec + Tempo_inicial.tv_usec/1000000.0);
    return deltaT;

}

void amostrar(Pessoa *lista, char *descr){

    printf("\n    > Amostra: %s\n", descr);

    linha('_', 86);
    printf(" |__Cód__|_________Nome_________|_Idade_|__Empresa___|_____Departamento_____|_Salário_|\n");

    for(int i = 0; i < 10; i++){

        printf(
            " | %5d | %20s | %5d | %10s | %20s | %5.2f |\n",
            lista[i].codigo,
            lista[i].nome,
            lista[i].idade,
            lista[i].empresa,
            lista[i].departamento,
            lista[i].salario
        );

    }
    printf("\n");
    linha('=', 86);
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


