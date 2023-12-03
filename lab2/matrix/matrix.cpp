#include <iostream>
#include <Eigen/Dense>

using namespace Eigen;

int main()
{
    MatrixXd A(4, 4);
    A << 1, 2, 3,
        4, 5, 6,
        7, 8, 9;

    MatrixXd B(3, 1);
    B << 1, 2, 3;

    // ������� ������� ������� �������� �������
    MatrixXd A_inv = A.inverse();
    MatrixXd X = A_inv * B;

    std::cout << "������� �������: " << std::endl;
    std::cout << X << std::endl;

    return 0;
}

//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//// ������� ��� ������ �������
//void printMatrix(vector<vector<double>> matrix) {
//    for (int i = 0; i < matrix.size(); i++) {
//        for (int j = 0; j < matrix[0].size(); j++) {
//            cout << matrix[i][j] << "\t";
//        }
//        cout << endl;
//    }
//}
//
//// ������� ��� ���������� ������������ �������
//double determinant(vector<vector<double>> matrix) {
//    int n = matrix.size();
//
//    // �������� ������� � ������������������ ����
//    for (int i = 0; i < n - 1; i++) {
//        for (int j = i + 1; j < n; j++) {
//            double factor = matrix[j][i] / matrix[i][i];
//            for (int k = i; k < n; k++) {
//                matrix[j][k] -= factor * matrix[i][k];
//            }
//        }
//    }
//
//    // ��������� ������������ �������
//    double det = 1;
//    for (int i = 0; i < n; i++) {
//        det *= matrix[i][i];
//    }
//
//    return det;
//}
//
//// ������� ��� ���������� �������� �������
//vector<vector<double>> inverse(vector<vector<double>> matrix) {
//    int n = matrix.size();
//
//    // ������� ��������� �������
//    vector<vector<double>> identity(n, vector<double>(n));
//    for (int i = 0; i < n; i++) {
//        identity[i][i] = 1;
//    }
//
//    // �������� ������� � ���������� ����
//    for (int i = 0; i < n; i++) {
//        double factor = matrix[i][i];
//        for (int j = i; j < n; j++) {
//            matrix[i][j] /= factor;
//        }
//        for (int j = 0; j < n; j++) {
//            identity[i][j] /= factor;
//        }
//        for (int j = i + 1; j < n; j++) {
//            factor = matrix[j][i];
//            for (int k = i; k < n; k++) {
//                matrix[j][k] -= factor * matrix[i][k];
//            }
//            for (int k = 0; k < n; k++) {
//                identity[j][k] -= factor * identity[i][k];
//            }
//        }
//
//        // �������� ������� � ������������� ����
//        for (int i = n - 1; i > 0; i--) {
//            for (int j = i - 1; j >= 0; j--) {
//                double factor = matrix[j][i] / matrix[i][i];
//                for (int k = i; k < n; k++) {
//                    matrix[j][k] -= factor * matrix[i][k];
//                }
//                for (int k = 0; k < n; k++) {
//                    identity[j][k] -= factor * identity[i][k];
//                }
//            }
//        }
//
//        return identity;
//    }
//}
//
//    // ������� ��� ������� ������� ���������
//    vector<double> solveEquations(vector<vector<double>> matrix, vector<double> b)
//    {
//        int n = matrix.size();
//        // ����� �������� �������
//        vector<vector<double>> inverseMatrix = inverse(matrix);
//
//        // �������� �������� ������� �� ������� ��������� ������
//        vector<double> solution(n);
//        for (int i = 0; i < n; i++) {
//            double sum = 0;
//            for (int j = 0; j < n; j++) {
//                sum += inverseMatrix[i][j] * b[j];
//            }
//            solution[i] = sum;
//        }return solution;
//    }
//
//        
//        void main() {
//            // ������� �������������
//            vector<vector<double>> matrix = { {1, -1, 2, -1}, {2, 0, 3, 1}, {1, 1, 3, -1} };
//
//            // ������� ��������� ������
//            vector<double> b = { 1, 4, 2,3 };
//
//            // ����� ������� ������� ���������
//            vector<double> solution = solveEquations(matrix, b);
//
//            // ������� �������
//            cout << "�������: ";
//            for (double x : solution) {
//                cout << x << " ";
//            }
//            cout << endl;
//
//          
//        }
//
