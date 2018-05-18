#include <iostream>
using namespace std;

int* mult(int* a, int* b, int n, int m){
    int t=(m+n)+1;
    int* c= new int[t];
    
    for(int i=0; i<=n; i++){
        for(int j=0; j<=m; j++){
            c[i+j]= c[i+j]+ (a[i]*b[j]);
        }
    }
    return c;
}

void escribir_arreglo(int* X, int n){
    for(int i=0;i<n;i++){
        cout<<X[i]<<" x^"<<i<<" +";
    }
}

int main() {
    int n=2;
    int* a= new int[n];
    int* b= new int[n];
   
    int t=(2*n)+1;
    int* c= new int[t];
    
    a[0]=1;
    a[1]=2;
    a[2]=3;
    b[0]=3;
    b[1]=5;
    b[2]=1;
    
    c=mult(a,b,n);
    escribir_arreglo(c,t);
}
