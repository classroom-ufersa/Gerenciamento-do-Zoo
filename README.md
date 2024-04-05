# Sistema de Gerenciamento de Zoológico



## Informações do Projeto
#### Desenvolvedores:
  * Evelyn Cristina de Oliveira Gomes;
  * Levítico Rimon Perez Andrade Alves.
#### Disciplina e Docente:
  Projeto desenvolvido na disciplina de Algoritmos e Estrutura de Dados I lecionada pela professora Dra. Rosana Cibely Batista Rego.
#### Tópicos presentes no Arquivo:
  * [Introdução](#Introdução)
  * [Problemática](#Problemática)
  * [Descrição](#Descrição)
  * [Funcionalidades do Sistema](#Funcionalidadesdosistema)
  * [Tecnologias e Métodos Utilizados no Programa](#Tecnologiasemetodosutilizadosnosistema)

## Introdução
  O Sistema de Gerenciamento de Zoológico é um programa feito com o objetivo de ter o controle de um Zoológico com base na gestão de seus recintos e animais, sendo um ambiente extenso e de difícil gerenciamento manual, o sistema de gerenciamento é crucial para uma maior facilidade tendo com ele o controle de seus recintos em relação a quantidade e capacidades de cada um e gerenciamento de seus animais, trazendo assim, uma enorme melhoria no funcionamento do Zoológico.

## Problemática
 Projetar um sistema imlementado na Linguagem C, com intuito de facilitar e melhorar o gerenciamento de um Zoológico. O sistema conta com a manipulação de recintos e animais oferecendo diversas funcionalidades para garantir uma melhor organização dos dados do zoológico.

## Descrição
  O sistema foi implementado com duas TADs, uma para Recintos e uma para Animais.

## Funcionalidades do Sistema
 ### Menu
  * É exibido um menu com as opções de manipulação e controle dos recintos e animais, esse menu possui 8 opções.

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
 
    void adiciona_animal(char nome_arquivo[]) {
      Animal * lista = carrega_animais_arquivo(nome_arquivo);
      char nome[50];
      char especie[50];
      int idade;

      printf("---- Insercao de animal ----\n");
      printf("# Informe o nome do animal:\n");
      scanf(" %[^\n]", nome);
      printf("# Informe a especie do animal:\n");
      scanf(" %[^\n]", especie);
      printf("# Informe a idade do animal:\n");
      scanf("%d", &idade);
      printf("----------------------------\n");

      lista = insere_animal_lista(lista, nome, especie, idade);
      insere_animais_arquivo(nome_arquivo, lista);
      libera_lista_animais(lista);
    
      printf("* Insercao concluida! *\n");
    }
    
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

    void edita_dados_animal(char nome_arquivo[], char nome_animal[]) {
      Animal * lista = carrega_animais_arquivo(nome_arquivo);
      Animal * resultado_busca = busca_animal(lista, nome_animal);
      char novo_nome[50];
      char nova_especie[50];
      int nova_idade;

      if(resultado_busca != NULL) {
        printf("---- Dados atuais do animal ----\n");
        imprime_dados_animal(resultado_busca);
        printf("--------------------------------\n");
        libera_lista_animais(lista);
        printf("* Insira os novos dados do animal *\n");
        printf("# Nome: ");
        scanf(" %[^\n]", novo_nome);
        printf("# Especie: ");
        scanf(" %[^\n]", nova_especie);
        printf("# Idade: ");
        scanf("%d", &nova_idade);
        remove_animal(nome_arquivo, nome_animal);
        lista = carrega_animais_arquivo(nome_arquivo);
        lista = insere_animal_lista(lista, novo_nome, nova_especie, nova_idade);
        insere_animais_arquivo(nome_arquivo, lista);
        printf("* Dados atualizados com sucesso! *\n");
      } else {
        printf("* Animal nao encontrado! Tente novamente. *\n");
      }
      libera_lista_animais(lista);
    }
   
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

 ### Métodos para desenvolvimento do programa
 #### Os métodos principais utilizados para o desenvolvimento do programa que foram ensinados em sala foram:
  * Ponteiros;
  * Alocação Dinâmica;
  * Struct;
  * TAD;
  * Arquivos;
  * Lista Encadeada.

