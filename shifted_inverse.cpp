# include <iostream>
# include <fstream>
# include <cmath>
# include "matrix.cpp"
# define EPS 0.000000000000001

using namespace std;

int main(int argc, char**) {

    ifstream in("input.txt");

    // Размерность матрицы
    int n;
    // Считываем размерность матрицы
    in >> n;

    double a, c = 1, c_prev = 1.5;

    // Матрица системы и Q матрица в RQ разложении
    Matrix A(n);

    cout.setf(std::ios::fixed);
    cout.precision(8);

    // Считываем A
    in >> A;
    in >> a;
    cout << endl;

    Vector x(n), y(n);
    Matrix B = (A - a * Matrix::E(n));
    // B = B.inverse();

    for (int i = 0; i < n; i++)
        x[i] = 1;

    double l = 0;

    while (abs(c - c_prev) > EPS) {
        // y = (B * ~x).toVector();
        y = B.solve(x);
        c_prev = c;
        c = (y * x) / (x * x);
        x = y.normalized();
    }

    l = 1/c + a;
    cout << l << endl;

    return 0;
}
