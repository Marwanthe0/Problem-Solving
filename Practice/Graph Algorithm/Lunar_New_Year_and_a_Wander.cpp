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
int n, m;
vector<set<int>> g;
vector<int> vis;
void marwan() {
    cin >> n >> m;
    g.assign(n + 1, set<int>());
    vis.assign(n + 1, 0);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].insert(v);
        g[v].insert(u);
    }
    multiset<int> ms;
    ms.insert(1);
    vis[1] = 1;
    while (!ms.empty()) {
        int u = *ms.begin();
        ms.erase(ms.begin());
        cout << u << " ";
        for (auto v : g[u]) {
            if (!vis[v]) {
                vis[v] = 1;
                ms.insert(v);
            }
        }
    }
    cout << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    marwan();
    return 0;
}