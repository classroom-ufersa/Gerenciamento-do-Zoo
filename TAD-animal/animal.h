/* Definição de novo tipo: Animal */
typedef struct animal Animal;

/* Função que inicializa uma lista de animais retornando NULL */
Animal * cria_lista_animais(void);

/* Função que insere um novo elemento em uma lista de animais e retorna o endereço atualizado
 do primeiro elemento da lista */
Animal * insere_elemento_lista(Animal * lista, char nome[], char especie[], int idade);

/* Função que carrega os dados de um arquivo em uma lista e retorna o seu endereço */
Animal * carrega_dados_arquivo(FILE * arquivo);