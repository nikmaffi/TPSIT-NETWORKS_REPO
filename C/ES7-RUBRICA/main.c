#include <stdio.h>
#include "rubrica.h"

#define INSERT_NEW_CONTACT 1 //Costante che indica l'opzione 1
#define SEARCH_CONTACT 2 //Costante che indica l'opzione 2
#define PRINT_PHONEBOOK 3 //Costante che indica l'opzione 3
#define EXIT_PROGRAM 4 //Costante che indica l'opzione 4

int main(int argc, const char **argv, const char **envp)
{
    Rubrica r; //Rubrica
    Contatto c; //Singolo contatto
    int cmd = 0; //Comando impartito dall'utente

    initRubrica(&r); //Inizializzazione della rubrica
    
    //Eseguo il programma finchè l'utente non inserisce 4
    do
    {
        printf("\n\nRUBRICA TELEFONICA\n\n");

        printf("\t+------------------------------+\n"
               "\t|             MENU'            |\n"
               "\t+------------------------------+\n"
               "\t| 1.Inserire un nuovo contatto |\n"
               "\t| 2.Cercare un contatto        |\n"
               "\t| 3.Stampare la rubrica        |\n"
               "\t| 4.Chiudi programma           |\n"
               "\t+------------------------------+\n\n");

        printf("Comando: ");
        if(!scanf("%d", &cmd)) //Input dell'utente con controllo di eventuali errori
        {
            printf("Errore di input.");
        }

        scanf("%*c"); //Pulizia del buffer di input

        switch(cmd)
        {
            //Inserire nuovo contatto
            case INSERT_NEW_CONTACT:
                printf("\nInserire il nome: ");
                fgets(c.nome, MAX_NAME_CHARS, stdin); //Input del nome

                printf("Inserire il numero: ");
                fgets(c.numero, MAX_NUMBER_CHARS, stdin); //Input del numero

                if(!creaContatto(c.nome, c.numero, &r)) //Inserirmento del contatto della rubrica
                {
                    //Se la rubrica è piena viene stampato questo messaggio di errore
                    printf("\nErrore numero massimo di contatti raggiunto.");
                }
                break;

            case SEARCH_CONTACT:
                printf("\nInserire il nome da cercare: "); //Input del nome
                fgets(c.nome, MAX_NAME_CHARS, stdin);

                cercaContatto(c.nome, &r); //Ricerca del nome della rubrica
                break;

            case PRINT_PHONEBOOK:
                stampaRubrica(&r); //Stampa della rubrica
                break;

            case EXIT_PROGRAM:
                printf("\nChiusura programma in corso."); //Messaggio chiusura di programma
                break;

            default:
                printf("\n%d operazione non trovata.", cmd); //Errore di comando invalido
        }

        printf("\n\nPremere un tasto per continuare. "); //Messaggio di pausa
        getchar();
    }
    while(cmd != EXIT_PROGRAM);

    return 0;
}