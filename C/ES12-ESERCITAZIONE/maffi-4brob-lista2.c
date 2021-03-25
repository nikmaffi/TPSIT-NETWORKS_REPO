/*
ES2
Modificare il programma sopra creando due funzioni: push per caricare la lista e stampa-lista per
stamparla.
*/

#include <stdio.h>
#include <stdlib.h>

struct El
{
    int valore;
    struct El* next;
};

char push(struct El* head, int value);
char printList(struct El* head);

int main()
{
    int n;
    struct El* lista;
    lista=NULL; /* inizializzazione della lista a NULL, il nodo (head) punta a NULL */

    do
    {
        printf("Inserisci un naturale o -1 per terminare\n");
        scanf("%d",&n);

        if(n>= 0)
            push(lista, n);
    } while (n>=0);

    printf("numeri inseriti:\n");
    printList(lista);
    printf("\n");
    return 0;
}

char push(struct El* head, int value)
{
    struct El* tmp;

    if(!head)
        return 0;

    if(!head) /* La lista è vuota (il primo puntatore punta a NULL) */
    {
        /*
        Alloco il primo nodo che verrà puntato da head,
        */

        head = (struct El*)calloc(1, sizeof(struct El));
        tmp = head; //Il puntatore di supporto viene fatto puntare alla prima cella della lista
    }
    else /* la lista non è vuota (è presenta almeno un nodo) */
    {
        /*
        Si scorre la lista fino a quando tmp punta all'ultima cella
        Si alloca una zona di memoria che verrà puntata dal puntatore next di tmp,
        il puntatore di supporto tmp punta ora all'ultimo elemento
        */
        tmp = head; //Il puntatore di supporto viene fatto puntare alla prima cella della lista
        while(tmp->next)
            tmp = tmp->next;

        tmp->next = (struct El*)calloc(1, sizeof(struct El));
        tmp = tmp->next;
    }

    tmp->valore = value; /* assegnazione del valore del nodo appena allocato */
    tmp->next = NULL; /* il puntatore next del nodo appena creato viene impostato a null */

    return 1;
}

char printList(struct El* head)
{
    if(!head) //lista vuota
        return 0;

    printf("%d\n", head->valore); //stampo il valore del nodo passato come parametro
    printList(head->next); //chiamo ricorsivamente la funzione con parametro il nodo successivo

    return 1;
}