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
// int f(int n, bool first, vector<vector<int>> &g, vector<pair<int, int>> &v, vector<int> &vis) {
//     if (n == v.size())
//         return 0ll;
//     if (dp[n][first] != -1)
//         return dp[n][first];
//     vis[n] = 1;
//     int a = INT_MIN, b = INT_MIN, c = INT_MIN, d = INT_MIN;
//     int ans = 0ll;
//     for (auto child : g[n]) {
//         if (!vis[child]) {
//             if (first == 0) {
//                 a = abs(v[n].first - v[child].first) + f(child, 0, g, v, vis);
//                 b = abs(v[n].first - v[child].second) + f(child, 1, g, v, vis);
//             } else {
//                 c = abs(v[n].second - v[child].first) + f(child, 0, g, v, vis);
//                 d = abs(v[n].second - v[child].second) + f(child, 1, g, v, vis);
//             }
//             ans += max({a, b, c, d, 0ll});
//         }
//     }
//     vis[n] = 0;
//     return dp[n][first] = ans;
// }
void marwan() {
    int n;
    cin >> n;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i].first >> v[i].second;
    vector<int> vis(n + 1, 0);
    vector<vector<int>> g(n, vector<int>());
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<vector<int>> dp(n + 1, vector<int>(2, 0));
    queue<int> q;
    q.push(0);
    vis[0] = 1;
    vector<int> ord = {0}, parent(n + 1);
    parent[0] = -1;
    while (!q.empty()) {
        int nd = q.front();
        q.pop();
        for (auto child : g[nd]) {
            if (!vis[child]) {
                q.push(child);
                parent[child] = nd;
                vis[child] = 1;
                ord.push_back(child);
            }
        }
    }
    reverse(all(ord));
    for (auto child : ord) {
        int par = parent[child];
        if (par == -1)
            break;
        dp[par][0] += max(
            dp[child][0] + abs(v[par].first - v[child].first),
            dp[child][1] + abs(v[par].first - v[child].second));
        dp[par][1] += max(
            dp[child][0] + abs(v[par].second - v[child].first),
            dp[child][1] + abs(v[par].second - v[child].second));
    }
    cout << max(dp[0][0], dp[0][1]) << endl;
    // for (int i = 0; i <= n; i++) {
    //     for (int j = 0; j < 2; j++)
    //         dp[i][j] = -1;
    // }
    // int x = f(0, 0, g, v, vis);
    // for (int i = 0; i <= n; i++) {
    //     for (int j = 0; j < 2; j++)
    //         dp[i][j] = -1;
    // }
    // for (int i = 0; i <= n; i++)
    //     vis[i] = 0;
    // int y = f(0, 1, g, v, vis);
    // cout << max(x, y) << endl;
    // queue<int> q;
    // q.push(0);
    // while ()
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