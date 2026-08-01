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
void marwan() {
    int n;
    cin >> n;
    vector<int> v(2 * n + 1, 0);
    vector<int> first(n + 1, -1);
    vector<int> dp(2 * n + 1, 0ll);

    for (int i = 1; i <= 2 * n; i++) {
        cin >> v[i];
        if (first[v[i]] == -1) {
            first[v[i]] = i;
        }
    }

    for (int i = 1; i <= 2 * n; i++) {
        dp[i] = dp[i - 1];
        // cerr << dp[i] << " ";
        if (first[v[i]] != i) {
            int l = first[v[i]], len = i - l + 1, tans = len * 1ll * len - len;
            dp[i] = max(dp[i], dp[l - 1] + tans);
            // cerr << dp[i] << endl;
        }
    }
    cout << dp[2 * n] + 2 * n << endl;
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