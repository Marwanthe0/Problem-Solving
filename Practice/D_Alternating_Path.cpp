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
int c0 = 0, c1 = 0;
bool dfs(int src, vector<vector<int>> &g, vector<int> &vis, vector<int> &color) {
    vis[src] = 1;
    bool flag = true;
    for (auto child : g[src]) {
        if (vis[child]) {
            if (color[child] == color[src])
                flag = false;
        } else {
            color[child] = !color[src];
            if (color[child])
                c1++;
            else
                c0++;
            flag &= dfs(child, g, vis, color);
        }
    }
    return flag;
}
void marwan() {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> g(n + 1);
    for (int i = 0; i < k; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int ans = 0ll;
    vector<int> vis(n + 1, 0), color(n + 1, -1);
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            c0 = 0, c1 = 1;
            color[i] = 1;
            if (dfs(i, g, vis, color))
                ans += max(c0, c1);
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