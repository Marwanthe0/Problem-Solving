#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define N 1e5
#define endl "\n"
#define all(v) v.begin(), v.end()
#define forn for (int i = 0; i < n; i++)
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
vector<bool> prime(N, true);
void sieve()
{
    for (int p = 2; p * p <= N; p++)
    {

        if (prime[p] == true)
        {
            for (int i = p * p; i <= N; i += p)
                prime[i] = false;
        }
    }
    // for (int p = 2; p <= N; p++)
    //     if (prime[p])
    //         cout << p << " ";
}

void marwan()
{
    int n, count = 0;
    cin >> n;
    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j * j <= i; j++)
        {
            if (i % j == 0)
            {
                int a = i, b = j;
                int x = (a * b) / (__gcd(a, b) * __gcd(a, b));
                if (prime[x] && a && b)
                    count++, cout << a << " " << b << endl;
                if ((i / j) != j)
                {
                    a = i / j;
                    x = (a * b) / (__gcd(a, b) * __gcd(a, b));
                    if (prime[x] && a && b)
                        count++, cout << a << " " << b << endl;
                }
            }
            cout << endl;
        }
    }
    cout << count++ << endl;
    cout << "SHESH" << endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    sieve();
    int t;
    cin >> t;
    while (t--)
    {
        marwan();
    }
    return 0;
}