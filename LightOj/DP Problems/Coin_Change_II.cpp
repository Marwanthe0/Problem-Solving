#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define M 100000007
#define N 1000005
#define INF 1e17
#define endl "\n"
#define all(v) v.begin(), v.end()
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define minus cout << "-1" << endl
#define zero cout << "0" << endl
#define make_unique(x) \
    sort(all((x)));    \
    (x).erase(unique(all((x))), (x).end())
int n, k;
vector<int> v;
vector<vector<int>> dp;
void marwan(int cs) {
    cin >> n >> k;
    v.assign(n + 1, 0);
    for (int i = 1; i <= n; i++)
        cin >> v[i];
    dp.assign(n + 1, vector<int>(k + 1, 0));
    for (int i = 1; i <= n; i++) {
        dp[i][0] = 1;
        for (int j = 1; j <= k; j++) {
            dp[i][j] += dp[i - 1][j];
            if (j >= v[i])
                dp[i][j] = (dp[i][j - v[i]] + dp[i][j]) % M;
        }
    }
    cout << dp[n][k] << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cout << "Case " << i << ": ";
        marwan(i);
    }
    return 0;
}