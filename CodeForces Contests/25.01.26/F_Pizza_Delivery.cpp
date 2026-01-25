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
int ans(int i, int j, int x, int y, vector<pair<int, int>> &v, vector<bool> &vis, int cnt, map<pair<int, int>, int> &dp)
{
    if (cnt == v.size())
    {
        if (i <= x)
            return abs(i - x) + abs(j - y);
        else
            return INT_MAX;
    }
    int mx = INT_MAX;
    // if (dp.find({i, j}) != dp.end())
    //     return dp[{i, j}];
    for (int k = 0; k < v.size(); k++)
    {
        if (vis[k] == 0 && v[k].first >= i)
        {
            vis[k] = 1;
            mx = min(mx, abs(v[k].first - i) + abs(v[k].second - j) + ans(v[k].first, v[k].second, x, y, v, vis, cnt + 1, dp));
            vis[k] = 0;
        }
    }
    return dp[{i, j}] = mx;
}
void marwan()
{
    int n, a, b, c, d;
    cin >> n >> a >> b >> c >> d;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i].first;
    for (int i = 0; i < n; i++)
        cin >> v[i].second;
    vector<bool> vis(n, 0);
    map<pair<int, int>, int> dp;
    cout << ans(a, b, c, d, v, vis, 0, dp) << endl;
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