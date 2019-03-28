#ifndef PILHA_H
#define PILHA_H

#define MAX 1000 // Define o máximo de elementos na pilha
#define TIPO int  // Define o tipo dos elementos
#define ERRO -1	 	

typedef struct pilha PILHA; /*Definição do tipo PILHA*/

/*Funções básicas: criar e apagar*/
PILHA *pilha_criar();	
void pilha_apagar(PILHA *P);
TIPO pilha_topo(PILHA *P);

/*Funções de conferência:*/
int pilha_tamanho(PILHA *P);
int pilha_vazia(PILHA *P);
int pilha_cheia(PILHA *P);

/*Funções principais: push, pop, ...*/
void pilha_empilhar(PILHA *P, TIPO n);
TIPO pilha_desempilhar(PILHA *P);		
void pilha_inverter(PILHA *P);

#endif