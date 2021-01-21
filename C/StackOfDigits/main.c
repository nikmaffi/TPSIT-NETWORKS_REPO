#include <stdio.h>
#include <stdlib.h>

#define STR_SIZE 256

typedef struct node_t
{
    char value;
    struct node_t *prev;
}node;

typedef node* stack;

stack initstack()
{
    stack s = NULL; //Il puntatore alla cima dello stack è nullo per l'inizializzazione

    return s;
}

short push(stack *s, char value)
{
    node *tmp = NULL; //Puntatore di supporto

    if(s == NULL) //Controllo della validità del puntatore allo stack
        return 0;

    tmp = *s;
    *s = (node *)calloc(1, sizeof(node)); //Creazione di un nuovo nodo, puntato da top
    (*s)->value = value; //Impostazione del valore del nodo
    (*s)->prev = tmp; //Collegamento tra il nodo appena creato e quello precedente

    return 1;
}

short pop(stack *s, char *value)
{
    node *tmp = NULL; //Puntatore di supporto

    //Controllo della validità dei puntatori passati come parametri
    //Se il il puntatore top è nullo lo stack è vuoto -> non si può effettuare la pop
    if(s == NULL || value == NULL || *s == NULL)
        return 0;

    tmp = *s;
    *value = (*s)->value; //Impostazione del valore che restituirà la pop
    *s = (*s)->prev; //Il puntatore top ora punta al nodo precedente
    free(tmp); //Deallocazione del nodo in cima allo stack

    return 1;
}

size_t stackdim(stack *s)
{
    node *tmp = NULL; //Puntatore di supporto
    size_t dim = 0; //Dimensione dello stack

    //Controllo della validità dei puntatori passati come parametri
    //Se il il puntatore top è nullo lo stack è vuoto -> non ha dimensione
    if(s == NULL || *s == NULL)
        return 0;

    tmp = *s;
    for(dim = 0; tmp != NULL; dim++) //Viene incrementata la dimensione dello stack fino a quando tmp è nullo
        tmp = tmp->prev; //tmp punta alla cella precedente

    return dim;
}

int main(int argc, const char** argv, const char** envp)
{
    stack s = NULL;
    char number[STR_SIZE];
    unsigned stackDim = 0;
    char digit = 0;

    printf("Insert a number: ");
    scanf("%s", number);

    for(unsigned k = 0; *(number + k) != '\0'; k++)
        push(&s, *(number + k));

    stackDim = stackdim(&s);

    printf("\nNumber digits in reverse order:\n");
    for(unsigned k = 0; k < stackDim; k++)
    {
        pop(&s, &digit);
        printf("%c", digit);
    }

    return 0;
}