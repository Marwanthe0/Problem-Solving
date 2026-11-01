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
int n, x;
vector<vector<int>> g;
vector<int> vis, dist1, dist2, bob, ansdist;
void dfs(int u, int p, int dist, bool alice = true) {

    if (alice)
        dist1[u] = dist;
    else if (dist1[u] <= dist)
        return;
    else
        dist2[u] = dist;
    for (auto v : g[u]) {
        if (v == p)
            continue;
        dfs(v, u, dist + 1, alice);
    }
}
void dfs2(int u, int p, int dist) {
    if (dist2[u] < dist1[u])
        ansdist[u] = dist;
    for (auto v : g[u]) {
        if (v == p)
            continue;
        dfs2(v, u, dist + 1);
    }
}
void marwan() {
    cin >> n >> x;
    g.assign(n + 1, vector<int>());
    dist1.assign(n + 1, 1e9);
    dist2.assign(n + 1, 1e9);
    ansdist.assign(n + 1, 1e9);
    bob.assign(n + 1, 0);
    for (int i = 0; i + 1 < n; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, 1, 0);
    dfs(x, x, 0, 0);
    // for (int i = 1; i <= n; i++)
    //     cout << dist1[i] << " ";
    // cout << endl;
    // for (int i = 1; i <= n; i++) {
    //     cout << dist2[i] << " ";
    // }
    // cout << endl;
    dfs2(1, 1, 0);
    // yes;
    // return;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (dist2[i] < dist1[i])
            ans = max(ans, ansdist[i]);
    }
    cout << ans * 2 << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    marwan();
    return 0;
}