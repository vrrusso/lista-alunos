run: all
	./t
all: teste.o lista.o aluno.o
	gcc -g -Wall aluno.o lista.o  teste.o -o t
teste.o: teste.c lista.o
	gcc -c -g -Wall teste.c -o teste.o
lista.o: lista.c
	gcc -c -g -Wall lista.c -o lista.o
aluno.o: aluno.c
	gcc -c -g -Wall aluno.c -o aluno.o
clean:
	rm *.o t
