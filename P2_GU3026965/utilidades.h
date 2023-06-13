/*
    Esta biblioteca cont�m fun��es para atividades auxiliares, tais como
    formata��es, gera��o de menus, gera��o de vetores, verifica��es etc.,
    bem como a fun��o principal de executar as medi��es e exibir os resultados.
*/
typedef struct obj{
    int codigo;
    char *nome;
    int idade;
    char *empresa;
    char *departamento;
    float salario;
} Pessoa;

// Quantidade de registros na massa de dados, tamanho comum � todas as listas.
#define TAMANHO 14999

// Cria uma linha com o caractere e desejado.
void linha(char formato, int tamanho);

// Cria um cabe�alho padr�o � todas as telas.
void gerarHeader();

// L� o arquivo cujo nome � informado por par�metro,
// carregando os dados em uma lista de estruturas do tipo Pessoa.
Pessoa *ler(char *arqauivo);

// Recebe por par�metro uma lista de estruturas do tipo Pessoa,
// a organiza em ordem crescente e a grava em um arquivo.
void ordenar(Pessoa *lista);

// Libera a mem�ria alocada para campos com cadeias de caracteres
// (nome, empresa e departamento) de cada elemento da lista recebida por par�metro.
// Em seguida, libera a mem�ria alocada para a lista.
void limpar(Pessoa *lista);

// Salva a lista recebida em um arquivo, cujo nome � informado por par�metro.
int gravar(Pessoa *lista, char *arquivo);

// Obtem uma amostra de 50 n�meros de uma lista e a exibe na tela.
// Esta fun��o foi implementada com a inten��o de verificar de forma simples a lista antes e depois
// de ordenada. Recebe para fins de identifica��o uma descri��o por par�metro e a exibe na tela.
void amostrar(Pessoa *lista, char *descr);

// Preenche a �rvore selecionada com dados do arquivo informado
// e executa a medi��o de tempo.
// Ao final, exibe os resultados das medi��es.
int executar(char *arvore, char *lista);
