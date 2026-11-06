#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define N 1000005
#define INF 1e17
#define endl "\n"
#define all(v) v.begin(), v.end()
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define minus cout << "-1" << endl
#define zero cout << "0" << endl
#define make_unique(x) \
    sort(all((x)));    \
    (x).erase(unique(all((x))), (x).end())
int n;
vector<set<int>> g;
vector<int> vis, ind;
queue<int> q;
int dfs(int u, int p) {
    if (u != p) {
        ind[u]--;
        g[p].erase(u);
        if (ind[u] == 0)
            q.push(u);
    }
    int ans = 0;
    bool flag = true;
    for (auto v : g[u]) {
        if (v == p)
            continue;
        // if (!vis[v])
        ans += dfs(v, u);
        flag = false;
    }
    return ans + (flag && u != p);
}
void marwan(int cs) {
    cin >> n;
    g.assign(n, set<int>());
    ind.assign(n, 0);
    vis.assign(n, 0);
    for (int i = 0; i + 1 < n; i++) {
        int u, v;
        cin >> u >> v;
        g[u].insert(v);
        ind[v]++;
    }
    for (int i = 0; i < n; i++) {
        if (ind[i] == 0) {
            q.push(i);
        }
    }
    int ans = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        int tans = 0;
        tans = dfs(u, u);
        ans += tans;
    }
    // cerr << endl;
    cout << ans << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cout << "Case " << i << ": ";
        marwan(i);
    }
    return 0;
}