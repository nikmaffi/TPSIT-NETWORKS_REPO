CC = gcc
OUT = Rubrica.exe

output: main.o rubrica.o
	$(CC) main.o rubrica.o -o $(OUT)

main.o: main.c
	$(CC) -c main.c

rubrica.o: rubrica.h rubrica.c
	$(CC) -c rubrica.c

delete:
	rm *.o *.exe