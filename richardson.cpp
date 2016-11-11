# include <iostream>
# include <fstream>
# include <cmath>
# include "matrix.hpp"

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

    in >> l_min;
    cout << l_min << endl;
    in >> l_max;
    cout << l_max << endl;
    cout << endl;

    Vector x(n), x_n(n);

    double w0 = - (l_max - l_min)/(l_min + l_max);
    double w = w0, w_n = - 1/(2 * (l_max + l_min)/(l_max - l_min) + w);

    int k = 0;

    while (((A*~x_n).toVector() - b).length() > 0.000000001) {

        Vector t = x_n + w * w_n * (x_n - x) - 2 / (l_min + l_max) * (1 + w * w_n) * (A*~x_n - ~b).toVector();

        x = x_n;
        x_n = t;

        w = w_n;
        w_n = - 1/(2 * (l_max + l_min)/(l_max - l_min) + w);

        k++;
    }

    cout << x_n << endl;
    cout << k;
    cout << endl;
}
