#ifndef IO_HPP
#define IO_HPP

int init();

double **MT_create(int n);
void MT_delete(double **mt, int n);

double *vector_create(int n);
void vector_delete(double *v);

void ans_print(double *ans, int N);
void ans_delete(double *ans);

#endif