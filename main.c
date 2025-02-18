#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

void exibirMenu() {
    printf(ANSI_COLOR_CYAN "\n"
           "  _______   ____   _______   _______     _____     ______               \n"
           " |__   __| |  __| |__   __| |   _   |   |_   _|   |   ___|      \n"
           "    | |    | |__     | |    |  |_|  |     |  |    |  /    \n"
           "    | |    |  __|    | |    |   _  |      |  |    |_  |__      \n"
           "    | |    | |__     | |    |  | |_ |    _|  |_    __|   |    \n"
           "    |_|    |____|    |_|    |__|   |_|  |______|  |______|           \n" ANSI_COLOR_RESET);

    printf(ANSI_COLOR_YELLOW "\n=== MENU PRINCIPAL ===\n" ANSI_COLOR_RESET);
    printf(ANSI_COLOR_GREEN "1 - Cadastrar peça padrão\n" ANSI_COLOR_RESET);
    printf(ANSI_COLOR_GREEN "2 - Criar nova peça personalizada\n" ANSI_COLOR_RESET);
    printf(ANSI_COLOR_GREEN "3 - Listar peças\n" ANSI_COLOR_RESET);
    printf(ANSI_COLOR_GREEN "4 - Reorganizar peças\n" ANSI_COLOR_RESET);
    printf(ANSI_COLOR_RED "0 - Sair\n" ANSI_COLOR_RESET);
    printf(ANSI_COLOR_YELLOW "======================\n" ANSI_COLOR_RESET);
    printf("Opção: ");
}

int main() {
    int opcao;

    do {
        exibirMenu();
        opcao = lerInteiro("", 0, 4);

        switch (opcao) {
            case 1:
                cadastrarPecaPadrao();
                break;
            case 2:
                criarPecaPersonalizada();
                break;
            case 3:
                listarPecas();
                break;
            case 4:
                reorganizarPecas();
                break;
            case 0:
                printf(ANSI_COLOR_MAGENTA "Saindo...\n" ANSI_COLOR_RESET);
                break;
            default:
                printf(ANSI_COLOR_RED "Opção inválida!\n" ANSI_COLOR_RESET);
        }
    } while (opcao != 0);

    return 0;
}
