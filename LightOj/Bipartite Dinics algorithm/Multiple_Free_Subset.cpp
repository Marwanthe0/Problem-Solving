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
int n;
vector<int> v;
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

int mxlen(vector<int> &a, vector<int> &ids) {
    vector<int> v;
    for (auto id : ids)
        v.push_back(a[id]);
    int n = v.size();
    int src = 0, dest = 2 * n + 1;
    Dinic D(dest + 1);
    for (int i = 0; i < n; i++) {
        D.add_edge(src, i + 1, 1);
        D.add_edge(i + n + 1, dest, 1);
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (v[i] != 0 && abs(v[j]) % abs(v[i]) == 0) {
                D.add_edge(i + 1, j + n + 1, 1);
            }
        }
    }
    return n - D.max_flow(src, dest);
}
void marwan(int cs) {
    cin >> n;
    v.assign(n, 0);
    for (auto &vl : v)
        cin >> vl;
    make_unique((v));
    n = v.size();
    vector<int> active(n, 1), ans, id;
    for (int i = 0; i < n; i++)
        id.push_back(i);
    int best = mxlen(v, id);
    for (int i = 0; i < n; i++) {
        if (!active[i])
            continue;
        active[i] = 0;
        vector<int> todel;
        for (int j = i + 1; j < n; j++) {
            if (active[j] && v[j] % v[i] == 0) {
                active[j] = 0;
                todel.push_back(j);
            }
        }

        int ache = ans.size();
        vector<int> ids;
        for (int j = i + 1; j < n; j++) {
            if (active[j])
                ids.push_back(j);
        }
        int len = mxlen(v, ids);
        if (ache + len + 1 == best) {
            ans.push_back(v[i]);
        } else {
            for (auto id : todel) {
                active[id] = 1;
            }
        }
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