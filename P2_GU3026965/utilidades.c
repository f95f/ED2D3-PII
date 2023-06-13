#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include "utilidades.h"
#include "radixSort.h"
#include "avlTree.h"
#include "rnTree.h"

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
        printf(" #### Desempenho de Árvores de Dados #####");
        linha('#', 41);

}

Pessoa *ler(char *arquivo){

    Pessoa *lista = (Pessoa*) calloc(100, TAMANHO);
    FILE *arquivoOriginal = fopen(arquivo, "rb");

    if(lista == NULL || arquivoOriginal == NULL){ return NULL; }

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
    free(codigos);
    free(vetorOrdenado);

}

void limpar(Pessoa *lista){

    for(int i = 0; i < TAMANHO; i++){

        free(lista[i].nome);
        free(lista[i].empresa);
        free(lista[i].departamento);

    }

    free(lista);
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
    fclose(arquivoOrdenado);
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

int executar(char *arvore, char *lista){

    struct timeval antes, depois;
    double tempo;
    Pessoa pessoa;

    FILE *arquivo = fopen(lista, "rb");
    if(arquivo == NULL){ return NULL; }
    char *registro = (char *) calloc(sizeof(char), 100);

    if(!strcmp(arvore, "avl")){ //---> Usar árvore AVL

        avlTree *raiz;
        raiz = criar_avlTree();

        gettimeofday(&antes, NULL);

        while(fgets(registro, 100, arquivo)){

            pessoa.codigo = atoi(strtok(registro, ";"));

            char *nome =  strtok(NULL, ";");
            pessoa.nome = (char *) calloc(sizeof(char), 50);
            strcpy(pessoa.nome, nome);

            pessoa.idade = atoi(strtok(NULL, ";"));

            char *empresa =  strtok(NULL, ";");
            pessoa.empresa = (char *) calloc(sizeof(char), 50);
            strcpy(pessoa.empresa, empresa);

            char *depto =  strtok(NULL, ";");
            pessoa.departamento = (char *) calloc(sizeof(char), 50);
            strcpy(pessoa.departamento, depto);

            pessoa.salario = atof(strtok(NULL, ";"));

            inserir_avlTree(raiz, pessoa);

        }

        gettimeofday(&depois, NULL);
        tempo = medirIntervalo(antes, depois);

        exibirResultados(tempo, lista, arvore, raiz, NULL);
        liberar_avlTree(raiz);
    }
    if(!strcmp(arvore, "rb")){ //---> Usar árvore Rubro-Negra

        arvoreLLRB *raiz;
        raiz = criar_arvoreLLRB();

        gettimeofday(&antes, NULL);

        while(fgets(registro, 100, arquivo)){

            pessoa.codigo = atoi(strtok(registro, ";"));

            char *nome =  strtok(NULL, ";");
            pessoa.nome = (char *) calloc(sizeof(char), 50);
            strcpy(pessoa.nome, nome);

            pessoa.idade = atoi(strtok(NULL, ";"));

            char *empresa =  strtok(NULL, ";");
            pessoa.empresa = (char *) calloc(sizeof(char), 50);
            strcpy(pessoa.empresa, empresa);

            char *depto =  strtok(NULL, ";");
            pessoa.departamento = (char *) calloc(sizeof(char), 50);
            strcpy(pessoa.departamento, depto);

            pessoa.salario = atof(strtok(NULL, ";"));

            inserir_arvoreLLRB(raiz, pessoa);

        }

        gettimeofday(&depois, NULL);
        tempo = medirIntervalo(antes, depois);

        exibirResultados(tempo, lista, arvore, NULL, raiz);
        liberar_arvoreLLRB(raiz);

    }

    free(registro);
    fclose(arquivo);

}

void exibirResultados(double tempo_total, char *lista, char *arvore, avlTree *raizAVL, arvoreLLRB *raizRN){

    int op = -1;

    do{

        system("cls");
        gerarHeader();
        printf("\n    > Resultados\n\n");

        printf("    - Árvore preenchida com o arquivo %s, pelo método %s.\n", lista, arvore);
        printf("      Tempo total: %f segundos.\n\n", tempo_total);

        printf("        [ 1 ] Consultar na árvore\n");
        printf("        [ 0 ] Voltar\n\n");
        printf("    > Escolha uma opção: ");
        scanf("%d", &op);

        if(op == 1){

            if(raizAVL != NULL){ consultarAVL(arvore, raizAVL); }
            else{ consultarRN(arvore, raizRN); }

        }
    }
    while(op);
}

void consultarAVL(char *arvore, avlTree *raiz){

    int resposta;
    int op = -1;
    do{

        system("cls");
        gerarHeader();

        printf("\n    > Consultar\n\n");
        printf("    - Informe o código a ser pesquisado, ou insira 0 para voltar: ");
        scanf("%d", &op);

        if(op){

            resposta = busca_avlTree(raiz, op);

            if(resposta == 0){
                printf("\n    [ ! ] Elemento não encontrado.\n");
            }

            system("pause");
        }
    }
    while(op);

}
void consultarRN(char *arvore, arvoreLLRB *raiz){

    int resposta;
    int op = -1;
    do{

        system("cls");
        gerarHeader();

        printf("\n    > Consultar\n\n");
        printf("    - Informe o código a ser pesquisado, ou insira 0 para voltar: ");
        scanf("%d", &op);

        if(op){
            resposta = buscar_arvoreLLRB(raiz, op);

            if(resposta == 0){
                printf("\n    [ ! ] Elemento não encontrado.\n");
            }

            system("pause");
        }
    }
    while(op);

}
