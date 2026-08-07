#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define N 1e6
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
vector<vector<int>> v;
vector<vector<vector<bool>>> dp, vis;
bool f(int i, int j, int sum) {
    if (i >= n || j >= m) {
        // cerr << "ERROR " << i << " " << j << " " << sum << endl;
        return 0;
    }
    sum += v[i][j];
    // cerr << i << " " << j << " " << sum << endl;
    if (i == n - 1 && j == m - 1) {
        return sum == 0;
    }
    if (vis[i][j][sum]) {
        return dp[i][j][sum];
    }
    bool right = false, down = false;
    if (j < m)
        right = f(i, j + 1, sum);
    if (i < n)
        down = f(i + 1, j, sum);
    vis[i][j][sum] = 1;
    return dp[i][j][sum] = right | down;
}
void marwan() {
    cin >> n >> m;
    v.assign(n, vector<int>(m, 0));
    dp.assign(n, vector<vector<bool>>(m, vector<bool>(n * m + 1, 0)));
    vis.assign(n, vector<vector<bool>>(m, vector<bool>(n * m + 1, 0)));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cin >> v[i][j];
    }
    bool ans = f(0, 0, 0);
    if (ans)
        yes;
    else
        no;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        marwan();
    }
    return 0;
}