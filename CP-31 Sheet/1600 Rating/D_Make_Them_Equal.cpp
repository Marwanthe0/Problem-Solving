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
vector<int> op(1e3 + 10, INT_MAX);
int knapsack(int i, int k, vector<int> &wt, vector<int> &val, vector<vector<int>> &dp)
{
    if (i < 0)
    {
        return 0;
    }
    if (dp[i][k] != -1)
        return dp[i][k];
    int nitamna = knapsack(i - 1, k, wt, val, dp);
    int nimu = 0;
    if (wt[i] <= k)
        nimu += (val[i] + knapsack(i - 1, k - wt[i], wt, val, dp));
    return dp[i][k] = max(nimu, nitamna);
}
void marwan()
{
    int n, k;
    cin >> n >> k;
    vector<int> b(n), c(n);
    for (auto &vl : b)
    {
        cin >> vl;
        vl = op[vl];
    }
    for (auto &vl : c)
        cin >> vl;
    k = min(k, accumulate(all(b), 0ll));
    vector<vector<int>>
        dp(n, vector<int>(k + 1, -1));
    cout << knapsack(n - 1, k, b, c, dp) << endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    op[1] = 0;
    op[2] = 1;
    for (int i = 1; i <= 1e3; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            int x = i + (i / j);
            if (x <= 1e3)
                op[x] = min(op[x], op[i] + 1);
        }
    }
    // for (int i = 1; i <= 1e3; i++)
    // {
    //     cerr << i << " " << op[i] << endl;
    // }
    int t;
    cin >> t;
    while (t--)
    {
        marwan();
    }
    return 0;
}