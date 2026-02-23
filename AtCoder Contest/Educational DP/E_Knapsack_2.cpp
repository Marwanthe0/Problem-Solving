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
void marwan()
{
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> v(n);
    int w = 0ll, g = 0;
    for (auto &[x, y] : v)
    {
        cin >> x >> y;
        g = __gcd(g, x);
    }
    for (auto &[x, y] : v)
    {
        x /= g;
        w += x;
    }
    k = min(k, w);
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0ll));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= k; j++)
        {
            dp[i][j] = dp[i - 1][j];
            if (v[i - 1].first <= j)
            {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - v[i - 1].first] + v[i - 1].second);
            }
        }
    }
    cout << dp[n][k] << endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}