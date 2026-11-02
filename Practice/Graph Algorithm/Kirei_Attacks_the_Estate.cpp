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
vector<int> a, ans;
vector<vector<int>> g;
void dfs(int u, int p, int evesum, int oddsum, int evemin, int oddmin, int dist) {
    if (dist == 0)
        evesum += a[u], oddsum -= a[u];
    else
        evesum -= a[u], oddsum += a[u];

    if (evesum < evemin)
        evemin = evesum;
    if (oddsum < oddmin)
        oddmin = oddsum;

    if (dist)
        ans[u] = oddsum - oddmin;
    else
        ans[u] = evesum - evemin;
    // cerr << u << " " << evesum << " " << oddsum << " " << evemin << " " << oddmin << endl;
    for (auto v : g[u]) {
        if (v == p)
            continue;
        dfs(v, u, evesum, oddsum, evemin, oddmin, !dist);
    }
}
void marwan() {
    cin >> n;
    a.assign(n + 1, 0);
    ans.assign(n + 1, 1e9);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    g.assign(n + 1, vector<int>());
    for (int i = 0; i + 1 < n; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, 1, 0, 0, 0, 0, 0);
    for (int i = 1; i <= n; i++)
        cout << ans[i] << " ";
    cout << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
        marwan();
    return 0;
}