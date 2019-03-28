#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

struct lista{
	TIPO vet[MAX];
	int ini;
	int fim;
};

LISTA *lista_criar(void){
	LISTA *new = (LISTA *)malloc(sizeof(LISTA));
	if(new != NULL){		
    for(int i=0; i<MAX; i++){
			new->vet[i] = VAZIO;
		}
		new->ini = 0;
		new->fim = 0;
	}
	return new;
}

void lista_apagar(LISTA *L){
	if(L != NULL){
		free(L);
		L = NULL;
	}
}

void lista_inserir(LISTA *L, int pos, TIPO item){
	int i = L->fim;
	if(L != NULL && !lista_cheia(L) && pos <= (L->fim-L->ini)){
	 	// Desloca
	 	while(i > pos){
			L->vet[i] = L->vet[i-1];
			i--;
		}
		// Insere
	 	L->vet[pos] = item;
	 	L->fim++;
	}	
}

void lista_inserir_no_fim(LISTA *L, TIPO item){
	if(L != NULL && !lista_cheia(L)){
		L->vet[L->fim] = item;
		L->fim++;
	}
}

void insertion_sort(TIPO *vet, int n){
	int i=1, j, chave;
	while(i < n){
		j=i-1;
		chave = vet[i];
		while(j >= 0 && chave < vet[j]){
			vet[j+1] = vet[j];
			j--;
		}	
		vet[j+1] = chave;
		i++;
	}
}

void lista_ordenar(LISTA *L){
	insertion_sort(L->vet, L->fim - L->ini);
}

int busca_binaria_original(TIPO *vet, TIPO chave, int comeco, int fim){
	int centro = (comeco+fim)/2;
	if(comeco > fim) return ERRO; 
	if(vet[centro] == chave) return centro;
	else{
		if(chave < vet[centro])
			busca_binaria_original(vet, chave, comeco, centro-1);
		else
			busca_binaria_original(vet, chave, centro+1, fim);
	}
}

int lista_buscar(LISTA *L, int chave){
	return busca_binaria_original(L->vet, chave, L->ini, L->fim);
}

TIPO lista_retirar(LISTA *L, int pos){
	/*RETIRAR O ITEM DA POSIÇÃO DETERMINADA E MOVER TODOS OS PŔOXIMOS UMA POSIÇÃO PARA TRÁS*/
	TIPO ret = ERRO;
	int i = pos;
	if(L != NULL && !lista_vazia(L) && pos < (L->fim-L->ini)){
		ret = L->vet[pos];
		while(i < L->fim){
			L->vet[i] = L->vet[i+1];
			i++;
		}
		L->vet[L->fim] = 0;
		L->fim--;
	}
	return ret;
}

TIPO lista_acessar(LISTA *L, int pos){
	if(L != NULL && !lista_vazia(L) && pos < (L->fim-L->ini))
		return L->vet[pos];
	else
		return ERRO;
}

int lista_vazia(LISTA *L){
	return (L != NULL ? (L->fim-L->ini) == 0 : ERRO);
}

int lista_cheia(LISTA *L){
	return (L != NULL ? (L->fim-L->ini) == MAX : ERRO);
}

int lista_inicio(LISTA *L){
	return (L != NULL ? L->ini : ERRO);
}

int lista_fim(LISTA *L){
	return (L != NULL ? L->fim : ERRO);
}

int lista_tamanho(LISTA *L){
	return (L != NULL ? (L->fim - L->ini) : ERRO);	
}