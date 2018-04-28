#ifndef NUMERICOS_H_INCLUDED
#define NUMERICOS_H_INCLUDED

int potencia(int a, int b);
bool divisible(int a, int b);
bool primo(int a);
bool p_relativo(int a, int b);
bool esfib(int num);
bool es_msuma(int a, int b, int c);
double ev_punto(double a, double b, double c, double x);
double coef_lin_der(double a, double b, double c, double x);
double ev_der_punto(double a, double b, double c, double x);
int menor(int a, int b);

#endif // NUMERICOS_H_INCLUDED
