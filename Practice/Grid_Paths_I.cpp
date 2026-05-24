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
    vector<string> v(n);
    for (auto &vl : v)
        cin >> vl;
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == 0 && j == 0)
                dp[i][j] = 1;
            if (v[i][j] == '*') {
                dp[i][j] = 0;
                continue;
            }
            dp[i][j] += (i ? dp[i - 1][j] : 0) + (j ? dp[i][j - 1] : 0);
            dp[i][j] %= M;
        }
    }
    cout << dp[n - 1][n - 1] << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}