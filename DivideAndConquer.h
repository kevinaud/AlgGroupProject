#ifndef DIVIDEANDCONQUER_H_INCLUDED
#define DIVIDEANDCONQUER_H_INCLUDED

void matMultRec(int** A, int** B, int** C, int n);

int** matrixMultDivideAndConquer(int** A, int ** B, int n){
    int** C = new int*[n];
    for(int i = 0; i < n; i++){
        C[i] = new int[n];
        for(int j = 0; j < n; j++){
            C[i][j] = 0;
        }
    }
    matMultRec(A,B,C, n);

    return C;
}

void matMultRec(int** A, int** B, int** C, int n){
    if (n % 2 > 0){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                    for(int k = 0; k < n; k++){
                        C[i][j] += A[i][k]*B[k][j];
                    }
            }
        }
    }
    else{
        int** a[4];
        int** b[4];
        int** c[4];
        for(int i = 0; i < 4; i++){
            a[i] = new int*[n/2];
            b[i] = new int*[n/2];
            c[i] = new int*[n/2];
        }


        // 0 = 11
        // 1 = 21
        // 2 = 12
        // 3 = 22

        for(int i = 0; i < n/2; i++){
            a[0][i] = A[i];
            b[0][i] = B[i];
            c[0][i] = C[i];

            a[1][i] = A[n/2 + i];
            b[1][i] = B[n/2 + i];
            c[1][i] = C[n/2 + i];

            a[2][i] = A[i]+n/2;
            b[2][i] = B[i]+n/2;
            c[2][i] = C[i]+n/2;

            a[3][i] = A[n/2 + i]+n/2;
            b[3][i] = B[n/2 + i]+n/2;
            c[3][i] = C[n/2 + i]+n/2;

        }

        matMultRec(a[0],b[0],c[0], n/2);
        matMultRec(a[2],b[1],c[0], n/2);

        matMultRec(a[0],b[2],c[2], n/2);
        matMultRec(a[2],b[3],c[2], n/2);

        matMultRec(a[1],b[0],c[1], n/2);
        matMultRec(a[3],b[1],c[1], n/2);

        matMultRec(a[1],b[2],c[3], n/2);
        matMultRec(a[3],b[3],c[3], n/2);
    }

}


int** BF_MatrixMult(int** A, int ** B, int n){

    int** C = new int*[n];
    for(int i = 0; i < n; i++){
        C[i] = new int[n];
        for(int j = 0; j < n; j++){
            C[i][j] = 0;
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
                for(int k = 0; k < n; k++){
                    C[i][j] += A[i][k]*B[k][j];
                }
        }
    }
        return C;
}




#endif // DIVIDEANDCONQUER_H_INCLUDED
