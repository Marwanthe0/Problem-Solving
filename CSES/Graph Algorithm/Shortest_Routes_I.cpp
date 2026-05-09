#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define N 1000000
#define endl "\n"
#define all(v) v.begin(), v.end()
#define forn for (int i = 0; i < n; i++)
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
void marwan() {
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> g(n + 1);
    multiset<pair<int, int>> ms;
    vector<int> vis(n + 1, 0);
    for (int i = 0; i < m; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        g[u].push_back({v, c});
    }
    vector<int> cost(n + 1, 1e15);
    cost[1] = 0;
    ms.insert({0, 1});
    while (!ms.empty()) {
        auto [ncost, node] = *ms.begin();
        ms.erase(ms.begin());
        if (ncost > cost[node])
            continue;
        for (auto [child, val] : g[node]) {
            if (val + cost[node] < cost[child]) {
                cost[child] = val + cost[node];
                ms.insert({cost[child], child});
            }
        }
    }
    for (int i = 1; i <= n; i++)
        cout << cost[i] << " ";
    cout << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}