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
int n, k;
vector<vector<pair<int, int>>> g;
vector<int> leaf, par, on;
int dfs(int nd, int p, int i, int md) {
    int ti = i;
    int count = 0;
    if (ti == 0) {
        if(on[])
        ti = md, count++;
    }
    for (auto [child, val] : g[nd]) {
        if (child == p)
            continue;
        count += dfs(child, nd, ti - 1);
    }
    return count;
}
bool ok(int mid) {
    return dfs(leaf, -1, mid, md) <= k;
}
void marwan() {
    cin >> n >> k;
    on.assign(n + 1, 0);
    g.assign(n + 1, vector<pair<int, int>>());
    for (int i = 1; i < n; i++) {
        int x, y, c;
        cin >> x >> y >> c;
        g[x].push_back({y, c});
        g[y].push_back({x, c});
        if (c == 0)
            on[x]++, on[y]++;
    }
    for (int i = 1; i <= n; i++) {
        if (g[i].size() == 1)
            leaf.push_back(i);
    }
    int l = 1, r = n, ans = 0;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        bool kk = ok(mid);
        if (kk) {
            ans = mid, r = mid - 1;
        } else
            l = mid + 1;
    }
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