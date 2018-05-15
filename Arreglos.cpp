#include <iostream>
#include <stdlib.h>
#include "Menu.h"
#include "Arreglos.h"
#include "Numericos.h"
#include "OperacionesDeReales.h"


using namespace std;
///1
bool* criba(bool* X, int n, int primo, int mult){

    if(primo > raiz(n)){

        return X;
    }
    else{

        if(mult > n || !X[primo]){

            primo++;
            return criba(X, n, primo, primo * 2);
        }
        else{

            X[mult] = false;
            mult += primo;
            return criba(X, n, primo, mult);
        }
    }
}

///2
int sumaArregloI(int* X, int pos, int n, int sum){

    if(pos == n){

        return sum;
    }
    else{

        sum += X[pos];
        pos++;
        return sumaArregloI(X, pos, n, sum);
    }
}
double sumaArregloR(double* X, int pos, int n, double sum){

    if(pos == n){

        return sum;
    }
    else{

        sum += X[pos];
        pos++;
        return sumaArregloR(X, pos, n, sum);
    }
}

///3
double promedio(int* X, int n){

    return sumaArregloI(X, 0, n, 0) * 1.0/ n ;
}

///4
int prodcutoArregloI(int* X, int* Y, int pos, int n, int prod){

    if(pos == n){

        return prod;
    }
    else{

        prod += X[pos] * Y[pos];
        pos++;
        return prodcutoArregloI(X, Y, pos, n, prod);
    }
}
double productoArregloR(double* X, double* Y, int pos, int n, double prod){

    if(pos == n){

        return prod;
    }
    else{

        prod += X[pos] * Y[pos];
        pos++;
        return productoArregloR(X, Y, pos, n, prod);
    }
}

///5
int idxMenorArr(int* X, int pos, int n, int mini, int idx){

    if(pos == n){

        return idx;
    }
    else{

        if(idx == -1){

            mini = X[pos];
            idx = pos;
        }
        else{

            if(X[pos] < mini){

                mini = X[pos];
                idx = pos;

            }
        }
        pos++;
        return idxMenorArr(X, pos, n, mini, idx);
    }
}
int minArregloI(int* X, int n){

    int idxMin = idxMenorArr(X, 0, n, -1, 0);
    return X[idxMin];
}
double minArregloR(double* X, int pos, int n, double mini){

    if(pos == n){

        return mini;
    }
    else{
        if(pos == 0){

            mini = X[pos];
        }
        else if(X[pos] < mini){

            mini = X[pos];
        }
        pos++;
        return minArregloR(X, pos, n, mini);
    }
}

///6
int idxMayorArr(int* X, int pos, int n, int maxi, int idx){

    if(pos == n){

        return idx;
    }
    else{

        if(idx == -1){

            maxi = X[pos];
            idx = pos;
        }
        else{

            if(X[pos] > maxi){

                maxi = X[pos];
                idx = pos;

            }
        }
        pos++;
        return idxMayorArr(X, pos, n, maxi, idx);
    }
}
int maxArregloI(int* X, int n){

    int idxMay = idxMayorArr(X, 0, n, -1, 0);
    return X[idxMay];
}
double maxArregloR(double* X, int pos, int n, double maxi){

    if(pos == n){

        return maxi;
    }
    else{
        if(pos == 0){

            maxi = X[pos];
        }
        else if(X[pos] > maxi){

            maxi = X[pos];
        }
        pos++;
        return maxArregloR(X, pos, n, maxi);
    }
}

///7
int* prodcutoDirectoArregloI(int* X, int* Y, int pos, int n){

    if(pos == n){

        return X;
    }
    else{

        X[pos] *= Y[pos];
        pos++;
        return prodcutoDirectoArregloI(X, Y, pos, n);
    }
}
double* productoDirectoArregloR(double* X, double* Y, int pos, int n){

    if(pos == n){

        return X;
    }
    else{

        X[pos] *= Y[pos];
        pos++;
        return productoDirectoArregloR(X, Y, pos, n);
    }
}

