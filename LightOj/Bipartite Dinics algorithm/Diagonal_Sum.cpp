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

    int add_edge(int u, int v, int wt) {
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
    int es = n + m - 1;
    vector<int> e1(es), e2(es);
    for (int i = 0; i < es; i++)
        cin >> e1[i];
    for (int i = 0; i < es; i++)
        cin >> e2[i];

    int src = 0, dest = 2 * es + 1;
    Dinic dn(dest + 1);

    vector<int> cnt(es, 0), cnt2(es, 0);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int r1 = i + j, r2 = i - j + (m - 1);
            cnt[r1]++, cnt2[r2]++;
        }
    }

    for (int i = 0; i < es; i++) {
        dn.add_edge(src, i + 1, e1[i] - cnt[i]);
        dn.add_edge(i + 1 + es, dest, e2[i] - cnt2[i]);
    }

    vector<vector<int>> pos(n, vector<int>(m, 0));
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int u = i + j + 1, v = (i - j + (m - 1)) + es + 1;
            pos[i][j] = dn.add_edge(u, v, 99);
        }
    }
    int fl = dn.max_flow(src, dest);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int u = i + j + 1;
            cout << 100 - dn.adj[u][pos[i][j]].wt << (j != m - 1 ? " " : "");
        }
        cout << endl;
    }
    cout << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cout << "Case " << i << ":" << endl;
        marwan(i);
    }
    return 0;
}