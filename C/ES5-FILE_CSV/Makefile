#Vengono linkati tutti i file object (.o)
link: main.o song.o
	gcc main.o song.o -o output.exe

#Compilazione del main
compilemain: main.c
	gcc -c main.c
    
#Compilazione del file song.c
compilesong: song.h song.c
	gcc -c song.c

#Cancella tutti i file object ed exe
destroy:
	rm *.o *.exe