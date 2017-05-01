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
