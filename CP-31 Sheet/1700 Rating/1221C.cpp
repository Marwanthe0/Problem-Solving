#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define N 1000000
#define endl "\n"
#define all(v) v.begin(), v.end()
#define forn for (int i = 0; i < n; i++)
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define minus cout << "-1" << endl
#define make_unique(x) \
    sort(all((x)));    \
    (x).erase(unique(all((x))), (x).end())
void marwan() {
    int c, m, x;
    cin >> c >> m >> x;
    int l = 0, r = (c + m + x) / 3, ans = 0;
    auto ok = [&](int mid) {
        int tc = c - mid, tm = m - mid;
        if (tc < 0 || tm < 0)
            return false;
        return tc + tm + x >= mid;
    };
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (ok(mid)) {
            ans = mid, l = mid + 1;
        } else
            r = mid - 1;
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