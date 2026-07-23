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
int n;
vector<vector<int>> g, dp;
int f(int nd, int p, int color) {
    if (dp[nd][color] != -1)
        return dp[nd][color];
    int ans = 1ll;
    for (auto child : g[nd]) {
        if (child != p) {
            if (color) {
                ans = ans * 1ll * f(child, nd, !color);
                ans %= M;
            } else {
                int tans = f(child, nd, color);
                tans %= M;
                tans += f(child, nd, !color);
                ans = ans * 1ll * tans;
                ans %= M;
            }
        }
    }
    return dp[nd][color] = ans % M;
}
void marwan() {
    cin >> n;
    g.assign(n + 1, vector<int>());
    dp.assign(n + 1, vector<int>(2, -1));
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    int ans = f(1, -1, 0) % M + f(1, -1, 1) % M;
    cout << ans % M << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}