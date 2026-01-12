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
bool ind;
int ans(int x, int y, map<int, int> &dp)
{
    if (x <= 1)
    {
        ind = ind | (x == y);
        return 0;
    }
    else if (x == y)
    {
        ind = true;
        return 0;
    }
    if (dp.count(x))
        return dp[x];
    int a = (x / 2);
    int b = (x / 2) + (x & 1);
    return dp[x] = min(ans(a, y, dp), ans(b, y, dp)) + 1;
}
void marwan()
{
    int n, k;
    cin >> n >> k;
    map<int, int> dp;
    ind = false;
    int x = ans(n, k, dp);
    if (ind)
        cout << x << endl;
    else
        cout << -1 << endl;
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