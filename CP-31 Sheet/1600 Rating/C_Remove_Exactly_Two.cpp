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
#define minus cout << "-1" << endl
#define make_unique(x) \
    sort(all((x)));    \
    (x).erase(unique(all((x))), (x).end())
void dfs(int src, vector<set<int>> &g, vector<int> &vis) {
    vis[src] = 1;
    for (auto child : g[src]) {
        if (!vis[child]) {
            dfs(child, g, vis);
        }
    }
}
void marwan() {
    int n;
    cin >> n;
    vector<unordered_set<int>> g(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        g[u].insert(v);
        g[v].insert(u);
    }
    vector<pair<int, int>> v;
    for (int i = 1; i <= n; i++) {
        v.push_back({i, g[i].size()});
    }
    sort(all(v), [&](pair<int, int> a, pair<int, int> b) { return a.second > b.second; });
    int mx = v[0].second, ans = INT_MIN;
    for (auto [x, y] : v) {
        if (y != mx)
            break;
        for (auto [i, j] : v) {
            if (i == x)
                continue;
            if (j + y - 1 <= ans)
                break;
            if (g[i].count(x))
                ans = max(ans, j + y - 2);
            else
                ans = max(ans, j + y - 1);
        }
    }
    cout << ans << endl;
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