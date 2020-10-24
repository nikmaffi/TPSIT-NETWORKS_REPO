/*
 * queue.h
 * 
 * Implementazione di una coda (F.I.F.O.) in C
 *
 * Autore:   Nicolò Maffi
 * Data:     15/05/2020
*/

#include <stdio.h> //Per size_t
#include <stdlib.h> //Per calloc

#ifndef _QUEUE_H_
#define _QUEUE_H_

#ifdef __cplusplus
extern "C" {
#endif

typedef struct node_t //Tipo node -> rappresenta una cella della coda
{
    int value; //Valore del nodo
    struct node_t *next; //Puntatore del nodo successivo
}node;

typedef struct queue_t //Tipo coda
{
    node* base; //Puntatore alla prima cella della coda
    node* top; //Puntatore alla cella in cima alla coda
}queue;

/*Funzionne che inizializza la coda
  RETURN: coda inizializzata*/
queue initqueue();

/*Funzione di accodamento -> inserimento di un dato nella coda
  PARAMETRI: q = puntatore alla coda su cui si vuole effettuare l'accodamento
             value = valore che si vuole far assumere al nodo
  RETURN: 1 se loperazione è riuscita, 0 altrimenti*/
short enqueue(queue *q, int value);

/*Funzione di estrazione -> rimozione di un dato dalla coda
  PARAMETRI: q = puntatore alla coda su cui si vuole effettuare l'estrazione
             value = valore del nodo che ritornerà l'estrazione
  RETURN: 1 se loperazione è riuscita, 0 altrimenti*/
short dequeue(queue *q, int *value);

/*Funzione queuedim -> funzione che calcola la dimensione della coda
  PARAMETRI: q = puntatore alla coda su cui si vuole effettuare il calcolo della dimensione
  RETURN: dimensione della coda se loperazione è riuscita, 0 altrimenti*/
size_t queuedim(queue *q);

#ifdef __cplusplus
}
#endif

#endif //_QUEUE_H_