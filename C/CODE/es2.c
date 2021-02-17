#include <stdio.h>
#include <stdlib.h>

/*
Scrivere una funzione che inverta una coda, ovvero produca una coda invertendo l’ordine
degli elementi della coda di partenza. Suggerimento: utilizzare una pila.
*/

typedef struct node_t //Tipo node -> rappresenta una cella della coda
{
    int value; //Valore del nodo
    struct node_t *next; //Puntatore del nodo successivo
}node;

typedef node* stack; //Tipo stack -> coincide con il puntatore alla cima dello stack

typedef struct queue_t //Tipo coda
{
    node* tail; //Puntatore all'ultima cella della coda
    node* head; //Puntatore alla prima cella della coda
}queue;


short push(stack *s, int value)
{
    node *tmp = NULL; //Puntatore di supporto

    if(s == NULL) //Controllo della validità del puntatore allo stack
        return 0;

    tmp = *s;
    *s = (node *)calloc(1, sizeof(node)); //Creazione di un nuovo nodo, puntato da top
    (*s)->value = value; //Impostazione del valore del nodo
    (*s)->next = tmp; //Collegamento tra il nodo appena creato e quello precedente

    return 1;
}

short pop(stack *s, int *value)
{
    node *tmp = NULL; //Puntatore di supporto

    //Controllo della validità dei puntatori passati come parametri
    //Se il il puntatore top è nullo lo stack è vuoto -> non si può effettuare la pop
    if(s == NULL || value == NULL || *s == NULL)
        return 0;

    tmp = *s;
    *value = (*s)->value; //Impostazione del valore che restituirà la pop
    *s = (*s)->next; //Il puntatore top ora punta al nodo precedente
    free(tmp); //Deallocazione del nodo in cima allo stack

    return 1;
}

short enqueue(queue *q, int value)
{
    node *tmp = NULL; //Puntatore di supporto

    if(q == NULL) //Controllo della validità del puntatore alla coda
        return 0;

    tmp = (node *)calloc(1, sizeof(node)); //Creazione di un nuovo nodo
    tmp->value = value; //Impostazione del valore del nodo

    if(q->tail != NULL) //Se tail non è null (non è la prima operazione di accodamento) *
        q->tail->next = tmp; //* viene collegato il nodo precedente a quello nuovo

    q->tail = tmp; //tail ora punta al nuovo nodo (la coda si estende)

    if(q->head == NULL) //Se head è null (è la prima operazione di accodamento) *
        q->head = q->tail; //head punta alla stessa cella puntata da tail

    return 1;
}

short dequeue(queue *q, int *value)
{
    node *tmp = NULL; //Puntatore di supporto

    //Controllo della validità dei puntatori passati come parametri
    //Se il il puntatore head è nullo la coda è vuota -> non si può effettuare l'estrazione
    if(q == NULL || value == NULL || q->head == NULL)
        return 0;

    tmp = q->head;
    *value = q->head->value; //Impostazione del valore che restituirà l'estrazione
    q->head = q->head->next; //Il puntatore head ora punta al nodo successivo (la coda si riduce)
    free(tmp); //Deallocazione del nodo sulla cima della coda

    if(q->head == NULL) //Se head è nullo (ultima operazione di estrazione possibile) *
        q->tail = q->head; //* head punta alla stessa cella puntata da tail

    return 1;
}

queue initqueue()
{
    queue q;

    q.head = NULL; //Il puntatore alla base della coda è nullo per l'inizializzazione
    q.tail = NULL; //Il puntatore alla cima della coda è nullo per l'inizializzazione

    return q;
}

void reverseQueue(queue* qSrc, queue* qDst)
{
    stack s = NULL;
    int el = 0;

    while(dequeue(qSrc, &el))
        push(&s, el);

    while(pop(&s, &el))
        enqueue(qDst, el);
}

int main()
{
    queue q1 = initqueue(), q2 = initqueue();
    int num = 0;

    printf("CODA IN ORDINE INVERSO\n\n");

    printf("Inserire i numeri in serie (inserire un carattere per terminare):\n");
    while(scanf("%d", &num) > 0)
        enqueue(&q1, num);

    reverseQueue(&q1, &q2);

    printf("\nContenuto della coda invertita: ");
    while(dequeue(&q2, &num))
        printf("[%d]", num);

    return 0;
}