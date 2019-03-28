#include "avl.h"

struct no{
	ITEM *item;
	struct NO *fesq;
	struct NO *fdir;
	int altura;
};

struct avl{
	NO *raiz;
	int profundiade;
};


AVL *avl_criar(void){
	AVL *arvore = (AVL *) malloc(sizeof (AVL));
	if(arvore != NULL){
		arvore->raiz = NULL;
		arvore->profundidade = -1;
	}
	return arvore;
}

void avl_apagar_aux(NO *raiz){
	if(raiz != NULL){
		apagar_avl_aux(raiz->fesq);
		apagar_avl_aux(raiz->fdir);
		apagar_item(&(raiz->item));
		free(raiz);
	}
}

void avl_apagar(AVL **arvore){
	avl_apagar_aux((*arvore)->raiz);
	free(*arvore);
	*arvore = NULL;
}

int avl_altura_no(NO* raiz){
	if(raiz == NULL){
		return -1;
	}else{
		return raiz->altura;
	}
}

NO *avl_cria_no(ITEM *item){
	NO *no = (NO *) malloc(sizeof (NO));
	if(no != NULL){
		no->altura = 0;
		no->fdir = NULL;
		no->fesq = NULL;
		no->item = item;
	}
	return no;
}

NO *rodar_direita(NO *a){
	NO *b = a->fesq;
	a->fesq = b->fdir;
	b->fdir = a;
	a->altura = max(avl_altura_no(a->fesq),avl_altura_no(a->fdir)) + 1;
	b->altura = max(avl_altura_no(b->fesq),	a->altura) + 1;
	return b;
}

NO *rodar_esquerda(NO *a){
	NO *b = a->fdir;
	a->fdir = b->fesq;
	b->fesq = a;
	a->altura = max(avl_altura_no(a->fesq),avl_altura_no(a->fdir)) + 1;
	b->altura = max(avl_altura_no(b->fdir),	a->altura) + 1;
	return b;
}

NO *rodar_esquerda_direita(NO *a){
	a->fesq = rodar_esquerda(a->fesq);
	return rodar_direita(a);
}

NO *rodar_esquerda_direita(NO *a){
	a->dir = rodar_direita(a->dir);
	return rodar_esquerda(a);
}

NO *avl_inserir_no(NO *raiz, ITEM *item){
	if(raiz == NULL){
		raiz = avl_cria_no(item);
	}else if(item_chave(item) > item_chave(raiz)){
		raiz->fdir = avl_inserir_no(raiz->fdir, item);
		if(avl_altura_no(raiz->fesq) – avl_altura_no(raiz->fdir) == -2){
			if(item_chave(item) > item_chave(raiz->fdir->item)){
				raiz = rodar_esquerda(raiz);
			}else{
				raiz = rodar_direita_esquerda(raiz);
			}
		}
	}else if(item_chave(item) < item_chave(raiz)){
		raiz->fesq = avl_inserir_no(raiz->fesq, item);
		if(avl_altura_no(raiz->fesq) – avl_altura_no(raiz->fdir) == 2){
			if(item_chave(item->chave) < item_chave(raiz->fesq->item)){
				raiz = rodar_direita(raiz);
			}else{
				raiz = rodar_esquerda_direita(raiz);
			}
		}
	}
	raiz->altura = max(avl_altura_no(raiz->fesq),avl_altura_no(raiz->fdir)) + 1;
	return raiz;
}

int avl_inserir(AVL *arvore, ITEM *item){
	return (arvore->raiz = avl_inserir_no(arvore->raiz, item)) != NULL;
}

int avl_remover(NO *raiz, NO *rem, NO *ant, int chave){
 /*avl_remover(T->raiz, T->raiz, NULL, chave);*/
	NO *prox;
	if(rem == NULL)
		return 0;
	if(chave < item_chave(rem)){ //Caso 1: 'desce' a árvore
		return avl_remover(raiz, rem->fesq, rem, chave);	
	}else if(chave > item_chave(rem)){
			return avl_remover(raiz, rem->fdir, rem, chave);
	}else{ 
		/*Caso 2: há apenas um dos filhos*/
		if(rem->fesq == NULL || rem->fdir == NULL){
			if(rem->fesq == NULL)
				prox = rem->fdir;
			else
				prox = rem->fesq;
			if(ant == NULL)
				raiz = prox;
			else{ /*rem eh fesq ou fdir de ant?*/
				if(rem == ant->fesq){
					ant->fesq = prox;
				}
				else{
					ant->fdir = prox;
				}
			}
			free(rem);
			rem = NULL;
		}
		else{ /*Caso 3: há ambos os filhos*/
			troca_max_esq(rem->fesq, rem, rem);
		}
		/*Atualizar a altura da árvore*/	
		ant->altura = max(avl_altura_no(ant->fesq),avl_altura_no(ant->fdir)) + 1;	
		/*Rotacionar caso necessário:*/
		if(avl_altura_no(ant->fesq) - avl_altura_no(ant->fdir) == -2){
			if(chave < item_chave(ant->fdir)){
				ant = rodar_esquerda(ant);
			}else{
				ant = rodar_direita_esquerda(ant);
			}
		}
		if(avl_altura_no(ant->fesq) - avl_altura_no(ant->fdir) == 2){
			if(chave > item_chave(ant->fesq)){
				ant = rodar_direita(ant);
			}else{
				ant = rodar_esquerda_direita(ant);
			}
		}
		return 1;	 
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