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
    g.assign(n + 1, vector<int>());
    vis.assign(n + 1, 0);
    color.assign(n + 1, -1);
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            dfs(i, 0);
        }
    }
    vector<int> a, b;
    for (int i = 1; i <= n; i++) {
        cerr << color[i] << " ";
        if (color[i])
            a.push_back(i);
        else
            b.push_back(i);
    }
    if (a.size() > b.size())
        a = b;
    cout << a.size() << endl;
    for (auto vl : a)
        cout << vl << " ";
    cout << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--)
        marwan();
    return 0;
}