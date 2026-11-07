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
vector<vector<int>> g;
vector<int> a, parent, sz, flat, heavy, head, depth, pos;
void dfs_sz(int u, int p) {
    parent[u] = p;
    sz[u] = 1;

    int mxsz = 0;
    for (auto v : g[u]) {
        if (v == p)
            continue;
        depth[v] = depth[u] + 1;
        dfs_sz(v, u);
        sz[u] += sz[v];
        if (sz[v] > mxsz) {
            mxsz = sz[v];
            heavy[u] = v;
        }
    }
}
int counter = 0;
void dfs_hld(int u, int h) {
    head[u] = h;
    pos[u] = counter;
    flat[counter++] = u;
    if (heavy[u]) {
        dfs_hld(heavy[u], u);
    }

    for (auto v : g[u]) {
        if (parent[u] != v && heavy[u] != v) {
            dfs_hld(v, v);
        }
    }
}

void marwan(int cs) {
    cin >> n;
    a.assign(n, 0);
    g.assign(n, vector<int>());
    parent.assign(n, 0);
    sz.assign(n, 0);
    flat.assign(n, 0);
    heavy.assign(n, 0);
    head.assign(n, 0);
    depth.assign(n, 0);
    pos.assign(n, 0);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i + 1 < n; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs_sz(0, 0);
    dfs_hld(0, 0);
    for (int i = 0; i < n; i++) {
        cout << flat[i] << " ";
    }
    cout << endl;

    int q;
    cin >> q;
    while (q--) {
        int op;
        cin >> op;
        if (op) {
            int u, val;
            cin >> u >> val;
        } else {
            int u, v;
            cin >> u >> v;
        }
    }
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