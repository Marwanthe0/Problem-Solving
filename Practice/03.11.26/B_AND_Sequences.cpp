#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define N 1000005
#define INF 1e17
#define endl "\n"
#define all(v) v.begin(), v.end()
#define minus cout << "-1" << endl
#define zero cout << "0" << endl
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define make_unique(x) \
    sort(all((x)));    \
    (x).erase(unique(all((x))), (x).end())
vector<int> fact(N + 5, 0ll), ifact(N + 5, 0ll);
int mod(int x, int m = M) { return (x % m + m) % m; }
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
    if (n < r || r < 0)
        return 0ll;
    if (r == 0 || n == r)
        return 1ll;
    return mod(mod(fact[n] * 1ll * ifact[r]) * 1ll * ifact[n - r]);
}
void marwan() {
    int n;
    cin >> n;
    vector<int> v(n), pf(n, 0), sf(n, 0);
    for (auto &vl : v)
        cin >> vl;
    for (int i = 0, j = n - 1; i < n; i++, j--) {
        pf[i] = v[i];
        if (i)
            pf[i] &= pf[i - 1];

        sf[j] = v[j];
        if (i)
            sf[j] &= sf[j + 1];
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        int x;
        if (i == 0)
            x = sf[1];
        else if (i == n - 1)
            x = pf[n - 2];
        else
            x = pf[i - 1] & sf[i + 1];
        if (x == v[i])
            cnt++;
    }
    int ans = (cnt * 1ll * (cnt - 1)) % M;
    ans = mod(ans * 1ll * fact[n - 2]);
    cout << ans << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    pre();
    int t;
    cin >> t;
    while (t--)
        marwan();
    return 0;
}