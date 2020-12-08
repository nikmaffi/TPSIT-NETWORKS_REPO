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
#include "song.h" //Per il tipo song

#define NO_ERR 0 //Costante che indica una corretta esecuzione
#define PARAM_ERR 1 //Costante che indica un errore sulla chiamata del programma
#define FILE_ERR 2 //Costante che indica un errore di un operazione sul file

int main(int argc, const char **argv, const char **envp)
{
    Playlist pl = initPlaylist(); //Inizializzazione della playlists

    if(argc != 2) //La chiamata al programma deve avvenire con 2 paramatri
    {
        printf("\nErrore: Numero invalido di parametri.\n\n");

        printf("SYNOPSIS\n");
        printf("\t%s  file_csv\n\n", argv[0]);

        return PARAM_ERR;
    }

    //Viene controllato se è possibile effettuare una lettura sul file
    if(!reading(argv[1], &pl))
    {        
        printf("\nErrore: Non e' possibile effettuare la lettura del file %s.\n\n", argv[1]);

        return FILE_ERR;
    }

    printsong(&pl, stdout); //Stampa sullo schermo delle canzoni in disordine

    return NO_ERR;
}
