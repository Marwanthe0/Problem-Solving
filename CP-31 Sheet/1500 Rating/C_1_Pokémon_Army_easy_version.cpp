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
int ans(int i, vector<int> &v, bool op, vector<vector<int>> &dp)
{
    if (i == v.size())
    {
        return 0;
    }
    if (dp[op][i] != -1)
        return dp[op][i];
    int nitamna = ans(i + 1, v, op, dp), nimu = ans(i + 1, v, !op, dp) + (op ? v[i] : -v[i]);
    return dp[op][i] = max(nimu, nitamna);
}
void marwan()
{
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    reverse(all(v));
    vector<vector<int>> dp(2, vector<int>(n + 1, -1));
    dp[1][0] = dp[0][0] = 1;
    for (int i = 0; i < 2; i++)
    {
        for(int )
    }
    cout << ans(0, v, 1, dp) << endl;
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