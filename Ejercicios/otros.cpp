#include "otros.h"
#include "numericos.h"

int h_arboles(int p, int k, int t){

    return t/(p*k);

}

int i_simple(int k, int i){

    return k+(i*7);

}

int i_compuesto(int k, int i){
    i=i/k;
    int itr=i+1;

    return k*potencia(itr,7);


}

