/*
 * Esercizio-5
 * 
 * File CSV (Comma Separated Value).
 * Programma che, letto un file csv contenente dei brani musicali, propone a caso uno di essi.
 *
 * Autore:   Nicolò Maffi
 * Data:     22/10/2020
*/

#include <stdio.h> //Per funzioni di input output
#include <stdlib.h> //Per calloc(), srand() e rand()
#include <time.h> //Per time()
#include "song.h" //Per il tipo song

#define NO_ERR 0 //Costante che indica una corretta esecuzione
#define PARAM_ERR 1 //Costante che indica un errore sulla chiamata del programma
#define FILE_ERR 2 //Costante che indica un errore di un operazione sul file

int main(int argc, const char **argv, const char **envp)
{
    song *s; //Array che conterrà tutti i brani del file csv
    unsigned long song_index; //Indice delbrano che verrà scelto a random
    unsigned long num_line; //Numero di linee del file csv

    srand(time(NULL)); //Il seme per il generatore di numeri casuali viene inizializzato

    if(argc != 2) //La chiamata al programma deve avvenire con 2 paramatri
    {
        printf("\nErrore: Numero invalido di parametri.\n\n");

        printf("SYNOPSIS\n");
        printf("\t%s  file_csv\n\n", argv[0]);

        return PARAM_ERR;
    }

    //Viene controllato se il file è vuoto (numero linee pari a 0)
    if((num_line = linecount(argv[1])) == 0)
    {
        printf("\nErrore: il file %s e' vuoto.\n\n", argv[1]);

        return FILE_ERR;
    }

    s = (song *)calloc(num_line, sizeof(song)); //Allocazione dell'array

    //Viene controllato se è possibile effettuare una lettura sul file
    if(!reading(argv[1], s))
    {
        printf("\nErrore: Non e' possibile effettuare la lettura del file %s.\n\n", argv[1]);

        return FILE_ERR;
    }

    song_index = rand() % num_line; //Viene generato l'indice (da 0 a num_line - 1)

    //Output del titolo del brano scelto a caso
    printf("\nConsigliata:\n");
    printf("\t%lu\n\t%s\n\t%s\n\n", (s + song_index)->index + 1, (s + song_index)->title, (s + song_index)->author);

    free(s); //Deallocazione dell'array

    return NO_ERR;
}
