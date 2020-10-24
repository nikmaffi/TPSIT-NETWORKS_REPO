/*
 * stack.h
 * 
 * Implementazione di uno stack (L.I.F.O.) in C
 *
 * Autore:   Nicolò Maffi
 * Data:     16/05/2020
*/

#include <stdio.h> //Per size_t
#include <stdlib.h> //Per calloc

#ifndef _STACK_H_
#define _STACK_H_

#ifdef __cplusplus
extern "C" {
#endif

typedef struct node_t //Tipo node -> rappresenta una cella dello stack
{
    int value; //Valore del nodo
    struct node_t *prev; //Puntatore del nodo precedente
}node;

typedef node* stack; //Tipo stack -> coincide con il puntatore alla cima dello stack

/*Funzionne che inizializza lo stack
  RETURN: stack inizializzato*/
stack initstack();

/*Funzione di push -> inserimento di un dato nello stack
  PARAMETRI: s = puntatore allo stack su cui si vuole effettuare la push
             value = valore che si vuole far assumere al nodo
  RETURN: 1 se loperazione è riuscita, 0 altrimenti*/
short push(stack *s, int value);

/*Funzione di pop -> rimozione di un dato dallo stack
  PARAMETRI: s = puntatore allo stack su cui si vuole effettuare la pop
             value = valore del nodo che ritornerà la pop
  RETURN: 1 se loperazione è riuscita, 0 altrimenti*/
short pop(stack *s, int *value);

/*Funzione stackdim -> funzione che calcola la dimensione dello stack
  PARAMETRI: s = puntatore allo stack su cui si vuole effettuare il calcolo della dimensione
  RETURN: dimensione dello stack se loperazione è riuscita, 0 altrimenti*/
size_t stackdim(stack *s);

#ifdef __cplusplus
}
#endif

#endif //_STACK_H_