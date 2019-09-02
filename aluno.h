#ifndef ALUNO_H
#define ALUNO_H
#define TRUE 1
#define FALSE 0
typedef int boolean;
typedef struct aluno_ Aluno;
Aluno * aluno_criar();
boolean aluno_apagar(Aluno * aluno);
void aluno_imprimir(Aluno * aluno);
void aluno_set(Aluno * aluno, int id_aluno, float horas, float nota1, float nota2);
int aluno_get_id(Aluno * aluno);
float aluno_get_horas(Aluno * aluno);
float aluno_get_media(Aluno * aluno);
boolean aluno_atribuir(Aluno * aluno_alvo,Aluno * aluno_origem);   
#endif
