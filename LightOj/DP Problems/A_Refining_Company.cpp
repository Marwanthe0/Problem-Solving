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
int n, m;
vector<vector<int>> u, r, pfu, pfr, dp;
int f(int i, int j) {
    if (i < 0 || j < 0)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    int ans = 0;
    ans = max(ans, pfu[i][j] + f(i - 1, j));
    ans = max(ans, pfr[i][j] + f(i, j - 1));
    return dp[i][j] = ans;
}
void marwan(int cs) {
    cin >> n >> m;
    u.assign(n, vector<int>(m, 0));
    r.assign(n, vector<int>(m, 0));
    pfu.assign(n, vector<int>(m, 0));
    pfr.assign(n, vector<int>(m, 0));
    dp.assign(n, vector<int>(m, -1));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> u[i][j];
            pfu[i][j] = u[i][j];
            if (j)
                pfu[i][j] += pfu[i][j - 1];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> r[i][j];
            pfr[i][j] = r[i][j];
            if (i)
                pfr[i][j] += pfr[i - 1][j];
        }
    }
    cout << f(n - 1, m - 1) << endl;
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