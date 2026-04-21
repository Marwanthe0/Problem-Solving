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
void dfs(int src, int count, vector<vector<int>> &g, vector<int> &vis, vector<int> &v, vector<int> &ans, unordered_map<int, int> &m) {
    vis[src] = 1;
    for (auto child : g[src]) {
        if (!vis[child]) {
            m[v[child]]++;
            int newcount = count + 1;
            cerr << child << " " << v[child] << " " << newcount << " " << m[v[child]] << endl;
            if (newcount >= 2 && m[v[child]] > (newcount / 2))
                ans[v[child]] = 1;
            dfs(child, newcount, g, vis, v, ans, m);
            m[v[child]]--;
        }
    }
}
void marwan() {
    int n;
    cin >> n;
    vector<int> v(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> v[i];
    vector<vector<int>> g(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int> vis(n + 1, 0), ans(n + 1, 0);
    unordered_map<int, int> m;
    m[v[1]]++;
    dfs(1, 1, g, vis, v, ans, m);
    for (int i = 1; i <= n; i++)
        cout << ans[i];
    cout << endl;
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