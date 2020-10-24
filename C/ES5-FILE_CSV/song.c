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

    //Viene controllato se s punta a null
    if(s == NULL)
        return 0;

    //Viene controllato se è possibile effettuare la lettura sul file
    if((fp = fopen(filename, "rt")) == NULL)
        return 0;

    //Viene letto il file per intero fino alla fine
    for(int k = 0; fgets(str, STR_SIZE, fp) != NULL; k++) //Lettura di una linea dal file
    {
        //strtok spezza una stringa utilizzando i caratteri delimitatori
        //Esempio: delimitatore = " " la stringa "hello world" verrà spezzata in 2 sottostringhe "hello" e "world"

        sscanf(strtok(str, ",\n"), "%lu", &((s + k)->index)); //Memorizzazione dell'indice del brano
        strncpy((s + k)->title, strtok(NULL, ",\n"), STR_SIZE); //Memorizzazione del titolo del brano
        strncpy((s + k)->author, strtok(NULL, ",\n"), STR_SIZE); //Memorizzazione dell'autore
    }

    fclose(fp); //Chiusura del file

    return 1;
}

unsigned long linecount(const char *filename)
{
    FILE *fp; //Stream collegato al file
    unsigned long line; //Variabile che conta le linee
    char byte; //Singolo byte letto dal file

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