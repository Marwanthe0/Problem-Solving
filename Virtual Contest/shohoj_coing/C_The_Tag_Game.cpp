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
void marwan() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n + 1);
    for (int i = 0; i + 1 < n; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int> vis(n + 1, 0), level(n + 1, 0);
    queue<int> q;
    q.push(1);
    vis[1] = 1;
    while (!q.empty()) {
        int nd = q.front();
        q.pop();
        for (auto child : g[nd]) {
            if (!vis[child]) {
                vis[child] = 1;
                level[child] = level[nd] + 1;
                q.push(child);
            }
        }
    }
    // for (int i = 1; i <= n; i++) {
    //     cerr << i << " " << level[i] << endl;
    // }
    cout << 2 * (*max_element(all(level))) << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}