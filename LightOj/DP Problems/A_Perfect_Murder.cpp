#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define N 1000005
#define INF 1e17
#define endl "\n"
#define all(v) v.begin(), v.end()
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define minus cout << "-1" << endl
#define zero cout << "0" << endl
#define make_unique(x) \
    sort(all((x)));    \
    (x).erase(unique(all((x))), (x).end())
int n, m;
vector<vector<int>> g;
vector<vector<int>> dp;
int f(int u, int p, int marbo) {
    if (dp[u][marbo] != -1)
        return dp[u][marbo];
    int ans = marbo;
    for (auto v : g[u]) {
        if (v == p)
            continue;
        int tans = 0;
        if (marbo)
            tans = max(tans, f(v, u, !marbo));
        else {
            tans = max(tans, f(v, u, !marbo));
            tans = max(tans, f(v, u, marbo));
        }
        ans += tans;
    }
    return dp[u][marbo] = ans;
}
void marwan(int cs) {
    cin >> n >> m;
    g.assign(n + 1, vector<int>());
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int ans = 0;
    dp.assign(n + 1, vector<int>(2, -1));
    for (int i = 1; i <= n; i++) {
        if (dp[i][0] == -1) {
            int tans = f(i, i, 0);
            tans = max(tans, f(i, i, 1));
            ans += tans;
        }
    }
    cout << ans << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cout << "Case " << i << ": ";
        marwan(i);
    }
    return 0;
}