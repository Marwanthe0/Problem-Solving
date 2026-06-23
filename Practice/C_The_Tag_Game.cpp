#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define N 1e6
#define INF 1e17
#define endl "\n"
#define all(v) v.begin(), v.end()
#define minus cout << "-1" << endl
#define zero cout << "0" << endl
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define make_unique(x) \
    sort(all((x)));    \
    (x).erase(unique(all((x))), (x).end())
int n, k;
vector<vector<int>> g;
void dfs(int v, int parent, int d, vector<int> &level) {
    level[v] = d;
    for (auto child : g[v]) {
        if (child != parent) {
            dfs(child, v, d + 1, level);
        }
    }
}
void marwan() {
    cin >> n >> k;
    g.resize(n + 1);
    vector<int> level1, level2;
    level1.resize(n + 1, 0);
    level2.resize(n + 1, 0);
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1, 0, 0, level1);
    dfs(k, 0, 0, level2);
    int ans = 1;
    for (int i = 1; i <= n; i++) {
        if (level2[i] < level1[i]) {
            ans = max(ans, level1[i] * 2);
        }
    }
    cout << ans << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}