#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define N 1000005
#define INF 1e17
#define endl "\n"
#define all(v) v.begin(), v.end()
#define minus cout << "-1" << endl
#define zero cout << "0" << endl
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define make_unique(x) \
    sort(all((x)));    \
    (x).erase(unique(all((x))), (x).end())
int n;
vector<pair<int, int>> v;
vector<int> a;
void marwan() {
    cin >> n;
    a.assign(n + 1, 0);
    v.assign(n + 1, pair<int, int>());
    for (int i = 1; i <= n; i++) {
        cin >> v[i].first >> v[i].second;
    }
    v[0].first = INT_MIN;
    sort(all(v));
    for (int i = 1; i <= n; i++)
        a[i] = v[i].first;
    a[0] = a[1] - 1;
    vector<int> dp(n + 1, INT_MAX);
    dp[0] = dp[1] = 0;
    for (int i = 2; i <= n; i++) {
        int x = v[i].first, y = v[i].second;
        int pos = lower_bound(all(a), x - y) - a.begin();
        pos = max(pos, 1ll);
        int destroy = i - pos;
        dp[i] = destroy + dp[pos - 1];
    }
    int ans = INT_MAX;
    for (int i = 1; i <= n; i++) {
        // cerr << dp[i] << " ";
        ans = min(ans, dp[i] + n - i);
    }
    cout << ans << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    marwan();
    return 0;
}