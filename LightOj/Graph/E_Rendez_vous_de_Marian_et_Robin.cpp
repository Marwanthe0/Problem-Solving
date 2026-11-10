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
int n, m, h;
struct Node {
    int cost, u, done;
    bool operator<(const Node &other) const {
        return cost < other.cost;
    }
};
vector<vector<pair<int, int>>> g;
vector<int> vis, horse, dist1, dist2;
void dijkstra(int src, vector<int> &dist) {
    vis.assign(n + 1, 0);
    using state = array<int, 3>;
    priority_queue<state, vector<state>, greater<state>> pq;
    pq.push({0, src, horse[src]});
    vector<vector<int>> distt(n + 1, vector<int>(2, 1e16));
    distt[src][0] = 0;
    while (!pq.empty()) {
        auto [cost, u, done] = pq.top();
        pq.pop();
        if (cost > distt[u][done])
            continue;
        for (auto [v, w] : g[u]) {
            if (!done) {
                if (cost + w < distt[v][done]) {
                    distt[v][done] = cost + w;
                    pq.push({distt[v][done], v, done || horse[v]});
                }
            } else {
                if (cost + (w / 2) < distt[v][done]) {
                    distt[v][done] = cost + (w / 2);
                    pq.push({distt[v][done], v, done || horse[v]});
                }
            }
        }
    }
    for (int i = 1; i <= n; i++)
        dist[i] = min(distt[i][0], distt[i][1]);
}
void marwan(int cs) {
    cin >> n >> m >> h;
    g.assign(n + 1, vector<pair<int, int>>());
    horse.assign(n + 1, 0);
    dist1.assign(n + 1, 1e16);
    dist2.assign(n + 1, 1e16);
    for (int i = 0; i < h; i++) {
        int x;
        cin >> x;
        horse[x] = 1;
    }
    for (int i = 0; i < m; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        g[u].push_back({v, c});
        g[v].push_back({u, c});
    }
    dijkstra(1, dist1);
    dijkstra(n, dist2);
    int ans = 1e16;
    for (int i = 1; i <= n; i++) {
        // cerr << dist1[i] << " " << dist2[i] << endl;
        ans = min(ans, max(dist1[i], dist2[i]));
    }
    // cerr << endl;
    if (ans >= 1e16) {
        minus;
        return;
    }
    cout << ans << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        // cout << "Case " << i << ": ";
        marwan(i);
    }
    return 0;
}