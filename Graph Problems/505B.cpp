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
vector<vector<vector<int>>> g;
vector<int> vis;
void dfs(int nd, int col) {
    vis[nd] = 1;
    for (auto child : g[nd][col])
        if (!vis[child])
            dfs(child, col);
}
void marwan() {
    int n, m;
    cin >> n >> m;
    g.resize(n + 1, vector<vector<int>>(m + 1));
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        g[a][c].push_back(b);
        g[b][c].push_back(a);
    }
    vis.resize(n + 1, 0);
    int q;
    cin >> q;
    while (q--) {
        int u, v;
        cin >> u >> v;
        int count = 0;
        for (int i = 1; i <= m; i++) {
            vis.assign(n + 1, 0);
            dfs(u, i);
            if (vis[v])
                count++;
        }
        cout << count << endl;
    }
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}