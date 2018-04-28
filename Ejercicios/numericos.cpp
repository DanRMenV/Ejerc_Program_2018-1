#include <iostream>
#include "numericos.h"

using namespace std;

int potencia(int a, int b){
    int p=1;
    for(int i = 0 ; i < b ; i++ ){
        p = p * a;
    }
    return p;
}

bool divisible(int a, int b){

    return a % b == 0;
}

bool primo(int a){
    int div=2;
    int cont=0;
    while(a>1){
       if(a%div==0){
        a=a/div;
        cont++;
       }else{
       div++;
       };
    };
   return cont == 1 ;
}

bool p_relativo(int a, int b){
    int n= menor(a,b);
    int cont=0;
    for(int i=2; i<=n ;i++){
        if(a % i == 0 &&  b % i ==0 ){
            cont++;
        }
    }

    return cont == 0;
}

bool es_msuma(int a, int b, int c){

return c%(a+b)==0;

}

double ev_punto(double a, double b, double c, double x){

    return a*x*x+b*x+c;

}

double coef_lin_der(double a, double b, double c, double x){

    return 2*a;

}

double ev_der_punto(double a, double b, double c, double x){

    return 2*a*x+b;

}

bool esfib(int num){
    int fib0=1;
    int fib1=1;
    int fib2;

    do{
        fib2=fib1+fib0;
        fib0=fib1;
        fib1=fib2;

    }while(num>fib2);

    return num == fib2;
}

int menor(int a, int b){
    if(a>=b){
        return a;
    }else{
        return b;
    }
}

