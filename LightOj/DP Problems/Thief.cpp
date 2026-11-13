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
int n, k;
vector<pair<int, int>> v;
vector<int> lagbe;
vector<vector<int>> dp;
int f(int i, int cap) {
    if (cap == 0)
        return 0;
    if (i == n)
        return 0;
    if (dp[i][cap] != -1)
        return dp[i][cap];
    int ans = f(i + 1, cap);
    if (cap >= v[i].second)
        ans = max(ans, v[i].first + f(i, cap - v[i].second));
    return dp[i][cap] = ans;
}
void marwan(int cs) {
    cin >> n >> k;
    v.assign(n, pair<int, int>());
    lagbe.assign(n, 0);
    for (int i = 0; i < n; i++) {
        int p, c, w;
        cin >> p >> c >> w;
        v[i] = {p, w};
        k -= w * c;
    }
    if (k < 0) {
        cout << "Impossible" << endl;
        return;
    }
    dp.assign(n + 1, vector<int>(k + 1, -1));
    cout << f(0, k) << endl;
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