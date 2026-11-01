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
vector<int> vis, color;
bool dfs(int u, int p, int c) {
    vis[u] = 1, color[u] = c;
    bool possible = true;
    for (auto v : g[u]) {
        if (v == p)
            continue;
        if (vis[v] == 1 && color[v] == c) {
            return false;
        } else if (vis[v] == 0) {
            possible &= dfs(v, u, !c);
        }
    }
    return possible;
}
void marwan() {
    cin >> n;
    m = n - 1;
    g.assign(n + 1, vector<int>());
    vis.assign(n + 1, 0);
    color.assign(n + 1, 0);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            dfs(i, i, 0);
        }
    }
    int a = 0, b = 0;
    for (int i = 1; i <= n; i++) {
        if (color[i])
            a++;
        else
            b++;
    }
    cout << a * b - m << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    marwan();
    return 0;
}