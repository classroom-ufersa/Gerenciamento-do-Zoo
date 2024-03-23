#include "recinto.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct recinto{
    int id;
    int capacidade;
    char horario[50];
    char animaispre[50];
    Recinto * pro_elemento;
};

Recinto * cria_lista_recinto(void) {
    return NULL;
}

Recinto * insere_recinto_lista(Recinto * lista, int id, int capacidade, char horario[], char animaispre[]) {
    Recinto * novo_elemento = (Recinto *) malloc(sizeof(Recinto));
    if(novo_elemento == NULL) {
        printf("Falha na alocacao de memoria.\n");
        exit(1);
    }
    novo_elemento->id = id;
    novo_elemento->capacidade = capacidade;
    strcpy(novo_elemento->horario, horario);
    strcpy(novo_elemento->animaispre, animaispre);

    if(lista == NULL || id < lista->id) {
        novo_elemento->pro_elemento = lista;
        return novo_elemento;
    }

    Recinto * elemento_atual = lista;
    while(elemento_atual->pro_elemento != NULL && id > elemento_atual->pro_elemento->id) {
        elemento_atual = elemento_atual->pro_elemento;
    }
    novo_elemento->pro_elemento = elemento_atual->pro_elemento;
    elemento_atual->pro_elemento = novo_elemento;

    return lista;
}
