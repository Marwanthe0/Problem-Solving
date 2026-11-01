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
int n, m;
vector<vector<int>> g;
vector<int> vis;
vector<pair<int, int>> coords;

int xmn, xmx, ymn, ymx;
void dfs(int u, int p) {
    vis[u] = 1;
    auto [x, y] = coords[u];

    xmn = min(xmn, x);
    xmx = max(xmx, x);
    ymn = min(ymn, y);
    ymx = max(ymx, y);
    for (auto v : g[u]) {
        if (v == p)
            continue;
        if (!vis[v])
            dfs(v, u);
    }
}
void marwan() {
    cin >> n >> m;
    g.assign(n + 1, vector<int>());
    vis.assign(n + 1, 0);
    coords.assign(n + 1, pair<int, int>());
    for (int i = 1; i <= n; i++) {
        int x, y;
        cin >> x >> y;
        coords[i] = {x, y};
    }
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int ans = INT_MAX;
    for (int i = 1; i <= n; i++) {
        xmn = INT_MAX, xmx = INT_MIN, ymn = INT_MAX, ymx = INT_MIN;
        if (!vis[i]) {
            dfs(i, i);
            int dist1 = xmx - xmn, dist2 = ymx - ymn;
            ans = min(ans, 2 * (dist1 + dist2));
        }
    }
    cout << ans << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("fenceplan.in", "r", stdin);
    freopen("fenceplan.out", "w", stdout);
    marwan();
    return 0;
}