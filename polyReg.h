#include <cmath>

double** matTranspose(double** A, int r, int c);
double* matMult1D(double ** A, double* b, int n, int deg);
void gaussJordan(double** A, int n);
void multRow(double** A, int r, int n, double val);
void rowAdd(double **A, int r1, int r2, int n, double multFact);
void choosePivot(double** A, int r, int n);
double** notSquareMatMult(double** A, double**B, int firstD, int middleD, int lastD);

double * polyReg(int* x, int* y, int n, int deg){

    double**z = new double*[n];
    double** Y = new double*[n];
    for(int i = 0; i < n; i++){
        z[i] = new double[deg];
        for(int j = 0; j < deg; j++){
            z[i][j] = pow(x[i],j);
        }
        Y[i][0] = y[i];
    }




    double** zT = matTranspose(z,n,deg);
    double** A1 = notSquareMatMult(zT,z, deg, n, deg);
    delete []z;
    double** A2 = notSquareMatMult(zT,Y,deg,n,1);
    delete []zT,Y;

    double ** A = new double*[n];
    for(int i = 0; i < n; i++){
        A[i] = new double[n+1];
        for(int j = 0; j < n; j++){
            A[i][j] = A1[i][j];
        }
        A[i][n] = A2[i][0];
    }
    delete []A1,A2;
    gaussJordan(A,n);

    double* a = new double[deg];
    for(int i = 0; i < deg; i++){
        a[i] = A[i][n+1];
    }

    return a;

}

double** matTranspose(double** A, int r, int c){
    double** result = new double*[r];

    for(int i = 0; i < r; i++){
        result[i] = new double[c];
        for(int j = i; j < c; j++){
            result[i][j] = A[j][i];
        }
    }

    return result;
}

void gaussJordan(double** A, int n){
    for(int i = 0; i < n; i++){
        choosePivot(A,i,n);
        multRow(A, i, n, 1.0/A[i][i]);
        for(int j = 0; j < n; j++){
            if (j!= i){
                rowAdd(A,j,i,n,-A[j][i]);
            }
        }
    }

}

void choosePivot(double** A, int r, int n){
    int maxNdx = r;
    for(int i = r; i < n; i++){
        if(A[i][r] > A[maxNdx][r]){
            maxNdx = r;
        }
    }
    if(r != maxNdx){
        for(int i = 0; i < n + 1; i++){
            swap(A[r][i], A[maxNdx][i]);
        }
    }
}

void multRow(double** A, int r, int n, double val){
    for(int i = 0; i < n + 1; i++){
        A[r][i] *= val;
    }
}

void rowAdd(double **A, int r1, int r2, int n, double multFact){
    for(int i = 0; i < n + 1; i++){
        A[r1][i] += multFact*A[r2][i];
    }
}

double** notSquareMatMult(double** A, double**B, int firstD, int middleD, int lastD){

    double** C = new double*[firstD];
    for(int i = 0; i < firstD; i++){
        C[i] = new double[lastD];
        for(int j = 0; j < lastD; j++){
            C[i][j] = 0;
        }
    }

    for(int i = 0; i < firstD; i++){
        for(int j = 0; j < lastD; j++){
                for(int k = 0; k < middleD; k++){
                    C[i][j] += A[i][k]*B[k][j];
                }
        }
    }
        return C;
}
