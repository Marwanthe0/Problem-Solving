#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define N 1000000
#define endl "\n"
#define all(v) v.begin(), v.end()
#define forn for (int i = 0; i < n; i++)
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define minus cout << "-1" << endl
#define make_unique(x) \
    sort(all((x)));    \
    (x).erase(unique(all((x))), (x).end())
void marwan() {
    int n;
    cin >> n;
    vector<vector<int>> g(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int> vis(n + 1, 0), level(n + 1, 0), par(n + 1, -1);
    level[1] = vis[1] = 1;
    queue<int> q;
    q.push(1);
    while (!q.empty()) {
        int nd = q.front();
        q.pop();
        for (auto c : g[nd]) {
            if (!vis[c]) {
                vis[c] = 1;
                level[c] = level[nd] + 1;
                par[c] = nd;
                q.push(c);
            }
        }
    }
    unordered_map<int, vector<int>> m;
    for (int i = 1; i <= n; i++) {
        m[level[i]].push_back(i);
    }
    int mx = 0, mxval;
    for (auto [x, y] : m) {
        if (y.size() > mx)
            mx = y.size();
    }
    bool flag = false;
    for (auto [x, y] : m) {
        if (y.size() == mx) {
            mxval = x;
            int first = par[m[mxval][0]];
            bool flag2 = true;
            for (auto vl : m[mxval]) {
                if (par[vl] != first)
                    flag2 = false;
            }
            if (flag2)
                flag = true;
        }
    }
    cout << mx + flag << endl;
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