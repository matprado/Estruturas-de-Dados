#include “ab.h”
#include <stdlib.h>

struct No{
	ITEM *item;
	NO *filhoesq;
	NO *filhodir;
};

struct arv{
	NO *raiz;
	int prof;
};

ARV *arv_criar(void){
	ARV *T = (ARV *) malloc(sizeof(ARV));
	if(T != NULL){
		T->raiz = NULL;
		T->prof = -1;
	}
	return (T);
}

NO *arv_criar_raiz(ARV *T, ITEM *i){
	if(T != NULL){
		T->raiz = (NO *) malloc(sizeof(NO));
		if(T->raiz != NULL){
			T->raiz->item = i;
			T->raiz->esq = NULL;
			T->raiz->dir = NULL;
		}
	}
	return (T->raiz);
}

void arv_inserir_filho(int filho, NO *no, ITEM *item){
	NO *pnovo = (NO *) malloc(sizeof (NO));
	if(pnovo != NULL){
		pnovo->filhodir = NULL;
		pnovo->filhoesq = NULL;
		pnovo->item = item;
		if(filho == 0){
			no->filhoesq = pnovo;
		}else{
			no->filhodir = pnovo;
		}
	}
}

void pre_ordem(NO *raiz){
	if(raiz != NULL){
		item_imprimir(raiz->item);
		pre_ordem(raiz->filhoesq);
		pre_ordem(raiz->filhodir);
	}
}

void em_ordem(NO *raiz){
	if(raiz != NULL){
		em_ordem(raiz->filhoesq);
		item_imprimir(raiz->item);	
		em_ordem(raiz->filhodir);
	}
}

void pos_ordem(NO *raiz){
	if(raiz != NULL){
		pos_ordem(raiz->filhoesq);
		pos_ordem(raiz->filhodir);	
		item_imprimir(raiz->item);
	}
}