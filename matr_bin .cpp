bool** un_mat(bool** A, bool** B,int n, int m){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            A[i][j]=A[i][j] || B[i][j];
        }
    }
    return A;
}

bool** inter_mat(bool** A, bool** B,int n, int m){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            A[i][j]=A[i][j] && B[i][j];
        }
    }
    return A;
}
