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
set<int> valid;
int n, m;
int dp[11][11];
int f(int i, int last) {
    if (i == n)
        return 1;
    if (dp[i][last] != -1)
        return dp[i][last];
    int ans = 0;
    for (auto d : valid) {
        if (abs(last - d) <= 2)
            ans += f(i + 1, d);
    }
    return dp[i][last] = ans;
}
void marwan(int cs) {
    valid.clear();
    cin >> m >> n;
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        valid.insert(x);
    }
    memset(dp, -1, sizeof dp);
    int ans = 0;
    for (auto vl : valid) {
        ans += f(1, vl);
    }
    cout << ans << endl;
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