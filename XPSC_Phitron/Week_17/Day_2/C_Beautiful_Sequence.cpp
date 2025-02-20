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
int ans = 0;
map<tuple<int, int, int>, int> dp;
int f(int idx, vector<int> &v, int one, int tt)
{
    if (idx == v.size())
    {
        return 0;
    }
    if (dp.find({idx, one, tt}) != dp.end())
    {
        return dp[{idx, one, tt}] % M;
    }
    if (v[idx] == 1)
    {
        if (!one)
            return dp[{idx, one, tt}] = (f(idx + 1, v, one + 1, tt) + f(idx + 1, v, one, tt)) % M;
        else
            return dp[{idx, one, tt}] = f(idx + 1, v, one, tt) % M;
    }
    else if (v[idx] == 2)
    {
        if (one)
        {
            return dp[{idx, one, tt}] = (f(idx + 1, v, one, tt + 1) + f(idx + 1, v, one, tt)) % M;
        }
        else
            return dp[{idx, one, tt}] = f(idx + 1, v, one, tt) % M;
    }
    else if (v[idx] == 3)
    {
        if (one > 0 && tt > 0)
        {
            cerr << one << " " << tt << " " << idx << " " << v[idx] << endl;
            return dp[{idx, one, tt}] = (f(idx + 1, v, one, tt) + 1) % M;
        }
        else
            return dp[{idx, one, tt}] = f(idx + 1, v, one, tt) % M;
    }
}
void marwan()
{
    dp.clear();
    ans = 0;
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &vl : v)
        cin >> vl;
    cout << f(0, v, 0, 0) << endl;
    // cout << ans << endl;
    cerr << endl;
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