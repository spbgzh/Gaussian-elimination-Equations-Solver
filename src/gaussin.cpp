#include <iostream>
#include "debug.hpp"
#include "gaussin.hpp"

double *gaussin(double **a, double *b, int n)
{
    for (size_t i = 0; i < n - 1; i++)
    {
        if (a[i][i] == 0)
        {
        
        }
        for (size_t k = i + 1; k < n; k++)
        {
            double c = a[k][i] / a[i][i];
            a[k][i] = 0;
            for (size_t j = i + 1; j < n; j++)
            {
                a[k][j] = a[k][j] - 1.0 * c * a[i][j];
            }
            b[k] = b[k] - 1.0 * c * b[i];
        }
    }

    std::cout << "Upper triangular matrix" << std::endl;
    debug_MT_print(a, n);
    std::cout << "The transformed vector b:" << std::endl;
    debug_vector_print(b, n);

    double *x = new double[n];
    for (int i = n - 1; i >= 0; i--)
    {
        double s = 0;
        for (int j = i + 1; j < n; j++)
        {
            s = s + a[i][j] * x[j];
        }
        x[i] = (b[i] - s) / a[i][i];
    }
    return x;
}