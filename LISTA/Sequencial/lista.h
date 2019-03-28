#ifndef LISTA_H
#define LISTA_H

#define ERRO -404
#define TIPO int  //Customização do tipo
#define MAX 100	  //Tamanho máximo 
#define VAZIO 0   //Elemento que indica vazio

typedef struct lista LISTA;

/*Funções básicas:*/
LISTA *lista_criar(void);
void lista_apagar(LISTA *L);

/*Inserir e ordenar:*/
void lista_inserir(LISTA *L, int pos, TIPO item);
void lista_inserir_no_fim(LISTA *L, int pos);
void lista_ordenar(LISTA *L);
void insertion_sort(TIPO *vet, int n); /*O(n^2) -> comportamento quadrático. Pode ser trocada por uma de complexidade menor*/

/*Busca:*/
int lista_buscar(LISTA *L, TIPO chave); /*Retorna a posição*/
int busca_binaria_original(TIPO *vet, TIPO chave, int comeco, int fim);

/*Retirar/acessar:*/
TIPO lista_retirar(LISTA *L, int pos); /*Retira da lista*/
TIPO lista_acessar(LISTA *L, int pos); /*Só acessa*/	

/*Funções de consulta:*/
int lista_vazia(LISTA *L);
int lista_cheia(LISTA *L);
int lista_inicio(LISTA *L);
int lista_fim(LISTA *L);
int lista_tamanho(LISTA *L);

#endif