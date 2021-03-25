/*
ES1
Scrivere il seguente programma che crea e stampa una lista. Studiarne il funzionamento ed inserire i
commenti necessari a spiegarlo.
*/

#include <stdio.h>
#include <stdlib.h>

struct El
{
    int valore;
    struct El* next;
};

int main()
{
    int n;
    struct El* lista;
    struct El* l;
    lista=NULL; /* inizializzazione della lista a NULL, il puntatore head punta a NULL */

    do
    {
        printf("Inserisci un naturale o -1 per terminare\n");
        scanf("%d",&n);
        if (n>=0)
        {
            if (lista==NULL) /* La lista è vuota (il primo puntatore punta a NULL) */
            {
                /*
                Alloco il primo nodo che verrà puntata da head (lista),
                il puntatore di supporto l punta anch'esso al primo nodo
                */

                lista = (struct El*) malloc(sizeof(struct El));

                l = lista;
            }
            else /* la lista non è vuota (è presenta almeno un nodo) */
            {
                /*
                Si alloca una zona di memoria che verrà puntata dal puntatore next dell'ultimo elemento,
                il puntatore di supporto l punta sempre all'ultimo elemento
                */

                l->next = (struct El*) malloc(sizeof(struct El));

                l = l->next;
            }
            l->valore = n; /* assegnazione del valore del nodo appena allocato */
            l->next = NULL; /* il puntatore next del nodo appena creato viene impostato a null */
        }
    } while (n>=0);

    l=lista; /* Il puntatore di supporto ora punta al primo nodo della lista */
    printf("numeri inseriti: ");
    while (l!=NULL)
    {
        printf("%d - %p \n",l->valore, l->next);
        l=l->next; /* il puntatore l punta al nodo successivo */
    }
    printf("\n");
    return 0;
}