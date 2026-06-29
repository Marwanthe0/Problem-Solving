#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define N 1e6
#define INF 1e17
#define endl "\n"
#define all(v) v.begin(), v.end()
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define minus cout << "-1" << endl
#define zero cout << "0" << endl
#define make_unique(x) \
    sort(all((x)));    \
    (x).erase(unique(all((x))), (x).end())
int n, m;
vector<vector<int>> g;
vector<int> vis;
void dfs(int nd, int d) {
    vis[nd] = 1;
    if (d <= 0)
        return;
    for (auto child : g[nd]) {
        if (!vis[child])
            dfs(child, d - 1);
    }
}
void marwan() {
    cin >> n >> m;
    g.assign(n + 1, vector<int>());
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    int count = 0;
    for (int i = 1; i <= n; i++) {
        vis.assign(n + 1, 0);
        dfs(i, 1);
        bool flag = true;
        for (int j = 1; j <= n; j++) {
            if (!vis[j]) {
                dfs(j, 1);
            }
            if (!vis[j]) {
                flag = false;
                break;
            }
        }
        if (flag) {
            yes;
            return;
        }
    }
    no;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        marwan();
    }
    return 0;
}