CC=gcc
CFLAGS=-Wall -g -ansi -O0 

main.o:main.c
	$(CC) $(CFLAGS) main.c -o main.o