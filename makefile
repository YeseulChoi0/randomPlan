all: main.o randomGen.o
	gcc -o program main.o randomGen.o

main.o: main.c header.h
	gcc -c main.c header.h

randomGen.o: randomGen.c header.h
	gcc -c randomGen.c header.h

run:
	./program

memcheck:
	valgrind --leak-check=yes ./program
