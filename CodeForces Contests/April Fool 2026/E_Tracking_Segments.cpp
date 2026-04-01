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
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> v(m);
    for (auto &[x, y] : v) {
        cin >> x >> y;
        x--, y--;
    }
    int q;
    cin >> q;
    vector<int> a(q);
    for (auto &vl : a) {
        cin >> vl;
        vl--;
    }
    int l = 1, r = q, ans = -1;
    auto ok = [&](int mid) {
        vector<int> b(n, 0);
        for (int i = 0; i < mid; i++) {
            b[a[i]] = 1;
        }
        for (int i = 1; i < n; i++)
            b[i] += b[i - 1];
        for (auto &[x, y] : v) {
            if ((b[y] - (x ? b[x - 1] : 0)) > ((y - x + 1) / 2))
                return true;
        }
        return false;
    };
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (ok(mid)) {
            ans = mid, r = mid - 1;
        } else
            l = mid + 1;
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