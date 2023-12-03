#include <iostream>
void main()

{
    using namespace std;
    float x, e = 0.001, a = -2, b = 2, counter=0;

    do {
        x = (a + b) / 2;

        if ((pow(x, 3) + 2 * x + 4) * (pow(a, 3) + 2 * a + 4) <= 0)
            b = x;
        else
            a = x;
        counter++;
        cout << x << endl;
    } while (abs(a - b) >= 2 * e);
    cout << counter;
}