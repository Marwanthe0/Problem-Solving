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
#define minus cout << "-1" << endl
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
    vector<int> es1(n), es2(m);
    for (int i = 0; i < n; i++) {
        cin >> es1[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> es2[i];
    }
    for (int i = n - 1; i >= 0; i--) {
        if (i)
            es1[i] -= es1[i - 1];
        es1[i] -= m;
    }
    for (int i = m - 1; i >= 0; i--) {
        if (i)
            es2[i] -= es2[i - 1];
        es2[i] -= n;
    }
    for (auto vl : es1)
        cerr << vl << " ";
    cerr << endl;
    for (auto vl : es2)
        cerr << vl << " ";
    cerr << endl;

    int src = 0, dest = n + m + 1;
    Dinic dn(dest + 1);

    // src -> each node
    for (int i = 0; i < n; i++) {
        dn.add_edge(src, i + 1, es1[i]);
    }
    // each node -> dest
    for (int i = 0; i < m; i++) {
        dn.add_edge(i + n + 1, dest, es2[i]);
    }

    vector<vector<int>> pos(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            pos[i][j] = dn.add_edge(i + 1, j + n + 1, 19);
        }
    }

    dn.max_flow(src, dest);
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << 20 - dn.adj[i + 1][pos[i][j]].wt << " ";
        }
        cout << endl;
    }
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cout << "Matrix " << i << endl;
        marwan(i);
    }
    return 0;
}