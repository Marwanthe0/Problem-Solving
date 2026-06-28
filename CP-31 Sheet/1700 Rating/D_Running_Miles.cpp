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
void marwan() {
    int n;
    cin >> n;
    vector<int> v(n), pf(n, 0ll), sf(n, 0ll);
    for (auto &vl : v)
        cin >> vl;
    int mx = 0ll;
    for (int i = n - 1; i >= 0; i--) {
        pf[i] = mx + v[i];
        mx = max(mx, v[i]);
        mx--;
    }
    mx = 0ll;
    for (int i = 0; i < n; i++) {
        sf[i] = mx + v[i];
        mx = max(mx, v[i]);
        mx--;
    }
    // for (auto vl : pf)
    //     cerr << vl << " ";
    // cerr << endl;
    // for (auto vl : sf)
    //     cerr << vl << " ";
    // cerr << endl;
    mx = 0ll;
    int ans = 0ll;
    for (int i = n - 1; i >= 0; i--) {
        ans = max(ans, v[i] + mx);
        mx = max(mx, pf[i]);
        mx--;
    }
    mx = 0ll;
    for (int i = 0; i < n; i++) {
        ans = max(ans, v[i] + mx);
        mx = max(mx, sf[i]);
        mx--;
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