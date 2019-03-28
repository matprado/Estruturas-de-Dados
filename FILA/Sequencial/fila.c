#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

struct fila{
	TIPO vet[MAX];
	int ini;
	int fim;
	int tamanho;
};

FILA *fila_criar(void){
	FILA *new = (FILA *)malloc(sizeof(FILA));
	if(new != NULL){		
		new->ini = 0;
		new->fim = 0;
		new->tamanho = 0;
	}
	return new;
}

void fila_apagar(FILA *F){
	if(F != NULL){
		free(F);
		F = NULL;
	}
}

void fila_inserir(FILA *F, TIPO item){
	if(F != NULL && !fila_cheia(F)){
	 	F->vet[F->fim] = item;
	 	F->fim = (F->fim+1) % MAX; 	
	 	F->tamanho++;
	}	
}

TIPO fila_retirar(FILA *F){
	/*RETIRAR O PRIMEIRO E MOVER TODOS OS PŔOXIMOS UMA POSIÇÃO PARA TRÁS*/
	TIPO ret = ERRO;
	int i = 0;
	if(F != NULL && !fila_vazia(F)){
		ret = F->vet[F->ini];
		F->ini = (F->ini + 1) % MAX;
		F->tamanho--;
	}
	return ret;
}

int fila_vazia(FILA *F){
	return(F->tamanho == 0);
}

int fila_cheia(FILA *F){
	return(F->tamanho == MAX);
}

