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
int mod(int x, int m = M) { return x % m; }
int binexp(int a, int b) {
    int ans = 1ll;
    while (b) {
        if (b & 1ll)
            ans = mod(ans * 1ll * a);
        a = mod(a * 1ll * a);
        b >>= 1ll;
    }
    return mod(ans);
}
int r_sum(int l, int r) {
    r = mod(mod((mod(r) * 1ll * mod(r + 1))) * 1ll * mod(binexp(2ll, M - 2)));
    l = mod(mod((mod(l) * 1ll * mod(l - 1))) * 1ll * mod(binexp(2ll, M - 2)));
    return mod(r - l + M);
}
void marwan() {
    int n;
    cin >> n;
    int ans = 0ll, d = 1ll;
    while (d <= n) {
        int q = (n / d);
        int r = (n / q);
        ans = mod(mod(ans) + mod(r_sum(d, r) * 1ll * mod(q)));
        d = r + 1ll;
    }
    cout << ans << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}