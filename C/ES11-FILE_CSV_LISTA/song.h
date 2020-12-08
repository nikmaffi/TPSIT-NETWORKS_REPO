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

//Struttura che rappresenta un nodo
typedef struct node_t
{
    song value; //Valore contenuto nel nodo
    struct node_t* next; //Indirizzo di memoria del nodo successivo
}Node;

//Tipo lista
typedef Node* Playlist;

//Funzione che inizializza la lista
Playlist initPlaylist();

//Funzione che restituisce la dimensione della lista
int playlistDim(Playlist *l);

//Funzione che effettua la push sulla lista
char push(Playlist *l, song value);

//Funzione che effettua la pop sulla lista
char pop(Playlist *l, song value);

//Funzione che legge da un file csv dei dati (titoli di brani musicali) e li carica in s
char reading(const char *filename, Playlist *pl);

//Funzione che stampa la lista di canzoni s in ordine casuale su stream
void printsong(Playlist *pl, FILE* stream);

#ifdef _cplusplus
}
#endif

#endif //_SONG_H_