///8
int* organizarArregloI(int* X, int pos, int n){

    if(pos == n){

        return X;
    }
    else{

        int salvar = X[pos];
        int idxMin = idxMenorArr(X, pos, n, 0, -1);
        X[pos] = X[idxMin];

        if(idxMin != pos){

            X[idxMin] = salvar;
        }
        pos++;
        organizarArregloI(X, pos, n);
    }
}
double mediana(int* X, int n){

    X = organizarArregloI(X, 0, n);

    if(n % 2 == 0){

        return (X[n / 2] + X[n / 2 - 1]) / 2.0;
    }
    else{

        return X[n / 2];
    }
}


///9
int* dejaAlFinal(int* X, int pos, int n, int val){

    if(pos == n){

        return X;
    }
    else{

        if(pos + 1 < n){

            X[pos] = X[pos + 1];
        }
        else{

            X[pos] = val;
        }
        pos++;
        return dejaAlFinal(X, pos, n, val);

    }
}
int* cerosAlFinal(int* X, int pos, int n, int numVeces){

    if(numVeces == n){

        return X;
    }
    else{

        if(X[pos] == 0){

            X = dejaAlFinal(X, pos, n, 0);
            pos--;
        }
        pos++;
        numVeces++;
        cerosAlFinal(X, pos, n, numVeces);
    }
}


