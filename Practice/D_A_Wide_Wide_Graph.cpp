#include <bits/stdc++.h>
using namespace std;
#define int long long
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
void marwan() {
    cin >> n;
    g.assign(n + 1, vector<int>());
    for (int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    vector<int> dis1 = bfs(1);
    int mxd = 0, a, b;
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
    // cout << a << " " << b << endl;
    vector<int> dis3 = bfs(b);
    vector<int> max_dist(n, 0);
    for (int i = 1; i <= n; i++) {
        max_dist[i - 1] = max(dis2[i], dis3[i]);
        // cout << max_dist[i] << " ";
    }
    sort(all(max_dist));
    int j = 0;
    for (int i = 1; i <= n; i++) {
        while (j < n - 1 && max_dist[j] < i)
            j++;
        cout << j + 1 << " ";
    }
    cout << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}