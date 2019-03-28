#include “abb.h”
#include <stdlib.h>

struct No{
	ITEM *item;
	NO *esq;
	NO *dir;
};

struct abb{
	NO *raiz;
};

ABB *abb_criar(void){
	ABB *T = (ARV *) malloc(sizeof(ABB));
	if(T != NULL){
		T->raiz = NULL;
	}
	return (T);
}

void abb_apagar(ABB *T){
	if(T != NULL) apagar_aux(T->raiz);
}

void apagar_aux(NO *raiz){
	if(raiz != NULL){
		//apagar_item(raiz->item);
		apagar_aux(raiz->esq);
		apagar_aux(raiz->dir);
		free(raiz);
	}
}

int abb_inserir(ABB *T, ITEM *item){
	if(T == NULL)
		return 0;
	if(abb_vazia(T)){
		T->raiz = (NO *) malloc(sizeof(NO));
		if(T->raiz != NULL){
			T->raiz->item = item;
			T->raiz->esq = NULL;
			T->raiz->dir = NULL;
			return 1;
		}
	}else return(abb_inserir_no(T->raiz, item));
}

NO *abb_inserir_filho(int filho, NO *no, ITEM item){
	NO *pnovo = (NO *) malloc(sizeof (NO));
	if(pnovo != NULL){
		pnovo->dir = NULL;
		pnovo->esq = NULL;
		pnovo->item = item;
		if(filho == FILHO_ESQ)
			no->esq = pnovo;
		else
			no->dir = pnovo;
	}
	return pnovo;
}

int abb_inserir_no(NO *raiz, ITEM *item){
	if(item_chave(item) < item_chave(raiz->item)){
		if(raiz->esq != NULL)
			return(abb_inserir_no(raiz->esq, item));
		else
			return (abb_inserir_filho(FILHO_ESQ, raiz, item) != NULL);
	}else{
		if(item_chave(item) > item_chave(raiz->item)){
			if(raiz->dir != NULL)
				return abb_inserir_no(raiz->dir, item);
			else
				return (abb_inserir_filho(FILHO_DIR, raiz, item) != NULL);
		}else
			return 0;
	}
}

ITEM *abb_busca(NO *raiz, int chave){
	if(raiz == NULL){
		return NULL;
	}else{
		if(chave == item_chave(raiz->item)){
			return (raiz->item);
		}
		else{
			if(chave < item_chave(raiz->item))
				return (abb_busca(raiz->esq, chave));
			else
				return (abb_busca(raiz->dir, chave));
			
		}
	}
}

void troca_max_esq(NO *troca, NO *rem, NO *ant){
	if(troca->dir != NULL){
		return troca_max_esq(troca->dir, rem, troca);
	}
	if(rem == ant)
		ant->esq = troca->esq;
	else
		ant->dir = troca->esq;
	rem->item = troca->item;
	free(troca);
	troca = NULL;
}

int abb_remover_aux(NO *raiz, NO *rem, NO *ant, int chave){
/*abb_remover_aux(T->raiz, T->raiz, NULL, chave);*/
	NO *prox;
	if(rem == NULL)
		return 0;
	if(chave < item_chave(rem->item))
		return abb_remover_aux(raiz, rem->esq, rem, chave);
	else{
		if(chave > item_chave(rem->item))
			return abb_remover_aux(raiz, rem->dir, rem, chave);
		else{
			/*Caso 2: há apenas um dos filhos*/
			if(rem->esq == NULL || rem->dir == NULL){
				if(rem->esq == NULL)
					prox = rem->dir;
				else
					prox = rem->esq;
				if(ant == NULL)
					raiz = prox;
				else{
				/*rem eh filho esq ou dir de ant?*/
					if(rem == ant->esq)
						ant->esq = prox;
					else
						ant->dir = prox;
				}
				free(rem); rem = NULL;}
			else{ /*Caso 3: há ambos os filhos*/
				troca_max_esq(rem->esq, rem, rem);
			}
			return 1;
		}
	}
}