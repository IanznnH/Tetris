#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "funcoes.h"

#define MAX_PECAS 100

Peca pecas[MAX_PECAS];
int totalPecas = 0;

//Colocando cor
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

// Nomes das peças 
const char *nomesPadrao[7] = {
    "Peça Ricky", "Peça Villain", "Peça Cheveland", "Peça Rhode", "Peça Hero", "Peça Teewee", "Peça Smashboy"
};

int lerInteiro(const char *mensagem, int min, int max) {
    int valor;
    while (1) {
        printf("%s", mensagem);
        if (scanf("%d", &valor) == 1 && valor >= min && valor <= max) {
            break;
        } else {
            printf(ANSI_COLOR_RED "Por Favor digite um número entre %d e %d.\n" ANSI_COLOR_RESET, min, max);
            while (getchar() != '\n'); // Limpa o buffer 
        }
    }
    return valor;
}

void lerString(const char *mensagem, char *buffer, int tamanho) {
    while (1) {
        printf("%s", mensagem);
        if (scanf(" %s[^\n]", buffer) == 1) {
            break;
        } else {
            printf(ANSI_COLOR_RED "Entrada inválida!\n" ANSI_COLOR_RESET);
            while (getchar() != '\n'); // Limpa o buffer
        }
    }
}

void cadastrarPecaPadrao() {
    if (totalPecas >= MAX_PECAS) {
        printf(ANSI_COLOR_RED "Limite de peças foi atingido!\n" ANSI_COLOR_RESET);
        return;
    }

    printf(ANSI_COLOR_YELLOW "\n=== CADASTRAR PEÇA PADRÃO ===\n" ANSI_COLOR_RESET);
    for (int i = 0; i < 7; i++) {
        printf("%d - %s\n", i + 1, nomesPadrao[i]);
    }

    int escolha = lerInteiro("Escolha uma peça (1-7): ", 1, 7);
    strcpy(pecas[totalPecas].nome, nomesPadrao[escolha - 1]);

    printf("Qual a cor da peça: (Exemplo: Amarelo, Azul, Roxo, Lilás, Vermelho...): ");
    lerString("", pecas[totalPecas].cor, 20);

    pecas[totalPecas].borda = lerInteiro("A peça possui borda? (1 para Sim, 0 para Não): ", 0, 1);

    totalPecas++;
    printf(ANSI_COLOR_GREEN "Peça padrão cadastrada com sucesso!\n" ANSI_COLOR_RESET);
}

void criarPecaPersonalizada() {
    if (totalPecas >= MAX_PECAS) {
        printf(ANSI_COLOR_RED "Limite de peças atingido!\n" ANSI_COLOR_RESET);
        return;
    }

    Peca novaPeca;

    printf(ANSI_COLOR_YELLOW "\n=== CRIAR PEÇA PERSONALIZADA ===\n" ANSI_COLOR_RESET);
    lerString("Qual é o nome da peça? : ", novaPeca.nome, 20);

    printf("Digite a cor da peça: ");
    lerString("", novaPeca.cor, 20);

    novaPeca.borda = lerInteiro("A peça possui alguma borda? (1 para Sim, 0 para Não): ", 0, 1);

    pecas[totalPecas++] = novaPeca;
    printf(ANSI_COLOR_GREEN "Peça personalizada criada com sucesso!\n" ANSI_COLOR_RESET);
}

void listarPecas() {
    if (totalPecas == 0) {
        printf(ANSI_COLOR_RED "Nenhuma peça foi cadastrada.\n" ANSI_COLOR_RESET);
        return;
    }

    printf(ANSI_COLOR_CYAN "\n=== LISTA DE PEÇAS ===\n" ANSI_COLOR_RESET);

    printf("+----+----------------------+----------------------+--------+\n");
    printf("| #  | Nome                  | Cor                  | Borda  |\n");
    printf("+----+----------------------+----------------------+--------+\n");

    // Dados das peças
    for (int i = 0; i < totalPecas; i++) {
        printf("| %-2d | %-20s | %-20s | %-6s |\n",//Espaçamento
               i + 1, pecas[i].nome, pecas[i].cor, pecas[i].borda ? "Sim" : "Não");
    }

    printf("+----+----------------------+----------------------+--------+\n");
    printf(ANSI_COLOR_CYAN "======================\n" ANSI_COLOR_RESET);
}

void reorganizarPecas() {
    if (totalPecas == 0) {
        printf(ANSI_COLOR_RED "Nenhuma peça foi cadastrada.\n" ANSI_COLOR_RESET);
        return;
    }

    // Usei algoritmo Bubble Sort
    for (int i = 0; i < totalPecas - 1; i++) {
        for (int j = 0; j < totalPecas - i - 1; j++) {
            if (strcmp(pecas[j].nome, pecas[j + 1].nome) > 0) {
                Peca temp = pecas[j];
                pecas[j] = pecas[j + 1];
                pecas[j + 1] = temp;
            }
        }
    }

    printf(ANSI_COLOR_GREEN "As peças foram reorganizadas por nome!\n" ANSI_COLOR_RESET);
}