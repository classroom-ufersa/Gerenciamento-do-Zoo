/* Definição de novo tipo: Animal */
typedef struct animal Animal;

/* Função que inicializa uma lista de animais retornando NULL */
Animal * cria_lista_animais(void);

/* Função que insere um novo elemento, em ordem alfabética, em uma lista de animais e retorna
 o endereço atualizado do primeiro elemento da lista */
Animal * insere_animal_lista(Animal * lista, char nome[], char especie[], int idade);

/* Função que carrega os dados de um arquivo em uma lista e retorna o seu endereço */
Animal * carrega_animais_arquivo(char nome_arquivo[]);

/* Função que insere os dados de uma lista de animais em um arquivo */
void insere_animais_arquivo(char nome_arquivo[], Animal * lista);

/* Função que libera a memória de uma lista de animais */
void libera_lista_animais(Animal * lista);

/* Função que adiciona os dados de um novo animal em arquivo */
void adiciona_animal(char nome_arquivo[]);

/* Função que imprime os dados de um animal */
void imprime_dados_animal(Animal * dados);

/* Função que busca um animal, especificado pelo nome, em uma lista e devolve o endereço
 do elemento que o contém, se o animal não for encontrado retorna NULL */
Animal * busca_animal(Animal * lista, char nome_animal[]);

/* Função que remove os dados de um animal, especificado pelo nome, de um arquivo. Retorna 1 
 para removido e 0 para animal não encontrado */
int remove_animal(char nome_arquivo[], char nome_animal[]);

/* Função que edita os dados de um animal e atualiza o arquivo com o novos dados */
void edita_dados_animal(char nome_arquivo[], char nome_animal[]);