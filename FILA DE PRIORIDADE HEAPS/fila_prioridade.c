#include "fila_prioridade.h"

struct heap_estatica{
	ITEM * vetor[TAM];
	int fim;
};


HEAP_ESTATICA *criar_heap(){
	HEAP_ESTATICA *heap = (HEAP_ESTATICA*)malloc(sizeof(HEAP_ESTATICA));
	if(heap != NULL){
		heap->fim = -1;
	}
	return heap;
}

void apagar_heap(HEAP_ESTATICA *heap){
	if(heap != NULL){
		for(int i=0; i<TAM; i++) free(vetor[i]);
		free(heap);	
	}
}

int heap_cheia(HEAP_ESTATICA *heap){
	return (heap->fim == TAM - 1);
}

int heap_vazia(HEAP_ESTATICA *heap){
	return (heap->fim == -1);
}

int enfileirar_heap(HEAP_ESTATICA *heap, ITEM *item){
	if(!cheia(heap)){
		heap->fim++;
		heap->vetor[heap->fim] = item;
		fix_up(heap);
		return 1;
	}
	return 0;
}

void swap(HEAP_ESTATICA *heap, int i, int j){
	ITEM *tmp = heap->vetor[i];
	heap->vetor[i] = heap->vetor[j];
	heap->vetor[j] = tmp;
}

void fix_up(HEAP_ESTATICA *heap){
	int pos = heap->fim;
	int pai = (pos - 1) / 2;
	while(pos > 0 && item_chave(heap->vetor[pos]) > item_chave(heap->vetor[pai])){
		swap(heap, pos, pai);
		pos = pai;
		pai = (pai - 1) / 2;
	}
}

ITEM *retirar(HEAP_ESTATICA *heap){
	ITEM *ret = NULL;
	if(!vazia(heap)){
		ret = heap->vetor[0];	
		swap(heap, 0, heap->fim);
		heap->fim--;
		fix_down(heap);
	}
	return ret;
}

void fix_down(HEAP_ESTATICA *heap){
	int pos = 0;
	//int pai = (pos - 1) / 2;
	int filho;
	while((filho = (2 * pai) + 1) <= heap->fim){
		filho = pos_maior_filho(heap, pos);
		if(item_chave(heap->vetor[pos]) >= item_chave(heap->vetor[filho])) break;
		swap(heap, pos, filho);
		pos = filho;
	}
}

int pos_maior_filho(HEAP_ESTATICA *heap, int pai){
	int filho1 = (2 * pai) + 1, filho2 = (2 * pai) + 2;
	if(filho2 <= heap->fim)
		return (filho1 >= filho2 ? filho1 : filho2);
	return (filho1);
}