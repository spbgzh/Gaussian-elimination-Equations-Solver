#include <iostream>
#include "debug.hpp"
#include "io.hpp"
#include "gaussin.hpp"
using namespace std;
double **MT;
double *vectorB;
int main(int argc, char *argv[])
{
    int N = 0;

    cout << "Linear Algebraic Equations Solver" << endl;
    if (judge_input_from_file())
    {
        getchar();
        load_file(&N, MT, vectorB);
    }
    else
    {
        N = init();
        MT = MT_create_from_keyboard(N);
        vectorB = vector_create_from_keyboard(N);
    }

    // input debug
    /* 
    debug_MT_print(MT, N);
    debug_vector_print(vectorB, N); 
    */

    double *vectorAns = gaussin(MT, vectorB, N);
    ans_print(vectorAns, N);

    MT_delete(MT, N);
    vector_delete(vectorB);
    ans_delete(vectorAns);

    return 0;
}

/*
Test Data

3
2 3 4
5 -6 7
8 9 10
119 80 353

ans
12 13 14

3
5 1 3
1 5 3
4 5 2
2 7 1

ans
-1.15 0.1 2.55
*/
