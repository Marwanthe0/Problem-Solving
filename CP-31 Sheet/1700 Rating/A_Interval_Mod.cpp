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
int f(int i, bool first, int k, vector<int> &pfa, vector<int> &pfb, vector<int> &a, vector<int> &b) {
    if (i < 0)
        return 0;
    int same = f(i - 1, first, k, pfa, pfb, a, b) + (first ? a[i] : b[i]);
    int change = INT_MAX;
    if (i - k >= -1) {
        int x = (pfa[i] - (((i - k) >= 0) ? pfa[i - k] : 0)), y = (pfb[i] - (((i - k) >= 0) ? pfb[i - k] : 0));
        change = min(change, f(i - k, first, k, pfa, pfb, a, b) + ((first) ? x : y));
        change = min(change, f(i - k, !first, k, pfa, pfb, a, b) + (first ? x : y));
    }
    return min(same, change);
}
void marwan() {
    int n, k, p, q;
    cin >> n >> k >> p >> q;
    vector<int> v(n);
    for (auto &vl : v)
        cin >> vl;
    vector<int> a(all(v)), b(all(v));
    for (auto &vl : a) {
        vl %= p;
    }
    for (auto &vl : b) {
        vl %= q;
        vl %= p;
    }
    vector<int> pfa(n), pfb(n);
    for (int i = 0; i < n; i++) {
        pfa[i] = a[i], pfb[i] = b[i];
        if (i)
            pfa[i] += pfa[i - 1], pfb[i] += pfb[i - 1];
    }
    // int i = 0, ans = 0ll;
    // while (i < n) {
    //     int ni = min(n - 1, i + k - 1);
    //     if ((pfa[ni] - (i ? pfa[i - 1] : 0)) < (pfb[ni] - (i ? pfb[i - 1] : 0)))
    //         ans += (pfa[ni] - (i ? pfa[i - 1] : 0));
    //     else {
    //         ans += (pfb[ni] - (i ? pfb[i - 1] : 0));
    //     }
    //     i += k;
    // }
    // cout << ans << endl;
    // for (auto vl : a)
    //     cerr << vl << " ";
    // cerr << endl;
    // for (auto vl : b)
    //     cerr << vl << " ";
    // cerr << endl;
    // int ans = 0;
    // for (int i = 0; i < n; i++) {
    //     ans += min(a[i], b[i]);
    // }
    // cout << ans << endl;
    int ans = f(n - 1, 0, k, pfa, pfb, a, b);
    int ans2 = f(n - 1, 1, k, pfa, pfb, a, b);
    cout << min(ans, ans2) << endl;
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