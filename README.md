# ⚔️ War: Battle Simulator (Estrutura de Dados)
> **Nível Mestre:** Implementação de Alocação Dinâmica, Ponteiros e Simulação de Combate.

![C](https://img.shields.io/badge/Language-C-A8B9CC?style=for-the-badge&logo=c&logoColor=white)
![Git](https://img.shields.io/badge/Status-Finalizado-success?style=for-the-badge&logo=git&logoColor=white)

Este repositório contém a evolução de um sistema de gerenciamento de territórios inspirado no jogo *War*. O projeto percorre desde conceitos básicos de lógica até o gerenciamento avançado de memória em C.

---

### 📂 Estrutura do Projeto

O repositório está dividido em etapas de aprendizado:

1.  **`novato.c`**: Implementação inicial utilizando vetores estáticos e menus simples.
2.  **`aventureiro.c`**: Versão avançada com as seguintes funcionalidades:
    * **Alocação Dinâmica:** Uso de `calloc` para definir o tamanho do mapa em tempo de execução.
    * **Ponteiros:** Manipulação direta de endereços de memória para otimização.
    * **Sistema de Batalha:** Simulação de ataques com `rand()` e `srand()`.
    * **Gestão de Memória:** Implementação rigorosa de `free()` para evitar Memory Leaks.

---

### 🕹️ Funcionalidades do Nível Mestre

| Recurso | Descrição |
| :--- | :--- |
| **Ataque Estratégico** | Escolha entre territórios atacantes e defensores. |
| **Simulação de Dados** | Rolagem de dados (1-6) para decidir o vencedor da rodada. |
| **Dominação** | Conquista de territórios e transferência automática de tropas. |
| **Validação de Cor** | Impede ataques entre territórios do mesmo exército. |

---

### 🚀 Como Compilar e Rodar

Para testar a versão mais recente (Aventureiro/Mestre):

```bash
# 1. Compile o arquivo principal
gcc aventureiro.c -o war_mestre.exe

# 2. Execute o simulador
./war_mestre.exe