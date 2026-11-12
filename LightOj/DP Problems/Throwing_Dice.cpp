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
vector<int> sum;
int n, x;
vector<vector<pair<int, int>>> dp;
pair<int, int> f(int i, int tsum) {
    if (i == 0)
        return {tsum >= x, tsum < x};

    if (dp[i][tsum].first != -1)
        return dp[i][tsum];
        
    pair<int, int> ans = {0, 0};
    for (int j = 1; j <= 6; j++) {
        pair<int, int> tans = f(i - 1, tsum + j);
        ans.first += tans.first;
        ans.second += tans.second;
    }
    return dp[i][tsum] = ans;
}
void marwan(int cs) {
    cin >> n >> x;
    dp.assign(n + 1, vector<pair<int, int>>(6 * n + 1, {-1, -1}));
    pair<int, int> ans = f(n, 0);
    ans.second += ans.first;
    int g = __gcd(ans.first, ans.second);
    if (ans.first == 0 || ans.second == 0) {
        cout << 0 << endl;
        return;
    }
    if (ans.second / g > 1)
        cout << ans.first / g << "/" << ans.second / g << endl;
    else
        cout << ans.first / g << endl;
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