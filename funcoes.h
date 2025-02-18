
#ifndef FUNCOES_H
#define FUNCOES_H

typedef struct {
    char nome[20];  // Nome da peça
    char cor[20];   //COR
    int borda;      //Borda
} Peca;

// Declarações das funções
void cadastrarPecaPadrao();
void criarPecaPersonalizada();
void listarPecas();
void reorganizarPecas();

// Declaração da função lerInteiro
int lerInteiro(const char *mensagem, int min, int max);

#endif