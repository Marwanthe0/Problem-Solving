#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define N 500000
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
vector<int> spf(N + 5, 0), cnt(N + 5, 0), vis(N + 1, 0);
void sieve() {
    for (int i = 2; i <= N; i++) {
        if (spf[i] == 0) {
            for (int j = i; j <= N; j += i) {
                if (!spf[j])
                    spf[j] = i;
            }
        }
    }
    for (int i = 2; i <= N; i++) {
        cnt[i] = cnt[i / spf[i]] + 1;
    }
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
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &vl : v)
        cin >> vl;
    make_unique(v);
    n = v.size();
    int src = 0, dest = n + 1;
    Dinic d(dest + 1);
    for (int i = 0; i < n; i++) {
        int u = i + 1;
        if (cnt[v[i]] & 1)
            d.add_edge(src, u, 1);
        else
            d.add_edge(u, dest, 1);

        int x = v[i];
        while (x > 1) {
            int f = spf[x];
            if (vis[v[i] / f]) {
                int end = vis[v[i] / f];
                if (cnt[v[i] / f] & 1)
                    d.add_edge(end, u, 1);
                else
                    d.add_edge(u, end, 1);
            }
            while (x % f == 0)
                x /= f;
        };
        vis[v[i]] = i + 1;
    }
    cout << n - d.max_flow(src, dest) << endl;
    for (auto vl : v)
        vis[vl] = 0;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    sieve();
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cout << "Case " << i << ": ";
        marwan(i);
    }
    return 0;
}