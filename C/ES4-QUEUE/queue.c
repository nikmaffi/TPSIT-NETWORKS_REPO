/*
 * queue.c
 * 
 * Implementazione delle funzioni dichiarate nel file queue.h
 *
 * Autore:   Nicolò Maffi
 * Data:     16/05/2020
*/

#include "queue.h"

queue initqueue()
{
    queue q;

    q.base = NULL; //Il puntatore alla base della coda è nullo per l'inizializzazione
    q.top = NULL; //Il puntatore alla cima della coda è nullo per l'inizializzazione

    return q;
}

short enqueue(queue *q, int value)
{
    node *tmp = NULL; //Puntatore di supporto

    if(q == NULL) //Controllo della validità del puntatore alla coda
        return 0;

    tmp = (node *)calloc(1, sizeof(node)); //Creazione di un nuovo nodo
    tmp->value = value; //Impostazione del valore del nodo

    if(q->base != NULL) //Se base non è null (non è la prima operazione di accodamento) *
        q->base->next = tmp; //* viene collegato il nodo precedente a quello nuovo

    q->base = tmp; //base ora punta al nuovo nodo (la coda si estende)

    if(q->top == NULL) //Se top è null (è la prima operazione di accodamento) *
        q->top = q->base; //top punta alla stessa cella puntata da base

    return 1;
}

short dequeue(queue *q, int *value)
{
    node *tmp = NULL; //Puntatore di supporto

    //Controllo della validità dei puntatori passati come parametri
    //Se il il puntatore top è nullo la coda è vuota -> non si può effettuare l'estrazione
    if(q == NULL || value == NULL || q->top == NULL)
        return 0;

    tmp = q->top;
    *value = q->top->value; //Impostazione del valore che restituirà l'estrazione
    q->top = q->top->next; //Il puntatore top ora punta al nodo successivo (la coda si riduce)
    free(tmp); //Deallocazione del nodo sulla cima della coda

    if(q->top == NULL) //Se top è nullo (ultima operazione di estrazione possibile) *
        q->base = q->top; //* top punta alla stessa cella puntata da base

    return 1;
}

size_t queuedim(queue *q)
{
    node *tmp = NULL; //Puntatore di supporto
    size_t dim = 0; //Dimensione della coda

    //Controllo della validità dei puntatori passati come parametri
    //Se il il puntatore top è nullo la coda è vuota -> non ha dimensione
    if(q == NULL || q->top == NULL)
        return 0;

    tmp = q->top;
    for(dim = 0; tmp != NULL; dim++) //Viene incrementata la dimensione della coda fino a quando tmp è nullo
        tmp = tmp->next; //tmp punta alla cella successiva

    return dim;
}