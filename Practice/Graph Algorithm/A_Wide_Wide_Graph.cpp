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
int n;
vector<vector<int>> g;
vector<int> vis, mxd;
void dfs(int u, int p, int dist) {
    mxd[u] = max(mxd[u], dist);
    for (auto v : g[u]) {
        if (v == p)
            continue;
        dfs(v, u, dist + 1);
    }
}
void marwan() {
    cin >> n;
    g.assign(n + 1, vector<int>());
    vis.assign(n + 1, 0);
    mxd.assign(n + 1, 0);
    for (int i = 0; i + 1 < n; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, 1, 0);
    int a = 1, b = 1;
    for (int i = 1; i <= n; i++) {
        if (mxd[i] > mxd[a])
            a = i;
    }
    mxd.assign(n + 1, 0);
    dfs(a, a, 0);
    for (int i = 1; i <= n; i++) {
        if (mxd[i] > mxd[b])
            b = i;
    }
    dfs(b, b, 0);
    sort(mxd.begin() + 1, mxd.end());
    // for (int i = 1; i <= n; i++)
    //     cout << mxd[i] << " ";
    // cout << endl;
    for (int k = 1; k <= n; k++) {
        int pos = lower_bound(all(mxd), k) - mxd.begin();
        cout << min(pos, n) << " ";
    }
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    marwan();
    return 0;
}