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
int n, m;
vector<set<int>> g;
vector<int> vis, del;
void dfs(int u, int p) {
    vis[u] = 1;
    for (auto v : g[u]) {
        if (v == p)
            continue;
        if (!vis[v])
            dfs(v, u);
    }
}
void marwan() {
    cin >> n >> m;
    g.assign(n + 1, set<int>());
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].insert(v);
        g[v].insert(u);
    }
    vis.assign(n + 1, 0);
    del.assign(n + 1, 0);
    int count = 0;
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            dfs(i, i);
            count++;
        }
    }
    if (count == 1) {
        yes;
    } else
        no;
    for (int i = 0; i < n; i++) {
        int u;
        cin >> u;
        del[u]++;
        vector<int> cons;
        for (auto v : g[u])
            cons.push_back(v);
        if (g[u].size())
            g[u].clear();
        for (auto v : cons) {
            if (g[v].count(u))
                g[v].erase(u);
        }
        vis.assign(n + 1, 0);
        count = 0;
        for (int i = 1; i <= n; i++) {
            if (vis[i] == 0 && del[i] == 0) {
                dfs(i, i);
                count++;
            }
        }

        if (count == 1) {
            yes;
        } else if (count > 1)
            no;
    }
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("closing.in", "r", stdin);
    freopen("closing.out", "w", stdout);
    marwan();
    return 0;
}