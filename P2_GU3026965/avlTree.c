#include <stdio.h>
#include <stdlib.h>
#include "avlTree.h"
#include "utilidades.h"

struct NO{

    Pessoa pessoa;
    int altura;
    struct NO *esq;
    struct NO *dir;

};

avlTree *criar_avlTree(){

    avlTree *raiz = (avlTree*) malloc(sizeof(avlTree));

    if(raiz != NULL){
        *raiz = NULL;
    }

    return raiz;
}

struct NO *procurarMenor(struct NO *atual){

    struct NO *no1 = atual;
    struct NO *no2 = atual -> esq;

    while(no2 != NULL){

        no1 = no2;
        no2 = no2 -> esq;

    }

    return no1;

}

int fatorBalanceamento_NO(struct NO * no){

    return labs(altura_no(no -> esq) - altura_no(no -> dir));

}

int altura_no(struct NO *no){

    if(no == NULL){
        return -1;
    }
    else{
        return no -> altura;
    }

}

int maior(int x, int y){

    if(x > y){
        return(x);
    }
    else{
        return(y);
    }
}

void liberar_avlTree(avlTree *raiz){

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

int vazia_avlTree(avlTree *raiz){

    if(raiz == NULL) { return 1;}
    if(*raiz == NULL){ return 1;}

    return 0;
}

int altura_avlTree(avlTree *raiz){

    if(raiz == NULL){ return 0;}
    if(*raiz == NULL){ return 0;}

    int alt_esq = altura_avlTree(&((*raiz) -> esq));
    int alt_dir = altura_avlTree(&((*raiz) -> dir));

    if(alt_esq > alt_dir){

        return(alt_esq + 1);
    }
    else{

        return(alt_dir + 1);
    }

}

int totalNO_avlTree(avlTree *raiz){

    if(raiz == NULL){ return 0;}
    if(*raiz == NULL){return 0;}

    int alt_esq = totalNO_avlTree(&((*raiz) -> esq));
    int alt_dir = totalNO_avlTree(&((*raiz) -> dir));

    return(alt_esq + alt_dir + 1);

}

// Percorrendo a árvore
// - Pré-ordem

void preOrdem_avlTree(avlTree *raiz){

    if(raiz == NULL){ return; }

    if(*raiz != NULL){

        printf(" -- %d\n", ((*raiz) -> pessoa.codigo));
        preOrdem_avlTree(&((*raiz) -> esq));
        preOrdem_avlTree(&((*raiz) -> dir));

    }

}

// Em ordem
void emOrdem_avlTree(avlTree *raiz){

    if(raiz == NULL){ return; }

    if(*raiz != NULL){
        emOrdem_avlTree(&((*raiz) -> esq));
        printf(" -- %d\n", (*raiz) -> pessoa.codigo);
        emOrdem_avlTree(&((*raiz) -> dir));
    }

}

// Pós-ordem
void posOrdem_avlTree(avlTree *raiz){

    if(raiz == NULL){ return; }

    if(*raiz != NULL){

        posOrdem_avlTree(&((*raiz) -> esq));
        posOrdem_avlTree(&((*raiz) -> dir));
        printf(" -- %d\n", (*raiz) -> pessoa.codigo);

    }

}

//consultando ----------------------------------------------------------------
int consulta_avlTree(avlTree *raiz, int valor){

    if(raiz == NULL){ return 0;}

    struct NO *atual = *raiz;

    while(atual != NULL){

        if(valor == atual -> pessoa.codigo){
            return 1;
        }

        if(valor > atual -> pessoa.codigo){
            atual = atual -> dir;
        }
        else{
            atual = atual -> esq;
        }
    }

    return 0;
}

// - Rotações

void rotacaoLL(avlTree *raiz){

    struct NO *no;

    no = (*raiz) -> esq;

    (*raiz) -> esq = no -> dir;
    no -> dir = *raiz;

    (*raiz) -> altura = maior(altura_no((*raiz) -> esq), altura_no((*raiz) -> dir)) +1;
    no -> altura = maior(altura_no(no -> esq), (*raiz) -> altura) +1; // ---------------------correto?
    *raiz = no;

}

void rotacaoRR(avlTree *raiz){

    struct NO *no;

    no = (*raiz) -> dir;

    (*raiz) -> dir = no -> esq;
    no -> esq = *raiz;

    (*raiz) -> altura = maior(altura_no((*raiz) -> esq), altura_no((*raiz) -> dir)) +1;
    no -> altura = maior(altura_no(no -> dir), (*raiz) -> altura) +1;
    *raiz = no;

}

void rotacaoLR(avlTree *raiz){

    rotacaoRR(&(*raiz) -> esq);
    rotacaoLL(raiz);

}

void rotacaoRL(avlTree *raiz){

    rotacaoLL(&(*raiz) -> dir);
    rotacaoRR(raiz);

}

//inserções
int inserir_avlTree(avlTree *raiz, Pessoa valor){

    int res;
    if(*raiz == NULL){
        struct NO *novo;
        novo = (struct NO*) malloc(sizeof (struct NO));

        if(novo == NULL){return 0;}

        novo -> pessoa = valor;
        novo -> altura = 0;
        novo -> esq = NULL;
        novo -> dir = NULL;

        *raiz = novo;
        return 1;
    }

    struct NO *atual = *raiz;

    if(valor.codigo < atual -> pessoa.codigo){

        if((res = inserir_avlTree(&(atual -> esq), valor)) == 1){

            if(fatorBalanceamento_NO(atual) >= 2){
                if(valor.codigo < (*raiz) -> esq -> pessoa.codigo){
                    rotacaoLL(raiz);
                }
                else{
                    rotacaoLR(raiz);
                }
            }
        }
    }
    else{

        if(valor.codigo > atual -> pessoa.codigo){

            if((res = inserir_avlTree(&(atual -> dir), valor)) == 1){

                if(fatorBalanceamento_NO(atual) >= 2){

                    if((*raiz) -> dir -> pessoa.codigo < valor.codigo){

                        rotacaoRR(raiz);
                    }
                    else{

                        rotacaoRL(raiz);
                    }
                }
            }
        }
        else{
            printf("Valor Duplicado!\n");
            return 0;
        }
    }
    atual -> altura = maior(altura_no(atual -> esq), altura_no(atual -> dir)) + 1;
    return res;
}
