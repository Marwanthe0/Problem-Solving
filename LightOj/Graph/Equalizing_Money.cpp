#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define N 1000005
#define INF 1e17
#define endl "\n"
#define all(v) v.begin(), v.end()
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define minus cout << "-1" << endl
#define zero cout << "0" << endl
#define make_unique(x) \
    sort(all((x)));    \
    (x).erase(unique(all((x))), (x).end())
int n, m;
vector<int> a, vis;
vector<vector<int>> g;
int cnt;
int dfs(int u, int p) {
    cnt++;
    vis[u] = 1;
    int ans = a[u];
    for (auto v : g[u]) {
        if (v == p)
            continue;
        if (!vis[v])
            ans += dfs(v, u);
    }
    return ans;
}
void marwan(int cs) {
    cin >> n >> m;
    a.assign(n + 1, 0);
    g.assign(n + 1, vector<int>());
    vis.assign(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int count = 0;
    int tsum = 0;
    for (int i = 1; i <= n; i++) {
        cnt = 0;
        if (!vis[i]) {
            // cerr << i << endl;
            int sum = dfs(i, i);
            if (sum % cnt != 0) {
                no;
                return;
            }
            sum /= cnt;
            if (count == 0)
                tsum = sum;
            else if (tsum != sum) {
                no;
                return;
            }
            count++;
        }
    }
    // cerr << endl;
    // cerr << endl;
    yes;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cout << "Case " << i << ": ";
        marwan(i);
    }
    return 0;
}