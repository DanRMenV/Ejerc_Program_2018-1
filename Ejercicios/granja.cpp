#include "granja.h"

double leche( int v, double n, double m, double M, double x ){

    return (n*m*x)/(v*M);

}

int huevos (int A){
    int G = A/3;
    return 8*G;

}

int escorpiones( int P, int M, int G ){
    int pes = 20*P + 30*M + 50*G ;
    int pob_i = (P + M + G)/3;
    int pob_f = (2/3)* pob_i;
    
        if (pob_i<=G){
            return pob_i*0.05;
        }else if (6+M>=pob_i){
            return G*0.05+(pob_i-G)*0.03;
        }else{
            return G*0.05+M*0.03+(pob_i-G-M)*0.02;
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
