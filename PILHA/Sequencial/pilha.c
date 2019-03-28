#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

struct pilha{
	TIPO vet[MAX];
	int quantidade;
};

PILHA *pilha_criar(){
	PILHA *P = (PILHA *) malloc(sizeof(PILHA));
	if(P != NULL){
		P->quantidade = 0;
	}
	return P;
}
	
void pilha_apagar(PILHA *P){
	free(P);
}

TIPO pilha_topo(PILHA *P){
	/*TIPO t = P->vet[quantidade-1];*/
	return (P != NULL ? P->vet[P->quantidade-1] : ERRO);
}

int pilha_tamanho(PILHA *P){
	return (P != NULL ? P->quantidade : ERRO);
}

int pilha_vazia(PILHA *P){
	return (P != NULL ? P->quantidade == 0 : ERRO);
}

int pilha_cheia(PILHA *P){
	return (P != NULL ? P->quantidade == MAX : ERRO);
}

void pilha_empilhar(PILHA *P, TIPO n){
	if(P != NULL){
		P->vet[P->quantidade] = n;
		(P->quantidade)++;
	}	
}

TIPO pilha_desempilhar(PILHA *P){
	TIPO n;
	if(P != NULL){
		n = P->vet[P->quantidade-1];
		P->vet[P->quantidade-1] = 0;
		P->quantidade--;
	}
	return n;
}	

void pilha_inverter(PILHA *P){
	TIPO aux;
	for(int i=0; i<((P->quantidade-1)/2)+1; i++){
		aux = P->vet[i];
		P->vet[i] = P->vet[P->quantidade-1-i];
		P->vet[P->quantidade-1-i] = aux;
	}
}