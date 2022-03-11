#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include "io.hpp"
#include "debug.hpp"
using namespace std;
extern double **MT;
extern double *vectorB;
int init()
{
    int n;

    cout << "Please enter the number N, which means N*N matrix:" << endl;
    cin >> n;
    return n;
}

bool judge_input_from_file()
{
    cout << "Do you want load matrix from file?" << endl;
    cout << "If you want, please enter Y otherwise enter n" << endl;
    return getchar() == 'Y';
}
void load_file(int *pN, double **mt, double *v)
{
    cout << "Please input file path:\n";
    ifstream file;
    char path[1000];
    cin.getline(path, 800);
    file.open(path);
    if (!file)
    {
        cout << "error" << endl;
        exit(1);
    }
    cout << "\nPlease choose the format,\n"
         << "For Equation likes this:\n3*3\n";
    cout << "a1X+a2Y+a3Z=b1\n"
         << "a4X+a5Y+a6Z=b2\n"
         << "a7X+a8Y+a9Z=b3\n";
    cout << "\nChoose 1 stand for:   Choose 2 stand for:\n";
    cout << "N                     N\n"
         << "a1 a2 a3 b1           a1 a2 a3\n"
         << "a4 a5 a6 b2           a4 a5 a6\n"
         << "a7 a8 a9 b3           a7 a8 a9\n";
    cout << "                      b1 b2 b3\n";
    char ch;
    while (true)
    {
        cin.get(ch);
        if (ch == '1')
        {
            string temp;
            getline(file, temp);
            *pN = stoi(temp);

            MT = new double *[*pN];
            for (size_t i = 0; i < *pN; i++)
                MT[i] = new double[*pN];

            vectorB = new double[*pN];

            string str = "";
            getline(file, temp);
            str = str + " " + temp;
            getline(file, temp);
            str = str + " " + temp;
            getline(file, temp);
            str = str + " " + temp;

            string space_delimiter = " ";
            vector<string> nums;

            size_t pos = 0;
            while ((pos = str.find(space_delimiter)) != string::npos)
            {
                nums.push_back(str.substr(0, pos));
                str.erase(0, pos + space_delimiter.length());
            }
            nums.push_back(str);
            MT[0][0] = stod(nums[1]);
            MT[0][1] = stod(nums[2]);
            MT[0][2] = stod(nums[3]);
            MT[1][0] = stod(nums[5]);
            MT[1][1] = stod(nums[6]);
            MT[1][2] = stod(nums[7]);
            MT[2][0] = stod(nums[9]);
            MT[2][1] = stod(nums[10]);
            MT[2][2] = stod(nums[11]);
            vectorB[0] = stod(nums[4]);
            vectorB[1] = stod(nums[8]);
            vectorB[2] = stod(nums[12]);
            file.close();
            break;
        }
        else if (ch == '2')
        {
            string temp;
            getline(file, temp);
            *pN = stoi(temp);

            MT = new double *[*pN];
            for (size_t i = 0; i < *pN; i++)
                MT[i] = new double[*pN];

            vectorB = new double[*pN];

            string str = "";
            getline(file, temp);
            str = str + " " + temp;
            getline(file, temp);
            str = str + " " + temp;
            getline(file, temp);
            str = str + " " + temp;
            getline(file, temp);
            str = str + " " + temp;

            string space_delimiter = " ";
            vector<string> nums;

            size_t pos = 0;
            while ((pos = str.find(space_delimiter)) != string::npos)
            {
                nums.push_back(str.substr(0, pos));
                str.erase(0, pos + space_delimiter.length());
            }
            nums.push_back(str);
            MT[0][0] = stod(nums[1]);
            MT[0][1] = stod(nums[2]);
            MT[0][2] = stod(nums[3]);
            MT[1][0] = stod(nums[4]);
            MT[1][1] = stod(nums[5]);
            MT[1][2] = stod(nums[6]);
            MT[2][0] = stod(nums[7]);
            MT[2][1] = stod(nums[8]);
            MT[2][2] = stod(nums[9]);
            vectorB[0] = stod(nums[10]);
            vectorB[1] = stod(nums[11]);
            vectorB[2] = stod(nums[12]);

            break;
        }
        else
        {
            cout << "Its not a right choise!" << endl;
        }
    }
}

double **MT_create_from_keyboard(int n)
{
    double **mt = new double *[n];
    for (size_t i = 0; i < n; i++)
        mt[i] = new double[n];
    cout << "Please enter the Matrix from keyboard:" << endl;
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

double *vector_create_from_keyboard(int n)
{
    double *vB = new double[n];
    cout << "Please enter the vector B from keyboard:" << endl;
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
    if (ans == nullptr)
        cout << "No answer or have infinite answer" << endl;
    else
    {
        cout << "Vector x* is:" << endl;
        for (size_t i = 0; i < N; i++)
        {
            cout << setiosflags(ios::left) << setw(6) << setprecision(3) << ans[i] << endl;
        }
        double vectorR[N];
        for (size_t i = 0; i < N; i++)
        {
            double sum = 0;
            for (size_t j = 0; j < N; j++)
            {
                sum += ans[i] * MT[i][j];
            }
            vectorR[i] = sum - *(vectorB + i);
        }
/*         
        cout << "Vector r is:" << endl;
        for (size_t i = 0; i < N; i++)
        {
            cout << setiosflags(ios::left) << setw(6) << setprecision(3) << vectorR[i] << endl;
        }
*/
    }
}

void ans_delete(double *ans)
{
    delete[] ans;
}
