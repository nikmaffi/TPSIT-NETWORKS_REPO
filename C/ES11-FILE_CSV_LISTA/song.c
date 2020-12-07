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
    Playlist l = NULL;

    return l;
}

int playlistDim(Playlist *l)
{
    int dim = 1;
    Node *pt;

    if(!l)
        return 0;

    if(!(*l))
        return 0;

    pt = *l;
    while(pt->next != NULL)
    {
        dim++;
        pt = pt->next;
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
        *l = (Node *)calloc(1, sizeof(Node));
        (*l)->value = value;
        (*l)->next = NULL;
    }
    else
    {
        pt = *l;
        while(pt->next != NULL)
            pt = pt->next;

        pt->next = (Node *)calloc(1, sizeof(Node));
        pt->next->value = value;
        pt->next->next = NULL;
    }

    return 1;
}

char pop(Playlist *pl, song value)
{
    Node* pt;
    int dim = 0;

    if(!pl)
        return 0;

    if(!(*pl))
        return 0;

    dim = playlistDim(pl);

    for(int k = 0; k < dim - 1; k++)
        pt = pt->next;

    free(pt->next);
    pt->next = NULL;

    return 1;
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
        printf("%d - ", playlistDim(pl));
    }

    fclose(fp); //Chiusura del file

    return 1;
}

void printsong(Playlist *pl, FILE* stream)
{
    int dim = playlistDim(pl);
    int *arr;
    int last = dim - 1;
    int pos = 0;
    Node *pt;

    if(!pl || !stream)
        return;

    if(dim <= 0)
        return;

    arr = (int*)calloc(dim, sizeof(int));

    for(int k = 0; k < dim; k++)
        *(arr + k) = k;

    srand(time(NULL));

    fprintf(stream, "\nOrdine dei brani consigliato:\n\n");

    //Posizionamento a random
    while(last >= 0)
    {
        pt = *pl;

        if(last == 0)
        {
            for(int k = 0; k < *(arr + pos); k++)
                pt = pt->next;

            fprintf(stream, "%d\n%s\n%s\n\n", pt->value.index, pt->value.title, pt->value.author);
            break;
        }

        pos = rand() % (last + 1);

        for(int k = 0; k < *(arr + pos); k++)
            pt = pt->next;

        fprintf(stream, "%d\n%s\n%s\n\n", pos, pt->value.index, pt->value.title, pt->value.author);

        if(pos < last)
        {
            for(int k = pos + 1; k <= last; k++)
                *(arr + k - 1) = *(arr + k);
        }

        last--;
    }

    return;
}