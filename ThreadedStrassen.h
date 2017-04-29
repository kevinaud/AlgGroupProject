/**
* Authors: Kevin Aud|Jesse McNicoll|Connor Blandin|Jackson Swenson
* Assignment Title: Program 2 - Threaded Matrix Multiplication
* Assignment Description: This header file contains the function definition for
*	a threaded matrix multiplication function. It uses divide and conquer and assigns
*   1 quadrant of the matrix solution to each of 4 threads.
* Due Date: 3/2/2017
* Date Created: 3/2/2017
* Date Last Modified: 3/2/2017
*/
#ifndef MATRIX_MULT
#define MATRIX_MULT

#include <cstdlib>
#include <pthread.h>
#define PAD 1

using namespace std;

/**
* data structure used to pass arguments into each thread
*/
struct matrix_data {
   int dim;

   int** A;
   int** B;
   int** ret;
};

// PROTOTYPES

/**
* Strassen MATRIX MULT
* description: Given two matrices, A and B, as well as the dimension of A and B,
*   returns A * B
* return: A * B
* precondition: A and B are both square matrices with the same dimension and their
*   dimension is a power of 2
* postcondition: The correct solution to A * B is returned
*/
int** ThreadedStrassen(int **A, int **B, int dimension);
int** Strassen(int **A, int **B, int dimension);
void* threadFunc(void* matrix_data);
int** newMatrix(int rowBegin, int colBegin, int** matrix, int dim);
int** addMatrix(int** A, int** B, int dim);
int** subMatrix(int** A, int** B, int dim);
int** padZero(int** Matrix, int dim);
// DEFINITIONS

