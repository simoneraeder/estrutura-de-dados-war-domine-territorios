# 🗺️ War: Domine Territórios
> **Status:** Finalizado / Em Desenvolvimento 🚀

![C](https://img.shields.io/badge/Language-C-A8B9CC?style=for-the-badge&logo=c&logoColor=white)
![Git](https://img.shields.io/badge/Version_Control-Git-F05032?style=for-the-badge&logo=git&logoColor=white)
![VSCode](https://img.shields.io/badge/Editor-VSCode-007ACC?style=for-the-badge&logo=visual-studio-code&logoColor=white)

### 📝 Sobre o Projeto
Este é um sistema de gerenciamento de dados desenvolvido para a disciplina de **Estrutura de Dados**. O objetivo é simular o controle de ocupação de um mapa do jogo *War*, utilizando estruturas de dados em C para organizar exércitos, frentes de batalha e distribuição de tropas.

---

### 🕹️ Interface do Sistema
O sistema opera via Terminal com um menu interativo moderno e tratamento de buffer para entradas de texto:

| Opção | Ação | Descrição |
| :--- | :--- | :--- |
| `1` | **Cadastrar** | Adiciona novos territórios com suporte a nomes compostos. |
| `2` | **Listar** | Exibe uma tabela organizada com o status atual do mapa. |
| `0` | **Sair** | Encerra a execução do programa com segurança. |

---

### 🛠️ Diferenciais Técnicos
- **Structs Avançadas:** Organização de dados heterogêneos para representar territórios.
- **Buffer Cleansing:** Implementação de ` %[^\n]s` para evitar erros de leitura com espaços.
- **Modularidade:** Código estruturado para facilitar futuras expansões (como listas encadeadas).

---

### 🚀 Como Rodar
```bash
# Clone o repositório
git clone [https://github.com/simoneraeder/estrutura-de-dados-war-domine-territorios.git](https://github.com/simoneraeder/estrutura-de-dados-war-domine-territorios.git)

# Entre na pasta
cd estrutura-de-dados-war-domine-territorios

# Compile
gcc territorios.c -o war_game.exe

# Execute
./war_game.exe