#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
#define N 1000000
#define endl "\n"
#define all(v) v.begin(), v.end()
#define forn for (ll i = 0; i < n; i++)
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
map<pair<int, int>, ll> dp;
ll ans(ll l, ll r, ll k)
{
    if (r - l + 1 < k)
        return dp[{l, r}] = 0;
    ll m = (l + r) / 2;
    if ((r - l + 1) & 1)
    {
        if (dp.count({l, r}) != 0)
            return dp[{l, r}];
        else
            return dp[{l, r}] = ans(l, m - 1, k) + ans(m + 1, r, k) + m;
    }
    else
    {
        if (dp.count({l, r}) != 0)
            return dp[{l, r}];
        else
            return dp[{l, r}] = ans(l, m, k) + ans(m + 1, r, k);
    }
}
void marwan()
{
    ll n, k;
    cin >> n >> k;
    cout << ans(1, n, k) << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t;
    cin >> t;
    while (t--)
    {
        marwan();
    }
    return 0;
}