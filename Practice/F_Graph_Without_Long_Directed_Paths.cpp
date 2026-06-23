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
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define make_unique(x) \
    sort(all((x)));    \
    (x).erase(unique(all((x))), (x).end())
vector<vector<int>> g;
vector<int> vis, color;
bool flag = true;
void dfs(int v, bool c) {
    vis[v] = 1;
    color[v] = c;
    for (auto child : g[v]) {
        if (vis[child] && color[child] == color[v]) {
            flag = false;
        }
        if (!vis[child]) {
            dfs(child, !c);
        }
    }
}
void marwan() {
    int n, m;
    cin >> n >> m;
    g.resize(n + 1);
    vis.resize(n + 1, 0);
    color.resize(n + 1, -1);
    vector<pair<int, int>> edges;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        edges.push_back({x, y});
        g[x].push_back(y);
        g[y].push_back(x);
    }
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            dfs(i, 0);
        }
    }
    if (flag) {
        yes;
        for (auto [x, y] : edges) {
            if (color[x]) {
                cout << 0;
            } else
                cout << 1;
        }
        cout << endl;
    } else {
        no;
        return;
    }
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}