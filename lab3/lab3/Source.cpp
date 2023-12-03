#include <iostream> 
#include <cmath> 

using namespace std;

// Функция, которую нужно интегрировать
//double f(double x) {
//    return sin(2*x)*pow(cos(x),3);
//}
double f(double x) {
    return cos(5*x)/x;
}

// Метод трапеций
double trapezoidal(double a, double b, int n) {
    double h = (b - a) / n; // шаг разбиения
    double sum = (f(a) + f(b)) / 2; 
    for (int i = 1; i < n; i++) {
        double x = a + i * h; // текущая точка
        sum += f(x); 
    }
    return sum * h; 
}
//1,6943
// 
// Метод средних прямоугольников
double midpoint(double a, double b, int n) {
    double h = (b - a) / n; 
    double sum = 0; 
    for (int i = 0; i < n; i++) {
        double x = a + (i + 0.5) * h; // середина прямоугольника
        sum += f(x); 
    }
    return sum * h; 
}

// Метод Симпсона
double simpson(double a, double b, int n) {
    double h = (b - a) / n; 
    double sum = f(a) + f(b); // начальная сумма
    for (int i = 1; i < n; i += 2) {
        double x = a + i * h; // нечетная
        sum += 4 * f(x); 
    }
    for (int i = 2; i < n; i += 2) {
        double x = a + i * h; //четная
        sum += 2 * f(x); 
    }
    return sum * h / 3;
}

int main() {
    setlocale(LC_ALL, "rus");
    double a = 2.0, b = 3.0; // границы интегрирования
    /*double exact = -(2*pow(cos(b), 5) - 2*pow(cos(a), 5))/5;*/
    double exact = 1.6943;
    cout << "Точное значение: " << exact << endl; 
    for (int n = 10; n <= 100; n *= 10) { 
        cout << "n = " << n << endl; 
        double T = trapezoidal(a, b, n);
        double M = midpoint(a, b, n); 
        double S = simpson(a, b, n);
        cout << "Метод трапеций: " << T << "\nAбсолютная погрешность: " << abs(T - exact)
            << "\nОтносительная погрешность: " << abs(T - exact) / exact << endl;
        cout << "\nМетод средних прямоугольников: " << M << "\nAбсолютная погрешность: " << abs(M - exact)
            << "\nОтносительная погрешность: " << abs(M - exact) / exact << endl;
        cout << "\nМетод Симпсона: " << S << "\nAбсолютная погрешность: " << abs(S - exact)
            << "\nОтносительная погрешность: " << abs(S - exact) / exact << endl;
    }
    return 0;
}