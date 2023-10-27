CC=gcc
CFLAGS=-I.

all: program

LoShuSquare.o: LoShuSquare.c
	$(CC) -c LoShuSquare.c -o LoShuSquare.o 

program: LoShuSquare.c
	$(CC) -o program LoShuSquare.c

clean:  
	del program.exe LoShuSquare.o 