#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define M 1000000007
#define N 1000000
#define endl "\n"
#define all(v) v.begin(), v.end()
#define forn for (int i = 0; i < n; i++)
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
void marwan() {
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> v(n);
    for (auto &vl : v)
        cin >> vl.first;
    for (auto &vl : v)
        cin >> vl.second;
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= k; j++) {
            dp[i][j] = max(dp[i - 1][j], (j >= v[i - 1].first ? dp[i - 1][j - v[i - 1].first] + v[i - 1].second : 0));
        }
    }
    cout << dp[n][k] << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}