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

    return 0;
}
