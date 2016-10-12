# include <iostream>
# include <cmath>
# include "matrix.hpp"

using namespace std;

int main(int argc, char**) {

    // Размерность матрицы
    int n;
    // Считываем размерность матрицы
    cin >> n;

    // Матрица системы и Q матрица в RQ разложении
    Matrix A(n), Q = Matrix::E(n);
    // Вектор b в Ax = b
    Vector b(n);

    cout.setf(std::ios::fixed);
    cout.precision(8);

    // Считываем A
    cin >> A;
    cout << endl;
    // Считываем b
    cin >> b;

    for (int i = 0; i < n - 1; i++) {
        if (A[i][i] == 0.) {
            int j;
            for (j = i + 1; j < n && A[j][i] == 0; j++);
            for (int k = i; k < n; k++) {
                A[i][k] += A[j][k];
            }
            b[i] += b[j];
        }

        for (int j = i + 1; j < n; j++) {

            double r = sqrt(A[i][i] * A[i][i] + A[j][i] * A[j][i]);
            double c = A[i][i] / r;
            double s = - A[j][i] / r;

            for (int k = i + 1; k < n; k++) {
                r = A[i][k] * c - A[j][k] * s;
                A[j][k] = A[i][k] * s + A[j][k] * c;
                A[i][k] = r;

                r = Q[i][k] * c - Q[j][k] * s;
                Q[j][k] = Q[i][k] * s + Q[j][k] * c;
                Q[i][k] = r;

                cout << A;
            }
        }
    }

    cout << ~Q * Q;

    // Применяем преобразование Q к вектору B
    Matrix d = ~(b * ~Q);

    cout << d;

    // Обратный ход Гаусса
    for (int i = n - 1; i >= 0; i--) {
        for (int j = i + 1; j < n; j++) {
            d[i][0] -= A[i][j] * d[j][0];
        }
        d[i][0] /= A[i][i];
    }

    for (int i = 0; i < n; i++) {
        cout << "x" << i + 1 << " = " << d[i][0] << endl;
    }


    return 0;
}
