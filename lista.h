#ifndef LISTA_H
#define LISTA_H
#include "aluno.h"
#define TRUE 1
#define FALSE 0
typedef int boolean;
typedef struct lista_ Lista;
typedef Aluno Item;
//cria uma lista de aulnos e retorna um pinteiro para alista criada
Lista * lista_criar();
//apaga todos os elemntos da lista, depois apaga a lista
boolean lista_apagar(Lista ** lista);
//verifica se a lista esta cheia
boolean lista_cheia(Lista * lista);
//verifica se a lista esta vazia
boolean lista_vazia(Lista * lista);
//insere um item na lista
boolean lista_inserir(Lista * lista, Item * i);
//remove um item da lista com base em seu id
boolean lista_remove_item(Lista * lista, int key);
//imprime todos os registros da lista
void lista_imprimir(Lista * lista);
//imprime os relatorio de aprovaçoes dos alunos da lista
void lista_imprimir_status(Lista * lista);
//retorna a media de horas de estudo dos alunos
float lista_media_horas(Lista * lista);

#endif
