#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define M 1000000007
#define N 1e6
#define INF 1e17
#define endl "\n"
#define all(v) v.begin(), v.end()
#define minus cout << "-1" << endl
#define zero cout << "0" << endl
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define make_unique(x) \
    sort(all((x)));    \
    (x).erase(unique(all((x))), (x).end())
int n;
vector<vector<int>> g;
vector<int> best_path, last_dist;
vector<int> bfs(int start) {
    vector<int> dist(n + 1, 0), vis(n + 1, 0);
    queue<int> q;
    q.push(start);
    vis[start] = 1;
    while (!q.empty()) {
        int nd = q.front();
        q.pop();
        for (auto child : g[nd]) {
            if (!vis[child]) {
                vis[child] = 1;
                q.push(child);
                dist[child] = dist[nd] + 1;
            }
        }
    }
    return dist;
}
bool dfs(int nd, int p, int b) {
    if (nd == b) {
        return best_path[nd] = 1;
    }
    bool ans = false;
    for (auto child : g[nd]) {
        if (child != p) {
            ans |= dfs(child, nd, b);
        }
    }
    return best_path[nd] = ans;
}
void marwan() {
    cin >> n;
    g.assign(n + 1, vector<int>());
    best_path.assign(n + 1, 0);
    last_dist.assign(n + 1, 0);
    for (int i = 0; i + 1 < n; i++) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    vector<int> dis1 = bfs(1);
    int mxd = 0, a, b, c;
    for (int i = 1; i <= n; i++) {
        if (dis1[i] >= mxd)
            mxd = dis1[i], a = i;
    }
    vector<int> dis2 = bfs(a);
    mxd = 0;
    for (int i = 1; i <= n; i++) {
        if (dis2[i] >= mxd)
            mxd = dis2[i], b = i;
    }
    // cout << a << ' ' << b << endl;
    bool jabe = dfs(a, -1, b);
    queue<int> q;
    vector<int> vs(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        // cerr << best_path[i] << " ";
        if (best_path[i]) {
            q.push(i);
            vs[i] = 1;
        }
    }
    // cerr << endl;
    dis1.assign(n + 1, 0);
    while (!q.empty()) {
        int nd = q.front();
        q.pop();
        for (auto child : g[nd]) {
            if (!vs[child]) {
                vs[child] = 1;
                q.push(child);
                dis1[child] = dis1[nd] + 1;
            }
        }
    }
    int mxd2 = 0;
    for (int i = 1; i <= n; i++) {
        // cerr << dis1[i] << " ";
        if (i == a || i == b)
            continue;
        if (dis1[i] >= mxd2)
            mxd2 = dis1[i], c = i;
    }
    cout << mxd + mxd2 << endl;
    cout << a << ' ' << b << ' ' << c << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}