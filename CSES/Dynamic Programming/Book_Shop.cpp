#include <bits/stdc++.h>
using namespace std;
#define int long long
#define intt int32_t
#define M 1000000007
#define N 1000000
#define endl "\n"
#define all(v) v.begin(), v.end()
#define forn for (int i = 0; i < n; i++)
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
void marwan()
{
    intt n, k;
    cin >> n >> k;
    vector<intt> a(n), b(n);
    for (auto &vl : a)
        cin >> vl;
    for (auto &vl : b)
        cin >> vl;
    vector<vector<int32_t>> dp(n + 1, vector<intt>(k + 1, 0));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= k; j++)
        {
            dp[i][j] = max(dp[i - 1][j], (a[i - 1] <= j ? dp[i - 1][j - a[i - 1]] + b[i - 1] : 0));
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