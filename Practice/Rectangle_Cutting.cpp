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
void marwan() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, INT_MAX));
    // dp[i][j] = minimum move to make the ixj rectangle a square

    // Base Case: If Row and Columns are equal, we're done
    for (int i = 0; i <= min(n, m); i++)
        dp[i][i] = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            // cutting in the rowwise
            for (int k = 1; k <= (i / 2); k++)
                dp[i][j] = min(dp[i][j],
                               1 + (dp[k][j] + dp[i - k][j]));
            // cutting in the columnwise
            for (int k = 1; k <= (j / 2); k++) {
                dp[i][j] = min(dp[i][j],
                               1 + dp[i][k] + dp[i][j - k]);
            }
        }
    }
    cout << dp[n][m] << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}