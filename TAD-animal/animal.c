#include "animal.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct animal {
    char nome[50];
    char especie[50];
    int idade;
    Animal * prox_elemento;
};

Animal * cria_lista_animais(void) {
    return NULL;
}

Animal * insere_elemento_lista(Animal * lista, char nome[], char especie[], int idade) {
    Animal * novo_elemento = (Animal *) malloc(sizeof(Animal));
    if(novo_elemento == NULL) {
        printf("Erro: Falha ao alocar memoria para um novo elemento na funcao 'insere_elemento_lista'.\n");
        exit(1);
    }
    strcpy(novo_elemento->nome, nome);
    strcpy(novo_elemento->especie, especie);
    novo_elemento->idade = idade;
    novo_elemento->prox_elemento = lista;

    return novo_elemento;
}

Animal * carrega_dados_arquivo(FILE * arquivo) {
    Animal * lista = cria_lista_animais();
    if(arquivo == NULL) {
        printf("Erro: Falha ao tentar abrir arquivo na funcao 'carrega_dados_arquivo'.\n");
        return lista;
    }
    char nome[50];
    char especie[50];
    int idade;

    while(fscanf(arquivo, "%49s %49s %d", nome, especie, &idade) == 3) {
        lista = insere_elemento_lista(lista, nome, especie, idade);
    }
    return lista;
}