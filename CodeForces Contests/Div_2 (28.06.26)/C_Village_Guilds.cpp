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
int n;
vector<vector<int>> g;
int ans;
int dfs(int nd, int p) {
    int mx = 0, smx = 0, count = 0;
    ans++;
    for (auto &child : g[nd]) {
        if (p != child) {
            count++;
            int x = dfs(child, nd) + 1;
            if (x >= mx) {
                smx = mx, mx = x;
            } else if (x >= smx)
                smx = x;
        }
    }
    if (count > 1) {
        ans += smx;
    }
    return mx;
}
void marwan() {
    cin >> n;
    g.assign(n + 1, vector<int>());
    for (int i = 2; i <= n; i++) {
        int x;
        cin >> x;
        g[i].push_back(x);
        g[x].push_back(i);
    }
    ans = 0ll;
    int x = dfs(1, -1);
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