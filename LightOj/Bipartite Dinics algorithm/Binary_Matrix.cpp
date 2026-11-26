#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define N 1000005
#define INF 1e17
#define endl "\n"
#define all(v) v.begin(), v.end()
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define minus cout << "impossible" << endl
#define zero cout << "0" << endl
#define make_unique(x) \
    sort(all((x)));    \
    (x).erase(unique(all((x))), (x).end())
struct Edge {
    int v;
    int wt;
    int rwt;
};
struct Dinic {
    int total_nodes;
    vector<vector<Edge>> adj;
    vector<int> level;
    vector<int> ptr;

    Dinic(int nodes) : total_nodes(nodes), adj(nodes), level(nodes), ptr(nodes) {}

    int add_edge(int u, int v, int wt, bool isS = false) {
        adj[u].push_back({v, wt, (int)adj[v].size()});
        adj[v].push_back({u, 0, (int)adj[u].size() - 1});
        return adj[u].size() - 1;
    }

    bool bfs(int s, int t) {
        fill(level.begin(), level.end(), -1);
        level[s] = 0;
        queue<int> q;
        q.push(s);

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (const auto &e : adj[u]) {
                if (e.wt > 0 && level[e.v] == -1) {
                    level[e.v] = level[u] + 1;
                    q.push(e.v);
                }
            }
        }
        return level[t] != -1;
    }

    int dfs(int u, int t, int pushed) {
        if (pushed == 0 || u == t)
            return pushed;
        for (int &cid = ptr[u]; cid < (int)adj[u].size(); ++cid) {
            auto &[v, wt, rwt] = adj[u][cid];
            if (level[u] + 1 != level[v] || wt == 0)
                continue;

            int tr = dfs(v, t, min(pushed, wt));
            if (tr == 0)
                continue;

            wt -= tr;
            adj[v][rwt].wt += tr;
            return tr;
        }
        return 0;
    }

    int max_flow(int s, int t) {
        int flow = 0;
        while (bfs(s, t)) {
            fill(ptr.begin(), ptr.end(), 0);
            while (int pushed = dfs(s, t, INF)) {
                flow += pushed;
            }
        }
        return flow;
    }
}; // Change if the graph is undirected
void marwan(int cs) {
    int n, m;
    cin >> n >> m;
    vector<int> r(n), c(m);
    int sum_r = 0, sum_c = 0;
    for (int i = 0; i < n; i++) {
        cin >> r[i];
        sum_r += r[i];
    }
    for (int j = 0; j < m; j++) {
        cin >> c[j];
        sum_c += c[j];
    }

    if (sum_r != sum_c) {
        cout << " impossible\n";
        return;
    }

    int src = 0, dest = n + m + 1;
    Dinic dn(dest + 1);
    for (int i = 0; i < n; i++) {
        if (r[i] > m) {
            cout << " impossible\n";
            return;
        }
        dn.add_edge(src, i + 1, r[i]);
    }
    for (int j = 0; j < m; j++) {
        if (c[j] > n) {
            cout << " impossible\n";
            return;
        }
        dn.add_edge(j + n + 1, dest, c[j]);
    }

    vector<vector<int>> pos(n, vector<int>(m));
    for (int i = n - 1; i >= 0; i--) {
        int r1 = i + 1;
        for (int j = m - 1; j >= 0; j--) {
            int c1 = j + n + 1;
            pos[i][j] = dn.add_edge(r1, c1, 1);
        }
    }

    if (dn.max_flow(src, dest) != sum_r) {
        cout << " impossible\n";
        return;
    }

    vector<int> vis(dest + 1, 0);
    int timer = 0;
    auto dfs_reroute = [&](auto &self, int u, int target) -> bool {
        if (u == target)
            return true;
        vis[u] = timer;
        for (auto &e : dn.adj[u]) {
            if (e.wt > 0 && e.v != src && e.v != dest && vis[e.v] != timer) {
                if (self(self, e.v, target)) {
                    e.wt -= 1;
                    dn.adj[e.v][e.rwt].wt += 1;
                    return true;
                }
            }
        }
        return false;
    };

    vector<vector<int>> ans(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        int u = i + 1;
        for (int j = 0; j < m; j++) {
            int v = j + n + 1;
            int idx = pos[i][j];
            int ridx = dn.adj[u][idx].rwt;

            if (dn.adj[u][idx].wt == 1) {
                dn.adj[u][idx].wt = 0;
                ans[i][j] = 0;
            } else {
                dn.adj[u][idx].wt = 0;
                dn.adj[v][ridx].wt = 0;
                timer++;
                if (dfs_reroute(dfs_reroute, u, v)) {
                    ans[i][j] = 0;
                } else {
                    ans[i][j] = 1;
                }
            }
        }
    }

    cout << "\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << ans[i][j];
        }
        cout << "\n";
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cout << "Case " << i << ":";
        marwan(i);
    }
    return 0;
}