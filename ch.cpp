# include <iostream>

# include "matrix.cpp"

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

    Vector solution = A.solve(b);
    for (int i = 0; i < n; ++i) {
        cout << solution[i] << " ";
    }
    cout << endl;
}
