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
int ans(vector<vector<int>> &v, int n, int idx, vector<vector<int>> &dp)
{
    if (idx == 0)
        return 1;
    int total = 0;
    if (dp[idx][n] != -1)
        return dp[idx][n];
    for (auto vl : v[n])
    {
        total = ((total % M) + (ans(v, vl, idx - 1, dp) % M)) % M;
    }
    return dp[idx][n] = total;
}
void marwan()
{
    int n, k;
    cin >> n >> k;
    vector<vector<int>> d(n + 1, vector<int>());
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j * j <= i; j++)
        {
            if (i % j == 0)
            {
                if ((i / j) != j)
                    d[i].push_back(i / j);
                d[i].push_back(j);
            }
        }
        sort(all(d[i]));
    }
    // for (int i = 1; i <= n; i++)
    // {
    //     cout << i << endl;
    //     for (auto vl : d[i])
    //         cout << vl << " ";
    //     cout << endl;
    // }
    // cout << endl;
    vector<vector<int>> dp(k + 1, vector<int>(n + 1, -1));
    int fn = 0;
    for (int i = 1; i <= n; i++)
    {
        fn = ((fn % M) + (ans(d, i, k - 1, dp) % M)) % M;
    }
    cout << fn << endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}