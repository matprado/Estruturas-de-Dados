#ifndef AVL_H
#define AVL_H

#define max(a, b) ((a > b) ? a : b)

typedef struct avl AVL;
typedef struct no NO;

/*Funções básicas:*/
AVL *avl_criar(void);
void avl_apagar_aux(NO *raiz);
void avl_apagar(AVL **arvore);

/*Funções de inserção e remoção*/
int avl_inserir(AVL *arvore, ITEM *item);
int avl_remover(NO *raiz, NO *rem, NO *ant, int chave);

/*Funções auxiliares*/
NO *avl_inserir_no(NO *raiz, ITEM *item);
void troca_max_esq(NO *troca, NO *rem, NO *ant);
int avl_altura_no(NO* raiz);
NO *avl_cria_no(ITEM *item);
NO *rodar_direita(NO *a);
NO *rodar_esquerda(NO *a);
NO *rodar_esquerda_direita(NO *a);
NO *rodar_esquerda_direita(NO *a);
