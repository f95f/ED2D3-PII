//Felipe Fernandes - GU3026965

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "utilidades.h"

int subMenu();

void main(){

    setlocale(LC_ALL, "");
    gerarHeader();

    printf("\n\n    > Preparando dados...\n\n");
    Pessoa *listaOriginal = ler("massaDados.csv");
    ordenar(listaOriginal, "massaDados - Ordenada.csv");
    free(listaOriginal);

    //Objeto *listaOriginal = importar();
    //Objeto *listaOrdenada = copiarLista(listaOriginal);
    //ordenar(listaOrdenada);

    int resposta = -1;
    int arvoreEscolhida = -1;
    int listaEscolhida = -1;

    do{
        system("cls");
        gerarHeader();
        printf("\n    > Menu Principal\n\n");

        printf("        [ 1 ] Verificar listas\n");
        printf("        [ 2 ] Medir com árvore AVL\n");
        printf("        [ 3 ] Medir com árvore Rubro-Negra\n");
        printf("        [ 0 ] Sair\n\n");

        printf("    > Escolha uma opção: ");
        scanf("%d", &resposta);

        if(resposta == 2 || resposta == 3){

            listaEscolhida = subMenu();
        }

        switch(resposta){
        case 1:

            // mostrar listas

        break;
        case 2: // Usar árvore AVL

            if(listaEscolhida == 1){

                // usar lista ordenada

            }
            else if(listaEscolhida == 2){

                // usar lista desordenada
            }

        break;
        case 3: //Usar árvore RN

            if(listaEscolhida == 1){

                // usar lista ordenada

            }
            else if(listaEscolhida == 2){

                // usar lista desordenada
            }

        break;
        }
    }
    while(resposta);

    //system("pause");

}

int subMenu(){

    int op = -1;

    do{
        system("cls");
        gerarHeader();
        printf("\n    > Modo de ordenação\n\n");

        printf("        [ 1 ] Usar lista ordenada\n");
        printf("        [ 2 ] Usar lista original\n");
        printf("        [ 0 ] Voltar\n\n");

        printf("    > Escolha uma opção: ");
        scanf("%d", &op);

        if(op == 1 || op == 2){ break; }
    }
    while(op);

    return op;
}
