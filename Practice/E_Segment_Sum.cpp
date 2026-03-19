#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 998244353
#define N 1000000
#define endl "\n"
#define all(v) v.begin(), v.end()
#define forn for (int i = 0; i < n; i++)
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
int mod(int x, int m = M) { return x % m; }
int pow10[20];
pair<int, int> dp[21][2][(1 << 10)][2];
bool vis[21][2][(1 << 10)][2];
pair<int, int> f(string &s, int i, bool tight, int mask, int k, bool lz) {
    if (i == s.size()) {
        return {__builtin_popcount(mask) <= k, 0ll};
    }
    if (vis[i][tight][mask][lz])
        return dp[i][tight][mask][lz];
    int lim = tight ? s[i] - '0' : 9;
    int count = 0ll, sum = 0ll;
    int remaining = s.size() - i - 1;
    for (int d = 0; d <= lim; d++) {
        int newmask = mask;
        if (lz == 0 || (d != 0))
            newmask = mask | (1 << d);
        // if (__builtin_popcount(mask) > k)
        //     continue;
        pair<int, int> tans = f(s, i + 1, tight && (d == lim), newmask, k, lz && (d == 0));
        count = mod((long long)count + (long long)tans.first);
        sum = mod(sum + mod(mod(tans.second) + mod(mod(mod(d) * 1ll * pow10[remaining]) * 1ll * mod(tans.first))));
        // cerr << i << " " << d << " " << count << " " << sum << " " << pow10[remaining] << endl;
    }
    vis[i][tight][mask][lz] = true;
    return dp[i][tight][mask][lz] = {count, sum};
}
void marwan() {
    int a, b, k;
    cin >> a >> b >> k;
    pow10[0] = 1;
    for (int i = 1; i < 20; i++) {
        pow10[i] = mod(pow10[i - 1] * 10ll);
        // cerr << i << " " << pow10[i] << endl;
    }
    string x = to_string(b), y = to_string(a - 1);
    memset(dp, -1, sizeof(dp));
    memset(vis, false, sizeof(vis));
    pair<int, int> aa = f(x, 0, 1, 0, k, 1);
    memset(dp, -1, sizeof(dp));
    memset(vis, false, sizeof(vis));
    pair<int, int> bb = f(y, 0, 1, 0, k, 1);
    // cerr << aa.first << " " << aa.second << endl;
    // cerr << bb.first << " " << bb.second << endl;
    cout << mod(aa.second - bb.second + M) << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}