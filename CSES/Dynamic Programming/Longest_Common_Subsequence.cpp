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
void marwan()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (auto &vl : a)
        cin >> vl;
    for (auto &vl : b)
        cin >> vl;
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (a[i - 1] == b[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    int l = n, r = m;
    vector<int> ans;
    while (l > 0 && r > 0)
    {
        if (a[l - 1] == b[r - 1])
        {
            ans.push_back(a[l - 1]);
            l--, r--;
        }
        else if (dp[l][r - 1] > dp[l - 1][r])
            r--;
        else
            l--;
    }
    reverse(all(ans));
    cout << dp[n][m] << endl;
    for (auto vl : ans)
        cout << vl << " ";
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}