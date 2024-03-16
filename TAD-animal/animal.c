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
    while(lista != NULL) {
        fprintf(arquivo, "%s %s %d\n", lista->nome, lista->especie, lista->idade);
        lista = lista->prox_elemento;
    }

    fclose(arquivo);
}

void libera_lista(Animal * lista) {
    Animal * elemento_atual;

    while(lista != NULL) {
        elemento_atual = lista;
        lista = lista->prox_elemento;
        free(elemento_atual);
    }
}

void adiciona_animal(char nome_arquivo[]) {
    Animal * lista;
    char nome[50];
    char especie[50];
    int idade;

    lista = carrega_dados_arquivo(nome_arquivo);
    printf("---- Insercao de animal ----\n");
    printf("# Informe o nome do animal:\n");
    scanf(" %49s", nome);
    printf("# Informe a especie do animal:\n");
    scanf(" %49s", especie);
    printf("# Informe a idade do animal:\n");
    scanf("%d", &idade);
    printf("----------------------------\n");

    lista = insere_elemento_lista(lista, nome, especie, idade);
    insere_dados_arquivo(nome_arquivo, lista);
    libera_lista(lista);
    
    printf("* Insercao concluida! *\n");
}

Animal * busca_animal(Animal * lista, char nome_animal[]) {
    while(lista != NULL) {
        if(strcmp(lista->nome, nome_animal) == 0) {
            return lista;
        }
        lista = lista->prox_elemento;
    }
    return lista;
}

int remove_animal(char nome_arquivo[], char nome_animal[]) {
    Animal * lista = carrega_dados_arquivo(nome_arquivo);
    Animal * elemento_atual = lista;
    Animal * elemento_remover;
    int removido = 0;

    if(strcmp(lista->nome, nome_animal) == 0){
        elemento_remover = lista;
        lista = lista->prox_elemento;
        free(elemento_remover);
        removido = 1;
    } else {
        while(elemento_atual->prox_elemento != NULL) {
            if(strcmp(elemento_atual->prox_elemento->nome, nome_animal) == 0) {
                elemento_remover = elemento_atual->prox_elemento;
                elemento_atual->prox_elemento = elemento_remover->prox_elemento;
                free(elemento_remover);
                removido = 1;
                break;
            }
            elemento_atual = elemento_atual->prox_elemento;
        }
    }
    insere_dados_arquivo(nome_arquivo, lista);
    libera_lista(lista);
    return removido;
}