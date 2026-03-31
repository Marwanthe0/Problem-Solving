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
#define minus cout << "-1" << endl
#define make_unique(x) \
    sort(all((x)));    \
    (x).erase(unique(all((x))), (x).end())
int dp[N + 1][6][2];
int n, k, z;
int f(int i, int j, bool abar, vector<int> &v) {
    if (i > k)
        return 0;
    if (dp[i][j][abar] != -1)
        return dp[i][j][abar];
    int shamne = f(i + 1, j, 1, v) + v[i - (2 * j)], pisone = 0;
    if ((i - (2 * j)) > 0 && j < z && abar) {
        pisone = f(i + 1, j + 1, 0, v) + v[i - (2 * j)];
    }
    return dp[i][j][abar] = max(shamne, pisone);
}
void marwan() {
    cin >> n >> k >> z;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j < 6; j++) {
            for (int k = 0; k < 2; k++) {
                dp[i][j][k] = -1;
            }
        }
    }
    vector<int> v(n);
    for (auto &vl : v)
        cin >> vl;
    cout << f(0, 0, 1, v) << endl;
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