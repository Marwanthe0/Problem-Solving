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
    int n;
    cin >> n;
    vector<pair<int, int>> v(n);
    for (auto &vl : v)
        cin >> vl.first >> vl.second;
    int l = 1, r = n, ans = 1;
    auto ok = [&](int mid) {
        int i = mid - 1, j = 0, count = 0;
        for (auto [x, y] : v) {
            if (x >= i && y >= j) {
                count++, i--, j++;
                if (count >= mid)
                    return true;
            }
        }
        return count >= mid;
    };

    while (l <= r) {
        int m = l + (r - l) / 2;
        if (ok(m)) {
            ans = m, l = m + 1;
        } else
            r = m - 1;
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