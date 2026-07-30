#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define N 1e6
#define INF 1e17
#define endl "\n"
#define all(v) v.begin(), v.end()
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define minus cout << "-1" << endl
#define zero cout << "0" << endl
#define make_unique(x) \
    sort(all((x)));    \
    (x).erase(unique(all((x))), (x).end())
int n, m, a, b;
vector<vector<int>> g, dist;
vector<int> par;
void marwan() {
    cin >> n >> m >> a >> b;
    g.assign(n + 1, vector<int>());
    par.assign(n + 1, -1);
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dist.assign(n + 1, vector<int>(2, INT_MAX));
    queue<int> q;
    q.push(b);
    dist[b][0] = dist[b][1] = 0;
    int cnt = 0;
    vector<int> vis(n + 1, 0);
    while (!q.empty() && cnt < 10) {
        int nd = q.front();
        q.pop();
        cerr << nd << " " << dist[nd][0] << " " << dist[nd][1] << endl;
        for (auto child : g[nd]) {
            if (child != par[nd]) {
                if (!vis[child])
                    q.push(child);
                vis[child] = 1;
                par[child] = nd;
                int dst = dist[nd][1] + 1, dst1 = dist[child][0], dst2 = dist[child][1];
                cerr << nd << "->" << child << "::" << " " << dst << " " << dst1 << " " << dst2 << endl;
                dist[child][0] = min({dst, dst1, dst2});
                vector<int> sst;
                sst.push_back(dst);
                sst.push_back(dst1);
                sst.push_back(dst2);
                sort(all(sst));
                dist[child][1] = sst[1];
            }
        }
        cnt++;
    }
    // cerr << endl;
    if (dist[a][1] != INT_MAX)
        cout << dist[a][1] << endl;
    else
        cout << -1 << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        marwan();
    }
    return 0;
}