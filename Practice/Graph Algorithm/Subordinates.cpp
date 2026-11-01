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
vector<vector<int>> g;
vector<int> vis, ans;
int dfs(int u, int p) {
    int childs = 1;
    for (auto v : g[u]) {
        if (v == p)
            continue;
        childs += dfs(v, u);
    }
    return ans[u] = childs;
}
void marwan() {
    cin >> n;
    g.assign(n + 1, vector<int>());
    ans.assign(n + 1, 0);
    for (int i = 2; i <= n; i++) {
        int x;
        cin >> x;
        g[x].push_back(i);
        g[i].push_back(x);
    }
    dfs(1, 0);
    for (int i = 1; i <= n; i++)
        cout << ans[i] - 1 << " ";
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    marwan();
    return 0;
}