CC = gcc
OUT = output.exe

output: main.o datiCovid.o
	$(CC) main.o datiCovid.o -o $(OUT)

main.o: main.c
	$(CC) -c main.c

datiCovid.o: datiCovid.h datiCovid.c
	$(CC) -c datiCovid.c

delete:
	rm *.o *.exe