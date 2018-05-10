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
    int pob_i = (ep + em + eg)/3;
    int pob_f = (2/3)* pob_i;
    
        if (pob_i<=eg){
            return pob_i*0.05;
        }else if (6+em>=pob_i){
            return eg*0.05+(pob_i-eg)*0.03;
        }else{
            return eg*0.05+em*0.03+(pob_i-eg-em)*0.02;
        }
}


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
