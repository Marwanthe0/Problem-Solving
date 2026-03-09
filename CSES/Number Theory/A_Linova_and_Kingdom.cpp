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
int dfs(int src, vector<vector<int>> &g, vector<pair<int, int>> &val, vector<int> &vis, int vl) {
    vis[src] = 1;
    int ans = 1;
    for (auto &child : g[src]) {
        if (!vis[child])
            ans += dfs(child, g, val, vis, vl + 1);
    }
    val.push_back({vl - ans, src});
    return ans;
}
void marwan() {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> g(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int> vis(n + 1, 0);
    vector<pair<int, int>> val;
    int tc = dfs(1, g, val, vis, 1);
    sort(all(val), greater<pair<int, int>>());
    int sum = 0;
    for (int i = 0; i < k; i++)
        sum += val[i].first;
    cout << sum << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}