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
    int wt;   // capacity
    int cost; // edge cost (-profit for max profit)
    int rwt;  // reverse edge index
};

struct MCMF {
    int total_nodes;
    vector<vector<Edge>> adj;
    vector<int> dist, ptr;
    vector<bool> in_queue, vis;

    MCMF(int nodes) : total_nodes(nodes), adj(nodes), dist(nodes), ptr(nodes), in_queue(nodes), vis(nodes) {}

    void add_edge(int u, int v, int wt, int cost) {
        adj[u].push_back({v, wt, cost, (int)adj[v].size()});
        adj[v].push_back({u, 0, -cost, (int)adj[u].size() - 1});
    }

    bool spfa(int s, int t) {
        fill(dist.begin(), dist.end(), INF);
        fill(in_queue.begin(), in_queue.end(), false);
        queue<int> q;
        dist[s] = 0;
        q.push(s);
        in_queue[s] = true;

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            in_queue[u] = false;
            for (const auto &e : adj[u]) {
                if (e.wt > 0 && dist[u] + e.cost < dist[e.v]) {
                    dist[e.v] = dist[u] + e.cost;
                    if (!in_queue[e.v]) {
                        q.push(e.v);
                        in_queue[e.v] = true;
                    }
                }
            }
        }
        return dist[t] < INF;
    }

    int dfs(int u, int t, int pushed, int &total_cost) {
        if (pushed == 0 || u == t)
            return pushed;
        vis[u] = true;
        for (int &cid = ptr[u]; cid < (int)adj[u].size(); ++cid) {
            auto &[v, wt, cost, rwt] = adj[u][cid];
            if (vis[v] || wt == 0 || dist[u] + cost != dist[v])
                continue;

            int tr = dfs(v, t, min(pushed, wt), total_cost);
            if (tr == 0)
                continue;

            wt -= tr;
            adj[v][rwt].wt += tr;
            total_cost += tr * cost;
            vis[u] = false; // allow revisit in subsequent augmenting paths
            return tr;
        }
        return 0;
    }

    pair<int, int> min_cost_max_flow(int s, int t) {
        int flow = 0, cost = 0;
        while (spfa(s, t)) {
            fill(ptr.begin(), ptr.end(), 0);
            fill(vis.begin(), vis.end(), false);
            while (int pushed = dfs(s, t, INF, cost)) {
                flow += pushed;
            }
        }
        return {flow, cost};
    }
};
void marwan(int cs) {
    int n, k, g;
    cin >> n >> k >> g;
    vector<int> a(n), b(n);
    for (auto &vl : a)
        cin >> vl;
    for (auto &vl : b)
        cin >> vl;
    int src = 0, dest = 2 * n + 1;
    MCMF mc(dest + 1);
    MCMF mc2(dest + 1);
    for (int i = 0; i < n; i++) {
        mc.add_edge(src, i + 1, 1, 0);
        mc2.add_edge(src, i + 1, 1, 0);

        mc.add_edge(i + 1 + n, dest, 1, 0);
        mc2.add_edge(i + 1 + n, dest, 1, 0);
        for (int j = 0; j < n; j++) {
            if (a[i] < b[j]) {
                int dif = b[j] - a[i];
                mc.add_edge(i + 1, j + 1 + n, 1, min(g, (dif - k) * (dif - k)));
                mc2.add_edge(i + 1, j + 1 + n, 1, min(g, (dif - k) * (dif - k)) * (-1));
            }
        }
    }
    auto [fl, cost] = mc.min_cost_max_flow(src, dest);
    auto [fl2, cost2] = mc2.min_cost_max_flow(src, dest);
    // cout << fl << " " << cost << endl;
    // cout << fl2 << " " << cost2 << endl;
    if (fl >= n) {
        cout << cost << " " << -cost2 << endl;
    } else
        cout << "impossible" << endl;
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