int** ThreadedStrassen(int **A, int **B, int dim) {
    if(dim%2 != 0){
	A = padZero(A, dim);
	B = padZero(B, dim);
	dim++;
    }

	const int THREAD_COUNT = 7;
	pthread_t threads[THREAD_COUNT];
	
	//Create structs for each thread 
	struct matrix_data t1, t2, t3, t4, t5, t6, t7;

    // used to hold solution matrix
    int **C = new int*[dim];


    // initialize C to all zeroes
    for (int i = 0; i < dim; i++) {
        C[i] = new int[dim];
        for (int j = 0; j < dim; j++) {
            C[i][j] = 0;
        }
    }

    if(dim == 2){
        C[0][0] = A[0][0]*B[0][0]+A[0][1]*B[1][0];
        C[0][1] = A[0][0]*B[0][1]+A[0][1]*B[1][1];
        C[1][0] = A[1][0]*B[0][0]+A[1][1]*B[1][0];
        C[1][1] = A[1][0]*B[0][1]+A[1][1]*B[1][1]; 
    return C;
    }
	
	int** a = newMatrix(0, 0, A, dim);
	int** b = newMatrix(0, dim/2, A, dim);
	int** c = newMatrix(dim/2, 0, A, dim);
	int** d = newMatrix(dim/2, dim/2, A, dim);
	
	int** e = newMatrix(0, 0, B, dim);
	int** f = newMatrix(0, dim/2, B, dim);
	int** g = newMatrix(dim/2, 0, B, dim);
	int** h = newMatrix(dim/2,dim/2, B, dim);
	
	//Set values for the matrix_data structs
	t1.A = a;
	t1.B = subMatrix(f,h,dim/2);
	t1.dim = dim/2;
	t2.A = addMatrix(a,b,dim/2);
	t2.B = h;
	t2.dim = dim/2;
	t3.A = addMatrix(c,d,dim/2);
	t3.B = e;
	t3.dim = dim/2;
	t4.A = d;
	t4.B = subMatrix(g,e,dim/2);
	t4.dim = dim/2;
	t5.A = addMatrix(a,d,dim/2);
	t5.B = addMatrix(e,h,dim/2);
	t5.dim = dim/2;
	t6.A = subMatrix(b,d,dim/2);
	t6.B = addMatrix(g,h,dim/2);
	t6.dim = dim/2;
	t7.A = subMatrix(a,c,dim/2);
	t7.B = addMatrix(e,f,dim/2);
	t7.dim = dim/2;
	
	//Spawn all threads
	pthread_create(&threads[0], NULL, threadFunc, (void*)&t1);
	pthread_create(&threads[1], NULL, threadFunc, (void*)&t2);
	pthread_create(&threads[2], NULL, threadFunc, (void*)&t3);
	pthread_create(&threads[3], NULL, threadFunc, (void*)&t4);
	pthread_create(&threads[4], NULL, threadFunc, (void*)&t5);
	pthread_create(&threads[5], NULL, threadFunc, (void*)&t6);
	pthread_create(&threads[6], NULL, threadFunc, (void*)&t7);

	//wait for all threads to complete
	pthread_join(threads[0],NULL);
	pthread_join(threads[1],NULL);
	pthread_join(threads[2],NULL);
	pthread_join(threads[3],NULL);
	pthread_join(threads[4],NULL);
	pthread_join(threads[5],NULL);
	pthread_join(threads[6],NULL);

	

	int** p1 = t1.ret;
	int** p2 = t2.ret; 
	int** p3 = t3.ret;
	int** p4 = t4.ret;
	int** p5 = t5.ret;
	int** p6 = t6.ret;
	int** p7 = t7.ret;

	int** C1 = subMatrix(addMatrix(addMatrix(p5,p4,dim/2),p6,dim/2),p2,dim/2);
	int** C2 = addMatrix(p1,p2,dim/2);
	int** C3 = addMatrix(p3,p4,dim/2);
	int** C4 = subMatrix(subMatrix(addMatrix(p1,p5,dim/2),p3,dim/2),p7,dim/2);

	for(int i = 0; i < dim/2; i++){
		for(int j  = 0; j < dim/2; j++){
			C[i][j] = C1[i][j];
		}
	}
	for(int i = 0; i < dim/2; i++){
		for(int j = dim/2; j < dim; j++){
			C[i][j] = C2[i][j-dim/2];
		}
	}
	for(int i = dim/2; i < dim; i++){
		for(int j = 0; j < dim/2; j++){
			C[i][j] = C3[i-dim/2][j];
		}
	}
	for(int i = dim/2; i < dim; i++){
		for(int j = dim/2; j < dim; j++){
			C[i][j] = C4[i-dim/2][j-dim/2];
		}
	}
    return C;

}

void* threadFunc(void* matrix_data){
	
	struct matrix_data* data = (struct matrix_data*) matrix_data;
	const int dim = data->dim;
	int** ret_mat = new int*[dim];
	for(int i = 0; i < dim; i++){
		ret_mat[i] = new int[dim];
	}

	ret_mat = Strassen(data->A, data->B, data->dim);
	data->ret = ret_mat;
}


int** newMatrix(int rowBegin, int colBegin, int** matrix, int dim){
	
	int** newM = new int*[dim/2];
	for(int i = 0; i < dim/2; i++){
		newM[i] = new int[dim/2];
	}
	for(int i = 0; i < dim/2; i++){
		for(int j = 0; j < dim/2; j++){
			newM[i][j] = matrix[i+rowBegin][j+colBegin];
		}
	}
	return newM;
}
	
int** addMatrix(int** A, int** B, int dim){
	
	int** C = new int*[dim];
	for(int i = 0; i < dim; i++){
		C[i] = new int[dim];
	}
	for(int i = 0; i < dim; i++){
		for(int j = 0; j < dim; j++){
			C[i][j] = A[i][j] + B[i][j];
		}
	}
	return C;
}

int** subMatrix(int** A, int** B, int dim){
	int** C = new int*[dim];
	for(int i = 0; i < dim; i++){
		C[i] = new int[dim];
	}
	for(int i = 0; i < dim; i++){
		for(int j = 0; j < dim; j++){
			C[i][j] = A[i][j] -  B[i][j];
		}
	}
	return C;
}

