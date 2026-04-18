#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    char nome[30];
    char cor[20];
    int tropas;
} Territorio;

// Protótipos
void atribuirMissao(char** destino, const char* missoes[], int total);
void cadastrarTerritorios(Territorio* mapa, int qtd);
void exibirMapa(const Territorio* mapa, int qtd);
void atacar(Territorio* atacante, Territorio* defensor);
int verificarMissao(const char* missao, const Territorio* mapa, int qtd, const char* corJogador);
void liberarMemoria(Territorio* mapa, char* missao);

int main() {
    srand(time(NULL));

    int qtd, opcao;
    char* missaoJogador = NULL;
    const char* listaMissoes[] = {
        "Dominar 3 territorios",
        "Ter mais de 10 tropas somadas",
        "Conquistar 2 territorios",
        "Ter exercito com mais de 5 tropas"
    };

    printf("\n--- WAR: NIVEL MESTRE ESTRATEGICO ---\n");
    printf("Quantos territorios no mapa? ");
    scanf("%d", &qtd);

    Territorio* mapa = (Territorio*) calloc(qtd, sizeof(Territorio));
    missaoJogador = (char*) malloc(100 * sizeof(char));

    if (!mapa || !missaoJogador) return 1;

    cadastrarTerritorios(mapa, qtd);

    // Sorteia e MOSTRA a missão imediatamente
    atribuirMissao(&missaoJogador, listaMissoes, 4);
    
    printf("\n****************************************\n");
    printf("   SUA MISSAO SECRETA: %s\n", missaoJogador);
    printf("****************************************\n");
    printf("Pressione ENTER para comecar o jogo...");
    getchar(); getchar(); // Pausa para voce ler a missao

    char minhaCor[20];
    strcpy(minhaCor, mapa[0].cor); 

    do {
        printf("\n--- MENU ---\n1-Atacar\n2-Ver Mapa\n3-Verificar Missao\n0-Sair\nEscolha: ");
        scanf("%d", &opcao);

        if (opcao == 1) {
            int atq, def;
            exibirMapa(mapa, qtd);
            printf("\nID Atacante: "); scanf("%d", &atq);
            printf("ID Defensor: "); scanf("%d", &def);
            
            if (atq >= 0 && atq < qtd && def >= 0 && def < qtd) {
                if (strcmp(mapa[atq].cor, mapa[def].cor) != 0) {
                    atacar(&mapa[atq], &mapa[def]);
                    printf("\nPressione ENTER para continuar...");
                    getchar(); getchar(); // Pausa para ver o resultado do ataque
                } else {
                    printf("\n[Erro] Voce nao pode atacar sua propria cor!\n");
                }
            }
        } else if (opcao == 2) {
            exibirMapa(mapa, qtd);
        } else if (opcao == 3) {
            if (verificarMissao(missaoJogador, mapa, qtd, minhaCor)) {
                printf("\n========================================");
                printf("\n🎉 PARABENS! VOCE GANHOU O JOGO!");
                printf("\nMissao: %s", missaoJogador);
                printf("\n========================================\n");
                opcao = 0;
            } else {
                printf("\n[Ainda nao...] Continue jogando para cumprir: %s\n", missaoJogador);
            }
        }
    } while (opcao != 0);

    liberarMemoria(mapa, missaoJogador);
    return 0;
}

void atribuirMissao(char** destino, const char* missoes[], int total) {
    int indice = rand() % total;
    strcpy(*destino, missoes[indice]);
}

void cadastrarTerritorios(Territorio* mapa, int qtd) {
    for (int i = 0; i < qtd; i++) {
        printf("\nTerritorio [%d]\nNome: ", i);
        scanf(" %[^\n]s", mapa[i].nome);
        printf("Sua Cor: ");
        scanf("%s", mapa[i].cor);
        printf("Tropas: ");
        scanf("%d", &mapa[i].tropas);
    }
}

void exibirMapa(const Territorio* mapa, int qtd) {
    printf("\nID | NOME            | COR        | TROPAS");
    printf("\n-------------------------------------------");
    for (int i = 0; i < qtd; i++) {
        printf("\n%d  | %-15s | %-10s | %d", i, mapa[i].nome, mapa[i].cor, mapa[i].tropas);
    }
    printf("\n");
}

void atacar(Territorio* atacante, Territorio* defensor) {
    int dAtq = (rand() % 6) + 1;
    int dDef = (rand() % 6) + 1;
    
    printf("\n--- RESULTADO DA BATALHA ---");
    printf("\n%s jogou: %d", atacante->nome, dAtq);
    printf("\n%s jogou: %d", defensor->nome, dDef);

    if (dAtq >= dDef) {
        printf("\n>>> VITORIA DO ATACANTE!");
        defensor->tropas--;
        if (defensor->tropas <= 0) {
            printf("\n🚩 O territorio %s foi CONQUISTADO!", defensor->nome);
            strcpy(defensor->cor, atacante->cor);
            defensor->tropas = atacante->tropas / 2;
            atacante->tropas -= defensor->tropas;
        }
    } else {
        printf("\n>>> O DEFENSOR RESISTIU!");
        atacante->tropas--;
    }
    printf("\n----------------------------");
}

int verificarMissao(const char* missao, const Territorio* mapa, int qtd, const char* corJogador) {
    int territoriosProprios = 0;
    int tropasTotais = 0;

    for (int i = 0; i < qtd; i++) {
        if (strcmp(mapa[i].cor, corJogador) == 0) {
            territoriosProprios++;
            tropasTotais += mapa[i].tropas;
        }
    }

    if (strcmp(missao, "Dominar 3 territorios") == 0 && territoriosProprios >= 3) return 1;
    if (strcmp(missao, "Conquistar 2 territorios") == 0 && territoriosProprios >= 2) return 1;
    if (strcmp(missao, "Ter mais de 10 tropas somadas") == 0 && tropasTotais > 10) return 1;
    if (strcmp(missao, "Ter exercito com mais de 5 tropas") == 0 && tropasTotais > 5) return 1;

    return 0;
}

void liberarMemoria(Territorio* mapa, char* missao) {
    free(mapa);
    free(missao);
}