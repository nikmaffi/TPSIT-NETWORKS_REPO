/*
 * Esercizio-1
 * 
 * Programma che calcola il numero di contagiati da COVID-19
 *
 * Autore:   Nicolò Maffi
 * Data:     01/10/2020
*/

#include <stdio.h> //Per funzioni di input output
#include <stdlib.h> //Per calloc
#include <math.h> //Per log

#define NO_ERR 0 //Costante che indica una corretta esecuzione
#define PARAM_ERR 1 //Costante che indica un errore sulla chiamata del programma
#define PARSE_ERR 2 //Costante che indica un errore sull'interpretazione dei paramatri
#define ALLOC_ERR 3 //Costante che indica un errore di allocazione

int main(int argc, const char **argv, const char **envp)
{
    float r = 0.0; //Parametro che indica il contagio esponenziale
    float *contagi_gior = NULL; //Array che conterrà il numero di contagiati in ogni giorno
    unsigned giorni = 0; //Numero di giorni in cui tutti saranno contagiati
    unsigned n_alunni = 0; //Numero di alunni contagiati

    if(argc != 3) //La chiamata del programma deve avvenire con tre paramatri
    {
        printf("\nErrore: Numero invalido di parametri.\n\n");

        printf("SYNOPSIS\n");
        printf("\t%s  parametro_contagi  numero di alunni\n\n", argv[0]);

        return PARAM_ERR;
    }

    //Controllo validità dei parametri mediante sscanf()
    if(!sscanf(argv[1], "%f", &r) || !sscanf(argv[2], "%u", &n_alunni))
    {
        printf("\nErrore: Non sono stati inseriri dei numeri.\n\n");

        return PARSE_ERR;
    }

    //Formula del cambiamento di base dei logaritmi -> calcolo numero di giorni
    //Viene aggiunto 1 perchè il primo giorno vi è già un contagiato
    giorni = log(n_alunni) / log(r) + 1;

    if(giorni <= 0) //Se il numero di giorni è <= 0 non si può allocare il vettore
    {
        printf("\nErrore: Impossibile eseguire la procedura.\n\n");
        return ALLOC_ERR;
    }

    contagi_gior = (float *)calloc(giorni, sizeof(float)); //Allocazione dell'array

    contagi_gior[0] = 1; //Un contagiato dal primo girno
    for(int k = 1; k < giorni; k++)
        contagi_gior[k] = contagi_gior[k - 1] * r; //Calcolo dei contagiati in ogni giorno

    printf("\nLa classe verra' contagiata in %u giorni.\n\n", giorni);
    printf("Tabella dei contagi durante i giorni:\n");
    for(int k = 0; k < giorni; k++)  //Stampa dell'array
        printf("giorno %5d: %10.0f persone contagiate\n", k + 1, contagi_gior[k]);
    printf("\n");

    free(contagi_gior); //Deallocazione array

    return NO_ERR;
}