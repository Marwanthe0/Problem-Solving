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
    for (int i = 0; i < n; i++)
        cin >> v[i].first;
    for (int i = 0; i < n; i++)
        cin >> v[i].second;
    sort(all(v));
    long double l = v[0].first, r = v[n - 1].first, ans = l;
    auto ok = [&](long double mid) {
        long double left = 0, right = 0;
        for (int i = 0; i < n; i++) {
            long double x = (long double)v[i].first, y = (long double)v[i].second;
            if (x == mid)
                continue;
            if (x < mid)
                left = max(left, y + (mid - x));
            else
                right = max(right, y + (x - mid));
        }
        return left >= right;
    };
    while (r - l > (long double)(1.0) / (long double)1e6) {
        long double mid = l + (r - l) / (long double)2.0;
        if (ok(mid)) {
            r = mid;
        } else
            l = mid;
    }
    cout << setprecision(10) << l << endl;
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