#ifndef DIVIDEANDCONQUER_H_INCLUDED
#define DIVIDEANDCONQUER_H_INCLUDED

void matMultRec(int** A, int** B, int** C, int aRow, int aCol, int bRow, int bCol, int cRow, int cCol, int n);

int** matrixMultDivideAndConquer(int** A, int ** B, int n) {
	int** C = new int*[n];
	for (int i = 0; i < n; i++) {
		C[i] = new int[n];
		for (int j = 0; j < n; j++) {
			C[i][j] = 0;
		}
	}
	matMultRec(A, B, C, 0, 0, 0, 0, 0, 0, n);

	return C;
}

void matMultRec(int** A, int** B, int** C, int aRow, int aCol, int bRow, int bCol, int cRow, int cCol, int n) {
	if (n == 1) {
		C[cRow][cCol] += A[aRow][aCol] * B[bRow][bCol];
	}
	else {
		matMultRec(A, B, C, aRow, aCol, bRow, bCol, cRow, cCol, n / 2);
		matMultRec(A, B, C, aRow, aCol + n / 2, bRow + n / 2, bCol, cRow, cCol, n / 2);

		matMultRec(A, B, C, aRow, aCol, bRow, bCol + n/2, cRow, cCol + n / 2, n / 2);
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




#endif // DIVIDEANDCONQUER_H_INCLUDED
