#ifndef AB_H
#define AB_H

#include “item.h”

typedef struct No NO;
typedef struct arv ARV;

ARV *arv_criar(void);
NO *arv_criar_raiz(ARV *T, ITEM *i);
void arv_inserir_filho(int filho, NO *no, ITEM *item);
void pre_ordem(NO *raiz);
void em_ordem(NO *raiz);
void pos_ordem(NO *raiz);

