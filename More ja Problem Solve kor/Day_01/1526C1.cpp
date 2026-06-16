#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define N 1e6
#define INF 1e17
#define endl "\n"
#define all(v) v.begin(), v.end()
#define minus cout << "-1" << endl
#define zero cout << "0" << endl
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define make_unique(x) \
    sort(all((x)));    \
    (x).erase(unique(all((x))), (x).end())
void marwan() {
    int n;
    cin >> n;
    vector<int> v(n);
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, INT_MIN));
    for (auto &vl : v)
        cin >> vl;
    for (int i = 0; i < n; i++) {
        dp[i + 1][1] = v[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            // dp[i][j] = max(dp[i][j], dp[i - 1][j]);
            if (j >= 1 && v[i - 1] + dp[i - 1][j - 1] >= 0)
                dp[i][j] = max(dp[i][j], v[i - 1] + dp[i - 1][j - 1]);
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i + 1; j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}