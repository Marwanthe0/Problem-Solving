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
int n, k;
vector<int> vis, cats;
vector<vector<int>> g;
int dfs(int u, int p, int cat) {
    if (cats[u])
        cat++;
    else
        cat = 0;
    if (cat > k)
        return 0;
    bool flag = true;
    int ans = 0;
    for (auto v : g[u]) {
        if (v != p) {
            flag = false;
            ans += dfs(v, u, cat);
        }
    }
    ans += flag;
    return ans;
}
void marwan() {
    cin >> n >> k;
    g.assign(n + 1, vector<int>());
    cats.assign(n + 1, 0);
    for (int i = 1; i <= n; i++)
        cin >> cats[i];
    for (int i = 0; i + 1 < n; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    cout << dfs(1, 1, 0) << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    marwan();
    return 0;
}