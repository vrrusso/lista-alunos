#include<stdio.h>
#include "aluno.h"
#include "lista.h"

//função de menu que mostra as opçoes e retorna o numero da opçao escolhida
int menu(){
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
        op=aux-'0';
        if(op<1||op>6)
            printf("\n\n\nOpção Inválida!!!\n\n\n\n");
	}while(op<1 || op>6);
	return op;
}
//recebe os dados de um aluno e o insere no final da lista
boolean  entrada_dados(Lista * lista){
   	Aluno * aluno_aux = aluno_criar();
    	int id;
    	float horas,nota1,nota2;
    	printf("\nId do Aluno:");scanf("%d",&id);
    	printf("Horas de Estudo:");scanf("%f",&horas);
    	printf("Nota da Primeira Avaliação:");scanf("%f",&nota1);
    	printf("Nota da Segunda Avaliação:");scanf("%f",&nota2);
    	aluno_set(aluno_aux,id,horas,nota1,nota2);
    	boolean teste = lista_inserir(lista,aluno_aux);
    	aluno_apagar(&aluno_aux);
	return teste;
}
//recebe o id do aluno a ser apagado e chama a funçã que deleta alunos
boolean remover_dados(Lista *lista){
	int id;
	printf("\nID do aluno a ser removido: "); scanf("%d", &id);

	return lista_remove_item(lista, id);
}
//printa o tempo medio de estudo da turma
void horas_estudo(Lista *lista){
	float h = lista_media_horas(lista);
	if(h >= 0){
		printf("\nTempo de estudo medio da turma: %.2f horas.\n\n", h);
	}
}

int main(void){
    	int opcao;
    	Lista * lista = lista_criar();
    	do//loop para rodar o programa até que o usuario queira sair
    	{
 		switch (opcao = menu()){

 			case (1)://Inserir Registro
 				if(entrada_dados(lista)== TRUE)
          				printf("\nAluno inserido com sucesso no fim da lista!\n\n");
 			break;

 			case (2)://Remover Registro
 				if(remover_dados(lista) == TRUE)
					printf("\nAluno removido da lista com sucesso!\n\n");
 			break;

 			case (3)://Imprimir Registros
 				printf("\nTodos os registros:\n\n");
          			lista_imprimir(lista);
 			break;

 			case (4)://Relatório de Aprovação
 				printf("\nRelatório de Aprovação:\n");
				lista_imprimir_status(lista);
 			break;

 			case (5)://Horas de estudo(Média)
				horas_estudo(lista);
 			break;

 			default://Sair
 				printf("\nObrigado por utilizar nosso programa!!\n");
 			break;
 		}
   	}while(opcao != 6);
    	lista_apagar(&lista);//desaloca a lista
	return 0;
}
