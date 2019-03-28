#ifndef PILHA_H
#define PILHA_H

#define TIPO int   // Define o tipo dos elementos
#define ERRO -1

typedef struct pilha PILHA;   /*Definição do tipo PILHA*/

/*Funções básicas: criar e apagar*/
PILHA *pilha_criar();	
void pilha_apagar(PILHA *P);

/*Funções de conferência:*/
int pilha_vazia(PILHA *P);
TIPO pilha_topo(PILHA *P);
int pilha_tamanho(PILHA *P);

/*Funções principais: push, pop, ...*/
void pilha_empilhar(PILHA *P, TIPO n);
TIPO pilha_desempilhar(PILHA *P);		
int pilha_maior(PILHA *P1, PILHA *P2);

#endif