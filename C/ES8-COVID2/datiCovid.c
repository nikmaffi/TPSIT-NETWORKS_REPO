#include "datiCovid.h"

int readLines(const char *fileName)
{
    //Funzione che conta quante righe ci sono nel file

    FILE *fp;
    char byte = 0;
    int lines = 0;

    if(!fileName) //Controllo validità filename
        return 0;

    if(!(fp = fopen(fileName, "rt"))) //Verifica esistenza del file
        return 0;

    while((byte = fgetc(fp)) != EOF) //Lettura byte per byte
    {
        if(byte == '\n')
            lines++;
    }

    fclose(fp);

    return (lines > 1) ? ++lines : lines;
}

int readFields(const char *fileName, DatiCovid *dc, int dim)
{
    //Funzione che legge il file linea per linea e memorizza i dati

    FILE *fp;
    char line[MAX_CHARS_LINE];

    if(!fileName || !dc || dim <= 0) //Controllo validità parametri
        return 0;

    if(!(fp = fopen(fileName, "rt"))) //Controllo esistenza del file
        return 0;

    //Lettura e memorizzazione di tutti i dati per ogni riga
    for(int k = 0; k < dim && fgets(line, MAX_CHARS_LINE, fp); k++)
    {
        strncpy((dc + k)->data, strtok(line, ","), STR_SIZE);
        strncpy((dc + k)->stato, strtok(NULL, ","), STR_SIZE);
        sscanf(strtok(NULL, ","), "%hd", &((dc + k)->codiceRegione));
        strncpy((dc + k)->denomRegione, strtok(NULL, ","), STR_SIZE);
        sscanf(strtok(NULL, ","), "%f", &((dc + k)->latitudine));
        sscanf(strtok(NULL, ","), "%f", &((dc + k)->longitudine));
        sscanf(strtok(NULL, ","), "%u", &((dc + k)->ricoveratiConSintomi));
        sscanf(strtok(NULL, ","), "%u", &((dc + k)->terapiaIntensiva));
        sscanf(strtok(NULL, ","), "%u", &((dc + k)->totOspedalizzati));
        sscanf(strtok(NULL, ","), "%u", &((dc + k)->isolamento));
        sscanf(strtok(NULL, ","), "%u", &((dc + k)->totPositivi));
        sscanf(strtok(NULL, ","), "%u", &((dc + k)->variazioneTotPositivi));
        sscanf(strtok(NULL, ","), "%u", &((dc + k)->nuoviPositivi));
        sscanf(strtok(NULL, ","), "%u", &((dc + k)->dismessiGuariti));
        sscanf(strtok(NULL, ","), "%u", &((dc + k)->deceduti));
        sscanf(strtok(NULL, ","), "%u", &((dc + k)->sospettiDiagnostici));
        sscanf(strtok(NULL, ","), "%u", &((dc + k)->screening));
        sscanf(strtok(NULL, ","), "%u", &((dc + k)->totaleCasi));
        sscanf(strtok(NULL, ","), "%u", &((dc + k)->tamponi));
        sscanf(strtok(NULL, ","), "%u", &((dc + k)->casiTestati));
    }

    fclose(fp);

    return 1;
}

int sortByTerapiaIntensiva(DatiCovid *dc, int dim)
{
    //Funzione che riordina l'array secondo i ricoverati della terapia intensiva
    //Viene utilizzato l'algoritmo del bubblesort

    DatiCovid tmp; //Variabile d'appoggio

    if(!dc || dim <= 0) //Controllo validità prametri
        return 0;

    for(int k = 0; k < dim; k++)
    {
        for(int j = 0; j < dim - 1 - k; j++)
        {
            if((dc + j)->terapiaIntensiva > (dc + j + 1)->terapiaIntensiva)
            {
                //Scambio dei valori
                tmp = *(dc + j);
                *(dc + j) = *(dc + j + 1);
                *(dc + j + 1) = tmp;
            }
        }
    }
}

void printDatiCovid(DatiCovid dc)
{
    //Funzione che stampa i dati di una singola riga

    printf("Data:                          %s\n", dc.data);
    printf("Stato:                         %s\n", dc.stato);
    printf("Codice Regione:                %s\n", dc.stato);
    printf("Denominazione Regione:         %s\n", dc.denomRegione);
    printf("Latitudine:                    %f\n", dc.latitudine);
    printf("Longitudine:                   %f\n", dc.longitudine);
    printf("Ricovarati Con Sintomi:        %u\n", dc.ricoveratiConSintomi);
    printf("Pazienti In Terapia Intensiva: %u\n", dc.terapiaIntensiva);
    printf("Pazienti Ospedalizzati:        %u\n", dc.totOspedalizzati);
    printf("Pazienti in isolamento:        %u\n", dc.isolamento);
    printf("Totale Positivi:               %u\n", dc.totPositivi);
    printf("Variazione Positivi:           %u\n", dc.variazioneTotPositivi);
    printf("Nuovi Positivi:                %u\n", dc.nuoviPositivi);
    printf("Dismessi Guariti:              %u\n", dc.dismessiGuariti);
    printf("Deceduti:                      %u\n", dc.deceduti);
    printf("Sospetti Diahnostici:          %u\n", dc.sospettiDiagnostici);
    printf("Casi Da Screening:             %u\n", dc.screening);
    printf("Casi Totali:                   %u\n", dc.totaleCasi);
    printf("Tamponi:                       %u\n", dc.tamponi);
    printf("Casi Testati:                  %u\n\n", dc.casiTestati);
}

int calcMaxMinTerapiaIntensiva(DatiCovid *dc, int dim, int maxNum, int minNum)
{
    //Controllo validità parametri
    if(!dc || dim <= 0 || maxNum <= 0 || maxNum > dim || minNum <= 0 || minNum > dim)
        return 0;

    //Calcolo e stampa del numero massimo di pazienti in terapia intensiva
    printf("\n%d Regioni con il maggior numero di pazienti in terapia intensiva:\n\n", maxNum);
    for(int k = dim - 1; k > dim - maxNum - 1; k--)
    {
        printDatiCovid(*(dc + k));
        
        if(k == dim - maxNum)
            continue;
        else
            printf("------------------------------------------------------------\n");
    }

    printf("-----------------------------------------------------------------------------------\n");
    printf("-----------------------------------------------------------------------------------\n");

    //Calcolo e stampa del numero minimo di pazienti in terapia intensiva
    printf("\n%d Regioni con il minor numero di pazienti in terapia intensiva:\n\n", minNum);
    for(int k = 1; k <= minNum; k++)
    {
        printDatiCovid(*(dc + k));
        
        if(k == minNum)
            continue;
        else
            printf("------------------------------------------------------------\n");
    }

    return 1;
}

int totPazientiTerapiaIntensiva(DatiCovid *dc, int dim)
{
    //Funzione che calcola il numero massimo di pazienti in terapia intensiva

    long long tot = 0;

    if(!dc || dim <= 0)
        return 0;

    for(int k = 0; k < dim; k++)
        tot += (dc + k)->terapiaIntensiva;

    printf("\n\nTotale pazienti in terapia intensiva: %lld\n\n", tot); //Stampa del calcolo

    return 1;
}