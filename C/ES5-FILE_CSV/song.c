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

char reading(const char *filename, song *s)
{
    FILE *fp; //Stream collegato al file
    char str[STR_SIZE]; //Stringa letta dal file

    //Controllo validità dei parametri
    if(!s || !filename)
        return 0;

    //Viene controllato se è possibile effettuare la lettura sul file
    if((fp = fopen(filename, "rt")) == NULL)
        return 0;

    //Viene letto il file per intero fino alla fine
    for(int k = 0; fgets(str, STR_SIZE, fp) != NULL; k++) //Lettura di una linea dal file
    {
        //strtok spezza una stringa utilizzando i caratteri delimitatori
        //Esempio: delimitatore = " " la stringa "hello world" verrà spezzata in 2 sottostringhe "hello" e "world"

        sscanf(strtok(str, ",\n"), "%d", &((s + k)->index)); //Memorizzazione dell'indice del brano
        strncpy((s + k)->title, strtok(NULL, ",\n"), STR_SIZE); //Memorizzazione del titolo del brano
        strncpy((s + k)->author, strtok(NULL, ",\n"), STR_SIZE); //Memorizzazione dell'autore
    }

    fclose(fp); //Chiusura del file

    return 1;
}

int linecount(const char *filename)
{
    FILE *fp; //Stream collegato al file
    int line; //Variabile che conta le linee
    char byte; //Singolo byte letto dal file
    
    //Controllo validità dei parametri
    if(!filename)
        return 0;

    //Viene controllato se è possibile effettuare la lettura sul file
    if((fp = fopen(filename, "rt")) == NULL)
        return 0;

    //Viene letto il file per intero fino alla fine
    for(line = 0; (byte = fgetc(fp)) != EOF;)
    {
        if(byte == '\n') //Se byte è uaguale a \n viene incrementato il numero di linee
            line++;
    }

    fclose(fp); //Chiusura del file

    //Se è stata letta almeno una linea incremento di uno il conteggio delle linee
    return (line > 0) ? line + 1 : line;
}

void printsong(song *s, int dim, FILE* stream)
{
    int pos = 0; //posizione scelta a random
    song *supp = (song *)calloc(dim, sizeof(song)); //Array di supporto
    int last = dim - 1; //Ultima posizione utile

    //Controllo validità dei parametri
    if(!s || !stream || dim <= 0)
        return;

    //Il seme per il generatore di numeri casuali viene inizializzato con l'orario del pc
    srand(time(NULL));

    //Copia di s in supp
    for(int k = 0; k < dim; k++)
        *(supp + k) = *(s + k);

    printf("\nOrdine dei brani consigliato:\n\n");

    //Posizionamento a random
    while(last >= 0)
    {
        //Se last è all'ultima posizione -> stampo solamente l'unico elemento rimasto
        if(last == 0)
        {
            fprintf(stream, "%d\n%s\n%s\n\n", (supp + last)->index, (supp + last)->title, (supp + last)->author);
            break;
        }

        //Scelta a random della posizione
        pos = rand() % (last + 1);
        //Stampa della canzone in posizione pos fra gli elementi rimasti
        fprintf(stream, "%d\n%s\n%s\n\n", (supp + pos)->index, (supp + pos)->title, (supp + pos)->author);

        //Se non è l'ultima posizione shifto gli elementi validi rimasti
        if(pos < last)
        {
            //Operazione di shift -> per eliminare dall'array la canzone già stampata
            for(int k = pos + 1; k <= last; k++)
                *(supp + k - 1) = *(supp + k);
        }

        last--;
    }
    
    free(supp); //Rimozione dall'heap dell'array

    return;
}
