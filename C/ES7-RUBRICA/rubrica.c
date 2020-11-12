#include "rubrica.h"

char initRubrica(Rubrica *r)
{
    if(!r) //Controllo validità dei parametri
        return 0;

    r->num_inseriti = 0; //Reset del numero di contatti inseriti

    return 1;
}

char creaContatto(const char *nome, const char *numero, Rubrica *r)
{
    if(!nome || !numero || !r) //Controllo validità dei parametri
        return 0;

    if(r->num_inseriti >= MAX_NUM_CONTATTI) //Viene controllato se si possono inserire nuovi contatti
        return 0;

    //Impostazione di tutti i parametri del contatto
    r->db[r->num_inseriti].id = r->num_inseriti;
    strncpy(r->db[r->num_inseriti].nome, nome, MAX_NAME_CHARS);
    strncpy(r->db[r->num_inseriti].numero, numero, MAX_NUMBER_CHARS);

    r->num_inseriti++; //Incremento dei contatti inseriti in rubrica

    return 1;
}

char cercaContatto(const char *nome, Rubrica *r)
{
    if(!r) //Controllo validità dei parametri
        return 0;

    for(short k = 0; k < r->num_inseriti; k++) //Iterazione su tutti i contatti della rubrica
    {
        if(strcmp(r->db[k].nome, nome) == 0) //Verifica dell'uguaglianza dei nomi
        {
            //Stampa del contatto
            printf("\nContatto trovato in posizione %d\n", k + 1);
            printf("Nome:   %s", r->db[k].nome);
            printf("Numero: %s\n", r->db[k].numero);

            break; //Salto fuori dal ciclo
        }
    }

    return 1;
}

char stampaRubrica(Rubrica *r)
{
    if(!r) //Controllo validità dei parametri
        return 0;

    //Itarazione e stampa di tutti i contatti della rubrica
    printf("\nElenco telefonico:\n\n");
    for(short k = 0; k < r->num_inseriti; k++)
    {
        printf("Nome:   %s", r->db[k].nome);
        printf("Numero: %s", r->db[k].numero);
        printf("--------------------------------\n");
    }

    return 1;
}