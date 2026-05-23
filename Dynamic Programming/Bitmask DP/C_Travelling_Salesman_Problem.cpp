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
vector<vector<int>> dp;
vector<pair<int, int>> v(n);
int f(int i, int mask) {
    if (__builtin_popcount(mask) == (n + 1))
        return 0ll;
    if (dp[i][mask] != -1)
        return dp[i][mask];
    int ans = INT_MAX;
    for (int j = 0; j <= n; j++) {
        if (j == i)
            continue;
        if (!(1 & (mask >> j))) {
            ans = min(ans, f(j, (mask | (1 << j))) + max(v[i].second, v[j].first - v[i].first));
        }
    }
    return dp[i][mask] = ans;
}
void marwan() {
    cin >> n;
    v.clear();
    v.resize(n);
    for (auto &[x, y] : v)
        cin >> x >> y;
    dp.clear();
    dp.resize(n + 1, vector<int>((1 << (n + 1)), -1));
    int ans = f(0, 0);
    cout << ans << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}