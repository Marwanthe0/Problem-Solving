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
    for (auto &vl : v)
        cin >> vl;
    vector<vector<int>> dp(2, vector<int>(n, 1));
    int ans = 1ll;
    for (int i = 1; i < n; i++) {
        if (v[i - 1] < v[i]) {
            dp[0][i] = max(dp[0][i], dp[0][i - 1] + 1);
            dp[1][i] = max(dp[1][i], dp[1][i - 1] + 1);
        }
        if (i > 1 && v[i - 2] < v[i])
            dp[1][i] = max(dp[1][i], dp[0][i - 2] + 1);
        ans = max({ans, dp[0][i], dp[1][i]});
    }
    cout << ans << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}