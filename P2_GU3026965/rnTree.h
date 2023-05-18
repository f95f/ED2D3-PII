typedef struct NO *arvoreLLRB;

arvoreLLRB *criar_arvoreLLRB();

void liberar_arvoreLLRB(arvoreLLRB *raiz);

int vazia_arvoreLLRB(arvoreLLRB *raiz);

int altura_arvoreLLRB(arvoreLLRB *raiz);

int totalNO_arvoreLLRB(arvoreLLRB *raiz);

// Percorrendo a árvore
    // - Pré-ordem
void preOrdem_arvoreLLRB(arvoreLLRB *raiz);

// Percorrendo a árvore
    // - Em ordem
void emOrdem_arvoreLLRB(arvoreLLRB *raiz);

// Percorrendo a árvore
    // - Pós-ordem
void posOrdem_arvoreLLRB(arvoreLLRB *raiz);

//consulta
int consulta_arvoreLLRB(arvoreLLRB *raiz, int valor);

int insere_arvoreLLRB(arvoreLLRB  *raiz, int valor);

int remove_arvoreLLRB(arvoreLLRB *raiz, int valor);
