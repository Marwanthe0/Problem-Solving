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
int f(int i, int j, vector<int> &v, vector<vector<int>> &dp)
{
    if (i == j)
        return v[i];
    if (j < i)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    int first = v[i] + min(f(i + 2, j, v, dp), f(i + 1, j - 1, v, dp)), second = v[j] + min(f(i + 1, j - 1, v, dp), f(i, j - 2, v, dp));
    return dp[i][j] = max(first, second);
}
void marwan()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &vl : v)
        cin >> vl;
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = i; j < n; j++)
        {
            if (i == j)
                dp[i][j] = v[i];
            else
            {
                dp[i][j] = max(v[i] + min((i + 2 <= j ? dp[i + 2][j] : 0), (i + 1 <= j - 1 ? dp[i + 1][j - 1] : 0)), v[j] + min((i + 1 <= j - 1 ? dp[i + 1][j - 1] : 0), (i <= j - 2 ? dp[i][j - 2] : 0)));
            }
        }
    }
    cout << dp[0][n - 1] << endl;
    // cout << f(0, n - 1, v, dp) << endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}