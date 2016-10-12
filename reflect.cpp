# include <iostream>

# include "matrix.hpp"

using namespace std;

Vector e(int n, int i) {
    Vector e(n);
    e[i] = 1;
    return e;
}

double sgn(double x) {
    if (x > 0) return 1;
    return -1;
}

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

    for (int i = 0; i < n-1; i++) {
        // Получаем i-ый вектор-столбец
        Vector t = (~A)[i];
        // Зануляем, все элементы над i-ым
        for (int j = 0; j < i; j++) {
            t[j] = 0;
        }
        // Находим вектор w необходимый для преобразования Хаусхолдера
        Vector w = (t - sgn(-t[i]) * t.length() * e(n, i)).normalized();
        // Находим матрицу преобразования
        Matrix H = Matrix::E(n) - 2 * ~w * w;
        // Применяем преобразование Хаусхолдера к A
        // Мы на шаг ближе к R из A = QR
        A = H * A;
        // Применяем к Q
        Q = H * Q;

        //cout << H << t * H << A << Q;
    }

    //cout << Q * ~Q;

    // Применяем преобразование Q к вектору B
    Matrix d = Q * ~b;

    //cout << A << d;

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
