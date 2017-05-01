#ifndef POLY_REG
#define POLY_REG

#include <cmath>
#include <vector>
#include "Shapes.h"

double** matTranspose(double** A, int r, int c);
double* matMult1D(double ** A, double* b, int n, int deg);
void gaussJordan(double** A, int n);
void multRow(double** A, int r, int n, double val);
void rowAdd(double **A, int r1, int r2, int n, double multFact);
void choosePivot(double** A, int r, int n);
double** notSquareMatMult(double** A, double**B, int firstD, int middleD, int lastD);
vector<double> polyReg(vector<Point> &points, int deg);

#endif
