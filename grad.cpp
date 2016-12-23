# include <iostream>
# include <fstream>
# include <cmath>
# include "matrix.hpp"
# include "matrix.cpp"

using namespace std;

int main(int argc, char**) {

    ifstream in("input.txt");

    // Размерность матрицы
    int n;
    // Считываем размерность матрицы
    in >> n;
    cout << n << endl;

    // Матрица системы
    Matrix A(n);
    // Вектор b в Ax = b
    Vector b(n);

    double l_min, l_max;

    cout.setf(std::ios::fixed);
    cout.precision(8);

    // Считываем A
    in >> A;
    cout << A;
    cout << endl;
    // Считываем b
    in >> b;
    cout << b << endl;

    Vector x(n);
    Vector r = b - (A * ~x).toVector();
    Vector r_prev(n);
    Vector z = r;
    double a, c;
    int k = 0;

    while ((b - (A * ~x).toVector()).length() > 0.00001) {
        Vector az = (A * ~z).toVector();
        a = r * r / (az * z);
        x = x + a * z;
        r_prev = r;
        r = r - a * az;
        c = (r * r) / (r_prev * r_prev);
        z = r + c * z;
        ++k;
    }

    cout << x << endl;
    cout << k;
    cout << endl;

    return 0;
}
