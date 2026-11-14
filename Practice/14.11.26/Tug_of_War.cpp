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
void marwan(int cs) {
    int n;
    cin >> n;
    vector<int> v(n);
    int sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        sum += v[i];
    }
    vector<int> dp((sum / 2) + 1, 0);
    int k = n / 2, k2 = (n + 1) / 2, half = sum / 2;
    dp[0] = 1;
    sort(all(v));
    for (int i = 0; i < n; i++) {
        for (int j = half; j >= v[i]; j--) {
            dp[j] |= dp[j - v[i]] << 1ll;
        }
    }
    int ans = 0;
    for (int i = half; i >= 0; i--) {
        if (dp[i] && ((dp[i] & (1ll << k)) || (dp[i] & (1ll << k2)))) {
            ans = i;
            break;
        }
    }
    cout << ans << " " << sum - ans << endl;
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