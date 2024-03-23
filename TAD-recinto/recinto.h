/* Definição de novo tipo: Recinto */
typedef struct recinto Recinto;

/* Função que inicializa uma lista de recintos retornando NULL */
Recinto * cria_lista_recinto(void);

/*Função que insere um novo recinto na lista encadeada ordenado por id*/
Recinto * insere_recinto_lista(Recinto * lista, int id, int capacidade, char horario[], char animaispre[]);