#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
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
void marwan(int cs) {
    int n;
    cin >> n;
    vector<vector<int>> v(n, vector<int>(3, 0)), dp(n, vector<int>(3, 1e9));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++)
            cin >> v[i][j];
    }
    for (int i = 0; i < 3; i++)
        dp[0][i] = v[0][i];
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                if (j != k)
                    dp[i][j] = min(dp[i][j], v[i][j] + dp[i - 1][k]);
            }
        }
    }
    cout << *min_element(all(dp[n - 1])) << endl;
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