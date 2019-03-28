#ifndef FILA_H
#define FILA_H

#define ERRO -404
#define TIPO int //Customização do tipo de dados
#define MAX 100		// Tamanho máximo da fila

typedef struct fila FILA;

/*Funções básicas:*/
FILA *fila_criar(void);
void fila_apagar(FILA *F);

/*Inserção e remoção:*/
void fila_inserir(FILA *F, TIPO item);
TIPO fila_retirar(FILA *F);

/*Funções de consulta:*/
int fila_vazia(FILA *F);
int fila_cheia(FILA *F);

#endif