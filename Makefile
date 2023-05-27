all: exec clean

main.o: main2.c fonctions.h
	gcc -c main2.c -o main.o

fonctions.o: fonctions2.c fonctions.h
	gcc -c fonctions2.c -o fonctions.o

exec: fonctions.o main.o
	gcc fonctions.o main.o -o exec
clean:
	rm *.o
