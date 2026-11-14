#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 100000007
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
int n, k, s;
void marwan(int cs) {
    cin >> n >> k >> s;
    vector<int> dp(s + 1, 0), pf(s + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        pf[0] = dp[0];
        for (int j = 1; j <= s; j++)
            pf[j] = (pf[j - 1] + dp[j]) % M;
        dp[0] = 0;
        for (int sum = 1; sum <= s; sum++) {
            int l = max(0ll, sum - k), r = sum - 1;
            dp[sum] = (pf[r] - (l ? pf[l - 1] : 0) + M) % M;
        }
    }
    int ans = dp[s];
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