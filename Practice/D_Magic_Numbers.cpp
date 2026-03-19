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
int mod(int x, int m = M) { return x % m; }
int dp[2005][2][2][2005][2];
int f(string &s, int m, int k, int i, bool tight, bool lz, int rem, bool flag) {
    if (i == s.size())
        return rem == 0;
    if (dp[i][tight][lz][rem][flag] != -1)
        return dp[i][tight][lz][rem][flag];
    int lim = tight ? s[i] - '0' : 9;
    int ans = 0ll;
    if (flag) {
        if (k <= lim) {
            int d = k;
            int newrem = rem;
            bool nlz = lz && (d == 0), newflag = flag;
            if (!nlz) {
                newrem = (rem * 10ll + d) % m;
                newflag = !flag;
            }
            ans = mod(ans + mod(f(s, m, k, i + 1, tight && (d == lim), nlz, newrem, newflag)));
        }
    } else {
        for (int d = 0; d <= lim; d++) {
            if (lz && d == 0) {
            } else if (d == k)
                continue;
            int newrem = rem;
            bool nlz = lz && (d == 0), newflag = flag;
            if (!nlz) {
                newrem = (rem * 10ll + d) % m;
                newflag = !flag;
            }
            ans = mod(ans + mod(f(s, m, k, i + 1, tight && (d == lim), nlz, newrem, newflag)));
        }
    }
    return dp[i][tight][lz][rem][flag] = mod(ans);
}
void marwan() {
    int m, k;
    cin >> m >> k;
    string x, y;
    cin >> y >> x;
    int last = y.size() - 1;
    while (y[last] == '0')
        last--;
    y[last]--;
    last++;
    while (last < y.size()) {
        y[last] = '9';
        last++;
    }
    memset(dp, -1, sizeof(dp));
    int right = f(x, m, k, 0, 1, 1, 0, 0);
    memset(dp, -1, sizeof(dp));
    int left = f(y, m, k, 0, 1, 1, 0, 0);
    cout << mod(right - left + M) << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}