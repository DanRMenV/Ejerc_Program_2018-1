#include <iostream>
using namespace std;

int contar(int a,int b){
    
    if(a>1){
        a=a/2;
        return contar(a,b+1);
    }else{
        return b+1;
    }
}

int* dec_bin(int a, int n){
    int* X = new int[n];
    
    for(int i = 0; i < n; i++){
        X[i] = a % 2;
        a= a/2;
    }
    X[n]=a/2;
    
    return X;

}


int main() {
    int n=389;
    int t= contar(n,0);
 	int* A=new int[t]; 
	
	A=dec_bin(n,t);
	
	for(int i= t-1 ; i>=0; i--){
	    cout<<A[i];
	}
	cout<<endl;
	
	for(int i=0; i<t;i++){
	    cout<<A[i];
	}		
}
