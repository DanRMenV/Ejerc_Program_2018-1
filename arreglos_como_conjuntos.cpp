#include "arreglos_como_conjuntos.h"

int* crear_arreglo_int(int n){
    return new int[n];
};

int* unio(int* x,int m, int* y,int n){
    int s = 1+n+m;
    int* c = crear_arreglo_int(s);
    c[0] = s;
    for(int i=1;i<=m;i++){
        c[i] = x[i-1];
    }
    for(int i=m+1;i<s;i++){
        c[i] = y[i-m-1];
    }
    return c;
}

int* interseccion(int* x,int m, int* y,int n){
    int h =1;
    int* c = crear_arreglo_int(h);
    for(int i=0;i<m;i++){
        for(int l=0;l<n;l++){
            if(y[l]==x[i]){
                c[h++] = x[i];
            }
        }
    }
    c[0] = h;
    return c;
}

int* diferencia(int* x,int m, int* y,int n){
    int* u = crear_arreglo_int(m);
    for(int i=0;i<m;i++){
        u[i] = x[i];
    }
    for(int i=0;i<m;i++){
        for(int l=0;l<n;l++){
            if(x[i]==y[l]){
                u[i] = 0;
            }
        }
    }
    int h =1;
    int* c = new int[h];
    for(int i=0;i<m;i++){
        if(u[i]!=0){
            c[h++] = u[i];
        }
    }
    c[0] = h;
    return c;
}

int* diferencia_simetrica(int* x,int m, int* y,int n){
    int* p = diferencia(x,m,y,n);
    int* o = diferencia(y,n,x,m);
    int a = p[0];
    int b = o[0];
    int s = a+b-1;
    int* d = crear_arreglo_int(s);
    d[0] = s;
    for(int i=1;i<a;i++){
        d[i] = p[i];
    }
    int t=1;
    for(int i=a;i<s;i++){
            d[i] = o[t++];
    }
    return d;
}

bool* pertenece(int* x,int m, int* y,int n, int p){
    bool* o = new bool[2];
    o[0] = false;
    o[1] = false;
    for(int i=0;i<m;i++){
        if(x[i]== p){
            o[0] = true;
        }
    }for(int l=0;l<n;l++){
        if(y[l]==p){
            o[1] = true;
        }
    }
    return o;
}

bool contenido(int* x,int m, int* y,int n){
    bool* c = new bool[m];
    for(int f=0;f<m;f++){
        c[f] = false;
    }for(int i=0;i<m;i++){
        for(int l=0;l<n;l++){
            if(x[i]==y[l]){
                c[i] = true;
            }
        }
    }int p=0;
    for(int r=0;r<m;r++){
        if(c[r]==true){
            p++;
        }
    }
    return p==m;
}

int* elm_repetidos(int* a, int n){
    int j=0,z=0,cont,num;
    int* aux=crear_arreglo_int(n);
    int* f=crear_arreglo_int(n);
    for(int i=0;i<n;i++){
        cont=0;
        num=a[i];
        aux[j]=num;
        j++;
        for(int k=0;k<n;k++){
            if(aux[k]==num){
                cont++;
            }
        }
        if(cont==1){
            f[z]=num;
            z++;
        }
    }
    return f;
}

int repetidos(int* a, int n){
    int j=0,z=0,cont,num;
    int* aux=crear_arreglo_int(n);
    int* f=crear_arreglo_int(n);
    for(int i=0;i<n;i++){
        cont=0;
        num=a[i];
        aux[j]=num;
        j++;
        for(int k=0;k<n;k++){
            if(aux[k]==num){
                cont++;
            }
        }
        if(cont==1){
            f[z]=num;
            z++;
        }
    }
    return z;
}
