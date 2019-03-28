#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

typedef struct no NO;

struct no{
	NO *anterior;
	TIPO valor;
};

struct pilha{
	NO *topo;
	int quantidade;
};

PILHA *pilha_criar(){
	PILHA *P = (PILHA *) malloc(sizeof(PILHA));
	if(P != NULL){
		P->topo = NULL;
		P->quantidade = 0;
	}else P = NULL;
	return P;
}
	
void pilha_apagar(PILHA *P){
	NO *aux;
	if(P != NULL && !pilha_vazia(P)){
		while(P->topo != NULL){
			aux = P->topo;
			P->topo = P->topo->anterior;
			aux->anterior = NULL;
			free(aux);
		}
	}
	free(P);
	P = NULL;
}

int pilha_vazia(PILHA *P){
	return ((P != NULL) ? P->quantidade == 0 : ERRO);
}

TIPO pilha_topo(PILHA *P){
	return ((P != NULL && !pilha_vazia(P)) ? P->topo->valor : ERRO);
}

int pilha_tamanho(PILHA *P){
	return ((P != NULL) ? P->quantidade : ERRO);
}

void pilha_empilhar(PILHA *P, TIPO n){
	NO *novo = (NO *) malloc(sizeof(NO));
	if(novo != NULL && P != NULL){
		novo->valor = n;
		novo->anterior = P->topo;
		P->topo = novo;
		P->quantidade++;
	}
}

TIPO pilha_desempilhar(PILHA *P){
	TIPO retorno;
	NO *aux;
	if(!pilha_vazia(P)){
		retorno = P->topo->valor;
		aux = P->topo;
		P->topo = P->topo->anterior;
		aux->anterior = NULL;
		free(aux);
		aux = NULL;
		P->quantidade--;
	}else retorno = ERRO;
	return retorno;
}	

int pilha_maior(PILHA *P1, PILHA *P2){
	return ((P1 != NULL && P2 != NULL) ? (P1->quantidade > P2->quantidade) : 0);
}