#include "arreglos.h"
#include <iostream>
#include "numericos.h"

using namespace std;

void escribir_arreglo_int(int* X, int n){
    for(int i=0;i<n;i++){
        cout<<X[i]<<endl;
        }
}

void escribir_arreglo_double(double* X, int n){
    for(int i=0;i<n;i++){
        cout<<X[i]<<endl;
        }
}



bool* arr_criba(int n){
    bool* criba=new bool[n];
    for(int i=0;i<n;i++){
        criba[i]=true;
    };

    for(int i = 2; i < n; i++){
        for(int j = 2; i*j <n; j++){
            criba[i*j] = false;
        };
    };
    return criba;
}

void escribir_criba(bool *a, int n){

    for(int i = 2; i<n;i++){
        if(a[i]){
            cout<<i<<", ";
        };
    };
};

double sum_arr(double* a, int n){
    double suma=0;
    for(int i=0; i < n; i++){
        suma= suma+ a[i];
    }

    return suma;
}

double pro_arr(double a, int n){
    return a/n;
}

double mult_arr(double* a, double* b, int n){
    double c=0;

    for(int i = 0; i < n; i++){
        c=c+(a[i]*b[i]);
    }

    return c;

}

/*int min_arr(int* a, int n){
    int min=a[0];
    for( int i = 0; i< n;i++){
        if(a[i]<min){
            min=a[i];
        }
    }

    return min;

}*/

int min_arr(int* a, int n){
    if(n==1){
        return a[0];
    }else{
    return menor(min_arr(a,n-1),a[n-1]);
    }
}

/*int max_arr(int* a, int n){
    int max=a[0];
    for( int i = 0; i< n;i++){
        if(a[i]>max){
            max=a[i];
        }
    }

    return max;

}*/

int max_arr(int* a, int n){
    if(n==1){
        return a[0];
    }else{
    return mayor(max_arr(a,n-1),a[n-1]);
    }
}

double* ordenar(double* a,int tam){
    int temp=0;
    if(tam>1){
    for(int i=0;i<tam-1;i++){
        if(a[i]>a[i+1]){
            temp=a[i];
            a[i]=a[i+1];
            a[i+1]=temp;
        }
    }
    return ordenar(a, tam-1);
}
}

double mediana(double* a, int tam){
    a=ordenar(a, tam);
    if(tam%2==0){
        return a[tam/2]+a[(tam/2)+1]/2;
    }else{
        return a[(tam-1)/2];
    }
}

int* ceros(int* a, int tam){
    int temp=0;
        if(tam>1){
        for(int i=0;i<tam-1;i++){
            if(a[i]==0){
                temp=a[i];
                a[i]=a[i+1];
                a[i+1]=temp;
            }
        }
    return ceros(a, tam-1);
    }
}

double* mult_arr_ii(double* a, double* b, int n){
    double* c= new double[n];

    for(int i = 0; i < n; i++){
        c[i]=a[i]*b[i];
    }

    return c;

      /*  int n;
    cin>>n;
    double* a=new double[n];
    double* b=new double[n];
    double* c=new double[n];

    for(int i = 0; i < n;i++){
        cin>>a[i];
    }
    for(int i = 0; i < n;i++){
        cin>>b[i];
    }

    c=mult_arr(a,b,n);
    escribir_arreglo_double(c,n);
*/

}
