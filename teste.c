#include<stdio.h>
#include "aluno.h"
#include "lista.h"

int menu(){ // menu dando erro quando se digita uma letra 
	int op = 0;

	do{
		printf("-------------MENU-------------\n");
		printf("| 1 - Inserir Registro\n| 2 - Remover Registro\n| 3 - Imprimir Registros\n| 4 - Relatório de Aprovação\n| 5 - Horas de estudo (Média)\n| 6 - Sair\n");
		printf("------------------------------\n");
		printf("ecolha uma opção: ");

		scanf("%d", &op);

		if(op>=1 && op<=6) return op;
	 	else{
			op = 0;
			printf("Opção Invalida\n");
		}
	}while(op<1 || op>6);
}

int main(void){
 	boolean flag = TRUE;

 	while(flag){
		switch (menu()){

			case (1):
				printf("Opção - 1\n");
			break;

			case (2):
				printf("Opção - 2\n");
			break;

			case (3):
				printf("Opção - 3\n");
			break;

			case (4):
				printf("Opção - 4\n");
			break;

			case (5):
				printf("Opção - 5\n");
			break;

			case (6):
				flag = FALSE;
			break;
		}
	}



//teste:
	// Aluno * aluno = aluno_criar();
	// Lista * lista=lista_criar();
	// int id;
	// float horas,nota1,nota2;
	// scanf("%d %f %f %f",&id,&horas,&nota1,&nota2);
	// aluno_set(aluno,id,horas,nota1,nota2);
	// printf("%d %f %f\n",aluno_get_id(aluno),aluno_get_horas(aluno),aluno_get_media(aluno));
	// //aluno_imprimir(aluno);
	// printf("|%d|",lista_inserir(lista,aluno));
	// printf("|%d|",lista_inserir(lista,aluno));
	// aluno_apagar(aluno);
	// lista_imprimir(lista);
	// lista_apagar(lista);


	return 0;
}
