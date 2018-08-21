#include <bits/stdc++.h>
using namespace std;

class Triplet
{
  public:
    int gcd;
    int x;
    int y;
};

Triplet gcdExtendedEuclid(int a, int b)
{
    if (b == 0)
    {
        Triplet myans;
        myans.gcd = a;
        myans.x = 1;
        myans.y = 0;
        return myans;
    }
    Triplet smallans = gcdExtendedEuclid(b, a % b);
    Triplet myans;
    myans.gcd = smallans.gcd;
    myans.x = smallans.y;
    myans.y = (smallans.x - ((a / b) * (smallans.y)));
    return myans;
}

int gcd(int a, int b)
{
    if (a < b)
    {
        return gcd(b, a);
    }
    if (b == 0)
    {
        return a;
    }
    gcd(a, b % a);
}

int main()
{
    int a, b;
    cin >> a >> b;
    Triplet myans = gcdExtendedEuclid(a, b);
    cout << myans.gcd << " " << myans.x << " " << myans.y;
    return 0;
}
