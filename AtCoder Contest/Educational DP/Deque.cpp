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
int n;
vector<int> v;
int dp[3000][3000][2];
int f(int i, int j, bool taro) {
    if (i > j)
        return 0;
    if (dp[i][j][taro] != -1)
        return dp[i][j][taro];
    if (taro) {
        int left = f(i + 1, j, !taro) + v[i], right = f(i, j - 1, !taro) + v[j];
        return dp[i][j][taro] = max(left, right);
    } else {
        int left = f(i + 1, j, !taro) - v[i], right = f(i, j - 1, !taro) - v[j];
        return dp[i][j][taro] = min(left, right);
    }
}
void marwan() {
    cin >> n;
    v.resize(n);
    for (auto &vl : v)
        cin >> vl;
    memset(dp, -1, sizeof(dp));
    int ans = f(0, n - 1, 1);
    cout << ans << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}