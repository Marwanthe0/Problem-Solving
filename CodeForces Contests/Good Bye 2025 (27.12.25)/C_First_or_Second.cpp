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
int ans(vector<int> &v, int i, int j, unordered_map<pair<int, int>, int> &dp)
{
    if (j > v.size() - 1)
    {
        return 0;
    }
    if (dp.count({i, j}))
    {
        return dp[{i, j}];
    }
    int x = 0, y = 0;
    x = ans(v, j, j + 1, dp) + v[i];
    y = ans(v, i, j + 1, dp) - v[j];
    return dp[{i, j}] = max(x, y);
}
void marwan()
{
    int n;
    cin >> n;
    unordered_map<pair<int, int>, int> dp;
    vector<int> v(n);
    for (auto &vl : v)
        cin >> vl;
    set<int> check;
    cout << ans(v, 0, 1, dp) << endl;
    // cerr << endl;
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