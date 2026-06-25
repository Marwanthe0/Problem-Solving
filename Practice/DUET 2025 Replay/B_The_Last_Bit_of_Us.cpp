#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define N 1e6
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
vector<int> ache;
vector<vector<int>> g;
int n, ans;
vector<int> v;
void dfs(int nd, int p) {
    for (auto child : g[nd]) {
        if (child == p) {
            continue;
        }
        dfs(child, nd);
    }
    if (v[nd]) {
        if (v[p])
            v[p] = 0;
        else
            v[p] = 1;
        ans++;
    }
}
void marwan() {
    cin >> n;
    ans = 0;
    v.assign(n + 1, 0);
    int count = 0;
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        count += v[i];
    }
    g.assign(n + 1, vector<int>());
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    if (count & 1) {
        minus;
        return;
    }
    dfs(1, 0);
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