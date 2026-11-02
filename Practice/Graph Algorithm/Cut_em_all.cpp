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
int ans = 0;
int dfs(int u, int p) {
    int nodes = 1;
    for (auto v : g[u]) {
        if (v == p)
            continue;
        nodes += dfs(v, u);
    }
    if (nodes % 2 == 0 && nodes != n && nodes)
        ans++;
    return nodes;
}
void marwan() {
    cin >> n;
    g.assign(n + 1, vector<int>());
    for (int i = 0; i + 1 < n; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    if (n & 1) {
        minus;
        return;
    }
    int x = dfs(1, 1);
    cout << ans << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    marwan();
    return 0;
}