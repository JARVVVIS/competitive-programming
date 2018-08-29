#include <bits/stdc++.h>
using namespace std;

int sieve(int n)
{
    //intialise a bool array of size n+1(0->n)
    bool prime[n + 1];
    //initialise each entry with true
    memset(prime, true, sizeof(prime));

    //optimisation 1
    // check the numbers from 2-sqrt(n)
    for (int i = 2; i * i <= n; i++)
    {
        //if the number is prime
        //mark all the multiples of given numbers as false
        if (prime[i])
        {
            //optimisation 2
            for (int j = i * i; j <= n; j += i)
            {
                prime[j] = false;
            }
        }
    }
    //print 2 seprately as it is the only even prime
    cout << "2" << endl;
    // check for each odd number which are prime
    for (int i = 3; i <= n; i += 2)
    {
        if (prime[i])
        {
            //print primes
            cout << i << endl;
        }
    }
}

//driver function
int main()
{
    //number <= which prime numbers we need to find
    int n;
    cin >> n;
    //sieve function will print for us all the primes <= n
    sieve(n);
    return 0;
}