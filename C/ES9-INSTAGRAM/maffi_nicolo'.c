/*
 * Nel file instagram.csv trovate alcuni dati esportati dal vostro account Instagram. Ogni riga del file corrisponde ad un post
 * pubblicato nel 2020 e su ogni riga trovate in ordine: mese, giorno del mese, identificativo del post, numero di like.

Scrivere un programma in C, che faccia uso della allocazione dinamica e della aritmetica dei puntatori (requisiti obbligatori):
il programma deve richiedere all'utente il nome di un mese e poi deve fornire in output il numero di post di quel mese ed il
numero totale di like ricevuto durante quel mese.

NOTA: non è possibile accedere agli elementi degli array utilizzando le parentesi [ ].

CONSEGNARE SOLTANTO IL FILE SORGENTE .C ADEGUATAMENTE COMMENTATO. IL FILE .C DEVE AVERE NOME: COGNOME_NOME.c
 */

#include <stdio.h> //Per funzioni di input/output
#include <stdlib.h> //Per calloc()
#include <string.h> //Per manipolare le stringhe

#define STR_SIZE 256 //Numero massimo di caratteri per stringa

//Struttura che rappresenta una riga del file csv
typedef struct data_t{
    char mese[STR_SIZE]; //Mese di pubblicazione
    char giorno[STR_SIZE]; //Giorno di pubblicazione
    long idPost;
    long numLike; 
}Data;

//Funzione che conta il numero di linee in un file
//filename è il nome del file su cui si vuole leggere
//La funzione restituisce il numero di linee
long lineCount(const char *fileName);

//Funzione che legge i dati dal file csv e li carica nella struttora dt
//filename è il nome del file su cui si vuole leggere
//dt puntatore a struttura su cui si vogliono caricare i dati
//dim è la dimensione della struttura
//La funzione ritornerà 1 se l'operazione è antata a buon fine, altrimenti ritornerà 0
char readData(const char *fileName, Data *dt, long dim);

//Funzione che stampa sullo stream il numero di post ed il numero di like del mese indicato come parametro
//month -> mese
//dt puntatore a struttura su cui si vogliono caricare i dati
//dim è la dimensione della struttura
//stream -> stream dove si vogliono stampare i risultati
//La funzione ritornerà 1 se l'operazione è antata a buon fine, altrimenti ritornerà 0
char searchMonth(const char *month, Data *dt, long dim, FILE *stream);

int main(int argc, const char **argv, const char **envp) //Entry point
{
    Data *dt; //Puntatore a data che rappresenta l'array dove verrano caricai i dati
    long dim = 0;//Dimensione dell'array (corrisponde al numero di linee del file csv)

    //La chiamata al main deve avvenire con tre parametri
    //1 - nome del programma eseguibile (ovviamente)
    //2 - nome del file csv
    //3 - nome del mese di cui si vogliono stampare i dati
    if(argc != 3)
    {
        printf("\nErrore: chiamata al programma errata.\n\n");

        printf("USAGE: %s  [nome file csv]  [mese]\n\n", *(argv));
        return -1;
    }

    dim = lineCount(*(argv + 1)); //Conteggio delle linee nel file csv

    if(dim <= 0) //Non si può allocare dinamicamente un array da 0 o n < 0 celle 
        return -2;

    //A differenza di malloc calloc alloca le celle in memoria e le azzera
    dt = (Data *)calloc(dim, sizeof(Data)); //Allocazione dinamica dell'array

    //Controllo di eventuali errori sulla lettura e caricamento dei dati
    if(!readData(*(argv + 1), dt, dim))
    {
        printf("\nErrore: Non e' stato possibile leggere e caricare i dati del file %s.\n\n", *(argv + 1));
        return -3;
    }

    //Controllo di eventuali errori sulla stampa dei dati richiesti
    if(!searchMonth(*(argv+ 2), dt, dim, stdout))
    {
        printf("\nErrore: Non e' stato possibile effettuare la stampa dei dati richiesti.\n\n");
        return -4;
    }

    free(dt); //Rimozione dell'array dall'heap

    return 0;
}

