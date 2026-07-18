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
    int n, k;
    cin >> n >> k;
    // vector<int> v(n);
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        v[i] = {x, i};
    }
    sort(all(v));
    int cnt = 0;
    int ans = 0ll;
    for (auto [x, y] : v) {
        // cout << x << " " << y << " " << cnt << endl;
        // if (__lg(y) == __lg(cnt)) {
        //     ans = max(ans, y ^ cnt);
        // } else
        ans = max(ans, 1ll << __lg(y ^ cnt));
        cnt++;
    }
    cout << ans << endl;
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