CC=gcc #compilatore
OUT=output.exe #Nome dell'eseguibile

#Linkaggio
output: main.o song.o
	$(CC) main.o song.o -o $(OUT)

#File object main
main.o: main.c
	$(CC) -c main.c

#File object song
song.o: song.h song.c
	$(CC) -c song.c

#Per la rimozione dei file .o e .exe
delete:
	rm *.o *.exe