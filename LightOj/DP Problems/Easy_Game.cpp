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
vector<int> v;
int n;
pair<int, int> dp[101][101][2];
pair<int, int> f(int i, int j, bool alice) {
    if (i > j)
        return {0, 0};
    if (dp[i][j][alice].first != -1)
        return dp[i][j][alice];
    int sum = 0;
    pair<int, int> ans = {0, 0};
    int dif = INT_MIN;
    if (alice) {
        for (int k = i; k <= j; k++) {
            sum += v[k];
            pair<int, int> tans = f(k + 1, j, !alice);
            tans.first += sum;
            if (tans.first - tans.second > dif)
                ans = tans, dif = tans.first - tans.second;
        }
        sum = 0;
        for (int k = j; k >= i; k--) {
            sum += v[k];
            pair<int, int> tans = f(i, k - 1, !alice);
            tans.first += sum;
            if (tans.first - tans.second > dif)
                ans = tans, dif = tans.first - tans.second;
        }
        
    } else {
        for (int k = i; k <= j; k++) {
            sum += v[k];
            pair<int, int> tans = f(k + 1, j, !alice);
            tans.second += sum;
            if (tans.second - tans.first > dif)
                ans = tans, dif = tans.second - tans.first;
        }
        sum = 0;
        for (int k = j; k >= i; k--) {
            sum += v[k];
            pair<int, int> tans = f(i, k - 1, !alice);
            tans.second += sum;
            if (tans.second - tans.first > dif)
                ans = tans, dif = tans.second - tans.first;
        }
    }
    return dp[i][j][alice] = ans;
}
void marwan(int cs) {
    cin >> n;
    v.assign(n, 0);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    memset(dp, -1, sizeof(dp));
    pair<int, int> ans = f(0, n - 1, 1);
    // cerr << ans.first << " " << ans.second << endl;
    cout << ans.first - ans.second << endl;
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