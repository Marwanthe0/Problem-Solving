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
map<char, int> mp = {{'R', 1}, {'B', 2}, {'G', 3}};
int mx = 0;
int dp[200005][4];
int f(int i, int ill, vector<vector<int>> &g, vector<vector<int>> &l, vector<int> &level, string &s) {
    if (i > mx)
        return 0;
    int ans = INT_MAX;
    if (dp[i][ill] != -1)
        return dp[i][ill];
    for (int k = 1; k <= 3; k++) {
        if (k == ill)
            continue;
        int cost = 0;
        for (auto val : l[i]) {
            cost += (mp[s[val - 1]] != k);
        }
        ans = min(ans, cost + f(i + 1, k, g, l, level, s));
    }
    return dp[i][ill] = ans;
}
void marwan() {
    mx = 0;
    int n;
    cin >> n;
    string s;
    cin >> s;
    if (n == 1) {
        cout << 0 << endl;
        return;
    }
    vector<vector<int>> g(n + 10), l(n + 10);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int> vis(n + 1, 0), level(n + 1, 1);
    queue<int> q;
    q.push(1);
    vis[1] = 1;
    while (!q.empty()) {
        int nd = q.front();
        q.pop();
        for (auto child : g[nd]) {
            if (!vis[child]) {
                vis[child] = 1;
                q.push(child);
                level[child] = level[nd] + 1;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        l[level[i]].push_back(i);
        mx = max(mx, level[i]);
    }
    for (int i = 1; i <= mx; i++) {
        for (int j = 0; j < 4; j++)
            dp[i][j] = -1;
    }
    // for (int i = 1; i <= mx; i++) {
    //     cerr << i << endl;
    //     for (auto vl : l[i])
    //         cerr << vl << " ";
    //     cerr << endl;
    // }
    // cerr << endl;
    int ans = f(1, 0, g, l, level, s);
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