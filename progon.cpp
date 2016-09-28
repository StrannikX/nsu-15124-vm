# include <cstdio>
# include <iostream>
# include <cmath>
# include <vector>

using namespace std;

int main(int argc, char**) {

    // Размерность матрицы
    int n;
    // Считываем размерность матрицы
    cin >> n;

    // Сама матрица
    vector<vector<double> > a(n);
    // Вектор значений ( b в Ax=b)
    vector<double> vec(n);

    // Вектор для значений P
    std::vector<double> p(n - 1);

    // Считываем матрицу A
    for (int i = 0; i < n; i++) {
        a[i] = vector<double>(n);
        // Считываем строку
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    cout << endl;

    // Считываем вектор значений b
    for (int i = 0; i < n; i++) {
        cin >> vec[i];
    }

    p[0] = - a[0][1] / a[0][0];
    for (int i = 1; i < n - 1; i++) {
        p[i] = a[i][i + 1] / 
    }

    return 0;
}
