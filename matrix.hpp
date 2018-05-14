# ifndef MATRIX_HPP
# define MATRIX_HPP

# include <vector>
# include <iostream>
# include <utility>

class Vector;

// Класс-матрица
class Matrix {

    std::vector<std::vector<double> > matrix;
    int n; int m;

public:

    Matrix(int); // Создать квадратную матрицу заданного размера
    Matrix(int, int); // Создать прямоугольную матрицу
    Matrix(std::vector<double> const &v); // Создать матрицу из набора векторов
    Matrix(Matrix const&); // Копировать матрицу

    Matrix& operator=(Matrix const&); // Присвоить матрицу
    std::vector<double>& operator[](int i); // Получить строку
    Matrix operator~(void); // Транспонировать матрицу
    Vector toVector();

    int rows_count(); // Количество строк
    int colls_count(); // Количество столбцов

    Matrix inverse(); // Получить обратную матрицу
    std::pair<Matrix, Matrix> qr(); // Получить QR разложение
 
    friend Matrix operator+(Matrix const&, Matrix const&); // Сложить две матрицы
    friend Matrix operator-(Matrix const&, Matrix const&); // Вычисть две матрицы
    friend Matrix operator*(Matrix const&, Matrix const&); // Перемножить две матрицы

    friend Matrix operator*(double const, Matrix const&); // Умножить число на матрицу
    friend Matrix operator*(Matrix const&, double const); // Умножить матрицу на число

    friend Matrix operator/(Matrix const&, double const); // Разделить матрицу на число
    friend std::ostream& operator<<(std::ostream&, Matrix const&); // Распечатать матрицу
    friend std::istream& operator>>(std::istream&, Matrix&); // Считать матрицу

    static Matrix E(int n); // Создать еденичную матрицу размера n

    Vector solve(Vector); // Решить систему с заданной правой частью
};

class Vector {
    double *el;
    int n;
    public:
        Vector(int); // Создать вектор фиксированного размера
        Vector(Vector const&); // Создать копию ветора
        Vector(std::vector<double> const&); // Создать вектор из набора чисел
        Vector& operator=(Vector const&); // Присвоить вектор

        ~Vector();

        Matrix operator~(); // Перевернуть вектор

        operator Matrix(); // Получить матрицу из вектора

        double operator[] (int i) const; // Получить i-ый компонент
        double& operator[] (int i); // Присвоить i-ый компонент

        int size(); // Размер вектора

        double length(); // Длина вектора

        Vector normalized(); // Нормализованный вектор

    friend double operator*(Vector const&, Vector const&); // Скалярное произведение
    friend Vector operator+(Vector const&, Vector const&); // Прибавить число к вектору
    friend Vector operator-(Vector const&, Vector const&); // Вычисть число из вектора

    friend Vector operator*(double const, Vector const&); // Умножить число на вектор
    friend Vector operator*(Vector const&, double const); // Умножить вектор на число

    friend Vector operator/(Vector const&, double const); // Разделить вектор на число

    friend std::ostream& operator<<(std::ostream&, Vector const&); // Распечатать вектор
    friend std::istream& operator>>(std::istream&, Vector&); // Считать вектор

    static Vector e(int, int); // Еденичный вектор
};

Matrix operator+(Matrix const&, Matrix const&); // Сумма матриц
Matrix operator-(Matrix const&, Matrix const&); // Разность матриц
Matrix operator*(Matrix const&, Matrix const&); // Произведение матриц
Matrix operator*(Matrix const&, Matrix const&); // Произведение матриц

Matrix operator*(double const, Matrix const&); // Произведение числа на матрицу
Matrix operator*(Matrix const&, double const); // Произведение матрицу на число

Matrix operator/(Matrix const&, double const); // Разделить матрицу на число

std::ostream& operator<<(std::ostream&, Matrix const&); // Вывести матрицу на печать
std::istream& operator>>(std::istream&, Matrix&); // Считать матрицу

double operator*(Vector const&, Vector const&); // Произведение векторов
Vector operator+(Vector const&, Vector const&); // Сумма векторов
Vector operator-(Vector const&, Vector const&); // Разность векторов

Vector operator*(double const, Vector const&); // Умножить число на вектор
Vector operator*(Vector const&, double const); // Умножить вектор на число

Vector operator/(Vector const&, double const); // Разделить вектор на число

std::ostream& operator<<(std::ostream&, Vector const&); // Распечатать вектор
std::istream& operator>>(std::istream&, Vector&); // Считать вектор

# endif // MATRIX_HPP
