#include <stdio.h>

#define DIM 10

int main(int argc, const char **argv, const char **envp)
{
    int vet[DIM] = {-12, 45, -8, 78, -12, 89, 4, 6, 124, 0};

    //Iterazione 1 (classica)
    printf("\nFirst iteration\n");
    for(int k = 0; k < DIM; k++)
        printf("%d ", vet[k]);

    //Iterazione 2 (classica ma con i puntatori)
    printf("\n\nSecond iteration\n");
    for(int k = 0; k < DIM; k++)
        printf("%d ", *(vet + k));

    //Iterazione 3 (viene incrementato il puntatore)
    printf("\n\nThird iteration\n");
    for(int *pv = vet; pv < vet + DIM; pv++)
        printf("%d ", *pv);

    return 0;
}