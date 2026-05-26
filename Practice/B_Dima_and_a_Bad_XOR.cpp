#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define N 1000000
#define endl "\n"
#define all(v) v.begin(), v.end()
#define forn for (int i = 0; i < n; i++)
#define yes cout << "TAK" << endl
#define no cout << "NIE" << endl
void marwan() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> v(n, vector<int>(m));
    for (auto &row : v) {
        for (auto &vl : row)
            cin >> vl;
    }
    int x = 1024;
    vector<vector<int>> dp(n + 1, vector<int>(x + 1, 0));
    // dp[0][0] = 1;
    // for (int i = 1; i <= n; i++) {
    //     for (int j = 0; j < m; j++) {
    //         for (int k = 0; k <= x; k++) {
    //             dp[i][x] = dp[i - 1][x ^ v[i - 1][j]];
    //         }
    //     }
    // }
    for (int i = 1; i < x; i++)
        if (dp[n][i]) {
            yes;
            return;
        }
    no;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}