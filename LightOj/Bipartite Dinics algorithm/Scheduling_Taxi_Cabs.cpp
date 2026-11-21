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
struct trip {
    int a, b, c, d, start, end, dist;
    void calc() {
        dist = end - start;
    }

    bool operator<(const trip &other) {
        return start < other.start;
    };
};
int time(string &s) {
    int hrs = s[0] - '0', minute = s[3] - '0';
    hrs *= 10;
    hrs += s[1] - '0';
    minute *= 10;
    minute += s[4] - '0';
    int time = hrs * 60 + minute;
    return time;
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
    vector<trip> t(n);
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        t[i].start = time(s);
        cin >> t[i].a >> t[i].b >> t[i].c >> t[i].d;
        t[i].end = t[i].start + (abs(t[i].a - t[i].c)) + abs(t[i].b - t[i].d);
        t[i].calc();
        // cout << t[i].start << " " << t[i].end << " " << t[i].a << " " << t[i].b << " " << t[i].c << " " << t[i].d << endl;
    }
    sort(all(t));
    int src = 0, dest = 2 * n + 1;
    Dinic D(dest + 1);
    for (int i = 0; i < n; i++) {
        D.add_edge(src, i + 1, 1);
        D.add_edge(i + 1 + n, dest, 1);
        for (int j = i + 1; j < n; j++) {
            int dist = abs(t[i].c - t[j].a) + abs(t[i].d - t[j].b);
            if (dist + t[i].end < t[j].start)
                D.add_edge(i + 1, j + n + 1, 1);
        }
    }
    cout << n - D.max_flow(src, dest) << endl;
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