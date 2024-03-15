#include <stdio.h>
#include "TAD-animal/animal.h"

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

int main() {
    int opcao = 0;
    char arq_animal[] = "dados/animais.txt";

    while(opcao != 8){
        exibir_menu();
        printf("Escolha uma opcao do menu: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                break;
            case 2:
                break;
            case 3:
                adiciona_animal(arq_animal);
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                break;
            case 7:
                break;
            case 8:
                printf("Programa encerrado.\n");
                break;
            default:
                printf("* Opcao invalida! *\n");
                break;
        }
    }
    return 0;
}