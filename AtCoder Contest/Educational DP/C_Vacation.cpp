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
int f(int i, int last, vector<vector<int>> &v, vector<vector<int>> &dp)
{
    if (i < 0)
        return 0;
    if (dp[i][last + 1] != -1)
        return dp[i][last + 1];
    int a = 0, b = 0, c = 0;
    if (last != 0)
        a = f(i - 1, 0, v, dp) + v[i][0];
    if (last != 1)
        b = f(i - 1, 1, v, dp) + v[i][1];
    if (last != 2)
        c = f(i - 1, 2, v, dp) + v[i][2];
    return dp[i][last + 1] = max({a, b, c});
}
void marwan()
{
    int n;
    cin >> n;
    vector<vector<int>> v(n, vector<int>(3, 0));
    for (auto &val : v)
        for (auto &vl : val)
            cin >> vl;
    vector<vector<int>> dp(n, vector<int>(4, -1));
    cout << f(n - 1, -1, v, dp) << endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}