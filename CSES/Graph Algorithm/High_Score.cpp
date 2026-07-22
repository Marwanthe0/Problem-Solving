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
int n, m;
vector<vector<pair<int, int>>> g;
vector<int> cost, vis;
void dfs(int nd) {
    // cerr << nd << endl;
    for (auto [child, c] : g[nd]) {
        // cout << child << " " << nd << " " << cost[nd] << " " << c << endl;
        cost[child] = max(cost[child], cost[nd] + c);
        dfs(child);
    }
}
void marwan() {
    cin >> n >> m;
    g.assign(n + 1, vector<pair<int, int>>());
    cost.assign(n + 1, INT_MIN);
    vis.assign(n + 1, 0);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        g[a].push_back({b, c});
    }
    cost[1] = 0;
    dfs(1);
    cout << cost[n] << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}