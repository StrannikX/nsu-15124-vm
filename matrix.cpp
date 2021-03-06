# include "matrix.hpp"
# include <cmath>
# include <exception>

Matrix::Matrix(int n, int m) {
    if (n <= 0 || m <= 0) throw std::invalid_argument("Wrong matrix size");

    this->n = n;
    this->m = m;

    matrix = std::vector<std::vector<double> >(n);

    for (int i = 0; i < n; i++) {
        matrix[i] = std::vector<double>(m);
        for (int j = 0; j < m; j++) {
            matrix[i][j] = 0.;
        }
    }
}

Matrix::Matrix(int n) {
    if (n <= 0) throw std::invalid_argument("Wrong matrix size");

    this->n = n;
    this->m = n;

    matrix = std::vector<std::vector<double> >(n);

    for (int i = 0; i < n; i++) {
        matrix[i] = std::vector<double>(n);
        for (int j = 0; j < n; j++) {
            matrix[i][j] = 0.;
        }
    }
}

Matrix::Matrix(Matrix const &a) {
    m = a.m;
    n = a.n;

    matrix = std::vector<std::vector<double> >(n);

    for (int i = 0; i < n; i++) {
        matrix[i] = std::vector<double>(m);
        for (int j = 0; j < m; j++) {
            matrix[i][j] = a.matrix[i][j];
        }
    }
}

Matrix::Matrix(std::vector<double> const &v) {
    Matrix(1, v.size());
    matrix[0] = v;
}

int Matrix::rows_count() {
    return n;
}

int Matrix::colls_count() {
    return m;
}

Matrix& Matrix::operator=(Matrix const &a) {
    m = a.m;
    n = a.n;

    matrix = std::vector<std::vector<double> >(n);

    for (int i = 0; i < n; i++) {
        matrix[i] = std::vector<double>(m);
        for (int j = 0; j < m; j++) {
            matrix[i][j] = a.matrix[i][j];
        }
    }

    return *this;
}

std::vector<double>& Matrix::operator[](int i) {
    if (i < 0 || i > n) throw std::out_of_range("Illegal index");
    return matrix[i];
}


Matrix Matrix::operator~(void) {
    Matrix result(m, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            result.matrix[j][i] = matrix[i][j];
        }
    }
    return result;
}

Matrix operator+(Matrix const &left, Matrix const &right) {
    if (left.n != right.n || left.m != right.m)
        throw std::invalid_argument("The matrices of different sizes!");

    Matrix result(left.n, right.m);
    for (int i = 0; i < left.n; i++) {
        for (int j = 0; j < left.m; j++) {
            result.matrix[i][j] = left.matrix[i][j] + right.matrix[i][j];
        }
    }

    return result;
}

Matrix operator-(Matrix const &left, Matrix const &right) {
    if (left.n != right.n || left.m != right.m)
        throw std::invalid_argument("The matrices of different sizes!");

    Matrix result(left.n, right.m);
    for (int i = 0; i < left.n; i++) {
        for (int j = 0; j < left.m; j++) {
            result.matrix[i][j] = left.matrix[i][j] - right.matrix[i][j];
        }
    }

    return result;
}

Matrix operator*(Matrix const &left, Matrix const &right) {
    if (left.m != right.n)
        throw std::invalid_argument("Matrix mismatched sizes!");

    Matrix result(left.n, right.m);

    for (int i = 0; i < left.n; i++) {
        for (int j = 0; j < right.m; j++) {
            for (int k = 0; k < left.m; k++) {
                result.matrix[i][j] += left.matrix[i][k] * right.matrix[k][j];
            }
        }
    }

    return result;
}

Matrix operator*(double const a, Matrix const& m) {
    Matrix result(m);
    for (int i = 0; i < m.n; i++) {
        for (int j = 0; j < m.m; j++) {
            result.matrix[i][j] = m.matrix[i][j] * a;
        }
    }

    return result;
}

Matrix operator*(Matrix const& m, double const a) {
    Matrix result(m);
    for (int i = 0; i < m.n; i++) {
        for (int j = 0; j < m.m; j++) {
            result.matrix[i][j] = m.matrix[i][j] * a;
        }
    }

    return result;
}

Matrix operator/(Matrix const& m, double const a) {
    if (a == 0.)
        throw std::runtime_error("Division by zero!");

    Matrix result(m);
    for (int i = 0; i < m.n; i++) {
        for (int j = 0; j < m.m; j++) {
            result.matrix[i][j] = m.matrix[i][j] / a;
        }
    }

    return result;
}

Matrix Matrix::E(int n) {
    Matrix result(n,n);
    for (int i = 0; i < n; i++) {
        result[i][i] = 1;
    }
    return result;
}

Vector Matrix::toVector() {
    if (n != 1 && m != 1)
        throw std::invalid_argument("Matrix can't be convert to vector!");
    if (n == 1) {
        Vector v(m);
        for (int  i = 0; i < m; ++i) {
            v[i] = matrix[0][i];
        }
        return v;
    }
    Vector v(n);
    for (int  i = 0; i < n; ++i) {
        v[i] = matrix[i][0];
    }
    return v;
}

std::ostream& operator<<(std::ostream& out, Matrix const& m) {
    for (int i = 0; i < m.n; i++) {
        for (int j = 0; j < m.m; j++) {
            out << m.matrix[i][j] << " ";
        }
        out << std::endl;
    }
    out << std::endl;

    return out;
}

