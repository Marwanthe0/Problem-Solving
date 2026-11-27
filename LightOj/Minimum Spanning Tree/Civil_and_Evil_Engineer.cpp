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
int n;
vector<tuple<int, int, int>> edges;
vector<vector<pair<int, int>>> g, g2;
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
int dfs(int u, int p, vector<vector<pair<int, int>>> &gr) {

    int ans = 0;
    for (auto [v, w] : gr[u]) {
        if (v == p)
            continue;
        ans += dfs(v, u, gr) + w;
    }
    return ans;
}
void marwan(int cs) {
    cin >> n;
    g.assign(n + 1, {});
    g2.assign(n + 1, {});
    edges.clear();
    while (1) {
        int u, v, w;
        cin >> u >> v >> w;
        if (u == 0 && v == 0 && w == 0)
            break;
        edges.push_back({w, u, v});
    }
    auto edges2 = edges;
    sort(all(edges));
    sort(all(edges2));
    reverse(all(edges2));
    DSU ds(n + 1), ds2(n + 1);
    for (auto [w, u, v] : edges) {
        if (ds.find(u) != ds.find(v)) {
            g[u].push_back({v, w});
            g[v].push_back({u, w});
            ds.unite(u, v);
        }
    }
    for (auto [w, u, v] : edges2) {
        if (ds2.find(u) != ds2.find(v)) {
            g2[u].push_back({v, w});
            g2[v].push_back({u, w});
            ds2.unite(u, v);
        }
    }
    int sum1 = dfs(0, 0, g), sum2 = dfs(0, 0, g2);
    sum1 += sum2;
    if (sum1 & 1)
        cout << sum1 << "/" << 2 << endl;
    else
        cout << sum1 / 2 << endl;
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