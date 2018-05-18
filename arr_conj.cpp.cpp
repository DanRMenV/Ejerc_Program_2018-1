#include <iostream>
#include "arreglos_como_conjuntos.h"
using namespace std;

char** Opciones (int n){
    char** X = new char*[n];
    return X;
};

int menu( char** opciones, int n ){
    for( int i=0; i<n; i++ ){
        cout << (i+1) << ". " << opciones[i] << endl;
    };
    cout << "0. Salir" << endl;
    int opc;
    do{
      cout << "Ingrese opcion:";
      cin >> opc;
      if( opc<0 || opc>n ){
        cout << "Opcion invalida, por favor intente de nuevo" << endl;
      };
    }while( opc < 0 || opc>n );
    return opc;
};

int* leer_arreglo_int(int n){
    int* x = new int[n];
    for(int i = 0; i < n; i++){
        cin >> x[i];
    };
    return x;
};

int* imprimir(int* x){
    int s = x[0];
    for(int i=1;i<s;i++){
        cout << x[i] << endl;
    }
    return x;
};

void arr_con_opti(){
}

void arr_conjuntos(){
    int n;
    int m;
    cout << "Ingrese el tama\244o del primer conjunto: ";
    cin >> n;
    cout << "Ingrese los datos del primer conjunto: ";
    int* x = leer_arreglo_int(n);
    cout << "Ingrese el tama\244o del segundo conjunto: ";
    cin >> m;
    cout << "Ingrese los datos del segundo conjunto: ";
    int* y = leer_arreglo_int(m);
    char** opciones = new char*[7];
    opciones[0] = "Union";
    opciones[1] = "Interseccion";
    opciones[2] = "Diferencia";
    opciones[3] = "Diferencia simetrica";
    opciones[4] = "Pertenece";
    opciones[5] = "Contenido";
    opciones[6] = "Menu optimizado";
    int opc;
    do{
      opc = menu(opciones, 7);
      switch( opc ){
    case 1: cout << "La union de los conjuntos es: ";
            imprimir(unio(x,n,y,m));
            cout << endl; break;
        case 2: cout << "La interseccion entre los conjuntos es: ";
        imprimir(interseccion(x,n,y,m));
        cout << endl; break;
        case 3: cout << "La deferencia del primer conjunto con el segundo es: ";
            imprimir(diferencia(x,n,y,m));
            cout << endl; break;
        case 4: cout << "La deferencia simetrica de los conjuntos es: ";
            imprimir(diferencia_simetrica(x,n,y,m));
            cout << endl; break;
        case 5: {int p;
                cout << "Ingrese el numero a verificar si esta en alguno de los conjuntos: ";
                cin >> p;
                bool* l = pertenece(x,n,y,m,p);
                if(l[0]==1){
                    cout << "Pertenece al primer conjunto" << endl;
                }else{
                    cout << "No pertenece al primer conjunto"<< endl;
                }
                if(l[1]==1){
                    cout << "Pertenece al segundo conjunto"<< endl;
                }else{
                    cout << "No pertenece al segundo conjunto"<< endl;
                }
                }break;
        case 6: if(contenido(x,n,y,m)==1){
                cout << "El primer conjunto esta contenido en el segundo" << endl;
            }else{
                cout << "El primer conjunto no esta contenido en el segundo" << endl;
            }
             break;
        case 7: arr_con_opti(); break;
      };
    }while(opc!=0);
}

int main(){
    arr_conjuntos();
    return 0;
}
