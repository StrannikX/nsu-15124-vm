# include <iostream>
# include <cmath>
# include <cstdlib>
# include <vector>

using namespace std;

// Печать матрицы и вектора
void print_matrix(vector<vector<double> > matrix, vector<double> vec) {
    cout << endl;
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix.size(); j++) {
            cout << matrix[i][j] << " ";
        }
        cout << " | ";
        cout << vec[i];
        cout << endl;
    }
}

// Печать матрицы и вектора
void print_matrix(vector<vector<double> > matrix) {
    cout << endl;
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix.size(); j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    // Размерность матрицы
    int n;
    // Считываем размерность матрицы
    cin >> n;

    // Сама матрица
    vector<vector<double> > matrix(n);
    // Вектор значений ( b в Ax=b)
    vector<double> vec(n);
    // Определитель
    double det = 1.;
    // Единичная матрица - будет обратной
    vector<vector<double> > inv(n);

    // Считываем матрицу A
    for (int i = 0; i < n; i++) {
        matrix[i] = *(new vector<double>(n));
        inv[i] = *(new vector<double>(n));
        // Считываем строку
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
            inv[i][j] = 0.;
        }
        inv[i][i] = 1.;
    }

    cout << endl;

    // Считываем вектор значений b
    for (int i = 0; i < n; i++) {
        cin >> vec[i];
    }

    // Цикл приведения в треугольному виду
    // По всем строкам
    for (int i = 0; i < n; i++) {
        // Фиксируем диагональный элемент
        double el = matrix[i][i];

        if (el == 0.) {
            int j = 0;
            // Ищем такую строку из последующих
            // i-ый элемент которой не нулевой
            for (j = i + 1; matrix[j][i] == 0 && j < n; j++);

            // Поэлементно прибавляем к i-ой строке j-ую
            for (int l = 0; l < n; l++) {
                matrix[i][l] += matrix[j][l];
                inv[i][l] += inv[j][l];
            }
            // Не забываем про вектор b
            vec[i] += vec[j];
            // Фиксируем новый диагональный элемент
            el = matrix[i][i];
        }

        // По всем строкам ниже i-ой
        for (int j = i + 1; j < n; j++) {
            // Коэффициент, при умножении на который i-ой строки
            //  И прибавлении её к j-ой мы занулим i-ый элемент j-ой строки
            double k = - matrix[j][i] / el;
            for (int l = 0; l < n; l++) {
                matrix[j][l] += matrix[i][l] * k;
                inv[j][l] += inv[i][l] * k;
            }
            vec[j] += vec[i] * k;
        }

        // Делим i-ую строку на диагональный
        for (int j = 0; j < n; j++) {
            matrix[i][j] /= el;
            inv[i][j] /= el;
        }
        vec[i] /= el;

        det *= el;
    }

    print_matrix(matrix, vec);

    // Считаем решенгия
    for (int i = n - 1; i >= 0; i--) {
        for (int j = i + 1; j < n; j++) {
            vec[i] -= matrix[i][j] * vec[j];
        }
    }

    // Доводим процесс поиска обратной до конца
    for (int i = n - 1; i >= 0; i--) {
        for (int j = i - 1; j >= 0; j--) {
            for (int l = 0; l < n; l++) {
                inv[j][l] -= inv[i][l] * matrix[j][i];
            }
        }
    }

    cout << endl;

    for (int i = 0; i < n; i++) {
        cout << "x" << (i + 1) << " = " << vec[i] << endl;
    }

    cout << endl << "Det = " << det << endl << endl << "Inversed matrix" << endl;

    print_matrix(inv);

    for (int i = 0; i < n; i++) {
        delete &(matrix[i]);
        delete &(inv[i]);
    }

    return 0;
}
