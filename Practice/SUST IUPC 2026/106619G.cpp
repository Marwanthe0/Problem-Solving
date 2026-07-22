#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 998244353
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
vector<vector<int>> dp;
int binexp(int a, int b) {
    int ans = 1ll;
    while (b) {
        if (b & 1)
            ans = (ans * 1ll * a) % M;
        a = (a * 1ll * a) % M;
        b >>= 1ll;
    }
    return ans % M;
}
int inv(int x) {
    return binexp(x, M - 2) % M;
}
int f(int nd, int p, int color) {
    if (g[nd].size() == 1)
        return dp[nd][color] = 1ll;
    int sum = 0ll, product = 1ll, ans = 0ll;
    if (dp[nd][color] != -1)
        return dp[nd][color];
    for (auto child : g[nd]) {
        if (child == p)
            continue;
        product *= f(child, nd, color);
        product %= M;
    }
    if (color)
        return dp[nd][color] = product;
    for (auto child : g[nd]) {
        if (child == p)
            continue;
        ans += (f(child, nd, 1) * 1ll * (product * inv(dp[child][0]))) % M;
        ans %= M;
    }
    return dp[nd][color] = ans;
}
void marwan() {
    cin >> n;
    if (n == 1) {
        cout << 0 << endl;
        return;
    }
    g.assign(n + 1, vector<int>());
    dp.assign(n + 1, vector<int>(2, -1));
    int leaf;
    for (int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    if (n == 2) {
        cout << 1 << endl;
        return;
    }
    if (g[1].size() != 1) {
        int x = f(1, -1, 0);
        cout << x << endl;
    } else {
        int x = f(1, -1, 0);
        int y = f(1, -1, 1);
        cout << x << " " << y << endl;
    }
    // cout << dp[1][0] + dp[1][1] << endl;
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