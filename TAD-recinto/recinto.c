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

Recinto * carrega_recintos_arquivo(char arquivo_nome[]){
    Recinto * lista = cria_lista_recinto();
    FILE * arquivo = fopen(arquivo_nome, "r");
    if(arquivo == NULL){
        printf("Erro na tentativa de abrir\n");
        exit(1);
    }
    int id;
    int capacidade;
    char horario[50];
    char animaispre[50];

    while(fscanf(arquivo, "%d %d %49s %49s", &id, &capacidade, horario, animaispre) == 4) {
        lista = insere_recinto_lista(lista, id, capacidade, horario, animaispre);
    }

    fclose(arquivo);
    return lista;
}

void insere_recintos_arquivo(char arquivo_nome[], Recinto * lista){
   FILE * arquivo = fopen(arquivo_nome, "w"); 
   if(arquivo == NULL) {
        printf("Falha ao tentar abrir arquivo '%s' na funcao 'insere_recintos_arquivo'.\n", arquivo_nome);
        exit(1);
    }
    while(lista != NULL) {
        fprintf(arquivo, "%d %d %s %s\n", lista->id, lista->capacidade, lista->horario, lista->animaispre);
        lista = lista->pro_elemento;
    }

    fclose(arquivo);
}

void libera_lista_recintos(Recinto * lista) {
    Recinto * elemento_atual;

    while(lista != NULL) {
        elemento_atual = lista;
        lista = lista->pro_elemento;
        free(elemento_atual);
    }
}
