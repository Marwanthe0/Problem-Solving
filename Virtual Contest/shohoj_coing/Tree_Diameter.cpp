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
void dfs(int n, vector<vector<int>> &g, vector<int> &vis, vector<int> &level) {
    vis[n] = 1;
    for (auto child : g[n]) {
        if (!vis[child]) {
            level[child] = level[n] + 1;
            dfs(child, g, vis, level);
        }
    }
}
void marwan() {
    int n;
    cin >> n;
    if (n <= 1) {
        cout << 0 << endl;
        return;
    }
    vector<vector<int>> g(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int> vis(n + 1, 0), level(n + 1, 0);
    dfs(1, g, vis, level);
    int mx = 0, mxnode;
    for (int i = 1; i <= n; i++) {
        if (level[i] > mx)
            mx = level[i], mxnode = i;
    }
    for (int i = 1; i <= n; i++)
        vis[i] = level[i] = 0;
    dfs(mxnode, g, vis, level);
    cout << *max_element(all(level)) << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}