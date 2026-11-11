#include <bits/stdc++.h>
using namespace std;
// #define int long long
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
int l, r, k, n;
string a, b;
int dp[10][2][2][100][100];
int f(int i, bool tight, bool lz, int sum, int val, string &s) {
    if (i == s.size()) {
        return lz == 0 && (sum % k == 0) && (val % k == 0);
    }
    if (dp[i][tight][lz][sum][val] != -1)
        return dp[i][tight][lz][sum][val];

    int lim = tight ? s[i] - '0' : 9;
    int ans = 0;
    for (int d = 0; d <= lim; d++) {
        ans = (ans + f(i + 1, tight && d == lim, lz && d == 0, (sum + d) % k, ((val * 10) + d) % k, s));
    }
    return dp[i][tight][lz][sum][val] = ans;
}
void marwan(int cs) {
    cin >> l >> r >> k;
    if (k > 90) {
        cout << 0 << endl;
        return;
    }
    l--;
    a = to_string(l), b = to_string(r);
    memset(dp, -1, sizeof dp);
    int left = f(0, 1, 1, 0, 0, a);
    memset(dp, -1, sizeof dp);
    int right = f(0, 1, 1, 0, 0, b);
    cout << right - left << endl;
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