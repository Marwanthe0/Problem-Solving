#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 998244353
#define N 1000000
#define endl "\n"
#define all(v) v.begin(), v.end()
#define forn for (int i = 0; i < n; i++)
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
int binex(int n, int i)
{
    int x = n, ans = 1;
    while (i > 0)
    {
        if (i & 1)
        {
            ans = (ans * 1ll * x) % M;
        }
        x = (x * 1ll * x) % M;
        i >>= 1;
    }
    return ans % M;
}
void marwan()
{
    int n;
    cin >> n;
    int point = 0, mn = 0, mx = 0;
    for (int i = 0; i < n; i++)
    {
        int x = binex(2, i);
        int dif1 = point - x, dif2 = point + x;
        if (i & 1)
        {
            if ()
        }
        mn = min(point, mn), mx = max(point, mx);
    }
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