#include "polyReg.h"

vector<double> polyReg(vector<Point> &points, int deg) {

	double**z = new double*[points.size()];
    double** Y = new double*[points.size()];

    for (int i = 0; i < points.size(); i++) {
        z[i] = new double[deg];
        for (int j = 0; j < deg; j++) {
            z[i][j] = pow(points[i].x, j);
        }
        Y[i] = new double[1];
        Y[i][0] = points[i].y;
    }

    double** zT = matTranspose(z, points.size(), deg);
    double** A1 = notSquareMatMult(zT, z, deg, points.size(), deg);

    for(int i = 0; i < points.size(); i++)
        delete []z[i];
    delete[]z;
    double** A2 = notSquareMatMult(zT, Y, deg, points.size(), 1);

    for(int i = 0; i < deg; i++)
        delete []zT[i];
    for(int i = 0; i < points.size(); i++)
        delete[]Y[i];
    delete[]zT;
    delete[]Y;

    double ** A = new double*[deg];
    for (int i = 0; i < deg; i++) {
        A[i] = new double[deg + 1];
        for (int j = 0; j < deg; j++) {

            A[i][j] = A1[i][j];
        }
        A[i][deg] = A2[i][0];
    }

    for(int i = 0; i < deg; i++){
        delete []A1[i];
        delete []A2[i];
    }
    delete[]A1, A2;
    gaussJordan(A, deg);

    double* a = new double[deg];
    for (int i = 0; i < deg; i++) {
        a[i] = A[i][deg];
    }
    delete[]A;

    cout << "a: ";
    for(int i = 0; i < sizeof(a) / sizeof(double); i++)
        cout << a[i] << ',';
    cout << endl;

    return vector<double>(a, a + sizeof(a) / sizeof(double));

}

double** matTranspose(double** A, int r, int c) {
    double** result = new double*[c];

    for (int i = 0; i < c; i++) {
        result[i] = new double[r];
        for (int j = 0; j < r; j++) {
            result[i][j] = A[j][i];
        }
    }

    return result;
}

void gaussJordan(double** A, int n) {
    for (int i = 0; i < n; i++) {
        choosePivot(A, i, n);
        multRow(A, i, n, 1.0 / A[i][i]);
        for (int j = 0; j < n; j++) {
            if (j != i) {
                rowAdd(A, j, i, n, -A[j][i]);
            }
        }
    }
}

void choosePivot(double** A, int r, int n) {
    int maxNdx = r;
    for (int i = r; i < n; i++) {
        if (A[i][r] > A[maxNdx][r]) {
            maxNdx = r;
        }
    }
    if (r != maxNdx) {
        for (int i = 0; i < n + 1; i++) {
            std::swap(A[r][i], A[maxNdx][i]);
        }
    }
}

void multRow(double** A, int r, int n, double val) {
    for (int i = 0; i < n + 1; i++) {
        A[r][i] *= val;
    }
}

void rowAdd(double **A, int r1, int r2, int n, double multFact) {
    for (int i = 0; i < n + 1; i++) {
        A[r1][i] += multFact*A[r2][i];
    }
}

double** notSquareMatMult(double** A, double**B, int firstD, int middleD, int lastD) {

    double** C = new double*[firstD];
    for (int i = 0; i < firstD; i++) {
        C[i] = new double[lastD];
        for (int j = 0; j < lastD; j++) {
            C[i][j] = 0;
        }
    }

    for (int i = 0; i < firstD; i++) {
        for (int j = 0; j < lastD; j++) {
            for (int k = 0; k < middleD; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return C;
}
