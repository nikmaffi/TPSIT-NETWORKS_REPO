/*
 * Esercizio-5
 * 
 * File CSV (Comma Separated Value).
 * Programma che, letto un file csv contenente dei brani musicali, propone a caso uno di essi.
 * 
 * file song.h -> contiene i prototipi delle funzioni
 *
 * Autore:   Nicolò Maffi
 * Data:     22/10/2020
*/

#include <stdio.h> //Per il tipo FILE
#include <string.h> //Per strtok()
#include <stdlib.h> //Per rand() e srand() e calloc()
#include <time.h> //Per time()

#ifndef _SONG_H_
#define _SONG_H_

#ifdef _cplusplus
extern "C" {
#endif

#define STR_SIZE 256 //Costante che indica il numero massimo di caratteri di una stringa

//Tipo song
typedef struct t_song
{
    int index; //Indice del brano
    char title[STR_SIZE]; //Titolo del brano
    char author[STR_SIZE]; //Nome dell'autore
}song;

/*Funzione che legge da un file csv dei dati (titoli di brani musicali) e li carica in s
  PARAMETRI: filename = nome del file da cui leggere
             s = puntatore a song, dove si vogliono caricare i dati
  RETURN: 1 se l'operazione è riuscita, 0 altrimenti */
char reading(const char *filename, song *s);

/*Funzione che conta le linee di un file
  PARAMETRI: filename = nome del file dove si vogliono contare le righe
  RETURN: numero delle linee del file se l'operazione è riuscita, 0 altrimenti*/
int linecount(const char *filename);

/*Funzione che stampa la lista di canzoni s in ordine casuale su stream
  PARAMETRI: s = array di canzoni da stampare in ordine casuale
             dim = dimensione dell'array
             stream = stream su cui si vuole stampare la lista*/
void printsong(song *s, int dim, FILE* stream);

#ifdef _cplusplus
}
#endif

#endif //_SONG_H_