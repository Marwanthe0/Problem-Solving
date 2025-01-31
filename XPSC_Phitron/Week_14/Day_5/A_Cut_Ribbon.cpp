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
int dp[100000];
int ans(int n, int a, int b, int c)
{
    if (n == 0)
        return 0;
    else if (n < 0)
        return INT_MIN;
    if (dp[n] != -1)
        return dp[n];
    return dp[n] = max({ans(n - a, a, b, c), ans(n - b, a, b, c), ans(n - c, a, b, c)}) + 1;
}
void marwan()
{
    memset(dp, -1, sizeof(dp));
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    if (n % min({a, b, c}) == 0)
        cout << n / min({a, b, c}) << endl;
    else
        cout << ans(n, a, b, c) << endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}