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
int dfs(int src, vector<vector<int>> &g, vector<int> &vis, vector<int> &mxlevel, vector<int> &level) {
    vis[src] = 1;
    int mx = 0;
    for (auto child : g[src]) {
        if (!vis[child]) {
            level[child] = level[src] + 1;
            mx = max((int)dfs(child, g, vis, mxlevel, level), mx);
        }
    }
    return mxlevel[src] = max(mx, level[src]);
}
void marwan() {
    int n;
    cin >> n;
    vector<vector<int>> g(n + 1);
    for (int i = 0; i + 1 < n; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int> vis(n + 1, 0), level(n + 1, 0), mxlevel(n + 1, 0), levelnode(n + 1, 0), mxlevelnode(n + 1, 0);
    level[1] = 1;
    dfs(1, g, vis, mxlevel, level);
    vector<int> leaves;
    int mx = 0;
    for (int i = 1; i <= n; i++) {
        if (g[i].size() == 1)
            leaves.push_back(i);
        levelnode[level[i]]++;
        mxlevelnode[mxlevel[i]]++;
        mx = max(mx, level[i]);
        // cerr << i << " " << level[i] << " " << mxlevel[i] << endl;
    }
    // cerr << endl;
    vector<int> prl(mx + 2, 0);
    for (int i = mx; i >= 1; i--) {
        // cerr << levelnode[i] << " ";
        prl[i] = prl[i + 1] + levelnode[i];
    }
    // cerr << endl;
    // for (int i = 1; i <= mx; i++) {
    //     cerr << mxlevelnode[i] << " ";
    // }
    int mxlevelnodeCount = 0;
    int ans = n;
    for (int i = 1; i <= mx; i++) {
        ans = min(ans, mxlevelnodeCount + prl[i + 1]);
        mxlevelnodeCount += mxlevelnode[i];
    }
    cout << ans << endl;
    // cerr << endl;
    // cerr << endl;
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