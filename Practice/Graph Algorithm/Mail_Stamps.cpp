#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define N 1000005
#define INF 1e17
#define endl "\n"
#define all(v) v.begin(), v.end()
#define minus cout << "-1" << endl
#define zero cout << "0" << endl
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define make_unique(x) \
    sort(all((x)));    \
    (x).erase(unique(all((x))), (x).end())
int n;
map<int, set<int>> g;
map<int, int> vis, deg;
void dfs(int u, int p) {
    vis[u] = 1;
    cout << u << " ";
    for (auto v : g[u]) {
        if (v == p)
            continue;
        if (vis[v] == 0)
            dfs(v, u);
    }
}
void marwan() {
    cin >> n;
    vector<int> vs;
    for (int i = 0; i < n; i++) {
        int u, v;
        cin >> u >> v;
        g[u].insert(v);
        g[v].insert(u);
        deg[u]++, deg[v]++;
        vs.push_back(u);
        vs.push_back(v);
    }
    int a = vs[0];
    make_unique(vs);
    for (auto i : vs) {
        if (deg[i] == 1) {
            a = i;
            break;
        }
    }
    dfs(a, a);
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    marwan();
    return 0;
}