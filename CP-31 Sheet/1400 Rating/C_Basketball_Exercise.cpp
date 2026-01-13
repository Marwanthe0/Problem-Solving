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
int ans(vector<vector<int>> &v, int idx, int op, map<pair<int, int>, int> &dp)
{
    if (idx == 0)
    {
        int mx = 0ll;
        for (int i = 0; i < 2; i++)
        {
            if (i != op)
            {
                mx = max(mx, v[i][idx]);
            }
        }
        return mx;
    }
    int mx = 0ll;
    if (dp.find({idx, op}) != dp.end())
        return dp[{idx, op}];
    for (int i = 0; i < 2; i++)
    {
        if (i != op)
        {
            int points = ans(v, idx - 1, i, dp) + v[i][idx];
            mx = max(mx, points);
        }
    }
    int points = ans(v, idx - 1, op, dp);
    mx = max(mx, points);
    return dp[{idx, op}] = mx;
}
void marwan()
{
    int n;
    cin >> n;
    vector<vector<int>> v(2, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
        cin >> v[0][i];
    for (int i = 0; i < n; i++)
        cin >> v[1][i];
    map<pair<int, int>, int> dp;
    cout << ans(v, n - 1, 2, dp) << endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}