#include<stdio.h>
#include<stdlib.h>
#include "lista.h"

typedef struct node_ Node;
struct node_
{
	Item * item;
	Node * next;
};
struct lista_
{
	Node * inicio;
	Node * fim;
	int tamanho;
};

Lista * lista_criar()
{
	Lista * lista =(Lista *)malloc(sizeof(Lista));
	if(lista != NULL)
	{
		lista->inicio=NULL;
		lista->fim=NULL;
		lista->tamanho=0;
	}
	return(lista);
}
boolean lista_apagar(Lista ** lista)
{
	//programar depois, precisa desalocar Alunos(usar função) nodes e a lista em si
	return TRUE;
}
boolean lista_cheia(Lista * lista)
{
	//programar depois--pesquisar como verificar memória
	return TRUE;
}
boolean lista_vazia(Lista * lista)
{
	if(lista->inicio==NULL)
		return TRUE;
	return FALSE;
}









