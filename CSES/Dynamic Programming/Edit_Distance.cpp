#include <bits/stdc++.h>
using namespace std;
#define M 1000000007
#define N 1000000
#define endl "\n"
#define all(v) v.begin(), v.end()
#define forn for (int i = 0; i < n; i++)
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
int f(int i, int j, string &s, string &t, vector<vector<int>> &dp)
{
    if (i < 0)
        return j + 1;
    if (j < 0)
        return i + 1;

    if (dp[i][j] != -1)
        return dp[i][j];
    // equal
    if (s[i] == t[j])
        return dp[i][j] = f(i - 1, j - 1, s, t, dp);
    // remove from s
    int remove = f(i - 1, j, s, t, dp);
    // add in s
    int add = f(i, j - 1, s, t, dp);
    // replace s to t
    int replace = f(i - 1, j - 1, s, t, dp);
    return dp[i][j] = min({remove, add, replace}) + 1;
}
void marwan()
{
    string s, t;
    cin >> s >> t;
    int n = s.size(), m = t.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    cout << f(n - 1, m - 1, s, t, dp);
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}