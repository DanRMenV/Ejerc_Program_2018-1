#include <iostream>

using namespace std;

int mcd(int a, int b){
	if(b==0){
		return a;
	}else
	{
		if(b>a)
		{
			return mcd(b, a);
		}else
		{
			return mcd(b, a%b);
		}
	}
}

int MCD_arr(int* X, int n){
	if(n==0){
		return X[0];
	}else{
		return mcd(MCD_arr(X, n-1), X[n-1]);
	}
	
}

int mcm(int a, int b){
	return a*b/(mcd(a, b));
}

int MCM_arr(int* X, int n){
	if(n==0){
		return X[0];
	}else{
		return mcm(MCM_arr(X, n-1), X[n-1]);
	}
	
}


int main(){
	
	int* A = new int[4];

	A[0] = 12;
	A[1] = 20;
	A[2] = 30;
	A[3] = 15;

	cout<<MCM_arr(A,4);
	
	
}
