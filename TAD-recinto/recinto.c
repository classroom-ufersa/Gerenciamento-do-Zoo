#include "recinto.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct recinto{
    int id;
    int capacidade;
    char horario[50];
    char animais_pre[100];
    Recinto * prox_elemento;
};

Recinto * cria_lista_recinto(void) {
    return NULL;
}

Recinto * insere_recinto_lista(Recinto * lista, int id, int capacidade, char horario[], char animais_pre[]) {
    Recinto * novo_elemento = (Recinto *) malloc(sizeof(Recinto));
    if(novo_elemento == NULL) {
        printf("Falha na alocacao de memoria na funcao 'insere_recinto_lista'.\n");
        exit(1);
    }
    novo_elemento->id = id;
    novo_elemento->capacidade = capacidade;
    strcpy(novo_elemento->horario, horario);
    strcpy(novo_elemento->animais_pre, animais_pre);

    if(lista == NULL || id < lista->id) {
        novo_elemento->prox_elemento = lista;
        return novo_elemento;
    }

    Recinto * elemento_atual = lista;
    while(elemento_atual->prox_elemento != NULL && id > elemento_atual->prox_elemento->id) {
        elemento_atual = elemento_atual->prox_elemento;
    }
    novo_elemento->prox_elemento = elemento_atual->prox_elemento;
    elemento_atual->prox_elemento = novo_elemento;

    return lista;
}

Recinto * carrega_recintos_arquivo(char arquivo_nome[]){
    Recinto * lista = cria_lista_recinto();
    FILE * arquivo = fopen(arquivo_nome, "r");
    if(arquivo == NULL){
        printf("Erro na tentativa de abrir arquivo na funcao 'carrega_recintos_arquivo'\n");
        exit(1);
    }
    int id;
    int capacidade;
    char horario[50];
    char animais_pre[100];

    while(fscanf(arquivo, "%d %d %[^\t] %[^\n]", &id, &capacidade, horario, animais_pre) == 4) {
        lista = insere_recinto_lista(lista, id, capacidade, horario, animais_pre);
    }

    fclose(arquivo);
    return lista;
}

void insere_recintos_arquivo(char arquivo_nome[], Recinto * lista){
   FILE * arquivo = fopen(arquivo_nome, "w"); 
   if(arquivo == NULL) {
        printf("Erro ao tentar abrir arquivo na funcao 'insere_recintos_arquivo'.\n");
        exit(1);
    }
    while(lista != NULL) {
        fprintf(arquivo, "%d\t%d\t%s\t%s\n", lista->id, lista->capacidade, lista->horario, lista->animais_pre);
        lista = lista->prox_elemento;
    }

    fclose(arquivo);
}

void libera_lista_recintos(Recinto * lista) {
    Recinto * elemento_atual;

    while(lista != NULL) {
        elemento_atual = lista;
        lista = lista->prox_elemento;
        free(elemento_atual);
    }
}

void adiciona_recinto(char arquivo_nome[]){
    Recinto * lista = carrega_recintos_arquivo(arquivo_nome);
    int id;
    int capacidade;
    char horario[50];
    char animais_pre[50];

    printf("----Adicione o recinto----\n");
    printf("Informe a identificacao do recinto:\n ex:456\n");
    scanf("%d", &id);
    printf("Informe a capacidade maxima de animais do recinto:\n ex:80\n");
    scanf("%d", &capacidade);
    printf("Informe o horario de visitas do recinto:\n ex: dez da manha as seis da tarde\n");
    scanf(" %[^\n]", horario);
    printf("Informe os animais que estao presentes no recinto:\n ex:seis ursos\n");
    scanf(" %[^\n]", animais_pre);
    printf("--------------------------\n");

    lista = insere_recinto_lista(lista, id, capacidade, horario, animais_pre);
    insere_recintos_arquivo (arquivo_nome, lista);
    libera_lista_recintos(lista);

    printf("* Recinto adicionado com sucesso! *\n");
}

void imprime_dados_recinto(Recinto * lista) {
    printf("========= Recintos =========\n");
    if(lista == NULL) {
        printf("* Nenhum recinto encontrado *\n");
    }
    while(lista != NULL) {
        printf("Id: %d\n", lista->id);
        printf("Capacidade: %d\n", lista->capacidade);
        printf("Horario: %s\n", lista->horario);
        printf("Animais Presentes: %s\n", lista->animais_pre);
        if(lista->prox_elemento != NULL) {
            printf("\n");
        }
        lista = lista->prox_elemento;
    }
    printf("============================\n");
}

int remove_recinto(char arquivo_nome[], int id_recinto) {
    Recinto * lista = carrega_recintos_arquivo(arquivo_nome);
    Recinto * elemento_atual = lista;
    Recinto * elemento_remover;
    int removido = 0;

    if(lista != NULL) {
        if(lista->id == id_recinto) {
            elemento_remover = lista;
            lista = lista->prox_elemento;
            free(elemento_remover);
            removido = 1;
        } else {
            while(elemento_atual->prox_elemento != NULL) {
                if(elemento_atual->prox_elemento->id == id_recinto) {
                    elemento_remover = elemento_atual->prox_elemento;
                    elemento_atual->prox_elemento = elemento_remover->prox_elemento;
                    free(elemento_remover);
                    removido = 1;
                    break;
                }
                elemento_atual = elemento_atual->prox_elemento;
            }
        }
        insere_recintos_arquivo(arquivo_nome, lista);
        libera_lista_recintos(lista);
    }
    return removido;
}
