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
int dfs(int nd, vector<vector<int>> &g, vector<int> &vis, vector<int> &ans) {
    int x = 1;
    vis[nd] = 1;
    for (auto child : g[nd]) {
        if (!vis[child]) {
            x += dfs(child, g, vis, ans);
        }
    }
    ans[nd] = x;
    return x;
}
void marwan() {
    int n;
    cin >> n;
    vector<vector<int>> g(n + 1);
    for (int i = 2; i <= n; i++) {
        int x;
        cin >> x;
        g[i].push_back(x);
        g[x].push_back(i);
    }
    vector<int> vis(n + 1, 0), ans(n + 1, 0);
    int total = dfs(1, g, vis, ans);
    for (int i = 1; i <= n; i++)
        cout << ans[i] - 1 << " ";
    cout << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}