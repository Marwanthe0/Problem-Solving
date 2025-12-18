#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define N 1000000
#define endl "\n"
#define all(v) v.begin(), v.end()
#define forn for (int i = 0; i < n; i++)
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
vector<int> primes;
vector<bool> dv(100000);
void sieve(int n)
{
    dv[0] = dv[1] = true;
    for (int i = 2; i * i <= n; i++)
    {
        if (dv[i] == false)
        {
            for (int j = i * i; j < n; j += i)
            {
                dv[j] = true;
            }
        }
    }
    for (int i = 1; i < n; i++)
    {
        if (dv[i] == false)
            primes.push_back(i);
    }
}
void marwan()
{
    int n;
    cin >> n;
    int ans = 1, x = 1;
    for (int i = 0; i < 2; i++)
    {
        x = *lower_bound(all(primes), x + n);
        // cerr << x << " ";
        ans *= x;
    }
    // cerr << endl;
    cout << ans << endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    for (int i = 0; i < 100000; i++)
        dv[i] = false;
    sieve(100000);
    // for (auto vl : primes)
    //     cerr << vl << " ";
    // cerr << endl;
    int t;
    cin >> t;
    while (t--)
    {
        marwan();
    }
    return 0;
}