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
vector<vector<int>> t;
map<int, map<int, int>> g;
vector<int> order, vis, order2;

void dfs1(int u, int p) {
    order.push_back(u);
    vis[u] = 1;
    for (auto v : t[u]) {
        if (v == p)
            continue;
        if (!vis[v])
            dfs1(v, u);
    }
}
void marwan() {
    cin >> n;
    t.assign(n + 1, vector<int>());
    vis.assign(n + 1, 0);
    for (int i = 0; i < n; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        g[u][v] = c;
        t[u].push_back(v);
        t[v].push_back(u);
    }
    dfs1(1, 1);
    order.push_back(order[0]);
    int cost1 = 0, cost2 = 0;
    for (int i = 1; i < order.size(); i++) {
        int x = order[i - 1], y = order[i];
        // cerr << x << " " << y << endl;
        if (g.count(x) && g[x].count(y))
            continue;
        else
            cost1 += g[y][x];
    }

    // cerr << endl;
    reverse(all(order));

    for (int i = 1; i < order.size(); i++) {
        int x = order[i - 1], y = order[i];
        // cerr << x << " " << y << endl;
        if (g.count(x) && g[x].count(y))
            continue;
        else
            cost2 += g[y][x];
    }
    // cout << endl;
    cout << min(cost1, cost2) << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    marwan();
    return 0;
}