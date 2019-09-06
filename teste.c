#include<stdio.h>
#include "aluno.h"
#include "lista.h"

int menu(){ // menu dando erro quando se digita
	int op = 0;
    char aux;
	do{
		printf("-------------MENU-------------\n");
		printf("| 1 - Inserir Registro       |");
		printf("\n| 2 - Remover Registro       |");
		printf("\n| 3 - Imprimir Registros     |");
        printf("\n| 4 - Relatório de Aprovação |");
		printf("\n| 5 - Horas de estudo(Média) |");
        printf("\n| 6 - Sair                   |\n");
		printf("------------------------------\n");
		printf("ecolha uma opção: ");
        scanf(" %c",&aux);;
		//scanf("%d", &op);
        op=aux-'0';
        if(op<1||op>6)
            printf("\n\n\nOpção Inválida!!!\n\n\n\n");
	}while(op<1 || op>6);
	return op;
}

boolean  entrada_dados(Lista * lista){
    Aluno * aluno_aux = aluno_criar();
    int id;
    float horas,nota1,nota2;
    printf("Id do Aluno:");scanf("%d",&id);
    printf("Horas de Estudo:");scanf("%f",&horas);
    printf("Nota da Primeira Avaliação:");scanf("%f",&nota1);
    printf("Nota da Segunda Avaliação:");scanf("%f",&nota2);
    aluno_set(aluno_aux,id,horas,nota1,nota2);
    boolean teste = lista_inserir(lista,aluno_aux);
    aluno_apagar(aluno_aux);
    return teste;
}

boolean remover_dados(Lista *lista){
	int id;
	printf("ID do aluno a ser removido: "); scanf("%d", &id);

	return lista_remove_item(lista, id);
}

void horas_estudo(Lista *lista){
	float h = lista_media_horas(lista);
	if(h >= 0){
		printf("Tempo de estudo medio da turma: %.2f horas.\n", h);
	}
}

int main(void){
    int opcao;
    Lista * lista = lista_criar();
    do
    {
 		switch (opcao = menu()){

 			case (1):
 				if(entrada_dados(lista)==1)
          printf("Aluno inserido com sucesso no fim da lista!\n");
 			break;

 			case (2):
 				if(remover_dados(lista) == 1)
					printf("Aluno removido da lista com sucesso!\n");
 			break;

 			case (3):
 				printf("Todos os registros:\n");
          lista_imprimir(lista);
 			break;

 			case (4):
 				printf("Relatório de Aprovação:\n");
				lista_imprimir_status(lista);
 			break;

 			case (5):
				horas_estudo(lista);
 			break;

 			default:
 				printf("Obrigado por utilizar nosso programa!!\n");
 			break;
 		}
    }while(opcao != 6);
    lista_apagar(lista);


//teste:
/*
	Aluno * aluno = aluno_criar();
	Lista * lista=lista_criar();
	int id;
	float horas,nota1,nota2;
	for(int i=0; i<5; i++){
		scanf("%d %f %f %f",&id,&horas,&nota1,&nota2);
		aluno_set(aluno,id,horas,nota1,nota2);
		printf("%d %f %f\n",aluno_get_id(aluno),aluno_get_horas(aluno),aluno_get_media(aluno));
		//aluno_imprimir(aluno);
		printf("|%d|\n",lista_inserir(lista,aluno));
	}
	printf("Horas de estudo(TURMA): %.2f\n", lista_media_horas(lista));
	lista_imprimir_status(lista);
	aluno_apagar(aluno);
	lista_imprimir(lista);
	printf("|%d|\n", lista_remove_item(lista, 15));
	lista_imprimir(lista);
	lista_apagar(lista);

*/
	return 0;
}
