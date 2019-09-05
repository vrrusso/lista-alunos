#include<stdio.h>
#include<stdlib.h>
#include "lista.h"

typedef struct node_ Node;

struct node_{
	Item * item;
	Node * next;
};

struct lista_{
	Node * inicio;
	Node * fim;
	int tamanho;
};

Lista * lista_criar(){
	Lista * lista =(Lista *)malloc(sizeof(Lista));
	if(lista != NULL)
	{
		lista->inicio=NULL;
		lista->fim=NULL;
		lista->tamanho=0;
	}
	return(lista);
}

boolean lista_apagar(Lista * lista){
	//programar depois, precisa desalocar Alunos(usar função) nodes e a lista em si
	if(!lista_vazia(lista) && lista != NULL)
	{
		Node * p = lista->inicio;
		Node * next;
		do
		{
			next=p->next;
			aluno_apagar(p->item);
			free(p);
			p=next;
		}while(p != NULL);
		free(lista);
	}else{
		free(lista);
	}
	if(lista==NULL)
		return TRUE;
	return FALSE;
}

boolean lista_cheia(Lista * lista){
	Node * no=(Node *)malloc(sizeof(Node));

	if(no==NULL){
		free(no);
		return TRUE;
	}

	free(no);
	return FALSE;
}

boolean lista_vazia(Lista * lista){
	if(lista->inicio==NULL)
		return TRUE;
	return FALSE;
}

boolean lista_inserir(Lista * lista, Item * i){
	if((!lista_cheia(lista)) && lista != NULL){
		Node * no=(Node *)malloc(sizeof(Node));
		no->item=aluno_criar();
		aluno_atribuir(no->item,i);

		if(lista_vazia(lista)){
			lista->inicio=no;
		}else{
			lista->fim->next=no;
		}

		no->next=NULL;
		lista->fim=no;
		lista->tamanho++;
		return TRUE;
	}
	return FALSE;
}

void lista_imprimir(Lista * lista){
	Node * p;

	if((!lista_vazia(lista)) && lista != NULL){
		p = lista->inicio;

		while(p != NULL){
			aluno_imprimir(p->item);
			p=p->next;
		}
		return;
	}
	printf("A lista está vazia ou não foi iniciada!\n");
}

//falta testar os 3:
boolean lista_remove_item(Lista * lista, int key){
	Node *atual = lista->inicio;
	Node *aux;
	boolean flag = FALSE;

	if(atual == NULL){
		printf("Nenhum registro encontado\n");
		return flag;
	}

	//caso precise remover o primeiro da lista
	while(atual!=NULL && aluno_get_id(atual->item) == key){
		aux = atual;
		lista->inicio = aux->next;
		aluno_apagar(aux->item);
		free(aux);
		atual = lista->inicio;
		flag = TRUE;
        lista->tamanho--;
	}
	//demais remoçoes
	while(atual!=NULL && atual->next != NULL){
		if(aluno_get_id(atual->next->item) == key){
			aux =  atual->next;
			atual->next = aux->next;
			aluno_apagar(aux->item);
            free(aux);
			flag = TRUE;
            lista->tamanho--;
		}
		atual = atual->next;
	}
	return flag;
}

void lista_imprimir_status(Lista * lista){
	Node *atual = lista->inicio;
	int id;

	if(atual == NULL){
		printf("Nenhum registro encontado\n");
		return;
	}
	printf("Alunos:   Status: \n");
	while(atual!=NULL){
		id = aluno_get_id(atual->item);

		if(aluno_get_media(atual->item) >= 5.00) printf("%d ------ Aprovado\n", id);
		else printf("%d ------ Reprovado\n", id);

		atual = atual->next;
	}
	return;
}

float lista_media_horas(Lista * lista){
	Node *atual = lista->inicio;
	float soma = 0;

	if((atual == NULL) || (lista->tamanho == 0)){
		printf("Nenhum registro encontado");
		return -1;
	}

	while(atual!=NULL){
		soma += aluno_get_horas(atual->item);
		atual = atual->next;
	}

	return (soma/(float)lista->tamanho);
}
