#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define N 1e6
#define INF 1e17
#define endl "\n"
#define all(v) v.begin(), v.end()
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define minus cout << "-1" << endl
#define zero cout << "0" << endl
#define make_unique(x) \
    sort(all((x)));    \
    (x).erase(unique(all((x))), (x).end())
void marwan(int cs) {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (auto &vl : a)
        cin >> vl;
    for (auto &vl : b)
        cin >> vl;
    // if (cs == 10) {
    //     cout << n << " " << m << endl;
    //     for (auto vl : a)
    //         cout << vl << " ";
    //     cout << endl;
    //     for (auto vl : b)
    //         cout << vl << " ";
    //     cout << endl;
    //     return;
    // }
    vector<int> pf(n, 0), sf(n, 0);
    int j = m - 1, count = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (j >= 0 && a[i] >= b[j]) {
            count++, j--;
        }
        pf[i] = count;
    }
    count = 0, j = 0;
    for (int i = 0; i < n; i++) {
        if (j < m && a[i] >= b[j])
            j++, count++;
        sf[i] = count;
    }
    // for (auto vl : pf)
    //     cerr << vl << " ";
    // cerr << endl;
    // for (auto vl : sf)
    //     cerr << vl << " ";
    // cerr << endl;
    int ans = -1;
    if (pf[0] == m || sf.back() == m) {
        zero;
        return;
    }
    for (int i = 1; i < n; i++) {
        if (pf[i] + sf[i - 1] + 1 >= m) {
            if (ans == -1)
                ans = b[sf[i - 1]];
            else
                ans = min(ans, b[sf[i - 1]]);
        }
    }
    if (pf[0] == m - 1) {
        if (ans == -1)
            ans = b[0];
        else
            ans = min(ans, b[0]);
    }
    if (sf.back() == m - 1) {
        if (ans == -1)
            ans = b.back();
        else
            ans = min(ans, b.back());
    }
    cout << ans << endl;
    // int l = 0, r = *max_element(all(b));
    // auto ok = [&](int x) {
    // };
    // int ans = -1;
    // while (l <= r) {
    //     int mid = l + (r - l) / 2;
    //     bool kk = ok(mid);
    //     cerr << mid << " IS FOUND OR NOT" << kk << endl;
    //     if (kk) {
    //         ans = mid, r = mid - 1;
    //     } else
    //         l = mid + 1;
    // }
    // cout << ans << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    for (int cs = 1; cs <= t; cs++)
        marwan(cs);
    return 0;
}