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
int mod(int x, int m = M) { return x % m; }
// int f(int shamne, int k, bool aage, int n) {
//     if (shamne == 0 || k == 1)
//         return 1ll;
//     if (dp[shamne][k][aage] != -1)
//         return dp[shamne][k][aage];
//     int ans = 0ll;
//     for (int i = 0; i < shamne; i++) {
//         ans = mod(ans + f(n - shamne + i, k - 1, !aage, n));
//     }
//     ans = mod(ans + f(0, k - 1, aage, n));
//     return dp[shamne][k][aage] = ans;
// }
void marwan() {
    int n, k;
    cin >> n >> k;
    int dp[n][k][2];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            for (int t = 0; t < 2; t++) {
                if (j == 0)
                    dp[i][j][t] = 1;
                else
                    dp[i][j][t] = 0;
            }
        }
    }
    /// ans = dp[0][k][0];
    for (int j = 1; j < k; j++) {
        for (int i = n - 1; i >= 0; i--) {
            dp[i][j][0] = mod((i + 1 < n ? dp[i + 1][j][0] : 1) + (i - 1 >= 0 ? dp[i - 1][j - 1][1] : 1));
        }
        for (int i = 0; i < n; i++) {
            dp[i][j][1] = mod((i - 1 >= 0 ? dp[i - 1][j][1] : 1) + (i + 1 < n ? dp[i + 1][j - 1][0] : 1));
        }
    }

    cout << dp[0][k - 1][0] << endl;
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