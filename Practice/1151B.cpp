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
        for (auto &vl : row) {
            cin >> vl;
        }
    }
    // for (auto vl : v) {
    //     for (auto &val : vl)
    //         cerr << val << " ";
    //     cerr << endl;
    // }
    // cerr << endl;
    int x = 1024;
    vector<vector<bool>> dp(n + 1, vector<bool>(x + 1, false));
    dp[0][0] = true;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k <= x; k++) {
                dp[i][k] = (dp[i][k] || dp[i - 1][k ^ v[i - 1][j]]);
            }
        }
    }
    for (int i = 1; i < x; i++) {
        if (dp[n][i]) {
            yes;
            vector<int> ans;
            int x = i;
            for (int i = n; i >= 1; i--) {
                for (int j = 0; j < m; j++) {
                    int y = x ^ v[i - 1][j];
                    if (dp[i - 1][y]) {
                        x = y;
                        ans.push_back(j + 1);
                        break;
                    }
                }
            }
            reverse(all(ans));
            for (auto vl : ans)
                cout << vl << " ";
            cout << endl;
            return;
        }
    }

    no;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}