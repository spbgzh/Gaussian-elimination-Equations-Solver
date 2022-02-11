#ifndef IO_HPP
#define IO_HPP

int init();
bool judge_input_from_file();
void load_file(int *N, double **mt, double *v);

double **MT_create_from_keyboard(int n);
void MT_delete(double **mt, int n);

double *vector_create_from_keyboard(int n);
void vector_delete(double *v);

void ans_print(double *ans, int N);
void ans_delete(double *ans);

#endif