#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 998244353
#define N 100000
#define endl "\n"
#define all(v) v.begin(), v.end()
#define forn for (int i = 0; i < n; i++)
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
vector<int> fact(N + 5, 0), ifact(N + 5, 0);
int mod(int x, int m = M) { return x % m; }
int binexp(int a, int b) {
    int ans = 1ll;
    while (b) {
        if (b & 1)
            ans = mod(ans * 1ll * a);
        a = mod(a * 1ll * a);
        b >>= 1;
    }
    return mod(ans);
}
void pre() {
    fact[0] = 1ll;
    for (int i = 1; i <= N; i++)
        fact[i] = mod(fact[i - 1] * 1ll * i);
    ifact[N] = binexp(fact[N], M - 2);
    for (int i = N; i > 0; i--) {
        ifact[i - 1] = mod(ifact[i] * 1ll * i);
    }
}
int nCr(int n, int r) {
    return mod(mod(fact[n] * 1ll * ifact[r]) * 1ll * ifact[n - r]);
}
void marwan() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &vl : v)
        cin >> vl;
    int ans = 1ll;
    for (int i = 0; i < n; i += 3) {
        int a = v[i], b = v[i + 1], c = v[i + 2];
        int x = min({a, b, c});
        if (x == a && x == b && x == c)
            ans = mod(ans * 3ll);
        else if ((x == a && x == b && x != c) || (x == a && x == c && x != b) || (x == b && x == c && x != a))
            ans = mod(ans * 2ll);
    }
    ans = mod(ans * 1ll * nCr(n / 3, n / 6));
    cout << ans << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    pre();
    marwan();
    return 0;
}