#ifndef _RUBRICA_H_
#define _RUBRICA_H_

#ifdef _cplusplus
extern "C" {
#endif

#include <string.h>
#include <stdio.h>

#define MAX_NUM_CONTATTI (1 << 12) //Numero massimo di contatti per rubrica
#define MAX_NAME_CHARS (1 << 6) //Numero massimo di caratteri per nome
#define MAX_NUMBER_CHARS (1 << 4) //Numero massimo di caratteri per il numero di telefono

typedef struct contatto_t
{
    short id; //Id del contatto
    char nome[MAX_NAME_CHARS]; //Nome del contatto
    char numero[MAX_NUMBER_CHARS]; //Numero di telefono
}Contatto;

typedef struct rubrica_t
{
    short num_inseriti; //Numero di contatti inseriti
    Contatto db[MAX_NUM_CONTATTI]; //Contatti
}Rubrica;

char initRubrica(Rubrica *r); //Funzione che inizializza la rubrica
char creaContatto(const char *nome, const char *numero, Rubrica *r); //Funzione che inserisce un contatto in rubrica
char cercaContatto(const char *nome, Rubrica *r); //Funzione che cera un contatto in rubrica
char stampaRubrica(Rubrica *r); //Funzione che stampa la rubrica

#ifdef _cplusplus
}
#endif

#endif //_RUBRICA_H_