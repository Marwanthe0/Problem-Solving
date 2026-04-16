#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define N 1000000
#define endl "\n"
#define all(v) v.begin(), v.end()
#define forn for (int i = 0; i < n; i++)
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define minus cout << "-1" << endl
#define make_unique(x) \
    sort(all((x)));    \
    (x).erase(unique(all((x))), (x).end())
vector<int> vis, par;
int find(int x) {
    return par[x] == x ? par[x] : par[x] = find(par[x]);
}
void unite(int a, int b) {
    a = find(a), b = find(b);
    if (a != b)
        par[a] = b;
}
void marwan() {
    int n, x, y;
    cin >> n >> x >> y;
    vector<unordered_set<int>> f(n + 1), g(n + 1);
    vis.assign(n + 1, 0), par.assign(n + 1, 0);
    for (int i = 1; i <= n; i++)
        par[i] = i;
    set<int> a, b;
    for (int i = 0; i < x; i++) {
        int u, v;
        cin >> u >> v;
        a.insert(u);
        a.insert(v);
        f[u].insert(v);
        f[v].insert(u);
    }
    for (int i = 0; i < y; i++) {
        int u, v;
        cin >> u >> v;
        g[u].insert(v);
        g[v].insert(u);
        b.insert(u);
        b.insert(v);
    }
    int ans = 0;
    for (auto vl : a) {
        if (!b.count(vl)) {
            unordered_set<int> temp = f[vl];
            for (auto val : temp) {
                f[val].erase(vl);
                ans++;
            }
            f[vl].clear();
        }
    }
    for (int i = 1; i <= n; i++) {
        for (auto vl : g[i]) {
            unite(vl, i);
        }
    }
    for (int i = 1; i <= n; i++) {
        for (auto it = f[i].begin(); it != f[i].end();) {
            bool flag = true;
            if (find(i) != find(*it)) {
                f[*it].erase(i);
                int x = *it;
                flag = false;
                it++;
                f[i].erase(x);
                ans++;
            }
            if (flag)
                it++;
        }
    }
    for (int i = 1; i <= n; i++)
        par[i] = i;
    for (int i = 1; i <= n; i++) {
        for (auto vl : f[i]) {
            if (find(i) != find(vl))
                unite(vl, i);
        }
    }
    for (int i = 1; i <= n; i++) {
        for (auto vl : g[i]) {
            if (find(i) == find(vl))
                continue;
            else {
                unite(i, vl);
                ans++;
            }
        }
    }
    cout << ans << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        marwan();
    }
    return 0;
}