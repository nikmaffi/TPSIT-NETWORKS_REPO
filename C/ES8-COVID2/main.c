#include <stdio.h>
#include <stdlib.h>
#include "datiCovid.h"

int main(int argc, const char **argv, const char **envp)
{
    DatiCovid *dc;
    int dim = 0;

    dim = readLines("data.csv");
    dc = (DatiCovid *)calloc(dim, sizeof(DatiCovid));
    readFields("data.csv", dc, dim);

    sortByTerapiaIntensiva(dc, dim);
    calcMaxMinTerapiaIntensiva(dc, dim, 3, 3);
    printf("-----------------------------------------------------------------------------------\n");
    printf("-----------------------------------------------------------------------------------\n");
    totPazientiTerapiaIntensiva(dc, dim);

    return 0;
}