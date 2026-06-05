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
#define make_unique(x) \
    sort(all((x)));    \
    (x).erase(unique(all((x))), (x).end())
void marwan() {
    int n, m;
    cin >> n >> m;
    vector<vector<vector<int>>> g(m + 1, vector<vector<int>>(n + 1));
    vector<vector<int>> ans(n + 1, vector<int>(n + 1, 0));
    vector<int> cols;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        cols.push_back(c);
        g[c][a].push_back(b);
        g[c][b].push_back(a);
    }
    make_unique(cols);
    vector<int> vis;
    auto bfs = [&](int nd, vector<vector<int>> &ag) {
        vector<int> nodes;
        nodes.push_back(nd);
        queue<int> q;
        q.push(nd);
        vis[nd] = 1;
        while (!q.empty()) {
            int front = q.front();
            q.pop();
            for (auto child : ag[front]) {
                if (vis[child])
                    continue;
                vis[child] = 1;
                q.push(child);
                nodes.push_back(child);
            }
        }
        make_unique(nodes);
        for (int i = 0; i < (int)nodes.size(); i++) {
            // cerr << nodes[i] << " ";
            for (int j = i + 1; j < (int)nodes.size(); j++)
                ans[nodes[i]][nodes[j]]++;
        }
        cerr << endl;
    };

    for (auto i : cols) {
        vis.assign(n + 1, 0);
        for (int j = 1; j <= n; j++) {
            if (g[i][j].size() && !vis[j]) {
                bfs(j, g[i]);
            }
        }
    }
    int q;
    cin >> q;
    while (q--) {
        int a, b;
        cin >> a >> b;
        cout << max(ans[a][b], ans[b][a]) << endl;
    }
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}