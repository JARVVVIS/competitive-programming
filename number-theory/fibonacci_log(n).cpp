#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void multiply(int a[2][2], int m[2][2])
{
    int first_val = a[0][0] * m[0][0] + a[0][1] * m[1][0];
    int second_val = a[0][0] * m[0][1] + a[0][1] * m[1][1];
    int third_val = a[1][0] * m[0][0] + a[1][1] * m[1][0];
    int fourth_val = a[1][0] * m[0][1] + a[1][1] * m[1][1];
    a[0][0] = first_val;
    a[0][1] = second_val;
    a[1][0] = third_val;
    a[1][1] = fourth_val;
}

void power(int a[2][2], int n)
{
    if (n == 0 || n == 1)
    {
        return;
    }
    power(a, n / 2);
    //multiply a^n/2 with a^n/2
    multiply(a, a);
    if (n % 2 != 0)
    {
        int m[2][2] = {{1, 1}, {1, 0}};
        multiply(a, m);
    }
}

int fib(int n)
{
    int a[2][2] = {{1, 1}, {1, 0}};
    if (n == 0)
    {
        return 0;
    }
    power(a, n - 1);
    return a[0][0];
}

int main()
{
    int n;
    cin >> n;
    cout << fib(n);
}