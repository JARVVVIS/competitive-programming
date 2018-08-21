#include <bits/stdc++.h>
using namespace std;

//euclid algorithm a>b -> gcd(a,b) = gcd(b,a%b)
// a%b will always be less than b
// iterate till a%b = 0

int gcd(int a, int b)
{
    if (b > a)
    {
        gcd(b, a);
    }
    if (b == 0)
    {
        return a;
    }
    gcd(b, a % b);
}

int main()
{
    int a, b;
    cin >> a >> b;
    cout << gcd(a, b);
}