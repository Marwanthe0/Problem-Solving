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
int n, m;
vector<vector<int>> g, r;
stack<int> order;
vector<int> vis, components;
void dfs(int nd, bool rev) {
    vis[nd] = 1;
    if (rev)
        components.push_back(nd);
    auto &childs = rev ? r[nd] : g[nd];
    for (auto child : childs) {
        if (!vis[child]) {
            dfs(child, rev);
        }
    }
    if (!rev)
        order.push(nd);
}
void marwan() {
    cin >> n >> m;
    g.assign(n + 1, vector<int>());
    r.assign(n + 1, vector<int>());
    vis.assign(n + 1, 0);
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        r[y].push_back(x);
    }
    for (int i = 1; i <= n; i++) {
        if (!vis[i])
            dfs(i, 0);
    }
    vis.assign(n + 1, 0);
    vector<int> ans(n + 1, 0);
    int count = 1;
    while (!order.empty()) {
        int top = order.top();
        order.pop();
        if (!vis[top]) {
            // cerr << top << "::";
            dfs(top, 1);
            for (auto node : components) {
                // cerr << node << " ";
                ans[node] = count;
            }
            // cerr << endl;
            count++;
            components.clear();
        }
    }
    cout << count - 1 << endl;
    for (int i = 1; i <= n; i++)
        cout << ans[i] << " ";
    cout << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}