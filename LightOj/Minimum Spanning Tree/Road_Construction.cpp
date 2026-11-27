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
int comp;
vector<vector<pair<int, int>>> g;
vector<tuple<int, int, int>> edges;
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
            comp--;
        }
    }
};
int dfs(int u, int p) {
    int ans = 0;
    for (auto [v, w] : g[u]) {
        if (v == p)
            continue;
        ans += dfs(v, u) + w;
    }
    return ans;
}
void marwan(int cs) {
    map<string, int> mp;
    edges.clear();
    int m;
    cin >> m;
    int n = 0;
    for (int i = 0; i < m; i++) {
        string u, v;
        int cost;
        cin >> u >> v >> cost;
        if (!mp.count(u))
            mp[u] = mp.size();
        if (!mp.count(v))
            mp[v] = mp.size();
        edges.push_back({cost, mp[u], mp[v]});
    }
    n = comp = mp.size();
    g.assign(n, {});
    sort(all(edges));
    DSU ds(n);
    for (auto [w, u, v] : edges) {
        if (ds.find(u) != ds.find(v)) {
            g[u].push_back({v, w});
            g[v].push_back({u, w});
            ds.unite(u, v);
        }
    }
    if (comp != 1) {
        cout << "Impossible" << endl;
        return;
    }
    cout << dfs(0, 0) << endl;
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