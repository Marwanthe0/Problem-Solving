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
long double ff(int a, int b) {
    long double x = a, y = a + b;
    return a / (y);
}
vector<vector<vector<long double>>> dp;
long double f(int a, int b, bool alice) {
    if (a == 0 || b == 0)
        return a == 0 && b;
    if (dp[a][b][alice] != -1)
        return dp[a][b][alice];
    long double ans = 0;
    if (!alice)
        ans = f(a, b - 1, !alice);
    else {
        ans += f(a - 1, b, !alice) * (ff(a, b));
        ans += f(a, b - 1, !alice) * (ff(b, a));
    }
    return dp[a][b][alice] = ans;
}
void marwan(int cs) {
    int a, b;
    cin >> a >> b;
    if (a > b) {
        cout << 0 << endl;
        return;
    }
    long double ans = f(a, b, 1);
    cout << fixed << setprecision(10) << ans << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    dp.assign(502, vector<vector<long double>>(502, vector<long double>(2, -1)));
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cout << "Case " << i << ": ";
        marwan(i);
    }
    return 0;
}