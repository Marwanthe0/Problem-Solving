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
vector<vector<int>> g;
vector<int> sz;

int dfs(int u, int p) {
    int ans = 1;
    for (auto v : g[u]) {
        if (v == p)
            continue;
        ans += dfs(v, u);
    }
    sz[u] = ans - 1;
    return ans;
}
void marwan(int cs) {
    cin >> n;
    g.assign(n + 1, vector<int>());
    sz.assign(n + 1, 0);
    for (int i = 0; i + 1 < n; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int x = dfs(1, 1);
    // cerr << x << endl;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += sz[i];
        // cerr << sz[i] << " ";
    }
    // cerr << endl;
    cout << n - 1 << " " << ((n * (n - 1)) / 2) - ans << endl;
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