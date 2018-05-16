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

double* sum_pol(double* A, double* B, int n){
    if(n==0){
        A[0]= A[0]+B[0];
        return A;
    }else{
        A[n]=A[n]+B[n];
        return sum_pol(A,B,n-1);
    }
}

double* rest_pol(double* A, double* B, int n){
    if(n==0){
        A[0]= A[0]-B[0];
        return A;
    }else{
        A[n]=A[n]-B[n];
        return rest_pol(A,B,n-1);
    }
}


