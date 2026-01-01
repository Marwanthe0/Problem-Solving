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
int rnd(int n)
{
    int count = 0;
    if (n == 0)
        return 0;
    while ((n % 10) == 0)
    {
        count++;
        n /= 10;
    }
    return count;
}
int dig(int n)
{
    int count = 0;
    while (n)
        n /= 10, count++;
    return count;
}
int dati(int n, int i)
{
    int x = n;
    for (int j = 0; j < i; j++)
    {
        x /= 10;
    }
    return (x % 10);
}
void marwan()
{
    int n, k;
    cin >> n >> k;
    // cout << rnd(n * k) << endl;
    int ans = n * 1ll * k, x = 0, t = k, i = 0, xnt = 1;
    int mx = rnd(ans), dg = dig(k);
    
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        marwan();
    }
    return 0;
}