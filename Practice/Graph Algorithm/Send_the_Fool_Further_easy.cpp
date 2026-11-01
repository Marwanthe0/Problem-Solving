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
vector<vector<pair<int, int>>> g;
int dfs(int u, int p) {
    int ans = 0;
    for (auto [v, c] : g[u]) {
        if (p == v)
            continue;
        ans = max(ans, c + dfs(v, u));
    }
    return ans;
}
void marwan() {
    cin >> n;
    g.assign(n + 1, vector<pair<int, int>>());
    for (int i = 0; i + 1 < n; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        g[u].push_back({v, c});
        g[v].push_back({u, c});
    }
    cout << dfs(0, 0) << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    marwan();
    return 0;
}