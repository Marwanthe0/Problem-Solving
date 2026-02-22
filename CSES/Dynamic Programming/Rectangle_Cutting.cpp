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
int f(int i, int j, vector<vector<int>> &dp)
{
    if (i == j)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    int vert = INT_MAX, hor = INT_MAX;
    for (int k = 1; k < j; k++)
    {
        vert = min(vert, f(i, k, dp) + f(i, j - k, dp));
    }
    for (int k = 1; k < i; k++)
        hor = min(hor, f(k, j, dp) + f(i - k, j, dp));
    return dp[i][j] = min(vert, hor) + 1;
}
void marwan()
{
    int n, m;
    cin >> n >> m;
    const int INF = 1e9;
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, INF));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (i == j)
            {
                dp[i][j] = 0;
                continue;
            }
            for (int k = 1; k < j; k++)
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[i][j - k] + 1);
            for (int k = 1; k < i; k++)
                dp[i][j] = min(dp[i][j], dp[k][j] + dp[i - k][j] + 1);
        }
    }
    cout << dp[n][m] << endl;
    // cout << f(n, m, dp) << endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}