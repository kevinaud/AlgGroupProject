/**
* Authors: Kevin Aud|Jesse McNicoll|Connor Blandin|Jackson Swenson
* Assignment Title: Group Project
* Assignment Description: This header file contains the function definition for
*	a divide and conquer and a brute force matrix multiplication function.
* Due Date: 5/1/2017
* Date Created: 4/28/2017
* Date Last Modified: 5/1/2017
*/

#ifndef DIVIDEANDCONQUER_H_INCLUDED
#define DIVIDEANDCONQUER_H_INCLUDED

#include <cmath>
/*
 * description: recursive divide and conquer function
 * return: void
 * postcondition: Product of A and B are stored in C
*/
void matMultRec(int** A, int** B, int** C, int aRow, int aCol, int bRow, int bCol, int cRow, int cCol, int n);


/*
 * description: Pad zeros to a matrix
 * return: padded matrix pointer
 * postcondition: return is an newDim x newDim matrix
*/
int** padZeroMult(int** Matrix, int dim, int newDim);

int** matrixMultDivideAndConquer(int** A, int** B, int n) {

    bool pad = false;
    int newDim;

	if(n%2 == 1){
        pad = true;
		newDim = n+1;
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

    if(pad){
        for(int i = 0; i < newDim; i++){
            delete[]A[i];
            delete[]B[i];
        }
        delete[]A;
        delete[]B;
    }

    return C;

}

void matMultRec(int** A, int** B, int** C, int aRow, int aCol, int bRow, int bCol, int cRow, int cCol, int n) {
		if (n < 50 || n%2 == 1) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				for (int k = 0; k < n; k++) {
					C[cRow + i][cCol + j] += A[aRow + i][aCol + k] * B[bRow + k][bCol + j];
				}
			}
		}
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
