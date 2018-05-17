#include <iostream>
#include <stdlib.h>
#include "Menu.h"
#include "Matrices.h"


using namespace std;

int** crearMatriz(int** X, int n, int m){

    X = new int*[n];
    for(int i = 0; i < n; i++){

        X[i] = new int[m];
    }
    return X;
}
double** crearMatriz(double** X, int n, int m){

    X = new double*[n];
    for(int i = 0; i < n; i++){

        X[i] = new double[m];
    }
    return X;
}
bool** crearMatriz(bool** X, int n, int m){

    X = new bool*[n];

    for(int i = 0; i < n; i++){

        X[i] = new bool[m];
    }
    return X;
}

int** LlenarMatriz(int** X, int n, int m){

    for(int i = 0; i < n; i++){

        for(int j = 0; j < m; j++){

            cout<<"valor para la posicion: ["<<i + 1<<"]["<<j + 1<<"]"<<endl;
            cin>>X[i][j];
        }
    }
    return X;
}
double** LlenarMatriz(double** X, int n, int m){

    for(int i = 0; i < n; i++){

        for(int j = 0; j < m; j++){

            cout<<"valor para la posicion: ["<<i + 1<<"]["<<j + 1<<"]"<<endl;
            cin>>X[i][j];
        }
    }
    return X;
}

///1
double** sumaMatriz(double** X, double** Y, int posF, int posC, int n, int m){

    if(posF == n){

        return X;
    }
    else{

        if(posC == m){

            posC = 0;
            posF++;
            return sumaMatriz(X, Y, posF, posC, n, m);
        }
        else{

            X[posF][posC] += Y[posF][posC];
            posC++;
            return sumaMatriz(X, Y, posF, posC, n, m);
        }

    }

}

///2
double** multiMatrReal(double** X, double** Y, int posF, int posC, int n, int m){

    if(posF == n){

        return X;
    }
    else{

        if(posC == m){

            posC = 0;
            posF++;
            return multiMatrReal(X, Y, posF, posC, n, m);
        }
        else{

            X[posF][posC] *= Y[posF][posC];
            posC++;
            return multiMatrReal(X, Y, posF, posC, n, m);
        }
    }
}

///3
double sumaColMatriz(double** X, int posF, int columna, int n, int m, double sum){

    if(posF == n){

        return sum;
    }
    else{

        sum += X[posF][columna];
        posF++;
        return sumaColMatriz(X, posF, columna, n, m, sum);
    }
}

///4
double sumaFilMatriz(double** X, int fila, int posC, int n, int m, double sum){

    if(posC == m){

        return sum;
    }
    else{

        sum += X[fila][posC];
        posC++;
        return sumaFilMatriz(X, fila, posC, n, m, sum);
    }
}

///5
bool EsMatrizMagica(double** X, int n, int m){

    double val = sumaFilMatriz(X, 0, 0, n, m, 0);
    for(int i = 1; i < n; i++){

        if(sumaFilMatriz(X, i, 0, n, m, 0) != val){

            return false;
        }
    }
    for(int j = 0; j < m; j++){


        if(sumaColMatriz(X, 0, j, n, m, 0) != val){

            return false;
        }
    }
    double d1 = 0;
    for(int i = 0; i < n; i++){

        d1 += X[i][i];
    }
    double d2 = 0;
    for(int i = 0; i < n; i++){

        d2 += X[i][n - i - 1];
    }

    if(d1 != val || d2 != val){

        return false;
    }
    else{

        return true;
    }
}

///6
double** menoresYmayores(double** X, int posF, int posC, int n, int m, int val){

    if(posF == n){

        return X;
    }
    else{

        if(posC == m){

            posC = 0;
            posF++;
            return menoresYmayores(X, posF, posC, n, m, val);
        }
        else{

            if(X[posF][posC] > val){

                X[posF][posC] = 1;
            }
            else{

                X[posF][posC] = 0;
            }
            posC++;
            return menoresYmayores(X, posF, posC, n, m, val);
        }
    }

}

