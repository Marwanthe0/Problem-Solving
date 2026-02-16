#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define N 10000005
#define endl "\n"
#define all(v) v.begin(), v.end()
#define forn for (int i = 0; i < n; i++)
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define minus cout << "-1" << endl
#define make_unique(x) \
    sort(all((x)));    \
    (x).erase(unique(all((x))), (x).end())
vector<int> primes;
vector<bool> check(N, 0);
void sieve()
{
    for (int i = 2; i <= N; i++)
    {
        if (!check[i])
        {
            for (int j = i * i; j <= N; j += i)
            {
                check[j] = true;
            }
        }
    }
    for (int i = 2; i <= N; i++)
        if (!check[i])
            primes.push_back(i);
}
void marwan()
{
    int n;
    cin >> n;
    int ans = 0;
    for (auto vl : primes)
    {
        if (vl > n)
            break;
        ans += n / vl;
    }
    cout << ans << endl;
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