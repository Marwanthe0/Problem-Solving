#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define N 1000005
#define INF 1e17
#define endl "\n"
#define all(v) v.begin(), v.end()
#define minus cout << "-1" << endl
#define zero cout << "0" << endl
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define make_unique(x) \
    sort(all((x)));    \
    (x).erase(unique(all((x))), (x).end())
int n;
vector<vector<int>> g;
vector<int> vis, parent, dist;
int cycle = 0;
bool dfs(int u, int p) {
    vis[u] = 1;
    for (auto v : g[u]) {
        if (v == p)
            continue;
        parent[v] = u;
        if (vis[v]) {
            cycle = v;
            return true;
        } else {
            if (dfs(v, u))
                return true;
        }
    }
    return false;
}
void marwan() {
    cin >> n;
    g.assign(n + 1, vector<int>());
    vis.assign(n + 1, 0);
    dist.assign(n + 1, 1e9);
    parent.assign(n + 1, -1);
    for (int i = 0; i < n; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, 1);
    queue<int> q;
    vis.assign(n + 1, 0);
    int tmp = cycle;
    dist[cycle] = 0;
    vis[cycle] = 1;
    q.push(cycle);
    cycle = parent[cycle];
    while (cycle != tmp) {
        q.push(cycle);
        dist[cycle] = 0;
        vis[cycle] = 1;
        cycle = parent[cycle];
    }
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto v : g[u]) {
            if (!vis[v]) {
                vis[v] = 1;
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    for (int i = 1; i <= n; i++)
        cout << dist[i] << " ";
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    marwan();
    return 0;
}