std::istream& operator>>(std::istream& in, Matrix &m) {
    for (int i = 0; i < m.n; i++) {
        for (int j = 0; j < m.m; j++) {
            in >> m.matrix[i][j];
        }
    }

    return in;
}

Vector::Vector(int n) {
    if (n <= 0)
        throw std::invalid_argument("Wrong vector size");
    this->n = n;
    el = new double[n];
    for (int i = 0; i < n; i++) el[i] = 0;
}

Vector::Vector(Vector const &v) {
    n = v.n;
    el = new double[n];
    for (int i = 0; i < n; i++) el[i] = v.el[i];
}

Vector::Vector(std::vector<double> const &v) {
    n = v.size();
    el = new double[n];
    for (int i = 0; i < n; i++) el[i] = v[i];
}

Vector& Vector::operator=(Vector const &v) {
    n = v.n;
    el = new double[n];
    for (int i = 0; i < n; i++) el[i] = v.el[i];
    return *this;
}

Vector::~Vector() {
    delete[] el;
}

Matrix Vector::operator~() {
    Matrix result(n, 1);
    for (int i = 0; i < n; i++) {
        result[i][0] = el[i];
    }
    return result;
}

Vector::operator Matrix() {
    Matrix result(1, n);
    for (int i = 0; i < n; i++) {
        result[0][i] = el[i];
    }
    return result;
}

double Vector::operator[] (int i) const {
    if (i < 0 || i > n) throw std::out_of_range("Illegal index");
    return el[i];
}

double& Vector::operator[] (int i) {
    if (i < 0 || i > n) throw std::out_of_range("Illegal index");
    return el[i];
}

double operator*(Vector const &l, Vector const &r) {
    if (l.n != r.n)
        throw std::invalid_argument("Vectors of different sizes");
    double res = 0.;
    for (int i = 0; i < l.n; i++) {
        res += l.el[i] * r.el[i];
    }
    return res;
}

Vector operator+(Vector const &l, Vector const &r) {
    if (l.n != r.n)
        throw std::invalid_argument("Vectors of different sizes");
    Vector v(l.n);
    for (int i = 0; i < l.n; i++) {
        v.el[i] = l.el[i] + r.el[i];
    }
    return v;
}

Vector operator-(Vector const &l, Vector const &r) {
    if (l.n != r.n)
        throw std::invalid_argument("Vectors of different sizes");
    Vector v(l.n);
    for (int i = 0; i < l.n; i++) {
        v.el[i] = l.el[i] - r.el[i];
    }
    return v;
}

Vector operator*(double const a, Vector const& v) {
    Vector r(v.n);
    for (int i = 0; i < v.n;  i++) {
        r.el[i] = a * v.el[i];
    }
    return r;
}

Vector operator*(Vector const &v, double const a) {
    Vector r(v.n);
    for (int i = 0; i < v.n;  i++) {
        r.el[i] = a * v.el[i];
    }
    return r;
}

Vector operator/(Vector const &v, double const a) {
    if (a == 0.)
        throw std::runtime_error("Division by zero!");
    Vector r(v.n);
    for (int i = 0; i < v.n;  i++) {
        r.el[i] = v.el[i] / a;
    }
    return r;
}

int Vector::size() {
    return n;
}

double Vector::length() {
    return sqrt((*this) * (*this));
}

Vector Vector::normalized() {
    return *this / length();
}

std::ostream& operator<<(std::ostream& out, Vector const& v) {
    for (int i = 0; i < v.n; i++) {
        out << v.el[i] << " ";
    }
    out << std::endl;

    return out;
}

std::istream& operator>>(std::istream& in, Vector &v) {
    for (int i = 0; i < v.n; i++) {
        in >> v.el[i];
    }

    return in;
}

Matrix Matrix::inverse() {
    Matrix inv = Matrix::E(n);
    Matrix matrix = *this;

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
        }

        // Делим i-ую строку на диагональный
        for (int j = 0; j < n; j++) {
            matrix[i][j] /= el;
            inv[i][j] /= el;
        }

        // Доводим процесс поиска обратной до конца
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i - 1; j >= 0; j--) {
                for (int l = 0; l < n; l++) {
                    inv[j][l] -= inv[i][l] * matrix[j][i];
                }
            }
        }

        return inv;
    }
}

Vector Vector::e(int n, int i) {
    Vector e(n);
    e[i] = 1;
    return e;
}

inline double sgn(double x) {return x > 0 ? 1 : -1;}

std::pair<Matrix, Matrix> Matrix::qr() {
    Matrix R = *this, Q = Matrix::E(n);

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

    return std::make_pair(~Q, R);
}

Vector Matrix::solve(Vector b) {
    Vector solution(n);
    std::pair<Matrix, Matrix > QR  = qr();
    Matrix Q = QR.first;
    Matrix R = QR.second;
    // Применяем преобразование Q к вектору B
    Matrix d = ~Q * ~b;
    // Обратный ход Гаусса
    for (int i = n - 1; i >= 0; i--) {
        for (int j = i + 1; j < n; j++) {
            d[i][0] -= R[i][j] * d[j][0];
        }
        d[i][0] /= R[i][i];
    }
    for (int i = 0; i < n; i++) {
        solution[i] = d[i][0];
    }
    return solution;
}
