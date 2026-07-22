#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define N 1e6
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
vector<vector<int>> g, r;
vector<int> vis;
void dfs(int nd, bool rev) {
    vis[nd] = 1;
    auto &childs = rev ? r[nd] : g[nd];
    for (auto &child : childs) {
        if (!vis[child])
            dfs(child, rev);
    }
}
void marwan() {
    cin >> n >> m;
    g.assign(n + 1, vector<int>());
    r.assign(n + 1, vector<int>());
    vis.assign(n + 1, 0);
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        r[y].push_back(x);
    }
    dfs(1, 0);
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            no;
            cout << 1 << " " << i << endl;
            return;
        }
    }
    vis.assign(n + 1, 0);
    dfs(1, 1);
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            no;
            cout << i << " " << 1 << endl;
            return;
        }
    }
    yes;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}