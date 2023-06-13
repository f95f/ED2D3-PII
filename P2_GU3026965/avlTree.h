
typedef struct NO *avlTree;

avlTree *criar_avlTree();

void liberar_avlTree(avlTree *raiz);

int vazia_avlTree(avlTree *raiz);

int altura_avlTree(avlTree *raiz);

int totalNO_avlTree(avlTree *raiz);

// consulta - retorna 1 caso o código informado em 'valor' for encontrado
// na árvore, e retorna 0 caso não seja encontrado.
int consulta_avlTree(avlTree *raiz, int valor);

// Busca - Retorna o conteúdo do nó caso o valor informado na variável 'código'
// for encontrado, e retorna 0 caso não seja encontrado.
int busca_avlTree(avlTree *raiz, int codigo);

int remove_avlTree(avlTree *raiz, int valor);
