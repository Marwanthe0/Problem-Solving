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
#ifndef ONLINE_JUDGE
#define dout(...) cerr << "Line:" << __LINE__ << " [" << #__VA_ARGS__ << "] = [", _print(__VA_ARGS__)
#else
#define dout(...) ((void)0)
#endif
vector<vector<int>> g, t;
stack<int> st;
vector<int> vis;
void dfs(int u) {
    vis[u] = 1;
    for (auto v : g[u])
        if (!vis[v])
            dfs(v);
    st.push(u);
}
void dfs2(int u, vector<int> &comp, int id) {
    comp[u] = id;
    vis[u] = 1;
    for (auto v : t[u])
        if (!vis[v])
            dfs2(v, comp, id);
}
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
};
void marwan(int cs) {
    int n, m;
    cin >> n >> m;
    g.assign(n + 1, vector<int>());
    t.assign(n + 1, vector<int>());
    vis.assign(n + 1, 0);
    st = stack<int>();

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        t[v].push_back(u);
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            dfs(i);
        }
    }

    int count = 0;
    vis.assign(n + 1, 0);
    vector<int> comp(n + 1, 0);
    dout(st);
    while (!st.empty()) {
        int u = st.top();
        st.pop();
        if (vis[u]) {
            continue;
        }
        count++;
        dfs2(u, comp, count);
    }
    // dout(g);
    // dout(t);
    // cerr << endl;
    vector<pair<int, int>> edge;
    for (int i = 1; i <= n; i++) {
        for (int v : g[i]) {
            if (comp[i] != comp[v]) {
                edge.push_back({comp[i], comp[v]});
            }
        }
    }
    // dout(count);

    // dout(edge);
    int src = 0, dest = 2 * count + 1;
    Dinic dn(dest + 1);
    for (int i = 1; i <= count; i++) {
        dn.add_edge(src, i, 1);
        dn.add_edge(i + count, dest, 1);
        dn.add_edge(i + count, i, INF);
    }
    make_unique(edge);
    for (auto [x, y] : edge) {
        dn.add_edge(x, y + count, INF);
    }

    cout << count - dn.max_flow(src, dest) << endl;
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