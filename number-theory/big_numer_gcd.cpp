#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// advanced gcd ->when one number is very big

int gcd(ll a, ll mod)
{
    if (mod == 0)
    {
        return a;
    }
    return gcd(mod, a % mod);
}

int reduce(int a, string b)
{
    int mod = 0;
    if (b.size() == 0)
    {
        return a;
    }
    if (a == 0)
    {
        int num = 0;
        for (int i = 0; i < b.size(); i++)
        {
            num = num * 10 + b[i] - '0';
        }
        return num;
    }
    for (int i = 0; i < b.size(); i++)
    {
        mod = (mod * 10 + b[i] - '0') % a;
    }

    return gcd(a, mod);
}

int main()
{
    ll a;
    string b;
    cin >> a >> b;
    ll ans = reduce(a, b);
    cout << ans << endl;
}