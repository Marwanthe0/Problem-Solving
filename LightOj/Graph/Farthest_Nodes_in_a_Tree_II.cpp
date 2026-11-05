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
vector<vector<pair<int, int>>> g;
vector<int> dist;
void dfs(int u, int p, int d) {
    dist[u] = d;
    for (auto [v, w] : g[u]) {
        if (v == p)
            continue;
        dfs(v, u, d + w);
    }
}
void marwan(int cs) {
    cin >> n;
    g.assign(n + 1, vector<pair<int, int>>());
    dist.assign(n, 0);
    for (int i = 0; i + 1 < n; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    int a = 0, b = 0;
    dfs(0, 0, 0);
    for (int i = 0; i < n; i++) {
        if (dist[i] > dist[a])
            a = i;
    }
    dist.assign(n, 0);
    dfs(a, a, 0);
    vector<int> dist1 = dist;
    for (int i = 0; i < n; i++)
        if (dist[i] > dist[b])
            b = i;
    dist.assign(n, 0);
    dfs(b, b, 0);
    // cerr << a << " " << b << endl;
    vector<int> dist2 = dist;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        cout << max(dist1[i], dist2[i]) << endl;
    }
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cout << "Case " << i << ": " << endl;
        marwan(i);
    }
    return 0;
}