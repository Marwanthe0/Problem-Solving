#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define N 1e6
#define INF 1e17
#define endl "\n"
#define all(v) v.begin(), v.end()
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define minus cout << "-1" << endl
#define zero cout << "0" << endl
#define make_unique(x) \
    sort(all((x)));    \
    (x).erase(unique(all((x))), (x).end())
int n;
vector<vector<int>> v, dp;
void marwan(int cs) {
    cin >> n;
    v.resize(2 * n - 1);
    dp.resize(2 * n - 1);
    for (int i = 0; i < 2 * n - 1; i++) {
        int x = min(i + 1, (2 * n - 1) - i);
        v[i].resize(x);
        dp[i].resize(x);
        dp[i].assign(x, 0);
        for (int j = 0; j < x; j++) {
            cin >> v[i][j];
        }
    }
    int m = v.size();
    // int ans = f(0, 0);
    dp[0][0] = v[0][0];
    for (int i = 1; i < m; i++) {
        for (int j = 0; j < v[i].size(); j++) {
            int extraa = j + 1, tex = j;
            if (i < n)
                extraa = j - 1;
            if (extraa >= 0 && extraa < dp[i - 1].size())
                dp[i][j] = max(dp[i][j], dp[i - 1][extraa] + v[i][j]);
            if (tex >= 0 && tex < dp[i - 1].size())
                dp[i][j] = max(dp[i][j], dp[i - 1][tex] + v[i][j]);
            // cerr << dp[i][j] << " ";
        }
        // cerr << endl;
    }
    // cerr << endl;
    cout << "Case " << cs << ": " << dp[m - 1][0] << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
        marwan(i);
    return 0;
}