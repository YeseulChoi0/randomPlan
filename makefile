all: main.o randomGen.o
	gcc -o program main.o randomGen.o

main.o: main.c randomGen.c
	gcc -c main.c randomGen.c

run:
	./program

memcheck:
	valgrind --leak-check=yes ./program
