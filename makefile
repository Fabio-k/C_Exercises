all: programa

programa: prova1.o aula_menu.o
	gcc -o programa prova1.o aula_menu.o

prova1.o: prova1.c
	gcc -c prova1.c

aula_menu.o: aula_menu.c
	gcc -c aula_menu.c

clean:
	rm *.o programa
