#include <iostream>
#include <iomanip>
#include "io.hpp"
#include "debug.hpp"
using namespace std;
int init()
{
    int n;
    cout << "Linear Algebraic Equations Solver" << endl;
    cout << "Please enter the number:" << endl;
    cin >> n;
    return n;
}

double **MT_create(int n)
{
    double **mt = new double *[n];
    for (size_t i = 0; i < n; i++)
        mt[i] = new double[n];
    cout << "Please enter the Matrix:" << endl;
    for (size_t i = 0; i < n; i++)
        for (size_t j = 0; j < n; j++)
            cin >> mt[i][j];
    return mt;
}

void MT_delete(double **mt, int n)
{
    for (size_t i = 0; i < n; i++)
        delete[] mt[i];
    delete[] mt;
}

double *vector_create(int n)
{
    double *vB = new double[n];
    cout << "Please enter the vector B:" << endl;
    for (size_t i = 0; i < n; i++)
        cin >> vB[i];
    return vB;
}

void vector_delete(double *v)
{
    delete[] v;
}

void ans_print(double *ans, int N)
{
    cout << "Your ans is:" << endl;
    for (size_t i = 0; i < N; i++)
    {
        cout << setiosflags(ios::left) << setw(6) << setprecision(3) << ans[i] << ' ';
    }
    cout << endl;
}

void ans_delete(double *ans)
{
    delete[] ans;
}
