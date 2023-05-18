typedef struct NO *binTree;

binTree *criar_binTree();

void liberar_binTree(binTree *raiz);

int vazia_binTree(binTree *raiz);

int altura_binTree(binTree *raiz);

int totalNO_binTree(binTree *raiz);

// Percorrendo a árvore
    // - Pré-ordem
void preOrdem_binTree(binTree *raiz);

// Percorrendo a árvore
    // - Em ordem
void emOrdem_binTree(binTree *raiz);

// Percorrendo a árvore
    // - Pós-ordem
void posOrdem_binTree(binTree *raiz);

// Inserindo
int inserir_binTree(binTree *raiz, int valor);

//Removendo
int remove_binTree(binTree *raiz, int valor);

//consulta
int consulta_binTree(binTree *raiz, int valor);
