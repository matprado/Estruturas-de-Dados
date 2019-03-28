#ifndef ABB_H
#define ABB_H

#include “item.h”

typedef struct No NO;
typedef struct abb ABB;

/*Funções básicas:*/
ABB *abb_criar(void);
void abb_apagar(ABB *T);
void apagar_aux(NO *raiz);

/*Funções de inserção e remoção:*/
int abb_inserir(ABB *T, ITEM *item);
NO *abb_inserir_filho(int filho, NO *no, ITEM item);
int abb_inserir_no(NO *raiz, ITEM *item);

/*abb_remover_aux(T->raiz, T->raiz, NULL, chave);*/
int abb_remover_aux(NO *raiz, NO *rem, NO *ant, int chave);
void troca_max_esq(NO *troca, NO *rem, NO *ant);

/*Função de busca:*/
ITEM *abb_busca(NO *raiz, int chave);
