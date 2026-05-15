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
vector<vector<short>> v;
vector<vector<int32_t>> dp;
int f(int i, int mask) {
    if (i < 0)
        return 1;
    if (dp[i][mask] != -1)
        return dp[i][mask];
    int ans = 0ll;
    for (int j = 0; j < n; j++) {
        if (1 & (mask >> j))
            continue;
        if (v[i][j]) {
            ans = (ans + f(i - 1, mask | (1 << j))) % M;
        }
    }
    return dp[i][mask] = ans;
}
void marwan() {
    cin >> n;
    v.resize(n, vector<short>(n));
    dp.resize(n, vector<int32_t>(1 << (n), -1));
    for (auto &vl : v) {
        for (auto &val : vl)
            cin >> val;
    }
    int ans = f(n - 1, 0);
    cout << ans << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}