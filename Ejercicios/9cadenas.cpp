#include <iostream>

using namespace std;

int tamanio(char* c){

    int t = 0;

    while(c[t] != '\0'){

        t++;
    }
    return t;
}

char* traduccion(char* c, char* alfabeto){

    int t = tamanio(c);

    char* a = new char[t];

    for(int i = 0; i < t; i++){

        int trad = c[i] - 97;
        if(trad >= 0 && trad <= 26){

            a[i] = alfabeto[trad];
        }
        else{

            a[i] = c[i];
        }
    }
    return a;
}
int main(){

    char* cadena = new char[100000000];
    char* abecedario = new char[26];

    cin.getline(cadena, 100000000);
    cin>>abecedario;

    char* a = traduccion(cadena, abecedario);

    cout<<a<<endl;


    return 0;
}
