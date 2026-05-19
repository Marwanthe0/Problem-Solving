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
int n;
vector<vector<int>> g;
int f(int node, int par, bool black) {
    int ans = 0ll, flag = 1;
    for (auto child : g[node]) {
        if (child == par)
            continue;
        flag = 0;
        ans += f(child, node, !black);
        if (!black)
            ans += f(child, node, black);
    }
    if (flag)
        return 1;
    return ans;
}
void marwan() {
    cin >> n;
    g.resize(n + 1);
    for (int i = 0; i + 1 < n; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int ans = f(1, 0, 0);
    ans += f(1, 0, 1);
    cout << ans << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}