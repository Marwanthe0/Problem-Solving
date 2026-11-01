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
vector<int> vis;
vector<vector<int>> g;
void dfs(int u, int p) {
    vis[u] = 1;

    for (auto v : g[u]) {
        if (v != p) {
            if (!vis[v])
                dfs(v, u);
        }
    }
}
void marwan() {
    cin >> n >> m;
    g.assign(n + 1, vector<int>());
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vis.assign(n + 1, 0);
    vector<int> ans;
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            dfs(i, i);
            ans.push_back(i);
        }
    }
    cout << ans.size() - 1 << endl;
    if (ans.size() > 1) {
        for (int i = 0; i + 1 < ans.size(); i++)
            cout << ans[i] << " " << ans[i + 1] << endl;
    }
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    marwan();
    return 0;
}