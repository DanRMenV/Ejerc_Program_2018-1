#include "granja.h"

double leche( int v, double n, double m, double M, double x ){

    return (n*m*x)/(v*M);

}

int huevos (int A){
    int G = A/3;
    return 8*G;

}

int escorpiones( int ep, int em, int eg ){
    int pes = 20*ep + 30*em + 50*eg ;
    int pob_i = ep + em + eg;
    int pob_f = (2/3)* pob_i;


}

char* c_corral(int p, int q, int s, int m, int n){
    int pm = 2*4*q*(m+n);
    int pa = 2*5*p*(m+n);
    int pv = 2*8*s*(m+n);

    if(pm<pa && pm<pv){
        return "Madera";
    }else{
        if(pa<pv){
            return "Alambre";
        }
        else{
            return "Varilla";
        }
    }
}
