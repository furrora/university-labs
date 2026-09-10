#include <iostream>
using namespace std;

int main()
{
    // переменные
    int n = 6;
    double a[n] = {0,-1,-1,-1,-1,-1};
    double b[n] = {1,6,6,6,6,6};
    double c[n] = {0,-1,-2,-3,-4,0};
    double f[n] = {1,8,9,10,11,7};
    double P[n], Q[n], x[n];

    P[0] = c[0] / b[0];
    Q[0] = f[0] / b[0];

    // прямой обход

    for (int i = 1; i < n; i++)
    {   
        double den = b[i] - a[i] * P[i-1];
        P[i] = c[i] / den;
        Q[i] = (f[i] + a[i] * Q[i-1]) / den;
    }

    // обратный обход

    x[n - 1] = Q[n - 1];
    
    for (int i = n - 2; i >= 0; i--)
    {
        x[i] = P[i] * x[i + 1] + Q[i];
    }
    
    // вывод

    cout << "result:" << endl;

    for (int i = 0; i < n; i++)
        cout << "x" << i + 1 << " = " << x[i] << " ";   
    
    return 0;
}