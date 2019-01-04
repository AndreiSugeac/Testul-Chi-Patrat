#ifndef COD_H_INCLUDED
#define COD_H_INCLUDED

float val_prag(unsigned int m,unsigned int n);

void calc_W_H(unsigned int *dim,unsigned int *W,unsigned int *H,unsigned char* nume);

unsigned int *frecventa_val_R(unsigned char *nume,unsigned int dim);

unsigned int *frecventa_val_G(unsigned char *nume,unsigned int dim);

unsigned int *frecventa_val_B(unsigned char *nume,unsigned int dim);

float X_patrat_R(unsigned char *nume,unsigned int W,unsigned int H,unsigned int *frec_R);

float X_patrat_B(unsigned char *nume,unsigned int W,unsigned int H,unsigned int *frec_B);

float X_patrat_G(unsigned char *nume,unsigned int W,unsigned int H,unsigned int *frec_G);

void Chi_Squared_Test(unsigned char *nume);

#endif // COD_H_INCLUDED
