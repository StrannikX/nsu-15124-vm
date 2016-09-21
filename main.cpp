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
    
    // Считываем матрицу A
    for (int i = 0; i < n; i++) {
        matrix[i] = *(new vector<double>(n));
        // Считываем строку
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
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
            }
            // Не забываем про вектор b
            vec[i] += vec[j];
            // Фиксируем новый диагональный элемент
            el = matrix[i][i];

            print_matrix(matrix, vec);
        }
        
        // По всем строкам ниже i-ой
        for (int j = i + 1; j < n; j++) {
            // Коэффициент, при умножении на который i-ой строки
            //  И прибавлении её к j-ой мы занулим i-ый элемент j-ой строки
            double k = - matrix[j][i] / el;
            for (int l = 0; l < n; l++) {
                matrix[j][l] += matrix[i][l] * k;
            }
            vec[j] += vec[i] * k;
        }
        
        // Делим i-ую строку на диагональный
        for (int j = 0; j < n; j++) {
            matrix[i][j] /= el;
        }
        vec[i] /= el;

        print_matrix(matrix, vec);
    }

    print_matrix(matrix, vec);
    
    // Считаем решенгия
    for (int i = n - 1; i >= 0; i--) {
        for (int j = i + 1; j < n; j++) {
            vec[i] -= matrix[i][j] * vec[j];
        }
    }

    cout << endl;

    for (int i = 0; i < n; i++) {
        cout << "x" << (i + 1) << " = " << vec[i] << endl;
    }

    for (int i = 0; i < n; i++) {
        delete &(matrix[i]);
    }

    return 0;
}
