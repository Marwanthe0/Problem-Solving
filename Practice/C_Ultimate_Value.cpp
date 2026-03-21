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
    vector<int> v(n);
    int s1 = 0, s2 = 0;
    int mn = INT_MAX, mx = INT_MIN, mn2 = INT_MAX, mx2 = INT_MIN;
    int minusodd = INT_MAX, plusodd = INT_MAX, minuseven = INT_MIN, pluseven = INT_MIN;
    vector<pair<int, int>> mnv, mxv;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        if (i & 1) {
            s2 += v[i];
            mn2 = min(mn2, i), mx2 = max(mx, i);
            minuseven = max(minuseven, 2 * v[i] - i);
            pluseven = max(pluseven, 2 * v[i] + i);
        } else {
            s1 += v[i];
            mn = min(mn, i), mx = max(mx, i);
            minusodd = min(minusodd, 2 * v[i] - i);
            plusodd = min(plusodd, 2 * v[i] + i);
        }
    }
    int ans1 = (s1 - s2) + max((mx2 - mn2), (mx - mn)), ans2 = (s1 - s2) + max(minuseven - minusodd, pluseven - plusodd);
    cout << max(ans1, ans2) << endl;
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