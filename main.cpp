# include <iostream>
# include <cmath>
# include <cstdlib>
# include <vector>

using namespace std;

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
    int n;

    cin >> n;

    vector<vector<double> > matrix(n);
    vector<double> vec(n);

    for (int i = 0; i < n; i++) {
        matrix[i] = *(new vector<double>(n));
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    cout << endl;

    for (int i = 0; i < n; i++) {
        cin >> vec[i];
    }

    for (int i = 0; i < n; i++) {
        double el = matrix[i][i];

        if (el == 0.) {
            int j = 0;
            for (j = i + 1; matrix[j][i] == 0 && j < n; j++);
            if (j == n) cerr << "error";

            for (int l = 0; l < n; l++) {
                matrix[i][l] += matrix[j][l];
            }
            vec[i] += vec[j];

            el = matrix[i][i];

            print_matrix(matrix, vec);
        }

        for (int j = i + 1; j < n; j++) {
            double k = - matrix[j][i] / el;
            for (int l = 0; l < n; l++) {
                matrix[j][l] += matrix[i][l] * k;
            }
            vec[j] += vec[i] * k;
        }

        for (int j = 0; j < n; j++) {
            matrix[i][j] /= el;
        }
        vec[i] /= el;

        print_matrix(matrix, vec);
    }

    print_matrix(matrix, vec);

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
