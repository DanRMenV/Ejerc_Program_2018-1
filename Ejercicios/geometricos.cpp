#include "geometricos.h"
#include <iostream>
using namespace std;

void escribir_arreglo_double(double* X){
    for(int i=0;i<2;i++){
        cout<<X[i]<<endl;
        }

}

char* par_per(double p1, double c1, double p2, double c2){

    if(p1 == p2){
        return "Paralelas";
    }
    else if(p1 * p2 == -1){
        return "Perpendiculares" ;
    }
    else{
        return "Ninguna";
    }
}

double* inter(double p1, double c1, double p2, double c2){

    double x=(c2-c1)/(p1-p2);
    double y= p1*x+c1;

    double* r= new double [2];
    r[0]= x;
    r[1]= y;

    return r;

}


