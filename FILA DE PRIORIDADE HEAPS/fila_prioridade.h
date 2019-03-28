#ifndef FILA_PRIORIDADE_H
#define FILA_PRIORIDADE_H

typedef struct heap_estatica HEAP_ESTATICA;
#define TAM 100
#define ITEM int	

/*Funções básicas:*/	
HEAP_ESTATICA *criar_heap();
void apagar_heap(HEAP_ESTATICA *heap);

/*Funções básicas:*/
int heap_cheia(HEAP_ESTATICA *heap);
int heap_vazia(HEAP_ESTATICA *heap);

/*Funções de inserir e retirar:*/
int enfileirar_heap(HEAP_ESTATICA *heap, ITEM *item);
ITEM *retirar(HEAP_ESTATICA *heap);

void swap(HEAP_ESTATICA *heap, int i, int j);
void fix_up(HEAP_ESTATICA *heap);
void fix_down(HEAP_ESTATICA *heap);
int pos_maior_filho(HEAP_ESTATICA *heap, int pai);


#endif