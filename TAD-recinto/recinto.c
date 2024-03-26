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

Recinto * insere_recinto_lista(Recinto * listar, int id, int capacidade, char horario[], char animaispre[]) {
    Recinto * novo_elemento = (Recinto *) malloc(sizeof(Recinto));
    if(novo_elemento == NULL) {
        printf("Falha na alocacao de memoria na funcao 'insere_recinto_lista'.\n");
        exit(1);
    }
    novo_elemento->id = id;
    novo_elemento->capacidade = capacidade;
    strcpy(novo_elemento->horario, horario);
    strcpy(novo_elemento->animaispre, animaispre);

    if(listar == NULL || id < listar->id) {
        novo_elemento->pro_elemento = listar;
        return novo_elemento;
    }

    Recinto * elemento_atual = listar;
    while(elemento_atual->pro_elemento != NULL && id > elemento_atual->pro_elemento->id) {
        elemento_atual = elemento_atual->pro_elemento;
    }
    novo_elemento->pro_elemento = elemento_atual->pro_elemento;
    elemento_atual->pro_elemento = novo_elemento;

    return listar;
}

Recinto * carrega_recintos_arquivo(char arquivo_nome[]){
    Recinto * listar = cria_lista_recinto();
    FILE * arquivo = fopen(arquivo_nome, "r");
    if(arquivo == NULL){
        printf("Erro na tentativa de abrir arquivo na funcao 'carrega_recintos_arquivo'\n");
        exit(1);
    }
    int id;
    int capacidade;
    char horario[50];
    char animaispre[50];

    while(fscanf(arquivo, "%d %d %[^\n] %[^\n]", &id, &capacidade, horario, animaispre) == 4) {
        listar = insere_recinto_lista(listar, id, capacidade, horario, animaispre);
    }

    fclose(arquivo);
    return listar;
}

void insere_recintos_arquivo(char arquivo_nome[], Recinto * listar){
   FILE * arquivo = fopen(arquivo_nome, "w"); 
   if(arquivo == NULL) {
        printf("Erro ao tentar abrir arquivo na funcao 'insere_recintos_arquivo'.\n");
        exit(1);
    }
    while(listar != NULL) {
        fprintf(arquivo, "%d %d %s %s\n", listar->id, listar->capacidade, listar->horario, listar->animaispre);
        listar = listar->pro_elemento;
    }

    fclose(arquivo);
}

void libera_lista_recintos(Recinto * listar) {
    Recinto * elemento_atual;

    while(listar != NULL) {
        elemento_atual = listar;
        listar = listar->pro_elemento;
        free(elemento_atual);
    }
}

void adiciona_recinto(char arquivo_nome[]){
    char * caminho = "dados/recintos.txt";
    Recinto * listar = carrega_recintos_arquivo(arquivo_nome);
    int id;
    int capacidade;
    char horario[50];
    char animaispre[50];

    printf("----Adicione o recinto----\n");
    printf("Informe a identificacao do recinto:\n ex:456\n");
    scanf("%d", &id);
    printf("Informe a capacidade maxima de animais nesse recinto:\n ex:80");
    scanf("%d", &capacidade);
    printf("Informe o horario de visitas do recinto:\n ex: dez da manha as seis da tarde\n");
    scanf(" %[^\n]", horario);
    printf("Informe quantos animais estão presentes no recinto e qual a sua especie:\n ex:seis ursos\n");
    scanf(" %[^\n]", animaispre);
    printf("---------------------------\n");
    listar = insere_recinto_lista( listar, id, capacidade, horario, animaispre);
    insere_recintos_arquivo (arquivo_nome, listar);
    libera_lista_recintos(listar);
    printf("* Recinto adicionado com sucesso! *\n");
}

void imprime_dados_recinto(Recinto * dados){
    printf("Id: %d\n", dados->id);
    printf("Capacidade: %d\n", dados->capacidade);
    printf("Horario: %s\n", dados->horario);
    printf("Animais Presentes: %s\n", dados->animaispre);
}