///7
double diagonalMatrizD(double** X, int posF, int posC, int n, int m, double prod){

    if(posF == n){

        return prod;
    }
    else{

        if(posC == m){

            posC = 0;
            return diagonalMatrizD(X, posF, posC, n, m, prod);
        }
        else{

            prod *= X[posF][posC];
            posF++;
            posC++;

            return diagonalMatrizD(X, posF, posC, n, m, prod);
        }
    }
}
double diagonalMatrizI(double** X, int posF, int posC, int n, int m, double prod){

    if(posF == n){

        return prod;
    }
    else{

        if(posC == -1){

            posC = m - 1;
            return diagonalMatrizD(X, posF, posC, n, m, prod);
        }
        else{

            prod *= X[posF][posC];
            posF++;
            posC--;

            return diagonalMatrizI(X, posF, posC, n, m, prod);
        }
    }
}
double DeterminanteMatr(double** X, int n){

    int det = 0;
    for(int i = 0; i < n; i++){

        det += diagonalMatrizD(X, 0, i, n, n, 1);
        det -= diagonalMatrizI(X, 0, i, n, n, 1);
    }
    return det;
}


///10
int** Espiral(int** X, bool** B, int* Y, int* DirF, int* DirC, int direccion, int posF, int posC, int pos, int f, int c){


    if(pos == f * c){

        return X;
    }
    int nf = posF + DirF[direccion];
    int nc = posC + DirC[direccion];

    if(nf >= 0 && nf < f && nc >= 0 && nc < c && !B[nf][nc]){

        cout<<nf<<" "<<nc<<endl;
        X[nf][nc] = Y[pos];
        pos++;
        posF = nf;
        posC = nc;
        B[nf][nc] = true;
    }
    else{

        direccion++;
        if(direccion == 4){

            direccion -= 4;
        }
    }

    return Espiral(X, B, Y, DirF, DirC, direccion, posF, posC, pos, f, c);
}
void MATRICES(){

    system("cls");
    ///MATRICES

    char** X = opciones(19);

    X[0] = "Sumar matrices de enteros";
    X[1] = "Multiplicar dos Matrices";
    X[2] = "Suma elementos Columna";
    X[3] = "Suma elementos Fila";
    X[4] = "Es una matriz magica?";
    X[5] = "Mayores y Menores";
    X[6] = "Determinante matriz cuadrada";
    X[7] = "Cosa rara";
    X[8] = "Inversa Matriz Cuadrada";
    X[9] = "Matriz en espiral";


    int n, m;
    double** mat1;
    double** mat2;
    cout<<"Bienvenido a los problemas de Matrices: "<<endl<<endl;



    int k;
    do{

        k = menu(X, 10);

        switch(k){

            case 1:
                ///1
                system("cls");
                cout<<"Suma de matrices"<<endl<<endl;
                cout<<"Filas de las matrices"<<endl;
                cin>>n;
                cout<<"Columnas de las matrices"<<endl;
                cin>>m;

                mat1 = crearMatriz(mat1, n, m);
                mat2 = crearMatriz(mat2, n, m);
                cout<<"Llene la primera matriz"<<endl;
                LlenarMatriz(mat1, n, m);
                cout<<"Llene la segunda matriz"<<endl;
                LlenarMatriz(mat2, n, m);

                sumaMatriz(mat1, mat2, 0, 0, n, m);

                cout<<"La suma de ambas matrices quedaria: "<<endl;
                imp(0, n, 0, m, mat1);
            break;

            case 2:
                ///2
                system("cls");
                cout<<"Multiplicar matrices"<<endl<<endl;
                cout<<"Filas de las matrices"<<endl;
                cin>>n;
                cout<<"Columnas de las matrices"<<endl;
                cin>>m;

                mat1 = crearMatriz(mat1, n, m);
                mat2 = crearMatriz(mat2, n, m);
                cout<<"Llene la primera matriz"<<endl;
                LlenarMatriz(mat1, n, m);
                cout<<"Llene la segunda matriz"<<endl;
                LlenarMatriz(mat2, n, m);

                multiMatrReal(mat1, mat2, 0, 0, n, m);

                cout<<"La Multiplicacion de ambas matrices quedaria: "<<endl;
                imp(0, n, 0, m, mat1);
            break;

            case 3:
                ///3
                system("cls");
                cout<<"Suma De una Columna de una Matriz"<<endl<<endl;
                cout<<"Filas de la matriz"<<endl;
                cin>>n;
                cout<<"Columnas de la matriz"<<endl;
                cin>>m;

                mat1 = crearMatriz(mat1, n, m);
                cout<<"Llene la matriz"<<endl;
                LlenarMatriz(mat1, n, m);

                int p;
                cout<<"De Que Columna quiere saber la suma?: "; cin>>p;

                cout<<"La Suma de los valores en al columna "<<p--<<" es: ";
                cout<<sumaColMatriz(mat1, 0, p, n, m, 0)<<endl;

            break;

            case 4:
                ///4
                system("cls");
                cout<<"Suma De una Fila de una Matriz"<<endl<<endl;
                cout<<"Filas de la matriz"<<endl;
                cin>>n;
                cout<<"Columnas de la matriz"<<endl;
                cin>>m;

                mat1 = crearMatriz(mat1, n, m);
                cout<<"Llene la matriz"<<endl;
                LlenarMatriz(mat1, n, m);

                cout<<"De Que Fila quiere saber la suma?: "; cin>>p;

                cout<<"La Suma de los valores en al fila "<<p--<<" es: ";
                cout<<sumaFilMatriz(mat1, p, 0, n, m, 0)<<endl;

            break;

            case 5:
                ///5
                system("cls");
                cout<<"Matriz Magica"<<endl<<endl;
                cout<<"Filas de la matriz"<<endl;
                cin>>n;
                cout<<"Columnas de la matriz"<<endl;
                cin>>m;

                mat1 = crearMatriz(mat1, n, m);
                cout<<"Llene la matriz"<<endl;
                LlenarMatriz(mat1, n, m);

                if(EsMatrizMagica(mat1, n, m)){

                    cout<<"SI es una matriz magica"<<endl;
                }
                else{

                    cout<<"NO es una matriz magica"<<endl;
                }
                cout<<endl;
            break;

            case 6:
                ///6
                system("cls");
                cout<<"Menores y Mayores"<<endl<<endl;
                cout<<"Filas de la matriz"<<endl;
                cin>>n;
                cout<<"Columnas de la matriz"<<endl;
                cin>>m;

                mat1 = crearMatriz(mat1, n, m);
                cout<<"Llene la matriz"<<endl;
                LlenarMatriz(mat1, n, m);

                cout<<"Con que numero desea evaluar la matriz?: "; cin>>p;
                menoresYmayores(mat1, 0, 0, n, m, p);

                cout<<"La matriz evaluada, quedaria: "<<endl<<endl;
                imp(0, n, 0, m, mat1);
                cout<<endl;
            break;

            case 7:
                ///7
                system("cls");
                cout<<"Determinantes"<<endl<<endl;
                cout<<"Filas de la matriz"<<endl;
                cin>>n;
                cout<<"Columnas de la matriz"<<endl;
                cin>>m;

                mat1 = crearMatriz(mat1, n, m);
                cout<<"Llene la matriz"<<endl;
                LlenarMatriz(mat1, n, m);

                cout<<"La determinante de la matriz es: "<<DeterminanteMatr(mat1, n)<<endl<<endl;

            break;

            case 8:
                ///4
                system("cls");
            break;

            case 9:
                ///4
                system("cls");
            break;
            case 10:
                ///10
                system("cls");
                cout<<"Espiral"<<endl<<endl;


                cout<<"Ingrese el tamanio n"<<endl;
                cin>>n;
                int* arr = new int[n * n];
                for(int i = 0; i < n * n; i++){
                    cout<<"Ingrese el valor del arreglo en la posicion ["<<i + 1<<"]: ";
                    cin>>arr[i];
                }
                int** A;
                bool** B;
                A = crearMatriz(A, n, n);
                B = crearMatriz(B, n, n);

                for(int i = 0; i < n; i++){

                    for(int j = 0; j < n; j++){

                        B[i][j] = false;
                    }
                }
                int* DirC = new int[4];    DirC[0] =  1;     DirC[1] =  0;    DirC[2] = -1;    DirC[3] =  0;
                int* DirF = new int[4];    DirF[0] =  0;     DirF[1] =  1;    DirF[2] =  0;    DirF[3] = -1;
                int dir = 0;
                Espiral(A, B, arr, DirF, DirC, dir, 0 , -1, 0, n, n);

                cout<<"La Matriz puesta en espiral queda: "<<endl;
                imp(0, n, 0, n, A);
                cout<<endl<<endl;

            break;

        }
    }while(k);




}