///PRINCIPAL
void ARREGLOS(){

    ///ARREGLOS
    cout<<"Bienvenido a los Problemas de Arreglos: "<<endl;

    char** X = opciones(13);

    X[0] = "Criba de Eratostenes";
    X[1] = "Suma de elementos de un arreglo";
    X[2] = "Promedio de elementos de un arreglo";
    X[3] = "Producto de dos arreglos";
    X[4] = "Minimo de un arreglo";
    X[5] = "Maximo de un arreglo";
    X[6] = "Producto Directo de un arreglo";
    X[7] = "Mediana de elementos de un arreglo";
    X[8] = "Dejar los 0's al final";
    X[9] = "Arreglo de binario a deciaml";
    X[10] = "Decial a Arreglo de binario";
    X[11] = "Maximo Comun Divisor de un arreglo";
    X[12] = "Minimo Comun Multiplo de un arreglo";

    int n;
    int k;
    do{

        k = menu(X, 13);

        switch(k){

            case 1:
                {

                    ///1
                    system("cls");
                    cout<<"Criba de eratostenes: "<<endl;
                    int n;
                    cout<<"Hasta que numero quiere la criba?: "; cin>>n;

                    bool* B = new bool[n];
                    for(int i = 2; i < n + 1; i++){

                        B[i] = true;
                    }
                    criba(B, n, 2, 4);
                    cout<<"La criba de Eratostenes, para que solo queden los primos hasta el "<<n<<" seria:"<<endl;
                    for(int i = 2; i < n + 1; i++){

                        if(B[i]){

                            cout<<i<<" ";
                        }
                    }
                    cout<<endl;
                }
            break;

            case 2:
                {

                    ///2
                    system("cls");

                    cout<<"Suma de un arreglo: "<<endl;

                    cout<<"es un arreglo de enteros? o de reales: "<<endl;

                    int k;
                    do{

                    cout<<"0. Interos"<<endl;
                    cout<<"1. Reales"<<endl;
                    cin>>k;
                    }while(k < 0 || k > 1);

                    cout<<"Tamanio del arreglo?:"<<endl;
                    cin>>n;

                    if(!k){

                        int* Y = new int[n];
                        cout<<"llene los "<<n<<" datos: "<<endl;
                        for(int i = 0; i < n; i++){

                            cin>>Y[i];
                        }
                        cout<<"La suma de todos los elementos del arreglo es: "<<sumaArregloI(Y, 0, n, 0)<<endl;
                    }
                    else{
                        double* Y = new double[n];
                        cout<<"llene los "<<n<<" datos: "<<endl;
                        for(int i = 0; i < n; i++){

                            cin>>Y[i];
                        }
                        cout<<"La suma de todos los elementos del arreglo es: "<<sumaArregloR(Y, 0, n, 0)<<endl;
                    }
                }

            break;

            case 3:
                {


                    ///3
                    system("cls");

                    cout<<"Promedio de un arreglo: "<<endl;
                    cout<<"Tamanio del arreglo?:"<<endl;
                    cin>>n;

                    int* X = new int[n];
                    cout<<"llene los "<<n<<" datos del arreglo: "<<endl;
                    for(int i = 0; i < n; i++){

                        cin>>X[i];
                    }
                    cout<<"El promedio de los datos del arreglo es: "<<promedio(X, n)<<endl;
                }
            break;

            case 4:
                {

                    ///4
                    system("cls");

                    cout<<"Producto de dos arreglo: "<<endl;

                    cout<<"son arreglos de enteros? o de reales: "<<endl;

                    do{

                    cout<<"0. Interos"<<endl;
                    cout<<"1. Reales"<<endl;
                    cin>>k;
                    }while(k < 0 || k > 1);

                    cout<<"Tamanio del arreglo?:"<<endl;
                    cin>>n;

                    if(!k){

                        int* X = new int[n];
                        int* Y = new int[n];
                        cout<<"llene los "<<n<<" datos del primer arreglo: "<<endl;
                        for(int i = 0; i < n; i++){

                            cin>>X[i];
                        }
                        cout<<"llene los "<<n<<" datos del segundo arreglo: "<<endl;
                        for(int i = 0; i < n; i++){

                            cin>>Y[i];
                        }
                        cout<<"El producto de los dos arreglos es: "<<prodcutoArregloI(X, Y, 0, n, 0)<<endl;
                    }
                    else{
                        double* X = new double[n];
                        double* Y = new double[n];
                        cout<<"llene los "<<n<<" datos del primer arreglo: "<<endl;
                        for(int i = 0; i < n; i++){

                            cin>>X[i];
                        }
                        cout<<"llene los "<<n<<" datos del segundo arreglo: "<<endl;
                        for(int i = 0; i < n; i++){

                            cin>>Y[i];
                        }
                        cout<<"El producto de los dos arreglos es: "<<productoArregloR(X, Y, 0, n, 0)<<endl;
                    }
                }
            break;

            case 5:
                {


                    ///5
                    system("cls");

                    cout<<"Minimo de un arreglo: "<<endl;

                    cout<<"es un arreglo de enteros? o de reales: "<<endl;

                    do{

                    cout<<"0. Interos"<<endl;
                    cout<<"1. Reales"<<endl;
                    cin>>k;
                    }while(k < 0 || k > 1);

                    cout<<"Tamanio del arreglo?:"<<endl;
                    cin>>n;

                    if(!k){

                        int* Y = new int[n];

                        cout<<"llene los "<<n<<" datos del arreglo: "<<endl;
                        for(int i = 0; i < n; i++){

                            cin>>Y[i];
                        }
                        cout<<"El menor del arreglo es: "<<minArregloI(Y, n)<<endl;
                    }
                    else{
                        double* Y = new double[n];

                        cout<<"llene los "<<n<<" datos del arreglo: "<<endl;
                        for(int i = 0; i < n; i++){

                            cin>>Y[i];
                        }
                        cout<<"El menor del arreglo es: "<<minArregloR(Y, 0, n, 0)<<endl;
                    }
                }
            break;

            case 6:
                {


                    ///6
                    system("cls");

                    cout<<"Maximo de un arreglo: "<<endl;

                    cout<<"es un arreglo de enteros? o de reales: "<<endl;

                    do{

                    cout<<"0. Interos"<<endl;
                    cout<<"1. Reales"<<endl;
                    cin>>k;
                    }while(k < 0 || k > 1);

                    cout<<"Tamanio del arreglo?:"<<endl;
                    cin>>n;

                    if(!k){

                        int* Y = new int[n];

                        cout<<"llene los "<<n<<" datos del arreglo: "<<endl;
                        for(int i = 0; i < n; i++){

                            cin>>Y[i];
                        }
                        cout<<"El mayor del arreglo es: "<<maxArregloI(Y, n)<<endl;
                    }
                    else{
                        double* Y = new double[n];

                        cout<<"llene los "<<n<<" datos del arreglo: "<<endl;
                        for(int i = 0; i < n; i++){

                            cin>>Y[i];
                        }
                        cout<<"El mayor del arreglo es: "<<maxArregloR(Y, 0, n, 0)<<endl;
                    }
                }
            break;

            case 7:
                {


                    ///7
                    system("cls");

                    cout<<"Producto directo de dos arreglos: "<<endl;

                    cout<<"son arreglos de enteros? o de reales: "<<endl;

                    do{

                    cout<<"0. Interos"<<endl;
                    cout<<"1. Reales"<<endl;
                    cin>>k;
                    }while(k < 0 || k > 1);

                    cout<<"Tamanio del arreglo?:"<<endl;
                    cin>>n;

                    if(!k){

                        int* X = new int[n];
                        int* Y = new int[n];
                        cout<<"llene los "<<n<<" datos del primer arreglo: "<<endl;
                        for(int i = 0; i < n; i++){

                            cin>>X[i];
                        }
                        cout<<"llene los "<<n<<" datos del segundo arreglo: "<<endl;
                        for(int i = 0; i < n; i++){

                            cin>>Y[i];
                        }
                        cout<<"El producto directo de los dos arreglos es: "<<endl;

                        prodcutoDirectoArregloI(X, Y, 0, n);
                        for(int i = 0; i < n; i++){

                            cout<<X[i]<<" ";
                        }
                        cout<<endl;


                    }
                    else{
                        double* X = new double[n];
                        double* Y = new double[n];
                        cout<<"llene los "<<n<<" datos del primer arreglo: "<<endl;
                        for(int i = 0; i < n; i++){

                            cin>>X[i];
                        }
                        cout<<"llene los "<<n<<" datos del segundo arreglo: "<<endl;
                        for(int i = 0; i < n; i++){

                            cin>>Y[i];
                        }
                        cout<<"El producto directo de los dos arreglos es: "<<endl;

                        productoDirectoArregloR(X, Y, 0, n);
                        for(int i = 0; i < n; i++){

                            cout<<X[i]<<" ";
                        }
                        cout<<endl;
                    }
                }

            break;

            case 8:
                {


                    ///8
                    system("cls");

                    cout<<"Mediana de un arreglo: "<<endl;
                    cout<<"Tamanio del arreglo?:"<<endl;
                    cin>>n;

                    int* ARR = new int[n];
                    cout<<"llene los "<<n<<" datos del arreglo: "<<endl;
                    for(int i = 0; i < n; i++){

                        cin>>ARR[i];
                    }
                    cout<<"La mediana del arreglo es: "<<mediana(ARR, n)<<endl;
                }
            break;

            case 9:
                {


                    ///9
                    system("cls");
                    cout<<"Pasar ceros al final: "<<endl;
                    cout<<"Tamanio del arreglo?:"<<endl;
                    cin>>n;


                    int* ARR = new int[n];
                    cout<<"llene los "<<n<<" datos del arreglo: "<<endl;
                    for(int i = 0; i < n; i++){

                        cin>>ARR[i];
                    }
                    cout<<"Si pasamos los ceros al final, el arreglo quedaría asi: "<<endl;

                    cerosAlFinal(ARR, 0, n, 0);
                    for(int i = 0; i < n; i++){

                        cout<<ARR[i]<<" ";
                    }
                    cout<<endl;
                }
            break;

            case 10:
                ///10
                system("cls");
            break;

            case 11:
                ///11
                system("cls");
            break;

            case 12:
                ///12
                system("cls");
            break;

            case 13:
                ///12
                system("cls");
            break;


        }
    }while(k);


}





