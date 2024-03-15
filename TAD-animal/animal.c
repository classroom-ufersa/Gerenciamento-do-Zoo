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

    if(lista == NULL || strcmp(novo_elemento->nome, lista->nome) <= 0) {
        novo_elemento->prox_elemento = lista;
        return novo_elemento;
    }

    Animal * elemento_atual = lista;
    while(elemento_atual->prox_elemento != NULL && strcmp(novo_elemento->nome, elemento_atual->prox_elemento->nome) > 0) {
        elemento_atual = elemento_atual->prox_elemento;
    }
    novo_elemento->prox_elemento = elemento_atual->prox_elemento;
    elemento_atual->prox_elemento = novo_elemento;

    return lista;
}

Animal * carrega_dados_arquivo(char nome_arquivo[]) {
    Animal * lista = cria_lista_animais();
    FILE * arquivo = fopen(nome_arquivo, "r");
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

    fclose(arquivo);
    return lista;
}

void insere_dados_arquivo(char nome_arquivo[], Animal * lista) {
    FILE * arquivo = fopen(nome_arquivo, "w");
    if(arquivo == NULL) {
        printf("Erro: Falha ao tentar abrir arquivo '%s' na funcao 'insere_dados_arquivo'.\n", nome_arquivo);
        exit(1);
    }
    Animal * contador;
    for(contador = lista; contador != NULL; contador = contador->prox_elemento){
        fprintf(arquivo, "%s %s %d\n", contador->nome, contador->especie, contador->idade);
    }
    fclose(arquivo);
}

void libera_lista(Animal * lista) {
    Animal * elemento_atual;
    Animal * contador = lista;

    while(contador != NULL) {
        elemento_atual = contador;
        contador = contador->prox_elemento;
        free(elemento_atual);
    }
}

void adiciona_animal(char nome_arquivo[]) {
    Animal * lista;
    char nome[50];
    char especie[50];
    int idade;

    lista = carrega_dados_arquivo(nome_arquivo);
    printf("-------------------------\n");
    printf("Informe o nome do animal:\n");
    scanf(" %49s", nome);
    printf("Informe a especie do animal:\n");
    scanf(" %49s", especie);
    printf("Informe a idade do animal:\n");
    scanf("%d", &idade);
    printf("-------------------------\n");

    lista = insere_elemento_lista(lista, nome, especie, idade);
    insere_dados_arquivo(nome_arquivo, lista);
    libera_lista(lista);
    
    printf("Insercao concluida!\n");
}