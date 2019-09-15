#include "aluno.h"
#include<stdio.h>
#include<stdlib.h>

struct aluno_
{
	int id_aluno;
	float horas;
	float nota1;
	float nota2;
};

//cria um alno (aloca a posição da struct na heap)
Aluno * aluno_criar(){
	Aluno * aluno=(Aluno *)malloc(sizeof(Aluno));
	if(aluno==NULL)//caso a memoria heap esteja cheia
	{
		printf("Sem memoria");
		exit(0);
	}
	return aluno;
}

//apaga um registro de aluno
boolean aluno_apagar(Aluno ** aluno){
	free(*aluno);
	if((*aluno)==NULL)
		return TRUE;
	return FALSE;
}

//função imprime todas as informaçoes de um aluno
void aluno_imprimir(Aluno * aluno){
	printf("Id do Aluno    : %d\n",aluno->id_aluno);
	printf("Horas de Estudo: %.2f\n",aluno->horas);
	printf("Nota da P1     : %.2f\n",aluno->nota1);
	printf("Nota da P2     : %.2f\n\n",aluno->nota2);
}

//insere valores nos campos da struct aluno
void aluno_set(Aluno * aluno, int id_aluno, float horas, float nota1, float nota2){
	aluno->id_aluno=id_aluno;
	aluno->horas=horas;
	aluno->nota1=nota1;
	aluno->nota2=nota2;
}

//funçoes de retorno de informaçoes do aluno
int aluno_get_id(Aluno * aluno){
	return aluno->id_aluno;
}

float aluno_get_horas(Aluno * aluno){
	return aluno->horas;
}

float aluno_get_media(Aluno * aluno){
	return (aluno->nota1+aluno->nota2)/2;
}

//caso os dois alunos exiatam a função copia as informaçoes do aluno
//origem e as insere no aluno alvo
boolean aluno_atribuir(Aluno * aluno_alvo, Aluno * aluno_origem){//melhorar depois
	if(aluno_alvo != NULL && aluno_origem!=NULL){
		aluno_set(aluno_alvo,aluno_origem->id_aluno,aluno_origem->horas,aluno_origem->nota1,aluno_origem->nota2);
		return TRUE;
	}
	return FALSE;
}
