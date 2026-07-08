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
vector<vector<int>> v, dp;
int n, m;
int f(int i, int j) {
    if (i == n - 1 && j == m - 1)
        return v[i][j];
    // if (dp[i][j] != INT_MAX)
    //     return dp[i][j];
    int right = INT_MIN, down = INT_MIN;
    if (i < n - 1)
        right = f(i + 1, j);
    if (j < m - 1)
        down = f(i, j + 1);
    if (right == INT_MIN)
        return down + v[i][j];
    else if (down == INT_MIN)
        return right + v[i][j];
    int x = right + v[i][j], y = down + v[i][j];
    if (abs(x) < abs(y))
        return x;
    else
        return y;
}
void marwan() {
    cin >> n >> m;
    v.assign(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> v[i][j];
        }
    }
    if ((n + m - 1) & 1) {
        no;
        return;
    }
    // dp.resize(n + 1, vector<int>(m + 1, INT_MAX));
    if (!f(0, 0))
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