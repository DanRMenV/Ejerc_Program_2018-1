#include <iostream>
#include "numericos.h"

using namespace std;

bool par(int a){
    if(a%2==0){
        cout<<"es primo"<<endl;
    }
    else cout<<"no es primo"<<endl;
    return 1;
}
int main()
{
    int a;
    cin>>a;
    cout<<divisible(a,2)<<endl;
  return 0;
}
