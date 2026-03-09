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
    int n, k;
    cin >> n >> k;
    vector<int> v(n), a(n);
    for (auto &vl : v)
        cin >> vl;
    a.back() = v.back();
    for (int i = n - 2; i >= 0; i--) {
        a[i] = max(v[i], a[i + 1] + 1ll);
    }
    int ans = *max_element(all(v));
    for (int i = 0; i < n; i++) {
        int l = v[i], r = a[i], locans = 0ll;
        // cerr << l << " " << r << endl;
        auto ok = [&](int m) {
            int op = k;
            int tmpm = m;
            for (int j = i; j < n; j++) {
                // //cerr << v[j] << " " << tmpm << " " << op << endl;
                if (v[j] >= tmpm)
                    return true;
                if ((tmpm - v[j]) <= op)
                    op -= (tmpm - v[j]);
                else
                    return false;
                tmpm--;
            }
            return true;
        };
        while (l <= r) {
            int m = l + (r - l) / 2ll;
            if (ok(m)) {
                locans = m, l = m + 1ll;
            } else
                r = m - 1ll;
        }
        // cerr << i << " " << locans << endl;
        ans = max(ans, locans);
    }
    // cerr << endl;
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