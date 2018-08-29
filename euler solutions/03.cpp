#include <bits/stdc++.h>
using namespace std;

//program to find largest prime factor of any number(10^18)

long long max_prime(long long n)
{
    long long max = -1;
    while (n % 2 == 0)
    {
        max = 2;
        n = n / 2;
    }

    for (int i = 3; i < sqrt(n); i += 2)
    {
        while (n % i == 0)
        {
            max = i;
            n = n / i;
        }
    }

    if (n > 2)
    {
        max = n;
    }
    return max;
}

int main()
{
    long long n;
    cin >> n;
    cout << max_prime(n);
}