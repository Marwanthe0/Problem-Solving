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
int dfs(int nd, vector<vector<int>> &g, vector<int> &vis, vector<int> &par) {
    vis[nd] = 1;
    for (auto child : g[nd]) {
        if (vis[child] && par[nd] != child) {
            par[child] = nd;
            return child;
        }
        if (!vis[child]) {
            par[child] = nd;
            int x = dfs(child, g, vis, par);
            if (x)
                return x;
        }
    }
    return 0;
}
void marwan() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n + 1);
    vector<int> vis(n + 1, 0), par(n + 1, -1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int ans = -1;
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            int x = dfs(i, g, vis, par);
            if (x) {
                ans = x;
                break;
            }
        }
    }
    if (ans == -1) {
        cout << "IMPOSSIBLE" << endl;
        return;
    }
    int temp = ans;
    vector<int> uttor;
    do {
        uttor.push_back(ans);
        ans = par[ans];
    } while (ans != temp);
    uttor.push_back(temp);
    cout << uttor.size() << endl;
    for (auto vl : uttor)
        cout << vl << " ";
    cout << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    marwan();
    return 0;
}