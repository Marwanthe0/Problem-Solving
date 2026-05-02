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
int dfs(int n, vector<vector<int>> &g, vector<int> &dp) {
    // vis[n] = 1;
    // cout << n << " ";
    if (dp[n] != -1)
        return dp[n];
    int x = 0;
    for (auto child : g[n]) {
        // if (!vis[child]) {
        x = max(dfs(child, g, dp) + 1, x);
        // }
    }
    return dp[n] = x;
}
void marwan() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
    }
    vector<int> dp(n + 1, 0);
    int ans = 1;
    for (int i = 1; i <= n; i++) {
        // if (!vis[i]) {
        ans = max(ans, dfs(i, g, dp));
        // }
        // cout << endl;
    }
    cout << ans << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}