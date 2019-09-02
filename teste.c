#include<stdio.h>
#include "aluno.h"
#include "lista.h"
int main(void)
{
	Aluno * aluno = aluno_criar();
	Lista * lista=lista_criar();
	int id;
	float horas,nota1,nota2;
	scanf("%d %f %f %f",&id,&horas,&nota1,&nota2);
	aluno_set(aluno,id,horas,nota1,nota2);
	printf("%d %f %f\n",aluno_get_id(aluno),aluno_get_horas(aluno),aluno_get_media(aluno));
	aluno_imprimir(aluno);
	printf("|%d|",lista_inserir(lista,aluno));
	aluno_apagar(aluno);
	return 0;
}
