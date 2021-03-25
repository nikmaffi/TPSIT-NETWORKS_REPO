#ifndef _DATICOVID_H_
#define _DATICOVID_H_

#include <stdio.h>
#include <string.h>

#ifdef _cplusplus
extern "C" {
#endif

#define STR_SIZE (1 << 8) //Dimensione di default di una stringa
#define MAX_CHARS_LINE (1 << 10) //Dimensione di default di una linea

//Struttura che rappresenta una singola linea
typedef struct DatiCovid_t
{
    char data[STR_SIZE];
    char stato[STR_SIZE];
    short codiceRegione;
    char denomRegione[STR_SIZE];
    float latitudine;
    float longitudine;
    unsigned ricoveratiConSintomi;
    unsigned terapiaIntensiva;
    unsigned totOspedalizzati;
    unsigned isolamento;
    unsigned totPositivi;
    unsigned variazioneTotPositivi;
    unsigned nuoviPositivi;
    unsigned dismessiGuariti;
    unsigned deceduti;
    unsigned sospettiDiagnostici;
    unsigned screening;
    unsigned totaleCasi;
    unsigned tamponi;
    unsigned casiTestati;
}DatiCovid;

int readLines(const char *fileName);
int readFields(const char *fileName, DatiCovid *dc, int dim);
int sortByTerapiaIntensiva(DatiCovid *dc, int dim);
void printDatiCovid(DatiCovid dc);
int calcMaxMinTerapiaIntensiva(DatiCovid *dc, int dim, int maxNum, int minNum);
int totPazientiTerapiaIntensiva(DatiCovid *dc, int dim);

#ifdef _cplusplus
}
#endif


#endif //_DATICOVID_H_