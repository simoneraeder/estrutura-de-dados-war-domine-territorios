#include <stdio.h>
#include <string.h>
#include <stdlib.h> // Para usar o system("cls") ou "clear"

struct Territorio {
    char nome[30];
    char cor[10];
    int tropas;
};

int main() {
    struct Territorio lista[5];
    int contador = 0; // Controla quantos foram cadastrados
    int opcao;

    do {
        // Exibição do Menu
        printf("\n--- SISTEMA DE TERRITORIOS ---\n");
        printf("1. Adicionar Territorio\n");
        printf("2. Mostrar Lista\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                if (contador < 5) {
                    printf("\nCadastro do Territorio %d:\n", contador + 1);
                    
                    printf("Nome: ");
                    scanf(" %[^\n]s", lista[contador].nome);

                    printf("Cor do Exercito: ");
                    scanf("%s", lista[contador].cor);

                    printf("Quantidade de Tropas: ");
                    scanf("%d", &lista[contador].tropas);

                    contador++;
                    printf("\nTerritorio cadastrado com sucesso!\n");
                } else {
                    printf("\nLimite maximo de 5 territorios atingido!\n");
                }
                break;

            case 2:
                if (contador == 0) {
                    printf("\nNenhum territorio cadastrado ainda.\n");
                } else {
                    printf("\n--- LISTA DE TERRITORIOS ---\n");
                    printf("%-20s | %-10s | %-s\n", "TERRITORIO", "COR", "TROPAS");
                    printf("--------------------------------------------------\n");
                    for (int i = 0; i < contador; i++) {
                        printf("%-20s | %-10s | %d\n", lista[i].nome, lista[i].cor, lista[i].tropas);
                    }
                }
                break;

            case 0:
                printf("Saindo do sistema...\n");
                break;

            default:
                printf("Opcao invalida! Tente novamente.\n");
        }

    } while (opcao != 0);

    return 0;
}