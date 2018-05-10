#include "geometricos.h"
#include <iostream>
using namespace std;

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

double tri_cir(double r){
	double h = (2*r)+r;
	double b = 2*(r*1.73205080757);
	double a = (b*h)/2;
	return a;
}
    
double ar_cu_ins(int r){
    int d=2*r;

    return potencia(d,2)/2;
}

double per_cu_ins(int r){
    int d=2*r;
    int per= potencia(d,2)/2;

    return 4*raiz(per);
}

/*double ar_pe_ins(int r){

    double h=raiz((r*r)-((r/2)*(r/2)));
    double t=r*h/2;

    return 5*t;
}No lo copien*/ 

double per_pe_ins(int r){

    return 5*r;
}


double ar_hx_ins(int r){

    double h=raiz((r*r)-((r/2)*(r/2)));
    double t=r*h/2;

    return 6*t;
}

double per_hx_ins(int r){

    return 6*r;
}

double cua_cir(double r){
	double c = 4*r;
	return c;
}

double pen_cir(double r){
	double l = 2*(r/1.73205080757);
	double p = (5*l*r)/2;
	return p;
}

double hex_cir(double r){
	double l = 2*(r/1.73205080757);
	double p = (6*l*r)/2;
	return p;
}    