long lineCount(const char *fileName)
{
    FILE *fp; //Stream collegato al file
    long line; //Variabile che tiene il numero di linee nel file
    char byte; //Singolo byte letto dal file
    
    //Controllo validità dei parametri
    if(!fileName)
        return 0;

    //Viene controllato se è possibile effettuare la lettura sul file
    if((fp = fopen(fileName, "rt")) == NULL)
        return 0;

    //Viene letto il file per intero fino alla fine
    for(line = 0; (byte = fgetc(fp)) != EOF;)
    {
        if(byte == '\n') //Se byte è uaguale a \n viene incrementato il numero di linee
            line++;
    }

    fclose(fp); //Chiusura del file

    //Se è stata letta almeno una linea incremento di uno il conteggio delle linee
    //Poichè se vi è solo una linea non è presente il carattere \n
    return (line > 0) ? line + 1 : line;
}

char readData(const char *fileName, Data *dt, long dim)
{
    FILE *fp; //Stream collegato al file
    char str[STR_SIZE]; //Singola linea letta dal file

    //Controllo validità dei parametri
    if(!dt || !fileName|| dim <= 0)
        return 0;

    //Viene controllato se è possibile effettuare la lettura sul file
    if((fp = fopen(fileName, "rt")) == NULL)
        return 0;

    //Viene letto il file line aper linea fino alla fine
    for(int k = 0; fgets(str, STR_SIZE, fp) != NULL && k < dim; k++) //Lettura di una linea dal file
    {
        //strtok spezza una stringa utilizzando i caratteri delimitatori
        //Esempio: delimitatore = " " la stringa "hello world" verrà spezzata in 2 sottostringhe "hello" e "world"

        //Dato che la prima linea contiene solo i titoli dei campi non la memorizzo
        if(k == 0)
            continue;

        //Utilizzo strncpy dato che non si può utilizzare direttamente l'assegnamento
        strncpy((dt + k)->mese, strtok(str, ","), STR_SIZE); //Memorizzazione del mese nella struttura
        strncpy((dt + k)->giorno, strtok(NULL, ","), STR_SIZE); //Memorizzazione del giorno nella struttura
        //Converto la stringa elaborata da strtok in long e la memorizzo nel campo apposito
        sscanf(strtok(NULL, ","), "%ld", &((dt + k)->idPost)); //Memorizzazione dell'id post
        sscanf(strtok(NULL, ","), "%ld", &((dt + k)->numLike));//Memorizzazione del numero di like
    }

    fclose(fp); //Chiusura del file

    return 1;
}

char searchMonth(const char *month, Data *dt, long dim, FILE *stream)
{
    long numdiPost = 0; //Variabile che conta il numero di post del mese
    long numdiLike = 0; //Variabile che conta il numero di like del mese

    //Controllo validità dei parametri
    if(!month || !dt || !stream || dim <= 0)
        return 0;

    //Itero su tutti gli elementi dell'array dt
    for(int k = 0; k < dim; k++)
    {
        //Se il mese presente nell'elemento corrente è uguale al mese dato in input*
        if(strcmp((dt + k)->mese, month) == 0)
        {
            numdiPost++; //*Conto il numero di post
            numdiLike += (dt + k)->numLike; //Conteggio del numero di like
        }
    }

    //Stampa dei risultati
    if(numdiLike == 0 && numdiPost == 0)
    {
        fprintf(stream, "\nNon e' stata trovata nessuna corrispondenza.\n\n");
    }
    else
    {
        fprintf(stream, "\nNumero di post nel mese di %s: %ld", month, numdiPost);
        fprintf(stream, "\nNumero di like nel mese di %s: %ld\n\n", month, numdiLike);
    }        

    return 1;
}