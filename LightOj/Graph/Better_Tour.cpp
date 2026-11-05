#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define N 50000
#define INF 1e17
#define endl "\n"
#define all(v) v.begin(), v.end()
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define minus cout << "-1" << endl
#define zero cout << "0" << endl
#define make_unique(x) \
    sort(all((x)));    \
    (x).erase(unique(all((x))), (x).end())
int n;
vector<vector<int>> g;
vector<int> vis, dist, parent;
void marwan(int cs) {
    cin >> n;
    g.assign(N + 1, vector<int>());
    vector<int> t(n);
    vis.assign(N + 1, 0);
    dist.assign(N + 1, 1e9);
    parent.assign(N + 1, -1);
    vector<int> nodes;
    for (int i = 0; i < n; i++) {
        cin >> t[i];
        if (i) {
            int u = t[i - 1], v = t[i];
            g[u].push_back(v);
            g[v].push_back(u);
            nodes.push_back(u);
            nodes.push_back(v);
        }
    }
    make_unique(nodes);
    for (auto node : nodes) {
        sort(all(g[node]));
    }
    queue<int> q;
    q.push(t[0]);
    vis[t[0]] = 1;
    dist[t[0]] = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        // cerr << u << " ";
        if (u == t.back()) {
            break;
        }
        for (auto v : g[u]) {
            if (!vis[v]) {
                vis[v] = 1;
                dist[v] = dist[u] + 1;
                parent[v] = u;
                q.push(v);
            }
        }
    }
    int cur = t.back();
    vector<int> ans;
    while (cur != -1) {
        ans.push_back(cur);
        cur = parent[cur];
    }
    reverse(all(ans));
    for (auto vl : ans)
        cout << vl << " ";
    cout << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cout << "Case " << i << ": " << endl;
        marwan(i);
    }
    return 0;
}