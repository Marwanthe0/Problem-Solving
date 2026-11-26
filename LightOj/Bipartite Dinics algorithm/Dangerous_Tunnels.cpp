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
void marwan(int cs) {
    int n;
    cin >> n;
    int m;
    cin >> m;
    vector<tuple<int, int, int>> e(m);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        if (u > v)
            swap(u, v);
        e[i] = {u, v, w};
    }
    int k;
    cin >> k;
    auto ok = [&](int lim) -> bool {
        int src = 0, dest = 2 * (n + 1) + 1;
        Dinic dn(dest + 1);
        // cerr << dest << endl;
        for (int i = 1; i <= n; i++) {
            dn.add_edge(i, n + i + 1, 1);
            // cerr << i << " " << i + n + 1 << " " << 1 << endl;
        }

        for (auto [u, v, w] : e) {
            if (v == n + 1)
                v = dest;

            if (w <= lim) {
                int ul = u, ur = (u ? u + n + 1 : u), vl = v, vr = v + n + 1;
                dn.add_edge(ur, vl, 1);
                // cerr << ur << " " << vl << " " << 1 << endl;
            }
        }
        int fl = dn.max_flow(src, dest);
        // cerr << fl << endl;
        // cerr << endl;
        return fl >= k;
    };

    int l = 0, r = 1e6, ans = -1;
    // ok(10);
    // cerr << endl;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (ok(mid)) {
            r = mid - 1, ans = mid;
        } else
            l = mid + 1;
    }
    if (ans != -1)
        cout << ans << endl;
    else
        cout << "no solution" << endl;
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