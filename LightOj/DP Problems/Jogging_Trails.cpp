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
vector<vector<tuple<int, int, int>>> g;
vector<vector<int>> dp;
int mincost[16][16];
int f(int u, int mask, int start) {
    if (mask == (1ll << m) - 1) {
        return mincost[u][start];
    }
    if (dp[u][mask] != -1)
        return dp[u][mask];
    int ans = 1e9;
    for (auto [v, c, i] : g[u]) {
        if ((mask & (1 << i)))
            continue;
        ans = min(ans, c + f(v, mask | (1 << i), start));
    }
    return dp[u][mask] = ans;
}
void dijkstra(int src) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, src});
    mincost[src][src] = 0;
    vector<int> vis(n + 1, 0);
    vis[src] = 1;
    while (!pq.empty()) {
        auto [cost, u] = pq.top();
        pq.pop();
        for (auto [v, c, i] : g[u]) {
            if (vis[v] == 0 && c + cost < mincost[src][v]) {
                mincost[src][v] = c + cost;
                vis[src] = 1;
                pq.push({mincost[src][v], v});
            }
        }
    }
}
void marwan(int cs) {
    cin >> n >> m;
    g.assign(n + 1, vector<tuple<int, int, int>>());
    for (int i = 0; i < m; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        g[u].push_back({v, c, i});
        g[v].push_back({u, c, i});
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)
            mincost[i][j] = 1e9;
    }
    for (int i = 1; i <= n; i++) {
        dijkstra(i);
    }
    // for (int i = 1; i <= n; i++) {
    //     for (int j = 1; j <= n; j++)
    //         cout << mincost[i][j] << " ";
    //     cout << endl;
    // }
    // cout << endl;
    int msk = (1LL << m);
    dp.assign(n + 1, vector<int>(msk, -1));
    int ans = 1e9;
    for (int i = 1; i <= n; i++) {
        int tans = f(i, 0, i);
        // cerr << i << " " << tans << endl;
        ans = min(ans, tans);
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