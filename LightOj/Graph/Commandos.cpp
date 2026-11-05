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
vector<int> dist, dist2, vis;
void dfs(int src, vector<int> &dis) {

    queue<int> q;
    q.push(src);
    dist[src] = 0;
    vis[src] = 1;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto v : g[u]) {
            if (!vis[v]) {
                vis[v] = 1;
                dis[v] = dis[u] + 1;
                q.push(v);
            }
        }
    }
}
void marwan(int cs) {
    cin >> n >> m;
    g.assign(n, vector<int>());
    vis.assign(n, 0);
    dist.assign(n, 0);
    dist2.assign(n, 0);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int source, dest;
    cin >> source >> dest;
    // cerr << source << " " << dest << endl;
    dfs(source, dist);
    vis.assign(n, 0);
    dfs(dest, dist2);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        // cerr << i << " " << dist[i] << " " << dist2[i] << endl;
        ans = max(ans, dist[i] + dist2[i]);
    }
    // cerr << endl;
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