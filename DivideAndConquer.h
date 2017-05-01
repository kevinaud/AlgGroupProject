#ifndef DIVIDEANDCONQUER_H_INCLUDED
#define DIVIDEANDCONQUER_H_INCLUDED

#include <cmath>

void matMultRec(int** A, int** B, int** C, int aRow, int aCol, int bRow, int bCol, int cRow, int cCol, int n);
int** padZeroMult(int** Matrix, int dim, int newDim);

int** matrixMultDivideAndConquer(int** A, int** B, int n) {
	double logn = log2(static_cast<double>(n));
	int oldDim = n;
	if (floor(logn) != logn) {
		int newDim = pow(2,floor(logn) + 1);
		A = padZeroMult(A, n, newDim);
		B = padZeroMult(B, n, newDim);
        n = newDim;
	}

	int** C = new int*[n];
	for (int i = 0; i < n; i++) {
		C[i] = new int[n];
		for (int j = 0; j < n; j++) {
			C[i][j] = 0;
		}
	}
	matMultRec(A, B, C, 0, 0, 0, 0, 0, 0, n);
	if(oldDim == n){

        return C;
	}
	else{
        int** c = new int*[n];
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                    c[i][j] = C[i][j];
        }
        }
        for(int i = 0; i < n; i++){
            delete[] A[i];
            delete B[i];
            delete C[i];
        }
        delete[] A;
        delete[] B;
        delete[] C;

        return C;
	}

}

void matMultRec(int** A, int** B, int** C, int aRow, int aCol, int bRow, int bCol, int cRow, int cCol, int n) {
	if (n == 1) {
		C[cRow][cCol] += A[aRow][aCol] * B[bRow][bCol];
	}
	else {
		matMultRec(A, B, C, aRow, aCol, bRow, bCol, cRow, cCol, n / 2);
		matMultRec(A, B, C, aRow, aCol + n / 2, bRow + n / 2, bCol, cRow, cCol, n / 2);

		matMultRec(A, B, C, aRow, aCol, bRow, bCol + n / 2, cRow, cCol + n / 2, n / 2);
		matMultRec(A, B, C, aRow, aCol + n / 2, bRow + n / 2, bCol + n / 2, cRow, cCol + n / 2, n / 2);

		matMultRec(A, B, C, aRow + n / 2, aCol, bRow, bCol, cRow + n / 2, cCol, n / 2);
		matMultRec(A, B, C, aRow + n / 2, aCol + n / 2, bRow + n / 2, bCol, cRow + n / 2, cCol, n / 2);

		matMultRec(A, B, C, aRow + n / 2, aCol, bRow, bCol + n / 2, cRow + n / 2, cCol + n / 2, n / 2);
		matMultRec(A, B, C, aRow + n / 2, aCol + n / 2, bRow + n / 2, bCol + n / 2, cRow + n / 2, cCol + n / 2, n / 2);



	}

}

int** BF_MatrixMult(int** A, int ** B, int n) {

	int** C = new int*[n];
	for (int i = 0; i < n; i++) {
		C[i] = new int[n];
		for (int j = 0; j < n; j++) {
			C[i][j] = 0;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				C[i][j] += A[i][k] * B[k][j];
			}
		}
	}
	return C;
}


int** padZeroMult(int** Matrix, int dim, int newDim){



	int** newMat = new int*[newDim];
	for (int i = 0; i < newDim;i++) {
		newMat[i] = new int[newDim];
	}
	for (int i = 0; i < dim;i++) {
		for (int j = 0;j < dim;j++) {
			newMat[i][j] = Matrix[i][j];
		}
	}
	for (int i = 0; i < dim;i++) {
		for (int j = dim; j < newDim; j++) {
			newMat[i][j] = 0;
		}
	}
	for (int i = dim; i < newDim;i++) {
		for (int j = 0; j < newDim; j++) {
			newMat[i][j] = 0;
		}
	}

	return newMat;
}





#endif // DIVIDEANDCONQUER_H_INCLUDED
