#ifndef LISTA_H
#define LISTA_H
#define TRUE 1
#define FALSE 0
typedef int boolean;
typedef struct lista_ Lista;
typedef Aluno Item;

Lista * lista_criar();
boolean lista_apagar(Lista ** lista);
boolean lista_cheia(Lista * lista);
boolean lista_vazia(Lista * lista);
boolean lista_inserir(Lista * lista, Item i);
boolean lista_remove_item(Lista * lista, int key);
void lista_imprimir(Lista * lista);
void lista_imprimir_status(Lista * lista);
void lista_imprimir_horas(Lista * lista);

#endif
