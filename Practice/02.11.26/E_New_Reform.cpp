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
vector<int> vis;
bool dfs(int u, int p) {
    vis[u] = 1;
    bool flag = false;
    // cerr << u << " " << p << endl;
    for (auto v : g[u]) {
        if (v == p)
            continue;
        if (vis[v])
            flag = true;
        else
            flag |= dfs(v, u);
    }
    return flag;
}
void marwan() {
    cin >> n >> m;
    g.assign(n + 1, vector<int>());
    vis.assign(n + 1, 0);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            ans += !dfs(i, i);
        }
    }
    cout << ans << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    marwan();
    return 0;
}