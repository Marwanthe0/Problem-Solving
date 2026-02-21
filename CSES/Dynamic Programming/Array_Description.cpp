#include <bits/stdc++.h>
using namespace std;
#define M 1000000007
#define N 1000000
#define endl "\n"
#define all(v) v.begin(), v.end()
#define forn for (int i = 0; i < n; i++)
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
void marwan()
{
    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    for (auto &vl : v)
        cin >> vl;
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= m; i++)
    {
        if (v[0] == 0 || v[0] == i)
            dp[1][i] = 1;
    }
    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (v[i - 1] != 0 && v[i - 1] != j)
            {
                dp[i][j] = 0;
                continue;
            }
            for (int state = j - 1; state <= j + 1; state++)
            {
                if (state >= 1 && state <= m)
                {
                    dp[i][j] = (dp[i][j] + dp[i - 1][state]) % M;
                }
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= m; i++)
        ans = (dp[n][i] + ans) % M;
    cout << ans << endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}