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
	Node * no=(Node *)malloc(sizeof(Node));
	if(no==NULL)
	{	
		free(no);
		return TRUE;
	}
	free(no);
	return FALSE;
}
boolean lista_vazia(Lista * lista)
{
	if(lista->inicio==NULL)
		return TRUE;
	return FALSE;
}
boolean lista_inserir(Lista * lista, Item * i)
{
	if((!lista_cheia(lista)) && lista != NULL)
	{
		Node * no=(Node *)malloc(sizeof(no));
		no->item=aluno_criar();
		aluno_atribuir(no->item,i);
		aluno_imprimir(no->item);
		if(lista_vazia(lista))
		{
			lista->inicio=no;		
		}
		else
		{
			lista->fim->next=no;
		}
		no->next=NULL;
		lista->fim=no;
		lista->tamanho++;
		return TRUE;
	}
	return FALSE;
}









