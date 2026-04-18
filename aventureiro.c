#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Estrutura do Território
typedef struct {
    char nome[30];
    char cor[20];
    int tropas;
} Territorio;

// Protótipos das funções (Modularização)
void cadastrarTerritorios(Territorio* mapa, int quantidade);
void exibirMapa(Territorio* mapa, int quantidade);
void atacar(Territorio* atacante, Territorio* defensor);
void liberarMemoria(Territorio* mapa);

int main() {
    int qtd, opcao;
    Territorio* mapa = NULL;

    // Semente para números aleatórios (Dados de batalha)
    srand(time(NULL));

    printf("--- WAR: NIVEL MESTRE ---\n");
    printf("Quantos territorios deseja cadastrar no mapa? ");
    scanf("%d", &qtd);

    // ALOCAÇÃO DINÂMICA: Criando o vetor com o tamanho exato informado
    mapa = (Territorio*) calloc(qtd, sizeof(Territorio));

    if (mapa == NULL) {
        printf("Erro ao alocar memoria!\n");
        return 1;
    }

    cadastrarTerritorios(mapa, qtd);

    do {
        printf("\n========= MENU DE GUERRA =========\n");
        printf("1. Atacar Territorio\n");
        printf("2. Mostrar Mapa Atualizado\n");
        printf("0. Sair e Finalizar Guerra\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        if (opcao == 1) {
            int atq, def;
            exibirMapa(mapa, qtd);
            
            printf("\nID do Atacante (0 a %d): ", qtd - 1);
            scanf("%d", &atq);
            printf("ID do Defensor (0 a %d): ", qtd - 1);
            scanf("%d", &def);

            // Validações de segurança
            if (atq >= 0 && atq < qtd && def >= 0 && def < qtd) {
                if (strcmp(mapa[atq].cor, mapa[def].cor) == 0) {
                    printf("\n[AVISO] Voce nao pode atacar seu proprio exercito!\n");
                } else if (mapa[atq].tropas < 2) {
                    printf("\n[AVISO] Tropas insuficientes para atacar (minimo 2).\n");
                } else {
                    // Chamada da função usando ponteiros
                    atacar(&mapa[atq], &mapa[def]);
                }
            } else {
                printf("\nID invalido!\n");
            }
        } else if (opcao == 2) {
            exibirMapa(mapa, qtd);
        }

    } while (opcao != 0);

    liberarMemoria(mapa);
    printf("\nMemoria liberada. Ate a proxima batalha!\n");

    return 0;
}

// --- IMPLEMENTAÇÃO DAS FUNÇÕES ---

void cadastrarTerritorios(Territorio* mapa, int quantidade) {
    for (int i = 0; i < quantidade; i++) {
        printf("\nTerritorio ID %d:\n", i);
        printf("Nome: ");
        scanf(" %[^\n]s", mapa[i].nome); // %[^\n] para ler espaços
        printf("Cor do exercito: ");
        scanf("%s", mapa[i].cor);
        printf("Quantidade de tropas: ");
        scanf("%d", &mapa[i].tropas);
    }
}

void exibirMapa(Territorio* mapa, int quantidade) {
    printf("\n%s | %-15s | %-10s | %s\n", "ID", "TERRITORIO", "COR", "TROPAS");
    printf("--------------------------------------------------\n");
    for (int i = 0; i < quantidade; i++) {
        printf("%d  | %-15s | %-10s | %d\n", i, mapa[i].nome, mapa[i].cor, mapa[i].tropas);
    }
}

void atacar(Territorio* atacante, Territorio* defensor) {
    printf("\n⚔️ BATALHA: %s (%s) VS %s (%s)\n", atacante->nome, atacante->cor, defensor->nome, defensor->cor);

    // Simulação de dados (1 a 6)
    int dadoAtacante = (rand() % 6) + 1;
    int dadoDefensor = (rand() % 6) + 1;

    printf("Dado Atacante: [%d] | Dado Defensor: [%d]\n", dadoAtacante, dadoDefensor);

    // Lógica: Empate ou Atacante maior vence (conforme solicitado no nível aventureiro)
    if (dadoAtacante >= dadoDefensor) {
        printf("🔥 O ATACANTE VENCEU A RODADA!\n");
        defensor->tropas--;

        // Se o defensor perder todas as tropas, o atacante domina
        if (defensor->tropas <= 0) {
            printf("🚩 CONQUISTA! %s agora pertence ao exercito %s!\n", defensor->nome, atacante->cor);
            strcpy(defensor->cor, atacante->cor);
            
            // Transfere metade das tropas (mínimo 1 sobra no atacante)
            int transferencia = atacante->tropas / 2;
            defensor->tropas = transferencia;
            atacante->tropas -= transferencia;
        }
    } else {
        printf("🛡️ O DEFENSOR RESISTIU!\n");
        atacante->tropas--;
    }
}

void liberarMemoria(Territorio* mapa) {
    if (mapa != NULL) {
        free(mapa);
    }
}