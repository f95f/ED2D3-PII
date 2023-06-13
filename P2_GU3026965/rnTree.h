
typedef struct NO *arvoreLLRB;

arvoreLLRB *criar_arvoreLLRB();

void liberar_arvoreLLRB(arvoreLLRB *raiz);

int vazia_arvoreLLRB(arvoreLLRB *raiz);

int altura_arvoreLLRB(arvoreLLRB *raiz);

int totalNO_arvoreLLRB(arvoreLLRB *raiz);

// consulta - retorna 1 caso o código informado em 'valor' for encontrado
// na árvore, e retorna 0 caso não seja encontrado.
int consulta_arvoreLLRB(arvoreLLRB *raiz, int valor);

// Busca - Retorna o conteúdo do nó caso o valor informado na variável 'código'
// for encontrado, e retorna 0 caso não seja encontrado.
int buscar_arvoreLLRB(arvoreLLRB *raiz, int codigo);

int insere_arvoreLLRB(arvoreLLRB  *raiz, int valor);
