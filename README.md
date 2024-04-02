# Sistema de Gerenciamento de Zoológico

## Informações do Projeto
  * Desenvolvedores
  * Disciplina e Docente

## Visão Geral
  * O Sistema de Gerenciamento de Zoológico é um programa feito em C que tem como objetivo ter o controle dos recintos e dos animais do Zoológico.

## Problemática
 * Projetar um sistema na Linguagem C para gerenciamento de um zoológico. O sistema precisa manipular recintos e animais.

## Funcionalidades do Sistema
 ### Menu
  * É exibido um menu com as opções de manipulação e controle dos recintos e animais, esse menu possui 8 opções.
    

### 1-Adicionar recinto
   * Permite ao usuário adicionar um recinto onde são preenchidos e armazenados os campos de Identificação do recinto, a Capacidade, os Horários de Visitas e os Animais Presentes.
 
    void adiciona_recinto(char arquivo_nome[]){
      Recinto * lista = carrega_recintos_arquivo(arquivo_nome);
      int id;
      int capacidade;
      char horario[50];
      char animais_pre[50];
    
      printf("---- Insercao de recinto ----\n");
      printf("Informe a identificacao do recinto:\n ex:456\n");
      scanf("%d", &id);
      printf("Informe a capacidade maxima de animais do recinto:\n ex:80\n");
      scanf("%d", &capacidade);
      printf("Informe o horario de visitas do recinto:\n ex: 10:00 as 12:00\n");
      scanf(" %[^\n]", horario);
      printf("Informe os animais que estao presentes no recinto:\n ex:6 ursos\n");
      scanf(" %[^\n]", animais_pre);
      printf("-----------------------------\n");

      lista = insere_recinto_lista(lista, id, capacidade, horario, animais_pre);
      insere_recintos_arquivo (arquivo_nome, lista);
      libera_lista_recintos(lista);

      printf("* Recinto adicionado com sucesso! *\n");
      }
### 2-Remover recinto
   * Permite que o usuário remova um recinto que foi adicionado anteriormente.  
   
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

### 3-Adicionar animal
   * Permite ao usuário adicionar um animal em que os campos de Nome, Espécie e Idade são preenchidos e armazenados.
    

### 4-Remover animal
   * Permite que o usuário remova um animal que foi adicionado anteriormente.
    
    int remove_animal(char nome_arquivo[], char nome_animal[]) {
      Animal * lista = carrega_animais_arquivo(nome_arquivo);
      Animal * elemento_atual = lista;
      Animal * elemento_remover;
      int removido = 0;

    if(lista != NULL) {
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
        insere_animais_arquivo(nome_arquivo, lista);
        libera_lista_animais(lista);
    }
    return removido;
    }
### 5-Editar informação de animal
   * Possibilita ao usuário a edição dos dados anteriormente preenchidos dos animais.
   
### 6-Buscar animal por nome
   * Oferece o preenchimento do nome do animal adicionado anteriormente em que após informado é exibido os dados daquele animal.

    Animal * busca_animal(Animal * lista, char nome_animal[]) {
    while(lista != NULL) {
        if(strcmp(lista->nome, nome_animal) == 0) {
            return lista;
        }
        lista = lista->prox_elemento;
    }
    return lista;
    }
### 7-Listar recintos e os animais presentes
  * Nessa opção são listados todos os recintos armazenados de forma ordenada por identificação com os seus respectivos dados informados.

        void imprime_dados_recinto(Recinto * lista) {
           printf("--------- Recintos ---------\n");
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
         printf("----------------------------\n");
         }
    
### 8-Sair
   * Oferece a oportunidade de sair do programa, sendo essa a única opção que permite a saída.
     
    //Acontece um loop que enquanto a opção escolhida for diferente de 8, irá exibir o menu novamente
    while(opcao != 8){
        exibir_menu();
        printf("# Escolha uma opcao do nosso menu: ");
        scanf("%d", &opcao);
    //Caso seja escolhida a oitava opção o programa será encerrado.
    case 8:
      printf("Programa de gerenciamento de zoologico encerrado!\n");
      break;
## Tecnologias e Métodos Utilizados no Programa
 ### Linguagem de Programação
   * C

 ### Métodos 

