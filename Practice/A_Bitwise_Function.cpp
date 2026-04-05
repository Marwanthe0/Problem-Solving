#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 998244353
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
int mod(int x, int m = M) { return x % m; }
// int f(int i, bool tight, int last, string &s) {
//     if (i == s.size())
//         return 0ll;
//     int lim = tight ? s[i] - '0' : 9, ans = 0ll;
//     for (int j = 0; j <= lim; j++) {
//         ans +=
//     }
// }
int binexp(int a, int b) {
    int ans = 1ll;
    while (b) {
        if (b & 1)
            ans = mod(ans * 1ll * a);
        a = mod(a * 1ll * a);
        b >>= 1ll;
    }
    return mod(ans);
}
int f(int x) {
    if (x & 1)
        x++;
    return mod(mod((mod(x) * 1ll * mod(x))) * 1ll * binexp(4ll, M - 2));
}
void marwan() {
    int l, r;
    cin >> l >> r;
    cout << mod(f(r) - f(l - 1) + M) << endl;
    // cout << (ans(r) - ans(l) + M) % M << endl;
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