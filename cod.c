#include <stdio.h>
#include <stdlib.h>
#include <string.h>

float val_prag(unsigned int m,unsigned int n)
{
    float f;
    f = (m * n) / 256;
    return f;
}

void calc_W_H(unsigned int *dim,unsigned int *W,unsigned int *H,unsigned char* nume)
{
    FILE *fin;
    fin = fopen(nume,"rb");
    if(fin == NULL)
    {
        printf("Eroare la deschiderea fisierului!!!");
        return;
    }
    fseek(fin,2,SEEK_SET);
    fread(dim,sizeof(unsigned int),1,fin);
    fseek(fin,18,SEEK_SET);
    fread(W,sizeof(unsigned int),1,fin);
    fread(H,sizeof(unsigned int),1,fin);
    fclose(fin);
}

unsigned int *frecventa_val_R(unsigned char *nume,unsigned int dim)
{
    FILE *fin;
    fin = fopen(nume,"rb");
    if(fin == NULL)
    {
        printf("Eroare la deschiderea fisierului!!!");
        return;
    }
    unsigned char cul;
    unsigned int jump = 2;
    unsigned int *frec;
    frec = (unsigned int*)calloc(dim,sizeof(unsigned int));
    fseek(fin,54,SEEK_SET);
    while(1)
    {
        fseek(fin,jump,SEEK_CUR);
        fread(&cul,sizeof(unsigned char),1,fin);
        frec[cul]++;
        if(feof(fin)) break;
    }
    fclose(fin);
    return frec;
}

unsigned int *frecventa_val_G(unsigned char *nume,unsigned int dim)
{
    FILE *fin;
    fin = fopen(nume,"rb");
    if(fin == NULL)
    {
        printf("Eroare la deschiderea fisierului!!!");
        return;
    }
    unsigned char cul;
    unsigned int jump = 2;
    unsigned int *frec;
    frec = (unsigned int*)calloc(dim,sizeof(unsigned int));
    fseek(fin,53,SEEK_SET);
    while(1)
    {
        fseek(fin,jump,SEEK_CUR);
        fread(&cul,sizeof(unsigned char),1,fin);
        frec[cul]++;
        if(feof(fin)) break;
    }
    fclose(fin);
    return frec;
}

unsigned int *frecventa_val_B(unsigned char *nume,unsigned int dim)
{
    FILE *fin;
    fin = fopen(nume,"rb");
    if(fin == NULL)
    {
        printf("Eroare la deschiderea fisierului!!!");
        return;
    }
    unsigned char cul;
    unsigned int jump = 2;
    unsigned int *frec;
    frec = (unsigned int*)calloc(dim,sizeof(unsigned int));
    fseek(fin,52,SEEK_SET);
    while(1)
    {
        fseek(fin,jump,SEEK_CUR);
        fread(&cul,sizeof(unsigned char),1,fin);
        frec[cul]++;
        if(feof(fin)) break;
    }
    fclose(fin);
    return frec;
}

float X_patrat_R(unsigned char *nume,unsigned int W,unsigned int H,unsigned int *frec_R)
{
    int i;
    unsigned int f = val_prag(W,H);
    float X = 0;
    for(i = 0; i < 255; ++i)
    {
        X += ((frec_R[i] - f) * (frec_R[i] - f)) * (1.0 / f);
    }
    return X;
}

float X_patrat_B(unsigned char *nume,unsigned int W,unsigned int H,unsigned int *frec_B)
{
    int i;
    float f = val_prag(W,H);
    float X = 0;
    for(i = 0; i < 255; ++i)
    {
        X += ((frec_B[i] - f) * (frec_B[i] - f)) * (1.0 / f);
    }
    return X;
}

float X_patrat_G(unsigned char *nume,unsigned int W,unsigned int H,unsigned int *frec_G)
{
    int i;
    unsigned int f = val_prag(W,H);
    float X = 0;
    for(i = 0; i < 255; ++i)
    {
        X += ((frec_G[i] - f) * (frec_G[i] - f)) * (1.0 / f);
    }
    return X;
}

//functia de baza pentru testul Chi patrat
void Chi_Squared_Test(unsigned char *nume)
{
    //calculam dimensiunile imaginii trimise ca parametru
    unsigned int dim,W,H;
    calc_W_H(&dim,&W,&H,nume);
    unsigned int i;
    unsigned int X = 0;
    float R,G,B;
    //determinam frecventele intensitatilor valorilor pentru fiecare canal de culoare
    unsigned int *frec_R,*frec_G,*frec_B;
    frec_R = frecventa_val_R(nume,W * H);
    frec_G = frecventa_val_G(nume,W * H);
    frec_B = frecventa_val_B(nume,W * H);
    //determinam valorile testului Chi patrat pentru fiecare canal de culoare
    R = X_patrat_R(nume,W,H,frec_R);
    G = X_patrat_G(nume,W,H,frec_G);
    B = X_patrat_B(nume,W,H,frec_B);
    printf("Frecventa R: %.2f",R);
    printf("\nFrecventa G: %.2f",G);
    printf("\nFrecventa B: %.2f",B);
}
