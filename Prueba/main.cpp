#include <iostream>

using namespace std;

int main()
{   int fib0=1;
    int fib1=1;
    int fib2;
    int num;
    cin>>num;

    do{
        fib2=fib1+fib0;
        fib0=fib1;
        fib1=fib2;

    }while(num>fib2);

    if(num==fib2){
        cout<<"Es"<<endl;
    }
    else{
        cout<<"No es"<<endl;
    }


    return 0;
}
