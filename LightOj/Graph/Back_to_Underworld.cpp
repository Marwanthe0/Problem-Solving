#include <bits/stdc++.h>
using namespace std;
#define M 1000000007
#define N 20000
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
int n;
vector<vector<int>> g;
vector<int> vis, color;
int cnt;
int dfs(int u, int p, int c) {
    vis[u] = 1;
    color[u] = c;
    cnt++;
    int tans = !c;
    for (auto v : g[u]) {
        if (v == p)
            continue;
        if (!vis[v])
            tans += dfs(v, u, !c);
    }
    return tans;
}
void marwan(int cs) {
    cin >> n;
    g.assign(N + 1, vector<int>());
    vis.assign(N + 1, 0);
    color.assign(N + 1, 0);
    vector<int> nodes;
    for (int i = 0; i < n; i++) {
        int u, v;
        cin >> u >> v;
        nodes.push_back(u);
        nodes.push_back(v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int ans = 0;
    make_unique(nodes);
    for (auto i : nodes) {
        cnt = 0;
        if (!vis[i]) {
            int tans = dfs(i, i, 0);
            // cerr << tans << " " << cnt << endl;
            ans += max(tans, cnt - tans);
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