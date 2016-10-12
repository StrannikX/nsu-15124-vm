# ifndef MATRIX_HPP
# define MATRIX_HPP

# include <vector>
# include <iostream>

class Matrix {

    std::vector<std::vector<double> > matrix;
    int n; int m;

public:

    Matrix(int);
    Matrix(int, int);
    Matrix(std::vector<double> const &v);
    Matrix(Matrix const&);

    Matrix& operator=(Matrix const&);
    std::vector<double>& operator[](int i);
    Matrix operator~(void);

    int rows_count();
    int colls_count();

    friend Matrix operator+(Matrix const&, Matrix const&);
    friend Matrix operator-(Matrix const&, Matrix const&);
    friend Matrix operator*(Matrix const&, Matrix const&);

    friend Matrix operator*(double const, Matrix const&);
    friend Matrix operator*(Matrix const&, double const);

    friend Matrix operator/(Matrix const&, double const);
    friend std::ostream& operator<<(std::ostream&, Matrix const&);
    friend std::istream& operator>>(std::istream&, Matrix&);

    static Matrix E(int n);
};

class Vector {
    double *el;
    int n;
    public:
        Vector(int);
        Vector(Vector const&);
        Vector(std::vector<double> const&);
        Vector& operator=(Vector const&);

        ~Vector();

        Matrix operator~();

        operator Matrix();

        double operator[] (int i) const;
        double& operator[] (int i);

        int size();

        double length();

        Vector normalized();

    friend double operator*(Vector const&, Vector const&);
    friend Vector operator+(Vector const&, Vector const&);
    friend Vector operator-(Vector const&, Vector const&);

    friend Vector operator*(double const, Vector const&);
    friend Vector operator*(Vector const&, double const);

    friend Vector operator/(Vector const&, double const);

    friend std::ostream& operator<<(std::ostream&, Vector const&);
    friend std::istream& operator>>(std::istream&, Vector&);
};

Matrix operator+(Matrix const&, Matrix const&);
Matrix operator-(Matrix const&, Matrix const&);
Matrix operator*(Matrix const&, Matrix const&);
Matrix operator*(Matrix const&, Matrix const&);

Matrix operator*(double const, Matrix const&);
Matrix operator*(Matrix const&, double const);

Matrix operator/(Matrix const&, double const);

std::ostream& operator<<(std::ostream&, Matrix const&);
std::istream& operator>>(std::istream&, Matrix&);

double operator*(Vector const&, Vector const&);
Vector operator+(Vector const&, Vector const&);
Vector operator-(Vector const&, Vector const&);

Vector operator*(double const, Vector const&);
Vector operator*(Vector const&, double const);

Vector operator/(Vector const&, double const);

std::ostream& operator<<(std::ostream&, Vector const&);
std::istream& operator>>(std::istream&, Vector&);

# endif // MATRIX_HPP
