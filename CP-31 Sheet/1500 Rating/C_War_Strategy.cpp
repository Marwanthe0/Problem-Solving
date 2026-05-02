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
    int n, m, k;
    cin >> n >> m >> k;
    int l = 1, r = n, ans = 1;

    auto ok = [&](int x) -> bool {
        x--;
        int mn = min(k - 1, n - k);
        int left, right;
        if (k - 1 == n - k || mn >= ((x / 2) + (x & 1))) {
            left = (x / 2) + (x & 1), right = x / 2;
        } else if (k - 1 == mn) {
            left = mn, right = x - mn;
        } else {
            right = mn, left = x - mn;
        }
        int mx = max(left, right);
        mn = min(left, right);

        int count = mx - 1;
        count += mx;
        count += mn;
        return count <= m;
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