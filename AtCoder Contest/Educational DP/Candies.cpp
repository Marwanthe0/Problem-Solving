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
vector<int> v;
vector<vector<int32_t>> dp;
int f(int i, int k) {
    if (i < 0) {
        return (k == 0);
    }
    if (dp[i][k] != -1)
        return dp[i][k];
    int ans = 0ll;
    for (int j = 0; j <= min(k, v[i]); j++) {
        if (k >= j)
            ans = (ans + f(i - 1, k - j)) % M;
        else
            break;
    }
    return dp[i][k] = ans;
}

void marwan() {
    int k;
    cin >> n >> k;
    v.resize(n);
    for (auto &vl : v)
        cin >> vl;
    dp.resize(n + 1, vector<int32_t>(k + 2, 0));
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        vector<int> pf(k + 1, 0ll);
        for (int j = 0; j <= k; j++) {
            pf[j] = dp[i - 1][j];
            if (j)
                pf[j] = (pf[j] + pf[j - 1]) % M;
        }

        for (int j = 0; j <= k; j++) {
            // j....(j - min(j,v[i - 1]))
            // dp[i][j] += dp[i - 1][j + 1] - ((j - min(j, v[i - 1]) >= 0) ? dp[i - 1][j - min(j, v[i - 1])] : 0);
            int h = j, l = max(0ll, j - min(j, v[i - 1]));
            dp[i][j] = (dp[i][j] + (pf[h] - (l ? pf[l - 1] : 0ll) + M) % M) % M;
            // for (int tk = 0; tk <= min(j, v[i - 1]); tk++)
            //     dp[i][j] += dp[i - 1][j - tk];
        }
    }
    // int ans = f(n - 1, k);
    cout << dp[n][k] << endl;
    // cout << ans << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}