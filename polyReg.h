/**
* Authors: Kevin Aud|Jesse McNicoll|Connor Blandin|Jackson Swenson
* Assignment Title: Group Project
* Assignment Description: This header file contains the function prototypes for
*	a polynomial regression function that takes a 2 vectors of ints and a degree
*   for the fit
* Due Date: 5/1/2017
* Date Created: 4/28/2017
* Date Last Modified: 5/1/2017
*/

#ifndef POLY_REG
#define POLY_REG

#include <cmath>
#include <vector>
#include <algorithm>
#include "Shapes.h"

/*
 * description: calculate matrix transpose
 * return: new transposed matrix
 * postcondition: A is unchanged
*/
double** matTranspose(double** A, int r, int c);

/*
 * description: Perform partial pivoting gauss jordan on augmented matrix A
 * return: void
 * postcondition: A is in reduced echelon form
*/
void gaussJordan(double** A, int n);

/*
 * description: multiply row by val
 * return: void
 * postcondition: row r is multiplied by val
*/
void multRow(double** A, int r, int n, double val);

/*
 * description: add r2*multFact to r1
 * return: void
 * postcondition: A is changed
*/
void rowAdd(double **A, int r1, int r2, int n, double multFact);

/*
 * description: choose best pivot in column
 * return: void
 * postcondition: rows are swapped so the largest number is in the pivot position of the column
*/
void choosePivot(double** A, int r, int n);

/*
 * description: matrix multiplication (firstD x middleD)(middleD x lastD)
 * return: product of A and B
 * postcondition: A and C are unchanged
*/
double** notSquareMatMult(double** A, double**B, int firstD, int middleD, int lastD);

/*
 * description: recursive divide and conquer function
 * return: void
 * postcondition: Product of A and B are stored in C
*/
vector<double> polyReg(vector<int> &x,vector<int> &y, int deg);

#endif
