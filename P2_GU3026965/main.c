//Felipe Fernandes - GU3026965

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "utilidades.h"

int subMenu();

void main(){

    setlocale(LC_ALL, "");
    gerarHeader();

    printf("\n\n    > Importando dados...\n\n");

    //Objeto *listaOriginal = importar();
    //Objeto *listaOrdenada = copiarLista(listaOriginal);
    //ordenar(listaOrdenada);

    int resposta = -1;
    int arvoreEscolhida, listaEscolhida;

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

        if(resposta == 1){
            // mostrar listas
        }
        else if(resposta == 2 || resposta == 3){

            listaEscolhida = subMenu();

            if(!listaEscolhida){
                arvoreEscolhida = resposta -1;
                executar(arvoreEscolhida, listaEscolhida);
            }
        }
    }
    while(!resposta);

    system("pause");

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
    }
    while(!op);

    return op;
}
