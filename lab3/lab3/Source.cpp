#include <iostream> 
#include <cmath> 

using namespace std;

// �������, ������� ����� �������������
//double f(double x) {
//    return sin(2*x)*pow(cos(x),3);
//}
double f(double x) {
    return cos(5*x)/x;
}

// ����� ��������
double trapezoidal(double a, double b, int n) {
    double h = (b - a) / n; // ��� ���������
    double sum = (f(a) + f(b)) / 2; 
    for (int i = 1; i < n; i++) {
        double x = a + i * h; // ������� �����
        sum += f(x); 
    }
    return sum * h; 
}
//1,6943
// 
// ����� ������� ���������������
double midpoint(double a, double b, int n) {
    double h = (b - a) / n; 
    double sum = 0; 
    for (int i = 0; i < n; i++) {
        double x = a + (i + 0.5) * h; // �������� ��������������
        sum += f(x); 
    }
    return sum * h; 
}

// ����� ��������
double simpson(double a, double b, int n) {
    double h = (b - a) / n; 
    double sum = f(a) + f(b); // ��������� �����
    for (int i = 1; i < n; i += 2) {
        double x = a + i * h; // ��������
        sum += 4 * f(x); 
    }
    for (int i = 2; i < n; i += 2) {
        double x = a + i * h; //������
        sum += 2 * f(x); 
    }
    return sum * h / 3;
}

int main() {
    setlocale(LC_ALL, "rus");
    double a = 2.0, b = 3.0; // ������� ��������������
    /*double exact = -(2*pow(cos(b), 5) - 2*pow(cos(a), 5))/5;*/
    double exact = 1.6943;
    cout << "������ ��������: " << exact << endl; 
    for (int n = 10; n <= 100; n *= 10) { 
        cout << "n = " << n << endl; 
        double T = trapezoidal(a, b, n);
        double M = midpoint(a, b, n); 
        double S = simpson(a, b, n);
        cout << "����� ��������: " << T << "\nA��������� �����������: " << abs(T - exact)
            << "\n������������� �����������: " << abs(T - exact) / exact << endl;
        cout << "\n����� ������� ���������������: " << M << "\nA��������� �����������: " << abs(M - exact)
            << "\n������������� �����������: " << abs(M - exact) / exact << endl;
        cout << "\n����� ��������: " << S << "\nA��������� �����������: " << abs(S - exact)
            << "\n������������� �����������: " << abs(S - exact) / exact << endl;
    }
    return 0;
}