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
vector<int> fact(1005), invfact(1005);
int mod(int x, int m = M) { return x % m; }
int binexp(int a, int b) {
    int ans = 1ll;
    while (b) {
        if (b & 1)
            ans = mod(mod(ans) * 1ll * mod(a));
        a = mod(mod(a) * 1ll * mod(a));
        b >>= 1;
    }
    return mod(ans);
}
void fct() {
    fact[0] = invfact[0] = 1;
    for (int i = 1; i <= 1000; i++) {
        fact[i] = mod(mod(fact[i - 1]) * 1ll * i);
        invfact[i] = mod(binexp(fact[i], M - 2));
    }
}
int nCr(int n, int r) {
    return mod(mod(fact[n] * invfact[r]) * 1ll * invfact[n - r]);
}
void marwan() {
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    map<int, int> m;
    for (auto &vl : v) {
        cin >> vl;
        m[vl]++;
    }
    sort(all(v), greater<int>());
    int x = v[k - 1];
    int nc = m[x];
    int it = 0;
    while (v[it] != x)
        it++;
    // cout << nc << " " << k - it << endl;
    // cout << fact[nc] << " " << invfact[k - it] << " " << invfact[n - (k - it)] << endl;
    cout << nCr(nc, k - it) << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    fct();
    int t;
    cin >> t;
    while (t--) {
        marwan();
    }
    return 0;
}