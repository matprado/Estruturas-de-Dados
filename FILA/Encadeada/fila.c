#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

struct fila{
	NO* cabeca;
	NO* fim;
	int tamanho;
};

struct no_{
	TIPO item;
	NO *proximo;
};

FILA *fila_criar(void){
	FILA *new = (FILA *)malloc(sizeof(FILA));
	if(new != NULL){		
		new->cabeca = (NO *) malloc(sizeof(NO));
		new->cabeca->proximo = NULL;
		new->fim = NULL;
		new->tamanho = 0;
	}
	return new;
}

void fila_apagar(FILA *F){
	NO *aux, *apaga;
	if(F != NULL){
		aux = F->cabeca;
		do{
			apaga = aux;
			aux = aux->proximo;
			free(apaga);
		}while(aux != NULL);
		free(F);
	}
}

void fila_inserir(FILA *F, TIPO item){
	NO *novo;
	if(F != NULL){
	 	novo = (NO *)malloc(sizeof(NO));
	 	if(novo != NULL){
	 		novo->item = item;
	 		novo->proximo = NULL;
	 		if(fila_vazia(F)){
	 			F->cabeca->proximo = novo;
	 			F->fim = novo;
	 		}else{
	 			F->fim->proximo = novo;
	 			F->fim = novo; 	
			}
			F->tamanho++;	
		}
	}	
}

TIPO fila_retirar(FILA *F){
	/*RETIRAR O PRIMEIRO E MOVER TODOS OS PŔOXIMOS UMA POSIÇÃO PARA TRÁS*/
	TIPO item = ERRO;
	NO *aux;
	if(F != NULL && !fila_vazia(F)){
		item = F->cabeca->proximo->item;
		aux = F->cabeca->proximo;
		F->cabeca->proximo = F->cabeca->proximo->proximo;
		free(aux);
		F->tamanho--;	
	}
	return item;
}

int fila_vazia(FILA *F){
	return(F->tamanho == 0);
}