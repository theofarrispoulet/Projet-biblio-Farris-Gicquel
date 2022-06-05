all: exe

exe: book.o user.o choice.o main.o
	gcc book.o user.o choice.o main.o -o exe

book.o: book.c header.h
	gcc -c book.c -o book.o 

user.o: user.c header.h
	gcc -c user.c -o user.o

choice.o: choice.c header.h
	gcc -c choice.c -o choice.o

main.o: main.c header.h
	gcc -c main.c -o main.o
