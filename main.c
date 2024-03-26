#include <stdio.h>
#include "TAD-animal/animal.h"
#include "TAD-recinto/recinto.h"

void exibir_menu(void) {
    printf(
        "======= MENU =======\n"
        "1. Adicionar recinto\n"
        "2. Remover recinto\n"
        "3. Adicionar animal\n"
        "4. Remover animal\n"
        "5. Editar informacao de animal\n"
        "6. Buscar animal por nome\n"
        "7. Listar recintos e os animais presentes\n"
        "8. Sair\n"
        "====================\n"
    );
}

int main(void) {
    int opcao = 0;
    char arq_recinto[] = "dados/recintos.txt";
    char arq_animal[] = "dados/animais.txt";
    char nome_animal[50];
    Animal * lista;
    Animal * resultado_busca;
    //Recinto * listar;

    while(opcao != 8){
        exibir_menu();
        printf("==Escolha uma opcao do nosso menu:== ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                adiciona_recinto(arq_recinto);
                break;
            case 2:
                break;
            case 3:
                adiciona_animal(arq_animal);
                break;
            case 4:
                printf("# Informe o nome do animal que sera removido:\n");
                scanf(" %49s", nome_animal);
                if(remove_animal(arq_animal, nome_animal) == 1) {
                    printf("* Animal removido! *\n");
                } else {
                    printf("* Animal nao encontrado! *\n");
                }
                break;
            case 5:
                printf("# Informe o nome do animal para editar os seus dados:\n");
                scanf(" %49s", nome_animal);
                edita_dados_animal(arq_animal, nome_animal);
                break;
            case 6:
                printf("# Informe o nome do animal para realizar a busca:\n");
                scanf(" %49s", nome_animal);
                lista = carrega_animais_arquivo(arq_animal);
                resultado_busca = busca_animal(lista, nome_animal);
                if(resultado_busca != NULL) {
                    printf("--- Animal buscado ---\n");
                    imprime_dados_animal(resultado_busca);
                    printf("----------------------\n");
                } else {
                    printf("* Animal nao encontrado! *\n");
                }
                libera_lista_animais(lista);
                break;
            case 7:
                break;
            case 8:
                printf("Voce saiu do nosso gerenciamento de zoologico, volte sempre!\n");
                break;
            default:
                printf("* Opcao invalida! *\n");
                break;
        }
    }
    return 0;
}