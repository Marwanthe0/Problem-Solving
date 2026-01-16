#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define nn 40000

vector<int> pal;
vector<vector<int>> dp(nn + 1, vector<int>(500, -1));
// bool vis[nn + 1][600];

bool isPal(int n)
{
    string s = to_string(n);
    string r = s;
    reverse(r.begin(), r.end());
    return s == r;
}
int solve(int sum, int idx)
{
    if (sum == 0)
        return 1;
    if (sum < 0 || idx >= (int)pal.size())
        return 0;
    if (dp[sum][idx] != -1)
        return dp[sum][idx];
    // vis[sum][idx] = true;
    int take = solve(sum - pal[idx], idx);
    int skip = solve(sum, idx + 1);
    return dp[sum][idx] = (take + skip) % M;
}
void marwan()
{
    int n;
    cin >> n;
    cout << dp[n][0] << "\n";
}
int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for (int i = 1; i <= nn; i++)
        if (isPal(i))
            pal.push_back(i);
    solve(nn, 0);
    int t;
    cin >> t;
    while (t--)
    {
        marwan();
    }
    return 0;
}
