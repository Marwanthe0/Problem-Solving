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
#define minus cout << "-1" << endl
#define make_unique(x) \
    sort(all((x)));    \
    (x).erase(unique(all((x))), (x).end())
int dp[21][2][4];
int f(string &s, int i, bool tight, int count) {
    if (i == s.size() || count > 3)
        return count <= 3;
    if (dp[i][tight][count] != -1)
        return dp[i][tight][count];
    int lim = tight ? s[i] - '0' : 9;
    int ans = 0ll;
    for (int d = 0; d <= lim; d++) {
        ans += f(s, i + 1, tight && (d == lim), count + (d != 0));
    }
    return dp[i][tight][count] = ans;
}
void marwan() {
    int a, b;
    cin >> a >> b;
    string x = to_string(b), y = to_string(a - 1);
    memset(dp, -1, sizeof(dp));
    int ans1 = f(x, 0, 1, 0);
    memset(dp, -1, sizeof(dp));
    int ans2 = f(y, 0, 1, 0);
    cout << ans1 - ans2 << endl;
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