# include <cstdio>
# include <iostream>
# include <cmath>
# include <vector>

/*
*   Будем считать, что матрица имеет вид
*  --------------------------------------
*  | -b1  g1  0   0  ...  0   0  |  d1  |
*  |  a2 -b2  g2  0  ...  0   0  |  d2  |
*  |  0   a3 -b3  g3 ...  0   0  |  d3  |
*  | ... ... ... ... ... ... ... | ...  |
*  |  0   0  ... ...  an -bn  gn |  dn  |
*  --------------------------------------
*/

# define A(m, n) m[n][n-1]  // an
# define B(m, n) (-m[n][n]) // bn
# define G(m, n) m[n][n+1]  // gn

using namespace std;

int main(int argc, char**) {

    // Размерность матрицы
    int n;
    // Считываем размерность матрицы
    cin >> n;

    // Сама матрица
    vector<vector<double> > a(n);
    // Вектор значений ( b в Ax=b)
    vector<double> d(n), x(n);

    // Вектор для значений P
    std::vector<double> p(n - 1), q(n - 1);

    // Считываем матрицу A
    for (int i = 0; i < n; i++) {
        a[i] = vector<double>(n);
        // Считываем строку
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    cout << endl;

    // Считываем вектор значений d
    for (int i = 0; i < n; i++) {
        cin >> d[i];
    }

    /*
    *  Приводим матрицу к виду
    *  --------------------------------------
    *  |  1 -p1   0   0  ...  0   0  |  q1  |
    *  |  0  1  -p2   0  ...  0   0  |  q2  |
    *  |  0  0    1  -p3 ...  0   0  |  q3  |
    *  | ... ... ... ... ... ... ... | ...  |
    *  |  0   0   0   0  ...  0   1  |  qn  |
    *  --------------------------------------
    */

    p[0] = G(a, 0) / B(a, 0);
    q[0] = - b[0] / B(a, 0);
    for (int i = 1; i < n - 1; i++) {
        p[i] = G(a, i) / (B(a, i) - A(a, i) * p[i - 1]);
        q[i] = (A(a, i) * q[i - 1] - d[i]) / (B(a, i) - A(a, i) * p[i - 1]);
    }

    /**
    * Обратный ход алгоритм, поиск решения системы
    */

    x[n - 1] = (A(a, n - 1) * q[n - 2] - d[n - 1]) / (B(a, n - 1) - A(a, n - 1) * p[n - 2]);
    for (int i = n - 2; i >= 0; i--) {
        x[i] = p[i] * x[i + 1] + q[i];
    }


    cout.setf(ios_base::fixed);
    for (int i = 0; i < n; i++) {
        cout << "x" << i + 1 << " = " << x[i] << endl;
    }

    return 0;
}
