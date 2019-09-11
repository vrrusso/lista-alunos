#ifndef ALUNO_H
#define ALUNO_H
#define TRUE 1
#define FALSE 0
typedef int boolean;
typedef struct aluno_ Aluno;
//cria um aluno e retorna o endereço
Aluno * aluno_criar();
//apaga um aluno e retorna um TRUE caso a operação ocorra bem
boolean aluno_apagar(Aluno * aluno);
//imprime as informaçoes do aluno
void aluno_imprimir(Aluno * aluno);
//preenche os campos de informação de um aluno
void aluno_set(Aluno * aluno, int id_aluno, float horas, float nota1, float nota2);
//reorna o id de um aluno
int aluno_get_id(Aluno * aluno);
//retorna o numero de horas de estudo de um aluno
float aluno_get_horas(Aluno * aluno);
//retorna a media das provas de um aluno
float aluno_get_media(Aluno * aluno);
//copia os dade do aluno origem paa o aluno alvo
boolean aluno_atribuir(Aluno * aluno_alvo,Aluno * aluno_origem);
#endif
