// Using dijkstra

// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
// #define M 1000000007
// #define N 1000005
// #define INF 1e17
// #define endl "\n"
// #define all(v) v.begin(), v.end()
// #define yes cout << "YES" << endl
// #define no cout << "NO" << endl
// #define minus cout << "-1" << endl
// #define zero cout << "0" << endl
// #define make_unique(x) \
//     sort(all((x)));    \
//     (x).erase(unique(all((x))), (x).end())
// int n, m;
// vector<vector<pair<int, int>>> g;
// vector<int> vis, dist;
// void dijkstra(int src) {
//     priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
//     dist[src] = 0;
//     pq.push({0, src});
//     while (!pq.empty()) {
//         auto [cost, u] = pq.top();
//         pq.pop();
//         if (cost > dist[u])
//             continue;
//         for (auto [v, w] : g[u]) {
//             if (max(cost, w) < dist[v]) {
//                 dist[v] = max(cost, w);
//                 pq.push({dist[v], v});
//             }
//         }
//     }
// }
// void marwan(int cs) {
//     cin >> n >> m;
//     g.assign(n, vector<pair<int, int>>());
//     dist.assign(n, 1e9);
//     vis.assign(n, 0);
//     for (int i = 0; i < m; i++) {
//         int u, v, c;
//         cin >> u >> v >> c;
//         g[u].push_back({v, c});
//         g[v].push_back({u, c});
//     }
//     int u;
//     cin >> u;
//     dijkstra(u);
//     for (int i = 0; i < n; i++) {
//         if (dist[i] < 1e9)
//             cout << dist[i] << endl;
//         else
//             cout << "Impossible" << endl;
//     }
// }
// int32_t main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(0);
//     int t;
//     cin >> t;
//     for (int i = 1; i <= t; i++) {
//         cout << "Case " << i << ":" << endl;
//         marwan(i);
//     }
//     return 0;
// }

// Using MST
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
vector<tuple<int, int, int>> edges;
vector<vector<pair<int, int>>> g;
vector<int> ans;
struct DSU {
    vector<int> p, sz;
    DSU(int n) : p(n + 1), sz(n + 1, 1) {
        iota(p.begin(), p.end(), 0);
    }
    int find(int x) {
        return p[x] == x ? x : p[x] = find(p[x]);
    }
    void unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a != b) {
            if (sz[a] < sz[b])
                swap(a, b);
            p[b] = a;
            sz[a] += sz[b];
        }
    }
};
void dfs(int u, int p, int dist) {
    ans[u] = dist;
    for (auto [v, w] : g[u]) {
        if (v == p)
            continue;
        dfs(v, u, max(dist, w));
    }
}
void marwan(int cs) {
    cin >> n >> m;
    edges.assign(m, {});
    g.assign(n, {});
    ans.assign(n, 1e9);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({w, u, v});
    }
    int t;
    cin >> t;
    sort(all(edges));
    DSU ds(n);
    for (auto [w, u, v] : edges) {
        if (ds.find(u) != ds.find(v)) {
            g[u].push_back({v, w});
            g[v].push_back({u, w});
            ds.unite(u, v);
        }
    }
    dfs(t, t, 0);
    for (int i = 0; i < n; i++) {
        if (ans[i] >= 1e9)
            cout << "Impossible" << endl;
        else
            cout << ans[i] << endl;
    }
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cout << "Case " << i << ":" << endl;
        marwan(i);
    }
    return 0;
}