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
    int n, l, r;
    cin >> n >> l >> r;
    vector<int> v(n);
    for (auto &vl : v)
        cin >> vl;
    sort(all(v));
    int sum = accumulate(all(v), 0ll);
    l = sum - l, r = sum - r;
    swap(l, r);
    // cerr << l << " " << r << endl;
    // for (auto vl : v)
    //     cerr << vl << " ";
    // cerr << endl;
    int ans = 0ll;
    for (int i = 0; i < n; i++) {
        int x = v[i];
        int lowlim = max(i + 1, lower_bound(all(v), l - x) - v.begin());
        int uplim = upper_bound(all(v), r - x) - v.begin();
        // cerr << lowlim << " " << uplim << endl;
        ans += max(0ll, (uplim - lowlim));
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