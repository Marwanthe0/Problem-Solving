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
vector<vector<int>> g;
vector<int> vis, color;
int cycle, cnt;
void dfs(int u, int p, int c) {
    vis[u] = 1;
    color[u] = c;
    cnt++;
    for (auto v : g[u]) {
        if (v == p)
            continue;
        if (!vis[v])
            dfs(v, u, !c);
        if (vis[v] && c == color[v]) {
            cycle = 1;
        }
    }
}
void marwan() {
    cin >> n >> m;
    g.assign(n + 1, vector<int>());
    vis.assign(n + 1, 0);
    color.assign(n + 1, -1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    cycle = 0, cnt = 0;
    dfs(1, 1, 0);
    if (cnt == 1)
        cout << 0 << endl;
    else if (cycle) {
        cout << cnt << endl;
    } else {
        int a = 0, b = 0;
        for (int i = 1; i <= n; i++) {
            if (color[i] == color[1])
                a++;
        }
        cout << a << endl;
    }
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    for (int cs = 1; cs <= t; cs++) {
        cout << "Case " << cs << ": ";
        marwan();
    }
    return 0;
}