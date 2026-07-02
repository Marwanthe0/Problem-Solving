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
int n, a, b;
vector<vector<pair<int, int>>> g;
vector<int> v, t;
void dfs(int nd, int p, int xr) {
    v[nd] = xr;
    for (auto [child, cost] : g[nd]) {
        if (child != p) {
            dfs(child, nd, xr ^ cost);
        }
    }
}
void dfs2(int nd, int p, int xr) {
    if (nd == b)
        return;
    t[nd] = xr;
    for (auto [child, cost] : g[nd]) {
        if (child != p) {
            dfs2(child, nd, xr ^ cost);
        }
    }
}
void marwan() {
    cin >> n >> a >> b;
    g.assign(n + 1, vector<pair<int, int>>());
    v.assign(n + 1, 0);
    t.assign(n + 1, -1);
    for (int i = 0; i + 1 < n; i++) {
        int x, y, c;
        cin >> x >> y >> c;
        g[x].push_back({y, c});
        g[y].push_back({x, c});
    }
    dfs(b, -1, 0);
    if (!v[a]) {
        yes;
        return;
    }
    set<int> st;
    for (int i = 1; i <= n; i++) {
        if (i != b && v[i] == 0) {
            yes;
            return;
        } else if (i != b)
            st.insert(v[i]);
    }
    dfs2(a, -1, 0);
    for (int i = 1; i <= n; i++) {
        if (st.count(t[i])) {
            yes;
            return;
        }
    }
    no;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--)
        marwan();
    return 0;
}