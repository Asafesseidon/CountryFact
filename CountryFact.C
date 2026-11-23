#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define maxPaises 20
#define maxPaisWordLimit 30
#define maxFatos 100
#define maxFatosTexto 100

// Definindo os vetores de paises e fatos de cada pais

char paises[maxPaises][maxPaisWordLimit] = {"Brazil", "China", "Japan", "United States of America", "Greece", "Mexico", "Nigeria", "Australia"};

int tamanhoPaises = 8;

char fatos[maxPaises][maxFatos][maxFatosTexto] = {
  {"Colonizacao e forte imigracao fizeram a diversidade ser um ponto forte no pais", "Ma administracao no ultimo seculo fez o pais tomar uma posicao subalterna as grandes potencias"},
  {"e o pais mais antigo da historia ainda em funcionamento"},
  {"cometeu crimes de guerra foi o unico pais que sofreu um ataque nuclear"},
  {"e atualmente a maior economia do mundo"},
  {"o nascimento da democracia e o berco da filosofia e matematica"},
  {"e o berco de varios imperios pre hispanicos"},
  {"e a maior populacao negra do mundo"},
  {"e a maior ilha do mundo e uma das maiores biodversidades"}
};

int fatosTotais = 8;

// Functions

void getFatos(int pais) {
  printf("\n Fatos do %s\n", paises[pais]);

  for (int i = 0; i < fatosTotais; i++) {
    printf("%d - %s\n", i, fatos[pais][i]);
  }

}

void createFatos(int pais) {
  if (fatosTotais < maxFatos) {

    char novoFato[maxFatosTexto];
    printf("Digite um fato para %s: \n", paises[pais]);

    getchar(); // limpar o buffer do teclado

    fgets(novoFato, maxFatosTexto, stdin); // tipo scanf

    novoFato[strcspn(novoFato, "\n")] = 0; // Remove newline character

    for (int i = 0; i < maxFatos; i++) {
      if (strcmp(fatos[pais][i], "") == 0) {
        strcpy(fatos[pais][i], novoFato);
        break;
      }
    }
    fatosTotais++;

    printf("\nFato adicionado com sucesso!\n");
  }

  else {
    printf("\nLimite de fatos atingido!\n");
  }

}

void updateFatos(int pais) {

  getFatos(pais);

  int updateEscolha = -1;

  printf("\n Escolha um fato para alterar: \n");

  scanf("%d", &updateEscolha);

  getchar(); // Clear buffer

  char novoFato[maxFatosTexto];
  printf("\n Escreva o novo fato: \n");

  fgets(novoFato, maxFatosTexto, stdin);

  novoFato[strcspn(novoFato, "\n")] = 0;

  for (int i = 0; i < maxFatos; i++) {
      if (updateEscolha >= 0 && updateEscolha == i) {
        strcpy(fatos[pais][i], novoFato);

          printf("\nFato atualizado com sucesso!\n");
          break;
      }
  }
}


void deleteFatos(int pais) {
  getFatos(pais);
  int deleteEscolha = -1;

  printf("\n Escolha um fato para deletar: \n");
  scanf("%d", &deleteEscolha);

  for (int i = 0; i < maxFatos; i++) {
      if (deleteEscolha >= 0 && deleteEscolha == i) {
        strcpy(fatos[pais][i], "");

        printf("\nFato deletado com sucesso!\n");
        fatosTotais--;
        break;
      }
  }

}

void gerenciarPais(int pais) {
  int operacao = -1;
  while (1) {
    operacao = crudText(paises[pais]);

    if (operacao == 1) {
      getFatos(pais);
    }

    else if (operacao == 2) {
      createFatos(pais);
    }

    else if (operacao == 3) {
      updateFatos(pais);
    }

    else if (operacao == 4) {
      deleteFatos(pais);
    }

    else if (operacao == 5) {
      break;
    }
  }
}

int crudText(const char* pais){
  int operacao = -1;

  printf("\n Escolha uma das operacoes que deseja realizar nos fatos do %s \n", pais);
  printf("\n 1 - Ler\n");
  printf("\n 2 - Criar\n");
  printf("\n 3 - Atualizar\n");
  printf("\n 4 - Deletar\n");
  printf("\n 5 - Sair\n");

  scanf("%d", &operacao);

  return operacao;
}


int main() {
    int loopCondition = 1, escolha = -1;

    while (loopCondition) {
        printf("\n Escolha um dos paises!\n");
        for (int i = 0; i < tamanhoPaises; i++) {
            printf("%d - %s\n", i, paises[i]);
        }
        printf("%d - Sair\n", tamanhoPaises);

        scanf("%d", &escolha);

        if (escolha == tamanhoPaises) {
            break;
        }

        else if (escolha >= 0 && escolha <= tamanhoPaises) {
            printf("\n =!= %s =!=\n", paises[escolha]);
            gerenciarPais(escolha);
        } else {
            printf("Opcao invalida.\n");
        }
    }

    printf("CountryFact finalizado!\n");
    return 0;
}
