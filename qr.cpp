# include <iostream>
# include <cmath>
# include "matrix.cpp"
# define EPS 0.00000001

using namespace std;

Matrix qr(Matrix& A) {
    int n = A.rows_count();
    Matrix R = A, Q = Matrix::E(n);

    for (int i = 0; i < n-1; i++) {
        // Получаем i-ый вектор-столбец
        Vector t = (~R)[i];
        // Зануляем, все элементы над i-ым
        for (int j = 0; j < i; j++) {
            t[j] = 0;
        }
        // Находим вектор w необходимый для преобразования Хаусхолдера
        Vector w = (t - sgn(-t[i]) * t.length() * Vector::e(n, i)).normalized();
        // Находим матрицу преобразования
        Matrix H = Matrix::E(n) - 2 * ~w * w;
        // Применяем преобразование Хаусхолдера к A
        // Мы на шаг ближе к R из A = QR
        R = H * R;
        // Применяем к Q
        Q = H * Q;
    }

    return R * ~Q;
}

double max_above_d(Matrix& a) {
    double s = 0;
    for (int i = 0; i < a.rows_count(); ++i) {
        for (int j = i + 1; j < a.rows_count(); ++j) {
            s += a[j][i] * a[j][i];
        }
    }
    return sqrt(s);
}

int main(int argc, char**) {

    // Размерность матрицы
    int n;
    // Считываем размерность матрицы
    cin >> n;

    // Матрица системы и Q матрица в RQ разложении
    Matrix A(n);

    cout.setf(std::ios::fixed);
    cout.precision(8);

    // Считываем A
    cin >> A;
    cout << endl;

    int i;

    for (i = 0; max_above_d(A) > EPS &&  i < 20; i++) {
        A = qr(A);
    }

    cout << A;

    for (int i = 0; i < n; i++) {
        cout << "l" << i + 1 << " = " << A[i][i] << endl;
    }

    cout << i << endl;

    return 0;
}
