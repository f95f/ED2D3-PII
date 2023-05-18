#include <stdio.h>
#include <stdlib.h>
#include "binaryTree.h"

struct NO{

    int info;
    struct NO *esq;
    struct NO *dir;

};

binTree *criar_binTree(){

    binTree *raiz = (binTree*) malloc(sizeof(binTree));

    if(raiz != NULL){
        *raiz = NULL;
    }

    return raiz;
}

void liberar_binTree(binTree *raiz){

    if(raiz == NULL){
        return;
    }

    libera_NO(*raiz);
    free(raiz);
}

void libera_NO(struct NO *no){

    if(no == NULL){
        return;
    }

    libera_NO(no -> esq);
    libera_NO(no -> dir);

    free(no);

    no = NULL;
}

int vazia_binTree(binTree *raiz){

    if(raiz == NULL) { return 1;}
    if(*raiz == NULL){ return 1;}

    return 0;
}

int altura_binTree(binTree *raiz){

    if(raiz == NULL){ return 0;}
    if(*raiz == NULL){ return 0;}

    int alt_esq = altura_binTree(&((*raiz) -> esq));
    int alt_dir = altura_binTree(&((*raiz) -> dir));

    if(alt_esq > alt_dir){

        return(alt_esq + 1);
    }
    else{

        return(alt_dir + 1);
    }

}

int totalNO_binTree(binTree *raiz){

    if(raiz == NULL){ return 0;}
    if(*raiz == NULL){return 0;}

    int alt_esq = totalNO_binTree(&((*raiz) -> esq));
    int alt_dir = totalNO_binTree(&((*raiz) -> dir));

    return(alt_esq + alt_dir + 1);

}

// Percorrendo a árvore
// - Pré-ordem

void preOrdem_binTree(binTree *raiz){

    if(raiz == NULL){ return; }

    if(*raiz != NULL){

        printf(" -- %d\n", ((*raiz) -> info));
        preOrdem_binTree(&((*raiz) -> esq));
        preOrdem_binTree(&((*raiz) -> dir));

    }

}

// Em ordem
void emOrdem_binTree(binTree *raiz){

    if(raiz == NULL){ return; }

    if(*raiz != NULL){
        emOrdem_binTree(&((*raiz) -> esq));
        printf(" -- %d\n", (*raiz) -> info);
        emOrdem_binTree(&((*raiz) -> dir));
    }

}

// Pós-ordem
void posOrdem_binTree(binTree *raiz){

    if(raiz == NULL){ return; }

    if(*raiz != NULL){

        posOrdem_binTree(&((*raiz) -> esq));
        posOrdem_binTree(&((*raiz) -> dir));
        printf(" -- %d\n", (*raiz) -> info);

    }

}

// Inserindo
int inserir_binTree(binTree *raiz, int valor){

    if(raiz == NULL){return 0;}

    struct NO *novo;
    novo = (struct NO*) malloc(sizeof(struct NO));

    if(novo == NULL){return 0;}

    novo -> info = valor;
    novo -> dir = NULL;     // ---| O nó criado será sempre uma folha
    novo -> esq = NULL;     //    | (elemento na última camada da ávore)

    if(*raiz == NULL){
        *raiz = novo;
    }
    else{

        struct NO *atual = *raiz;
        struct NO *ant = NULL;

        while(atual != NULL){

            ant = atual;

            if(valor == atual -> info){
                free(novo); //Descartado - elemento já existe
                return 0;
            }

            if(valor > atual -> info){
                atual = atual -> dir;
            }
            else{
                atual = atual -> esq;
            }
        }

        if(valor > ant -> info){ // define de qual lado o nó será colocado
            ant -> dir = novo;
        }
        else{
            ant -> esq = novo;
        }
    }
    return 1;
}

//removendo ----------------------------------------------------------------

struct NO *remove_atual(struct NO *atual){

    struct NO *no1, *no2;

    if(atual -> esq == NULL){

        no2 = atual -> dir;
        free(atual);
        return no2;

    }

    no1 = atual;
    no2 = atual -> esq;

    while(no2 -> dir != NULL){

        no1 = no2;
        no2 = no2 -> dir;

    }

    if(no1 != atual){

        no1 -> dir = no2 -> esq;
        no2 -> esq = atual -> esq;

    }

    no2 -> dir = atual -> dir;
    free(atual);

    return no2;

}

int remove_binTree(binTree *raiz, int valor){

    if(raiz == NULL){return 0;}

    struct NO *ant = NULL;
    struct NO *atual = *raiz;

    while(atual != NULL){

        if(valor == atual -> info){

            if(atual == *raiz){

                *raiz = remove_atual(atual);

            }
            else{

                if(ant -> dir == atual){
                    ant -> dir = remove_atual(atual);
                }
                else{
                    ant -> esq = remove_atual(atual);
                }
            }
            return 1;
        }
        ant = atual;

        if(valor > atual -> info){

            atual = atual -> dir;

        }
        else{

            atual = atual -> esq;

        }
    }
}

//consultando ----------------------------------------------------------------
int consulta_binTree(binTree *raiz, int valor){

    if(raiz == NULL){ return 0;}

    struct NO *atual = *raiz;

    while(atual != NULL){

        if(valor == atual -> info){
            return 1;
        }

        if(valor > atual -> info){
            atual = atual -> dir;
        }
        else{
            atual = atual -> esq;
        }
    }

    return 0;
}











