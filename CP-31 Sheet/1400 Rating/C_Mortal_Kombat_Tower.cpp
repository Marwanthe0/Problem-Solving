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
int ans(bool turn, int i, vector<int> &v, vector<vector<int>> &dp)
{
    if (i < 0)
        return 0;
    if (i == 0)
        return (int)(turn && v[i]);
    if (dp[turn][i] != -1)
        return dp[turn][i];
    int ekta = ans(!turn, i - 1, v, dp) + (int)(turn && v[i]);
    int duita = ans(!turn, i - 2, v, dp) + (turn && v[i]) + (turn && v[i - 1]);
    return dp[turn][i] = min(ekta, duita);
}
void marwan()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    reverse(all(v));
    vector<vector<int>> dp(2, vector<int>(n + 1, -1));
    cout << ans(true, n - 1, v, dp) << endl;
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