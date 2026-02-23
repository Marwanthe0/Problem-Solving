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
int f(int i, vector<int> &v, vector<int> &dp)
{
    if (i == 0)
        return 0;
    if (dp[i] != -1)
        return dp[i];
    return dp[i] = min(abs(v[i] - v[i - 1]) + f(i - 1, v, dp), (i > 1 ? abs(v[i] - v[i - 2]) + f(i - 2, v, dp) : INT_MAX));
}
void marwan()
{
    int n;
    cin >> n;
    vector<int> dp(n + 1, 0), v(n);
    for (auto &vl : v)
        cin >> vl;
    dp[0] = 0;
    for (int i = 1; i < n; i++)
    {
        dp[i] = min(abs(v[i] - v[i - 1]) + dp[i - 1], (i > 1 ? abs(v[i] - v[i - 2]) + dp[i - 2] : INT_MAX));
    }
    cout << dp[n - 1] << endl;
    // cout << f(n - 1, v, dp);
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}