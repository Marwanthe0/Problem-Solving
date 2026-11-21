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

vector<pair<int, int>> path = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
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
    vector<string> v(n);
    vector<pair<int, int>> ghost, human;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        for (int j = 0; j < n; j++) {
            if (v[i][j] == 'G')
                ghost.push_back({i, j});
            if (v[i][j] == 'H')
                human.push_back({i, j});
        }
    }
    if (ghost.size() < human.size()) {
        cout << "Vuter Dol Kupokat" << endl;
        return;
    }
    if (human.size() == 0) {
        cout << 0 << endl;
        return;
    }
    int src = 0, dest = n * n + 2;
    auto valid = [&](int i, int j) {
        return i >= 0 && j >= 0 && i < n && j < n && v[i][j] != '#';
    };
    vector<vector<pair<int, int>>> g(n * n + 3, vector<pair<int, int>>());
    auto ok = [&](int lim) {
        Dinic din(dest+1);

        for (auto [si, sj] : ghost) {
            int u = si * n + sj + 1;
            din.add_edge(src, u, 1);
            queue<pair<int, int>> q;
            vector<vector<int>> dist(n, vector<int>(n, 1e9));
            vector<vector<int>> vis(n, vector<int>(n, 0));
            q.push({si, sj});
            dist[si][sj] = 0;
            vis[si][sj] = 1;

            while (!q.empty()) {
                auto [i, j] = q.front();
                q.pop();
                if (v[i][j] == 'H') {
                    int v = i * n + j + 1;
                    din.add_edge(u, v, 1);
                }

                for (auto [x, y] : path) {
                    x += i, y += j;
                    if (valid(x, y) && vis[x][y] == 0 && dist[i][j] + 1 <= lim) {
                        q.push({x, y});
                        vis[x][y] = 1;
                        dist[x][y] = dist[i][j] + 1;
                    }
                }
            }
        }
        for (auto [si, sj] : human) {
            int u = si * n + sj + 1;
            din.add_edge(u, dest, 1);
        }
        int mxfl = din.max_flow(src, dest);

        return mxfl;
    };

    int l = 1, r = 2 * n + 1, ans = -1;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        int kk = ok(mid);
        // cerr << mid << " " << kk << endl;
        if (kk >= human.size()) {
            ans = mid, r = mid - 1;
        } else
            l = mid + 1;
    }

    if (ans == -1)
        cout << "Vuter Dol Kupokat" << endl;
    else
        cout << ans * 2 + 2 << endl;
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