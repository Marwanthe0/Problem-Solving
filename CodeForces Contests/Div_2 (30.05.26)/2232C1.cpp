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
string s;
int n, x, k;
// int f(int i, int empty, int lim) {
//     if (i == s.size())
//         return 0;
//     int ans = 0ll;
//     if (s[i] == 'I') {
//         ans = max(ans, f(i + 1, empty - (empty > 0), lim) + (empty > 0));
//     } else if (s[i] == 'E') {
//         ans = max(ans, f(i + 1, empty, lim) + (empty < x));
//     } else
//         ans = max({ans, f(i + 1, (empty > 0 ? empty - 1 : empty), lim) + (empty > 0), f(i + 1, empty, lim) + (empty < x)});
//     return ans;
// }
void marwan() {
    cin >> n >> x >> k;
    cin >> s;
    vector<int> dp(x + 1, -1);
    dp[0] = 0;

    for (int i = 0; i < n; i++) {
        vector<int> ndp = dp;

        for (int j = 1; j <= x; j++) {
            if ((s[i] == 'I' || s[i] == 'A') && dp[j - 1] != -1) {
                ndp[j] = max(ndp[j], dp[j - 1] + 1);
            }
            if ((s[i] == 'E' || s[i] == 'A') && dp[j] != -1 && dp[j] < j * k) {
                ndp[j] = max(ndp[j], dp[j] + 1);
            }
        }
        dp = ndp;
    }
    int ans = 0;
    for (int j = 0; j <= x; j++) {
        ans = max(ans, dp[j]);
    }

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