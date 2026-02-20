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
int f(int i, int j, vector<string> &v, vector<vector<int>> &dp)
{
    if (i == 0 && j == 0 && v[i][j] != '*')
        return 1;
    if (i < 0 || j < 0 || v[i][j] == '*')
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    int up = f(i - 1, j, v, dp), left = f(i, j - 1, v, dp);
    return dp[i][j] = (up + left) % M;
}
void marwan()
{
    int n;
    cin >> n;
    vector<string> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    cout << f(n - 1, n - 1, v, dp);
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}