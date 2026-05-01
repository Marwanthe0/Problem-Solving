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
    int mx = 0;
    for (auto &vl : v) {
        cin >> vl;
        mx = max(mx, __lg(vl));
    }
    // for (auto vl : v) {
    //     for (int i = mx; i >= 0; i--)
    //         cout << (1 & (vl >> i));
    //     cout << endl;
    // }
    // cout << endl;
    int ans = 1;
    for (int i = mx; i >= 0; i--) {
        int last = -1, tans = 0, flag = 0;
        for (int j = 0; j < n; j++) {
            if (1 & (v[j] >> i)) {
                tans = max(tans, j - last);
                last = j;
                flag = 1;
            }
        }
        if (flag)
            tans = max(tans, n - last);
        if (flag)
            ans = max(ans, tans);
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