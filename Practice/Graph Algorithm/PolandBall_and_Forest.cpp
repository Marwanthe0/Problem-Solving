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
vector<int> vis;
void dfs(int u, int p) {
    vis[u] = 1;
    for (auto v : g[u]) {
        if (v == p)
            continue;
        if (!vis[v])
            dfs(v, u);
    }
}
void marwan() {
    cin >> n;
    g.assign(n + 1, vector<int>());
    vis.assign(n + 1, 0);
    for (int u = 1; u <= n; u++) {
        int v;
        cin >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int count = 0;
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            dfs(i, i);
            count++;
        }
    }
    cout << count << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    marwan();
    return 0;
}