/*
 * Esercizio-5
 * 
 * File CSV (Comma Separated Value).
 * Programma che, letto un file csv contenente dei brani musicali, propone a caso uno di essi.
 * 
 * file song.c -> contiene le implementazioni delle funzioni dichiarate in song.h
 *
 * Autore:   Nicolò Maffi
 * Data:     22/10/2020
*/

#include "song.h" //File che contiene i prototipi

Playlist initPlaylist()
{
    Playlist l = NULL; //All'inizio il puntatore alla lista punta a NULL

    return l;
}

int playlistDim(Playlist *l)
{
    /*La dimensione parte da 1 poichè se è presente solo un nodo la condizione del while
    non verrà eseguita e quindi dim sarà 0*/
    int dim = 1; //Dimensione delle lista
    Node *pt;

    if(!l)
        return 0;

    if(!(*l))
        return 0;

    //Scorrimento totale della lista
    pt = *l;
    while(pt->next != NULL)
    {
        dim++; //Incremento la dimensione
        pt = pt->next; //ilo puntatore punta al nodo successivo
    }

    return dim;
}

char push(Playlist *l, song value)
{
    Node *pt;

    if(!l)
        return 0;
    
    if(!(*l))
    {
        //Se non è presente nessun nodo il puntatore head viene allocato
        *l = (Node *)calloc(1, sizeof(Node));
        (*l)->value = value;
        (*l)->next = NULL;
    }
    else
    {
        /*Se sono presenti più di un nodo scorro la lista fino all'ultimo nodo
        ed alloco lo spazio*/
        pt = *l;
        while(pt->next != NULL)
            pt = pt->next;

        pt->next = (Node *)calloc(1, sizeof(Node));
        pt->next->value = value;
        pt->next->next = NULL;
    }

    return 1;
}

song pop(Playlist *pl)
{
    Node* pt;
    song c = {-1, "", ""};
    int dim = 0;

    if(!pl)
        return c;

    if(!(*pl))
        return c;

    dim = playlistDim(pl); //Calcolo della dimesnione per scorrere la lista

    //Scorro la lista fino al penultimo nodo
    if(dim == 1)
    {
        pt = *pl;
        c.index = pt->value.index;
        strncpy(c.title, pt->value.title, STR_SIZE);
        strncpy(c.author, pt->value.author, STR_SIZE);
        free(pt); //Deallocazione dell'ultimo nodo
        pt = NULL; //ora il penultimo nodo punta a null

        return c;
    }

    pt = *pl;
    for(int k = 0; k < dim - 1; k++)
        pt = pt->next;

    c.index = pt->next->value.index;
    strncpy(c.title, pt->next->value.title, STR_SIZE);
    strncpy(c.author, pt->next->value.author, STR_SIZE);
    free(pt->next); //Deallocazione dell'ultimo nodo
    pt->next = NULL; //ora il penultimo nodo punta a null

    return c;
}

char reading(const char *filename, Playlist *pl)
{
    FILE *fp; //Stream collegato al file
    char str[STR_SIZE]; //Stringa letta dal file
    song s;

    //Controllo validità dei parametri
    if(!pl || !filename)
        return 0;

    //Viene controllato se è possibile effettuare la lettura sul file
    if((fp = fopen(filename, "rt")) == NULL)
        return 0;

    //Viene letto il file per intero fino alla fine
    for(int k = 0; fgets(str, STR_SIZE, fp) != NULL; k++) //Lettura di una linea dal file
    {
        //strtok spezza una stringa utilizzando i caratteri delimitatori
        //Esempio: delimitatore = " " la stringa "hello world" verrà spezzata in 2 sottostringhe "hello" e "world"
        sscanf(strtok(str, ",\n"), "%d", &(s.index)); //Memorizzazione dell'indice del brano
        strncpy(s.title, strtok(NULL, ",\n"), STR_SIZE); //Memorizzazione del titolo del brano
        strncpy(s.author, strtok(NULL, ",\n"), STR_SIZE); //Memorizzazione dell'autore
        push(pl, s);
    }

    fclose(fp); //Chiusura del file

    return 1;
}

void printsong(Playlist *pl, FILE* stream)
{
    int dim = playlistDim(pl); //Dimensione della lista
    int *arr; //Arrai contenente gli indici possibili
    int last = dim - 1; //Ultima posizione utile
    int pos = 0; //posizione dell'array scelta a random
    Node *pt; //Nodo di supporto

    if(!pl || !stream)
        return;

    if(dim <= 0)
        return;

    arr = (int*)calloc(dim, sizeof(int));

    //Riempimento dell'array con gli indici da 0 a dim - 1
    for(int k = 0; k < dim; k++)
        *(arr + k) = k;

    srand(time(NULL)); //Inizializzazione del seme per generare i numeri pseudo casuali

    fprintf(stream, "\nOrdine dei brani consigliato:\n\n");

    //Posizionamento a random
    while(last >= 0)
    {
        //Il puntatore di supporto parte tutte le volte dall'inizio
        pt = *pl;

        //Se last è all'ultima posizione -> stampo solamente l'unico elemento rimasto
        if(last == 0)
        {
            for(int k = 0; k < *arr; k++)
                pt = pt->next;

            fprintf(stream, "%d\n%s\n%s\n\n", pt->value.index, pt->value.title, pt->value.author);
            break;
        }

        //Scelta a random della posizione
        pos = rand() % (last + 1);
        //Scorrimento della lista sino all nodo di indice contenuto nell'array all'indice scelto a random
        for(int k = 0; k < *(arr + pos); k++)
            pt = pt->next;

        fprintf(stream, "%d\n%s\n%s\n\n", pt->value.index, pt->value.title, pt->value.author);

        //Se non è l'ultima posizione shifto gli elementi validi rimasti
        //eliminando cos' l'indice già tirato a random
        if(pos < last)
        {
            for(int k = pos + 1; k <= last; k++)
                *(arr + k - 1) = *(arr + k);
        }

        last--;
    }

    free(arr); //Rimozione dell'heap dell'array di supporto

    //Deallocazione della lista
    for(int k = 0; k < dim; k++)
        printf("%d ", pop(pl).index);

    return;
}