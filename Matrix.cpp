#include <iomanip>
#include <iostream>
#include "ThreadedStrassen.h"
#include <cstdlib>
#include <pthread.h>

using namespace std;
int** BF_MatrixMult(int** A, int** B, int n);

int main(){

	int**a = new int*[9];
	int**b = new int*[9];
	for(int i = 0; i < 9; i++){
   	a[i] = new int[9];
	b[i] = new int[9];
      for(int j = 0; j < 9; j++){
   	   a[i][j] = rand() % 10;
         b[i][j] = rand() % 10;
         cout << a[i][j] << " ";
      }
      cout << endl;
   }
   cout << endl;
   for(int i = 0; i < 9; i++){
      for(int j = 0; j < 9; j++){
         cout << b[i][j] << " ";
      }
      cout << endl;
   }
   cout << endl;
   int** d = BF_MatrixMult(a,b,9);			
   cout << "About to start strassen..." << endl;
   int** c = ThreadedStrassen(a,b,9);
   cout << "The answer: " << endl;
   for(int i = 0; i < 9; i++){
       for(int j = 0; j < 9; j++){

            cout << setw(5)<<d[i][j] << " ";
        }
        cout << endl;
   }
	cout << endl << endl;
  for(int i = 0; i < 9; i++){
       for(int j = 0; j < 9; j++){

            cout << setw(5)<<c[i][j] << " ";
        }
        cout << endl;
   }
	return 0;
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


