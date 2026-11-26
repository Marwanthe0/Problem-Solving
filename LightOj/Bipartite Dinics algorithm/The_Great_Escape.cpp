#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define N 1000005
#define INF 1e17
#define endl "\n"
#define all(v) v.begin(), v.end()
#define yes cout << "yes" << endl
#define no cout << "no" << endl
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

    void add_edge(int u, int v, int wt, bool isS = false) {
        adj[u].push_back({v, wt, (int)adj[v].size()});
        adj[v].push_back({u, 0, (int)adj[u].size() - 1});
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

int n, m;
vector<int> dx = {-1, 0, 1, 0};
vector<int> dy = {0, -1, 0, 1};
bool valid(int i, int j) { return i >= 0 && j >= 0 && i < n && j < m; }
void marwan(int cs) {
    cin >> n >> m;
    vector<string> v(n);
    int src = 0, dest = 2 * n * m + 1;
    Dinic dn(dest + 1);
    int count = 0;
    for (int i = 0; i < n; i++)
        cin >> v[i];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int ul = (i)*m + j + 1;
            int ur = ul + m * n;
            if (v[i][j] == '*') {
                dn.add_edge(src, ul, 1);
                count++;
            }
            if (i == 0 || j == 0 || i == n - 1 || j == m - 1) {
                dn.add_edge(ur, dest, 1);
            }
            dn.add_edge(ul, ur, 1);

            for (int k = 0; k < 4; k++) {
                int x = i + dx[k], y = j + dy[k];
                if (valid(x, y) && v[x][y] == '.') {
                    int vl = (x)*m + y + 1;
                    int vr = vl + m * n;
                    dn.add_edge(ur, vl, 1);
                }
            }
        }
    }
    if (count == dn.max_flow(src, dest))
        yes;
    else
        no;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cout << "Case " << i << ": ";
        marwan(i);
    }
    return 0;
}