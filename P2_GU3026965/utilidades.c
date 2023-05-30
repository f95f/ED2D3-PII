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

Pessoa *ler(char *arquivo){

    Pessoa *lista = (Pessoa*) calloc(sizeof(Pessoa), TAMANHO);
    FILE *arquivoOriginal = fopen(arquivo, "rb");

    if(lista == NULL || arquivoOriginal == NULL){ return NULL; }

    Pessoa teste;
    int tamanho_linha = sizeof(Pessoa) + 5;
    char *linha = (char *) calloc(tamanho_linha, TAMANHO);

    //char *linha = "54651;Bryar L. Lott;47;Yahoo;Payroll;2255.08";
    fgets(linha, tamanho_linha, arquivoOriginal);

        teste.codigo = atoi(strtok(linha, ";"));
        char *name = strtok(NULL, ";");
       // printf("======= %s =======", name);
       teste.nome = (char *) calloc(sizeof(char), 100);
        strcpy(teste.nome, name);//strtok(NULL, ";"));
        /*teste.idade = atoi(strtok(linha, ";"));
        strcpy(teste.empresa, strtok(NULL, ";"));
        strcpy(teste.departamento, strtok(NULL, ";"));
        teste.salario = atof(strtok(linha, ";"));
*/
        //printf("%s", linha);

    printf("\n\n ------------------------------------------");
    printf("\n- %d \n", teste.nome);
    //printf("- %d \n- %s \n- %d \n- %s \n- %s \n- %f \n", teste.codigo, teste.nome, teste.idade, teste.empresa, teste.departamento, teste.salario);

    printf("\n\n ------------------------------------------");

    system("pause");

    fclose(arquivoOriginal);
    return lista;

}

void ordenar(Pessoa *lista, char *arquivo){


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
