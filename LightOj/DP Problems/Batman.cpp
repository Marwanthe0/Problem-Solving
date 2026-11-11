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
string a, b, c;
int n, m, o;
int dp[76][67][52];
int f(int i, int j, int k) {
    if (i == n || j == m || k == o)
        return 0;
    if (dp[i][j][k] != -1)
        return dp[i][j][k];
    int ans = f(i + 1, j, k);
    ans = max(ans, f(i, j + 1, k));
    ans = max(ans, f(i, j, k + 1));
    if (a[i] == b[j] && b[j] == c[k]) {
        ans = max(ans, 1 + f(i + 1, j + 1, k + 1));
    }
    return dp[i][j][k] = ans;
}
void marwan(int cs) {
    cin >> a >> b >> c;
    n = a.size(), m = b.size(), o = c.size();
    memset(dp, -1, sizeof dp);
    cout << f(0, 0, 0) << endl;
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