#ifndef FILA_H
#define FILA_H

#define ERRO -404
#define TIPO int   //Customização do tipo de dados

typedef struct fila FILA;
typedef struct no_ NO;

/*Funções básicas:*/
FILA *fila_criar(void);
void fila_apagar(FILA *F);

/*Inserção e remoção:*/
void fila_inserir(FILA *F, TIPO item);
TIPO fila_retirar(FILA *F);

/*Funções de consulta:*/
int fila_vazia(FILA *F);

#endif