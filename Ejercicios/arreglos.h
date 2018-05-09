#ifndef ARREGLOS_H_INCLUDED
#define ARREGLOS_H_INCLUDED

void escribir_arreglo_double(double* X, int n);
void escribir_arreglo_int(int* X, int n);
bool* arr_criba(int n);
void escribir_criba(bool *a, int n);
double sum_arr(double* a, int n);
double pro_arr(double a, int n);
double mult_arr(double* a, double* b, int n);
int min_arr(int* a, int n);
int max_arr(int* a, int n);
double* ordenar(double *a,int tam);
double mediana(double* a, int tam);
int* ceros(int* a, int tam);
double* mult_arr_ii(double* a, double* b, int n);

#endif // ARREGLOS_H_INCLUDED
