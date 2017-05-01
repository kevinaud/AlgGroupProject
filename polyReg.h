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

double** matTranspose(double** A, int r, int c);
void gaussJordan(double** A, int n);
void multRow(double** A, int r, int n, double val);
void rowAdd(double **A, int r1, int r2, int n, double multFact);
void choosePivot(double** A, int r, int n);
double** notSquareMatMult(double** A, double**B, int firstD, int middleD, int lastD);
vector<double> polyReg(vector<int> &x,vector<int> &y, int deg);

#endif
