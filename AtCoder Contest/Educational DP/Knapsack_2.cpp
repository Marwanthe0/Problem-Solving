#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define N 100000
#define endl "\n"
#define all(v) v.begin(), v.end()
#define forn for (int i = 0; i < n; i++)
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
void marwan() {
    int n, w;
    cin >> n >> w;
    vector<pair<int, int>> v(n);
    int mx = 0;
    for (auto &[x, y] : v) {
        cin >> x >> y;
    }
    vector<vector<int>> dp(n + 1, vector<int>(N + 1, INT_MAX));
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= N; j++) {
            dp[i][j] = dp[i - 1][j];
            if (j >= v[i - 1].second && dp[i - 1][j - v[i - 1].second] != INT_MAX) {
                int neww = dp[i - 1][j - v[i - 1].second] + v[i - 1].first;
                if (neww <= w)
                    dp[i][j] = min(dp[i][j], neww);
            }
        }
    }
    for (int i = N; i >= 0; i--)
        if (dp[n][i] <= w) {
            cout << i << endl;
            return;
        }
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}