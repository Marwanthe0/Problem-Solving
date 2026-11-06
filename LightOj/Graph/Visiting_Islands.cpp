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
vector<int> vis, dist;
void dfs(int u, int p, int d, vector<int> &nodes) {
    dist[u] = d;
    vis[u] = 1;
    nodes.push_back(u);
    for (auto v : g[u]) {
        if (v == p)
            continue;
        dfs(v, u, d + 1, nodes);
    }
}
void marwan(int cs) {
    cin >> n >> m;
    g.assign(n + 1, vector<int>());
    dist.assign(n + 1, 0);
    vis.assign(n + 1, 0);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<pair<int, int>> v;
    int mxd = 0;
    for (int i = 1; i <= n; i++) {
        if (vis[i])
            continue;
        vector<int> nodes;
        dfs(i, i, 0, nodes);
        int a = i, b = i;
        for (auto nd : nodes) {
            if (dist[nd] > dist[a])
                a = nd;
        }
        for (auto nd : nodes)
            dist[nd] = 0;
        nodes.clear();
        dfs(a, a, 0, nodes);
        for (auto nd : nodes) {
            if (dist[nd] > dist[b])
                b = nd;
        }
        int d = dist[b] + 1;
        v.push_back({nodes.size(), d});

        mxd = max(mxd, d);
    }
    sort(all(v));
    reverse(all(v));
    int q;
    cin >> q;
    while (q--) {
        int k;
        cin >> k;
        if (k <= mxd) {
            cout << k - 1 << endl;
        } else if (k > v[0].first) {
            cout << "impossible" << endl;
        } else {
            int xd = 0;
            for (int i = 0; i < v.size(); i++) {
                if (v[i].first < k)
                    break;
                xd = max(xd, v[i].second);
            }
            cout << (xd - 1) + (k - xd) * 2 << endl;
        }
    }
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cout << "Case " << i << ": " << endl;
        marwan(i);
    }
    return 0;
}