int** padZero(int** Matrix, int dim){
	int** newMat = new int*[dim+PAD];
	for(int i  = 0; i < dim+PAD;i++){
		newMat[i] = new int[dim+PAD];
	}
	for(int i = 0; i < dim;i++){
		for(int j = 0;j < dim;j++){
			newMat[i][j] = Matrix[i][j];;
		}
	}
	for(int i = 0; i < dim+PAD;i++){
		newMat[i][dim] = 0;
	}
	for(int i = 0; i < dim+PAD;i++){
		newMat[dim][i] = 0;
	}
 	return newMat;
}

int** Strassen(int **A, int **B, int dim) {


    if(dim%2 != 0){
	A = padZero(A, dim);
	B = padZero(B, dim);
	dim++;
    }
    // used to hold solution matrix
    int **C = new int*[dim];

    // initialize C to all zeroes
    for (int i = 0; i < dim; i++) {
        C[i] = new int[dim];
        for (int j = 0; j < dim; j++) {
            C[i][j] = 0;
        }
    }

    	if(dim == 2){
	C[0][0] = A[0][0]*B[0][0]+A[0][1]*B[1][0];
	C[0][1] = A[0][0]*B[0][1]+A[0][1]*B[1][1];
        C[1][0] = A[1][0]*B[0][0]+A[1][1]*B[1][0];
        C[1][1] = A[1][0]*B[0][1]+A[1][1]*B[1][1]; 
    	return C;
	}
	
	int** a = newMatrix(0, 0, A, dim);
	int** b = newMatrix(0, dim/2, A, dim);
	int** c = newMatrix(dim/2, 0, A, dim);
	int** d = newMatrix(dim/2, dim/2, A, dim);
	
	int** e = newMatrix(0, 0, B, dim);
	int** f = newMatrix(0, dim/2, B, dim);
	int** g = newMatrix(dim/2, 0, B, dim);
	int** h = newMatrix(dim/2,dim/2, B, dim);
	
	int** p1 = Strassen(a, subMatrix(f,h,dim/2), dim/2);
	int** p2 = Strassen(addMatrix(a,b,dim/2),h,dim/2);
	int** p3 = Strassen(addMatrix(c,d,dim/2),e,dim/2);
	int** p4 = Strassen(d,subMatrix(g,e,dim/2),dim/2);
	int** p5 = Strassen(addMatrix(a,d,dim/2),addMatrix(e,h,dim/2),dim/2);
	int** p6 = Strassen(subMatrix(b,d,dim/2),addMatrix(g,h,dim/2),dim/2);
	int** p7 = Strassen(subMatrix(a,c,dim/2),addMatrix(e,f,dim/2),dim/2);
	
	int** C1 = subMatrix(addMatrix(addMatrix(p5,p4,dim/2),p6,dim/2),p2,dim/2);
	int** C2 = addMatrix(p1,p2,dim/2);
	int** C3 = addMatrix(p3,p4,dim/2);
	int** C4 = subMatrix(subMatrix(addMatrix(p1,p5,dim/2),p3,dim/2),p7,dim/2);

	for(int i = 0; i < dim/2; i++){
		for(int j  = 0; j < dim/2; j++){
			C[i][j] = C1[i][j];
		}
	}
	for(int i = 0; i < dim/2; i++){
		for(int j = dim/2; j < dim; j++){
			C[i][j] = C2[i][j-dim/2];
		}
	}
	for(int i = dim/2; i < dim; i++){
		for(int j = 0; j < dim/2; j++){
			C[i][j] = C3[i-dim/2][j];
		}
	}
	for(int i = dim/2; i < dim; i++){
		for(int j = dim/2; j < dim; j++){
			C[i][j] = C4[i-dim/2][j-dim/2];
		}
	}
    return C;

}

#endif

