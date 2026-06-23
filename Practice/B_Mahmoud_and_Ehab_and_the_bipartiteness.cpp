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
// bool flag = true;
void dfs(int v, bool c) {
    vis[v] = 1;
    color[v] = c;
    for (auto child : g[v]) {
        if (!vis[child]) {
            dfs(child, !c);
        }
    }
}
void marwan() {
    int n;
    cin >> n;
    g.resize(n + 1);
    vis.resize(n + 1, 0);
    color.resize(n + 1, -1);
    for (int i = 0; i < n - 1; i++) {
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
    int ans = 0;
    int a = 0, b = 0;
    for (int i = 1; i <= n; i++) {
        // cerr << color[i] << " ";
        if (color[i])
            a++;
        else
            b++;
    }
    // cerr << a << " " << b << endl;
    cout << (a * 1ll * b) - (n - 1) << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}