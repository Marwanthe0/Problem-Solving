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
vector<int> v, vis, dis;
vector<vector<int>> g;
vector<int> a, b;
int cnt;
void dfs(int nd, int p, int d) {
    dis[nd] = d;
    for (auto child : g[nd]) {
        if (child != p) {
            dfs(child, nd, d + (v[child] != v[nd]));
        }
    }
}
void marwan() {
    int n;
    cin >> n;
    v.assign(n + 1, 0);
    vis.assign(n + 1, 0);
    dis.assign(n + 1, 0);
    a.clear();
    b.clear();
    g.assign(n + 1, vector<int>());
    for (int i = 1; i <= n; i++)
        cin >> v[i];
    for (int i = 0; i + 1 < n; i++) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1, -1, 0);
    int mxd = -1, d1;
    for (int i = 1; i <= n; i++) {
        // cout << dis[i] << " ";
        if (dis[i] > mxd)
            mxd = dis[i], d1 = i;
    }
    // cout << endl;
    dis.assign(n + 1, 0);
    // cout << d1 << endl;
    dfs(d1, -1, 0);
    // for (int i = 1; i <= n; i++)
    //     cout << dis[i] << " ";
    // cout << endl;
    cout << (*max_element(all(dis)) + 1) / 2 << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}