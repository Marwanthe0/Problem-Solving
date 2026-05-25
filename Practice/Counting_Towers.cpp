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
    int n;
    cin >> n;
    vector<vector<int>> dp(n + 1, vector<int>(7, 0));
    for (int i = 1; i <= 4; i++)
        dp[0][i] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 6; j++) {
            if (j <= 4)
                for (int k = 1; k <= 5; k++)
                    dp[i][j] += dp[i - 1][k];
            else {
                dp[i][j] += dp[i - 1][1] + dp[i - 1][5] + dp[i - 1][6];
            }
        }
    }
    // int ans = 0;
    for (int i = 1; i <= 6; i++)
        cout << dp[n][i] << " ";
    cout << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--)
        marwan();
    return 0;
}