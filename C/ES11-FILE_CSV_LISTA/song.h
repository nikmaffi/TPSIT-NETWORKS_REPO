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

typedef struct node_t
{
    song value;
    struct node_t* next;
}Node;

typedef Node* Playlist;

Playlist initPlaylist();
int playlistDim(Playlist *l);
char push(Playlist *l, song value);
char pop(Playlist *l, song value);

/*Funzione che legge da un file csv dei dati (titoli di brani musicali) e li carica in s
  PARAMETRI: filename = nome del file da cui leggere
             s = puntatore a song, dove si vogliono caricare i dati
  RETURN: 1 se l'operazione è riuscita, 0 altrimenti */
char reading(const char *filename, Playlist *pl);

/*Funzione che stampa la lista di canzoni s in ordine casuale su stream
  PARAMETRI: s = array di canzoni da stampare in ordine casuale
             dim = dimensione dell'array
             stream = stream su cui si vuole stampare la lista*/
void printsong(Playlist *pl, FILE* stream);

#ifdef _cplusplus
}
#endif

#endif //_SONG_H_