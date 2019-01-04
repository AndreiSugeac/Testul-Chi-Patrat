#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cod.h"

int main()
{
    unsigned char *nume;
    nume = (unsigned char*)malloc(50*sizeof(unsigned char));
    printf("Numele fisierului de testat este: ");
    fgets(nume,50,stdin);
    nume[strlen(nume) - 1] = '\0';
    Chi_Squared_Test(nume);
    return 0;
}
