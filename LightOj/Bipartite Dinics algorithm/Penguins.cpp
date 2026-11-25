#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define M 1000000007
#define N 1000005
#define INF 1e9
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
};
struct node {
    int x, y, p, cap;
};
/*
if final value of node is >= sum, then it is reachable.

src->ui = u.p
ui->uj  = INF
uj->vi  = u.cap
vi->vj  = INF
*/
void marwan(int cs) {
    int n;
    long double lim;
    cin >> n >> lim;
    vector<node> v(n);
    int total = 0;
    for (int i = 0; i < n; i++) {
        cin >> v[i].x >> v[i].y >> v[i].p >> v[i].cap;
        total += v[i].p;
    }
    int src = 0, dest = 2 * n + 1;
    auto dist = [&](int x1, int y1, int x2, int y2) {
        return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
    };
    vector<int> ans;
    for (int dst = 1; dst <= n; dst++) {
        Dinic d(dest + 1);
        for (int i = 0; i < n; i++) {
            if (i + 1 == dst)
                continue;
            d.add_edge(src, i + 1, v[i].p);
            d.add_edge(i + 1, i + n + 1, v[i].cap);
            if (dist(v[i].x, v[i].y, v[dst - 1].x, v[dst - 1].y) <= lim) {
                d.add_edge(i + 1 + n, dst, v[i].cap);
            }
            for (int j = 0; j < n; j++) {
                if (j + 1 == dst || j == i)
                    continue;
                if (dist(v[i].x, v[i].y, v[j].x, v[j].y) <= lim) {
                    d.add_edge(i + 1 + n, j + 1, v[i].cap);
                }
            }
        }
        d.add_edge(src, dst, v[dst - 1].p);
        int fl = d.max_flow(src, dst);
        if (fl >= total) {
            ans.push_back(dst - 1);
        }
    }
    if (ans.empty()) {
        minus;
        return;
    }
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
        cout << "Case " << i << ": ";
        marwan(i);
    }
    return 0;
}