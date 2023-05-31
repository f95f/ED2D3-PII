
/*
    Esta biblioteca contém funções para atividades auxiliares, tais como
    formatações, geração de menus, geração de vetores, verificações etc.,
    bem como a função principal de executar as medições e exibir os resultados.
*/

#define TAMANHO 14999

// Estrutura utilizada para armazenar cada instância.
typedef struct obj{
    int codigo;
    char *nome;
    int idade;
    char *empresa;
    char *departamento;
    float salario;

} Pessoa;

// Cria uma linha com o caractere e desejado.
void linha(char formato, int tamanho);

// Cria um cabeçalho padrão à todas as telas.
void gerarHeader();

// Lê o arquivo cujo nome é informado por parâmetro,
// carregando os dados em uma lista de estruturas do tipo Pessoa.
Pessoa *ler(char *arqauivo);

// Recebe por parâmetro uma lista de estruturas do tipo Pessoa
// A organiza em ordem crescente e a grava em um arquivo cujo nome
// é especificado por parâmetro.
void ordenar(Pessoa *lista);

void limpar(Pessoa *lista);

//a
int gravar(Pessoa *lista, char *arquivo);

// Obtem uma amostra de 50 números de uma lista e a exibe na tela.
// Esta função foi implementada com a intenção de verificar de forma simples a lista antes e depois
// de ordenada. Recebe para fins de identificação uma descrição por parâmetro e a exibe na tela.
void amostrar(Pessoa *lista, char *descr);

// Monta a lista de números aleatórios de acordo com a quantidade informada,
// executa a ordenação de acordo com o algoritmo solicitado e executa a medição de tempo.
// Ao final, exibe os resultados das medições.
int executar(int metodo);
