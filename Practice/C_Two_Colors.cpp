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
    cin >> k >> n;
    vector<int> v(n), pr(n + 1, 0);
    for (auto &vl : v)
        cin >> vl;
    int ans = 0ll;
    sort(all(v));
    for (int i = 1; i < k; i++) {
        int x = n - (lower_bound(all(v), i) - v.begin()), y = n - (lower_bound(all(v), k - i) - v.begin());
        // cerr << i << " " << x << " " << y << endl;
        ans += x * y - min(x, y);
    }
    cout << ans << endl;
    // cerr << endl;
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