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
#define minus cout << "-1" << endl
#define make_unique(x) \
    sort(all((x)));    \
    (x).erase(unique(all((x))), (x).end())
// vector<vector<int>> dp(1e6 + 1, vector<int>(2, 0ll));
int dp[10000001][2];
void marwan()
{
    int n;
    cin >> n;
    cout << (dp[n - 1][0] + dp[n - 1][1]) % M << endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    dp[0][0] = dp[0][1] = 1ll;
    for (int i = 1; i <= 1e6; i++)
    {
        dp[i][0] = (2 * 1ll * dp[i - 1][0] + dp[i - 1][1]) % M;
        dp[i][1] = (4 * 1ll * dp[i - 1][1] + dp[i - 1][0]) % M;
    }
    int t;
    cin >> t;
    while (t--)
    {
        marwan();
    }
    return 0;
}