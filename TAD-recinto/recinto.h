/* Definição de novo tipo: Recinto */
typedef struct recinto Recinto;

/* Função que inicializa uma lista de recintos retornando NULL */
Recinto * cria_lista_recinto(void);

/*Função que insere um novo recinto na lista encadeada ordenado por id*/
Recinto * insere_recinto_lista(Recinto * lista, int id, int capacidade, char horario[], char animais_pre[]);

/* Função que carrega os dados de um arquivo em uma lista e retorna o seu endereço */
Recinto * carrega_recintos_arquivo(char arquivo_nome[]);

/* Função que insere os dados de uma lista de recintos em um arquivo */
void insere_recintos_arquivo(char arquivo_nome[], Recinto * lista);

/*Função que libera a memória de uma lista de animais*/
void libera_lista_recintos(Recinto * lista);

/*Função responsável por adicionar um novo recinto no arquivo*/
void adiciona_recinto(char arquivo_nome[]);

/*Função responsável por imprimir os dados dos recintos*/
void imprime_dados_recinto(Recinto * lista);

/* Função que remove os dados de um recinto, especificado pelo id, de um arquivo. Retorna 1 
 para removido e 0 para animal não encontrado */
int remove_recinto(char arquivo_nome[], int id_recinto);

/*Tratativa responsável por garantir que uma entrada contenha apenas números inteiros.*/ 
int contem_apenas_numeros(const char *str);
