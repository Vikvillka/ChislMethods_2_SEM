#include <iostream>
#include <vector>

using namespace std;

int main()
{
    // ������ ������� �������������
    vector<vector<double>> A = { {1, -1, 2, -1},
                                {2, 0, 4, 1 },
                                {1, 1, 3,-1},
                                {2, 1, 5,-2} };

    // ������ ������ ������ ������
    vector<double> b = { 1, 4, 2, 3 };

    // ����������� �������
    int n = A.size();
    // ����� �������
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << A[i][j] << "\t";
        }
        cout << b[i] << endl;
    }
    // ������ ��� ������ ������
    for (int k = 0; k < n - 1; k++) {
        for (int i = k + 1; i < n; i++) {
            double coeff = A[i][k] / A[k][k];
            for (int j = k; j < n; j++) {
                A[i][j] -= coeff * A[k][j]; // A[i][j] = A[i][j] - coeff * A[k][j];
            }
            b[i] -= coeff * b[k];
        }
    }
    // ����� �������
    cout << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << A[i][j] << "\t";
        }
        cout << b[i] << endl;
    }

    // �������� ��� ������ ������
    vector<double> x(n);
    for (int i = n - 1; i >= 0; i--) {
        double s = 0;
        for (int j = i + 1; j < n; j++) {
            s += A[i][j] * x[j]; 
        }
        x[i] = (b[i] - s) / A[i][i];
    }

    // ����� �������
    for (int i = 0; i < n; i++) {
        cout << "x" << i + 1 << " = " << x[i] << endl;
    }

    return 0;
}
