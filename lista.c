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
//aloca uma struct lista na heap e inicializa valores
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
//desaloca todos os nodes(apagando os alunos também) e depois desaloca a lista
boolean lista_apagar(Lista ** lista){
	if(lista != NULL && !lista_vazia(*lista) )
	{
		Node * p = (*lista)->inicio;
		Node * next;
		do
		{
			next=p->next;
			aluno_apagar(&p->item);
			free(p);
			p=next;
		}while(p != NULL);
		free(*lista);
	}else{
		free(*lista);
	}
	(*lista)=NULL;
	if(lista==NULL)
		return TRUE;
	return FALSE;
}
//verifica se ainda ha espeço na memoria
boolean lista_cheia(Lista * lista){
	Node * no=(Node *)malloc(sizeof(Node));

	if(no==NULL){
		free(no);
		return TRUE;
	}

	free(no);
	return FALSE;
}
//verifica se ha elementos na lista
boolean lista_vazia(Lista * lista){
	if(lista->inicio==NULL)
		return TRUE;
	return FALSE;
}
//insere um elemento na lista caso ela exita e nao esteja cheia
boolean lista_inserir(Lista * lista, Item * i){
	if(lista != NULL && !lista_cheia(lista) ){
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
// imprime todos os elementos da lista
void lista_imprimir(Lista * lista){
	Node * p;

	if(lista != NULL && !lista_vazia(lista) ){
		p = lista->inicio;

		while(p != NULL){
			aluno_imprimir(p->item);
			p=p->next;
		}
		return;
	}
	printf("A lista está vazia ou não foi iniciada!\n\n");
}
//busca os itens por meio do id e deleta todos os que tiverem o id especificado
boolean lista_remove_item(Lista * lista, int key){
	Node *atual = lista->inicio;
	Node *aux;
	boolean flag = FALSE;

	if(atual == NULL){//caso alista esteja vazia
		printf("Nenhum registro encontado\n\n");
		return flag;
	}

	//caso precise remover o primeiro da lista
	while(atual!=NULL && aluno_get_id(atual->item) == key){
		aux = atual;
		lista->inicio = aux->next;
		aluno_apagar(&aux->item);
		aux->next = NULL;
		free(aux);
		atual = lista->inicio;
		flag = TRUE;
      lista->tamanho--;
	}
	//demais remoçoes
	while(atual!=NULL && atual->next != NULL){
		if(aluno_get_id(atual->next->item) == key){
			if(atual->next->next == NULL){
				lista->fim = atual;
			}
			aux =  atual->next;
			atual->next = aux->next;
			aluno_apagar(&aux->item);
				aux->next = NULL;
            free(aux);
			flag = TRUE;
            lista->tamanho--;
		}else atual = atual->next;
	}
	return flag;
}
//imprime a situação de todos os alunos da lista (Aprovado ou Reprovado)
void lista_imprimir_status(Lista * lista){
	Node *atual = lista->inicio;
	int id;

	if(atual == NULL){//caso a lista esteja vazia
		printf("Nenhum registro encontado\n\n");
		return;
	}
	printf("Alunos:   Status: \n");
	while(atual!=NULL){
		id = aluno_get_id(atual->item);
		//mosta a situação baseado na media
		if(aluno_get_media(atual->item) >= 5.00) printf("%d ------ Aprovado\n", id);
		else printf("%d ------ Reprovado\n", id);

		atual = atual->next;
	}
	printf("\n");
	return;
}
//calcula e mostra a media de horas de estudo de todos os alunos da lista
float lista_media_horas(Lista * lista){
	Node *atual = lista->inicio;
	float soma = 0;

	if((atual == NULL) || (lista->tamanho == 0)){
		printf("Nenhum registro encontado\n\n");
		return -1;
	}

	while(atual!=NULL){
		soma += aluno_get_horas(atual->item);
		atual = atual->next;
	}

	return (soma/(float)lista->tamanho);
}
