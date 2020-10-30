#include <stdio.h> //Per funzioni di input/output

#define NO_ERR 0 //Esecuzione corretta del programma
#define PARAM_ERR 1 //Esecuzione di un errore sulla chiamata del programma
#define FILE_ERR 2 //Esecuzione di un errore sull'apertura del file

int main(int argc, const char **argv, const char **envp)
{
    FILE *fp; //Puntatore a file su cui si andranno a leggere i parametri
    unsigned long citosine = 0, guanine = 0, adenine = 0, timine = 0; //Contatore di acidi nucleici
    char byte = 0; //Singolo byte letto da file

    //Controllo di eventuali errori sulla chiamata del programma
    if(argc != 2)
    {
        printf("\nErrore: Numero invalido di argomenti.\n\n");

        printf("SYNOPSIS\n");
        printf("\t%s  <rna_file>\n\n", argv[0]);

        return PARAM_ERR;
    }

    //Controllo di eventuali errori sull'apertura del file
    if(!(fp = fopen(argv[1], "rt")))
    {
        printf("\nErrore: Impossibile aprire il file %s.\n\n", argv[1]);

        return FILE_ERR;
    }

    //Si legge un byte ad ogni iterazione finchè non viene restituito EOF
    while((byte = fgetc(fp)) != EOF)
    {
        //Selezione che controllo di che tipo è il carattere letto
        //Incremento dei relativi contatori
        switch(byte)
        {
            case 'c':
                citosine++;
                break;

            case 'g':
                guanine++;
                break;

            case 'a':
                adenine++;
                break;

            case 't':
                timine++;
                break;
        }
    }

    fclose(fp); //Chiusura del file

    //Stampa dei risultati
    printf("\nNel codice RNA del file %s sono presenti:\n\n", argv[1]);
    printf("Citosine: %20d\n", citosine);
    printf("Guanine:  %20d\n", guanine);
    printf("Adenine:  %20d\n", adenine);
    printf("Timine:   %20d\n\n", timine);

    return NO_ERR;
}
