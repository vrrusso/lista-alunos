lista.o: clear aluno.o
	gcc -c -g -Wall lista.c -o lista.o
aluno.o: aluno.c
	gcc -c -g -Wall aluno.c -o aluno.o
clear:
	rm *.o
