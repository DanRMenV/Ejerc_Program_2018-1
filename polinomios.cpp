void escribir_arreglo_int(int* X, int n){
    for(int i=0;i<n;i++){
        cout<<X[i]<<",";
    };
}

double* crear_arreglo_pol(int n){
    return new double[n+1];
};

double* leer_arreglo_pol(double* x, int n){
    for(int i = 0; i <= n; i++){
        cout<<"Ingrese dato x^"<<n-i<<":";
        cin>>x[i];
    };
    return x;
};

void escribir_arreglo_sum(double* X, int n){
    for(int i=0;i<n;i++){
        cout<<"("<<X[i]<<"x^"<<n-i<<")+";
    }
    cout<<"("<<X[n]<<")";
}

double evaluar_pol(double* A, double x, int n, int e ){
    if(n==0){
        return A[0]*potencia(x,e);
    }else{
        return evaluar_pol(A,x,n-1,e+1)+ A[n]*potencia(x,e);
    };
};

double* sumar_polinomioos(double* a,int n, double* b, int m){
    int j = mayor_int(n,m);
    double* y = crear_arreglo_double(j);
    for(int i=j;i>=0;i--){
        if(n==m){
            y[i] = a[i] + b[i];
        }if(n>m){
            y[i] = a[n];
            n--;
        }if(n<m)
            {
            y[i] = b[m];
            m--;
        }
    }
    return y;
}

double* restar_polinomios(double* a,int n, double* b, int m){
    int j = mayor_int(n,m);
    double* y = crear_arreglo_double(j);
    for(int i=j;i>=0;i--){
        if(n==m){
            y[i]=a[i]-b[i];
        }if(n>m){
            y[i]=a[n];
            n--;
        }if(n<m){
            y[i]=b[m];
            m--;
        }
    }
    return y;
}


//Mios 

double evaluar_pol(double* A, double x, int n){
    if(n==0){
        return A[0]* pot(x,n);
    }else{
        return evaluar_pol(A,x,n-1)+ A[n]*pot(x,n);
    };
};
double* sum_pol(double* A, double* B, int n, int m){
    if(m<n){
        for(int i=0;i<=m;i++){
            A[i]=A[i]+B[i];
        }
        return A;
    }
    else{
        for(int i=0;i<=n;i++){
            B[i]=A[i]+B[i];
        }
        return B;
    };
};

double* rest_pol(double* A, double* B, int n, int m){
    if(m<n){
        for(int i=0;i<=m;i++){
            A[i]=A[i]-B[i];
        }
        return A;
    }
    else{
        for(int i=0;i<=n;i++){
            B[i]=A[i]-B[i];
        }
        return B;
    };
};

double* mult_pol(double* a, double* b, int n, int m){
    int t=n+m;
    double* c= crear_arreglo_pol(t);
    c=ini(c,t);
    for(int i=0; i<=n; i++){
        for(int j=0; j<=m; j++){
            c[i+j]= c[i+j]+ (a[i]*b[j]);
        }
    }
    return c;
};




