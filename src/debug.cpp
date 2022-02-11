#include <iostream>
#include <iomanip>
#include "debug.hpp"

using namespace std;

void debug_MT_print(double **mt, int N)
{
    for (size_t i = 0; i < N; i++)
    {
        for (size_t j = 0; j < N - 1; j++)
            cout << setiosflags(ios::left) << setw(6) << setprecision(3) << mt[i][j] << ' ';
        cout << setiosflags(ios::left) << setw(6) << setprecision(3) << mt[i][N - 1] << endl;
    }
}

void debug_vector_print(double *v, int N)
{
    for (size_t i = 0; i < N; i++)
    {
        cout << setiosflags(ios::left) << setprecision(3) << v[i] << endl;
    }
}
