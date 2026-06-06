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
    int n, k;
    cin >> n >> k;
    vector<vector<int>> v(k, vector<int>(n)), pos(k, vector<int>(n + 1));
    for (auto &row : v) {
        for (auto &vl : row)
            cin >> vl;
    }
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < n; j++) {
            pos[i][v[i][j]] = j;
        }
    }
    vector<int> dp(n + 5, 1);
    for (int id = 0; id < n; id++) {
        int i = v[k - 1][id];
        for (int j = 1; j <= n; j++) {
            if (i == j)
                continue;
            bool flag = true;
            for (int t = 0; t < k; t++) {
                if (pos[t][j] > pos[t][i])
                    flag = false;
            }
            if (flag && dp[j] + 1 > dp[i])
                dp[i] = dp[j] + 1;
        }
    }
    // for (int i = 0; i < k; i++) {
    //     for (int j = 1; j <= n; j++)
    //         cout << pos[i][j] << " ";
    //     cout << endl;
    // }
    cout << *max_element(all(dp));
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}