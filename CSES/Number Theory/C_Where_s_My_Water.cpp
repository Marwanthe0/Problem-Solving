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
    int n, h;
    cin >> n >> h;
    vector<int> v(n), a, ord(n), cord(n);
    for (auto &vl : v) {
        cin >> vl;
        a.push_back(h - vl);
    }
    for (int i = 0; i < n; i++) {
        int mn = a[i];
        for (int j = i; j < n; j++) {
            mn = min(mn, a[j]);
            ord[i] += mn;
        }
        mn = a[i];
        for (int j = i - 1; j >= 0; j--) {
            mn = min(mn, a[j]);
            ord[i] += mn;
        }
    }
    int mx = max_element(all(ord)) - ord.begin();
    int ans = ord[mx];
    ord[mx] = 0ll;
    int mn = a[mx];
    for (int i = mx; i < n; i++) {
        mn = min(mn, a[i]);
        ord[i] = a[i] - mn;
    }
    mn = a[mx];
    for (int i = mx - 1; i >= 0; i--) {
        mn = min(mn, a[i]);
        ord[i] = a[i] - mn;
    }
    // cout << ans << endl;

    for (int i = 0; i < n; i++) {
        int mn = ord[i];
        for (int j = i; j < n; j++) {
            mn = min(mn, ord[j]);
            cord[i] += mn;
        }
        mn = ord[i];
        for (int j = i - 1; j >= 0; j--) {
            mn = min(mn, ord[j]);
            cord[i] += mn;
        }
    }
    // int mxs = 0ll, cnt = 0ll;
    // for (auto vl : ord) {
    //     cerr << vl << " ";
    //     if (vl)
    //         cnt += vl;
    //     else
    //         cnt = 0ll;
    //     mxs = max(mxs, cnt);
    // }
    // cerr << endl;
    cout << ans + *max_element(all(cord)) << endl;
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