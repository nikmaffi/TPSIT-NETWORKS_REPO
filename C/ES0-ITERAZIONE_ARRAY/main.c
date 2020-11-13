#include <stdio.h>

#define DIM 10

int main(int argc, const char **argv, const char **envp)
{
    int vet[DIM] = {-12, 45, -8, 78, -12, 89, 4, 6, 124, 0};

    printf("\nITERAZIONE 1\n");
    for(int k = 0; k < DIM; k++)
        printf("%d ", vet[k]);

    printf("\n\nITERAZIONE 2\n");
    for(int k = 0; k < DIM; k++)
        printf("%d ", *(vet + k));

    printf("\n\nITERAZIONE 3\n");
    for(int *pv = vet; pv < vet + DIM; pv++)
        printf("%d ", *pv);

    return 0;
}