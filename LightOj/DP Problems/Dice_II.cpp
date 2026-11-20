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
int n, k, s;
int f(int i, int sum) {
    if (i == 0)
        return sum == 0;

    int ans = 0;
    for (int j = 1; j <= k; j++)
        if (j <= sum)
            ans += f(i - 1, sum - j);
    return ans;
}
void marwan(int cs) {
    cin >> n >> k >> s;
    vector<int> dp(s + 1, 0);
    dp[0] = 1;

    for (int i = 1; i <= n; i++) {
        vector<int> prev = dp, wprev = dp;
        int weight = s;
        wprev[0] = weight--;
        for (int j = 1; j <= s; j++) {
            prev[j] = (prev[j - 1] + prev[j]) % M;
            wprev[j] = (prev[j]) * weight % M;
            weight--;
        }

        dp[0] = 0;

        for (int sum = 1; sum <= s; sum++) {
            int r = sum - 1, l = max(0ll, sum - k);
            int sm = prev[r] - (l ? prev[l - 1] : 0);
            int wsm = wprev[r] - (l ? wprev[l - 1] : 0);
            int extra = s - r;
            wsm = (wsm - (extra * sm) % M + M) % M;
            dp[sum] = wsm;
        }
    }
    cout << dp[s] << endl;
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