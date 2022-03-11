#include <iostream>
#include <cmath>
#include <algorithm>
#include "debug.hpp"
#include "gaussin.hpp"
#define deviation 1e-10

double *gaussin(double **a, double *b, int n)
{
    for (size_t i = 0; i < n - 1; i++)
    {
        if (a[i][i] <= deviation)
        {
            for (size_t j = i + 1; j < n - 1; j++)
            {
                if (fabs(a[j][i]) > deviation)
                {
                    std::swap(a[i], a[j]);
                    std::swap(b[i], b[j]);
                    break;
                }
            }
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

    bool D = false;
    for (size_t i = 0; i < n - 1; i++)
    {
        if (fabs(a[i][i]) <= deviation)
        {
            D = true;
            break;
        }
    }

    double *x = new double[n];
    for (int i = n - 1; i >= 0; i--)
    {
        double s = 0;
        for (int j = i + 1; j < n; j++)
        {
            s = s + a[i][j] * x[j];
        }
        double temp = (b[i] - s) / a[i][i];
        if (fabs(temp) <= deviation)
        {
            x[i] = 0;
        }
        else
        {
            x[i] = temp;
        }
    }
    return x;
}

/*

10 -7 0
-3 2 6
5 -1 5
7 4 6

10 -7 0
-3 2.099 6
5 -1 5
7 3.901 6
*/
