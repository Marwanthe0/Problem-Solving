#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define N 1000005
#define INF 1e17
#define endl "\n"
#define all(v) v.begin(), v.end()
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define minus cout << "-1" << endl
#define zero cout << "0" << endl
#define make_unique(x) \
    sort(all((x)));    \
    (x).erase(unique(all((x))), (x).end())
vector<vector<int>> v, dp;
int n;
int f(int i, int mask) {
    if (__builtin_popcount(mask) == n || i >= n)
        return 0;
    if (dp[i][mask] != -1)
        return dp[i][mask];
    int ans = 0;
    for (int j = 0; j < n; j++) {
        if ((mask & (1 << j)) == 0) {
            ans = max(ans, v[i][j] + f(i + 1, mask | (1ll << j)));
        }
    }
    return dp[i][mask] = ans;
}
void marwan(int cs) {
    cin >> n;
    v.assign(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cin >> v[i][j];
    }
    // cout << n << " " << (1ll << n) << endl;
    int sz = (1ll << n);
    dp.assign(n, vector<int>(sz, -1));
    int ans = f(0, 0);
    cout << ans << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cout << "Case " << i << ": ";
        marwan(i);
    }
    return 0;
}