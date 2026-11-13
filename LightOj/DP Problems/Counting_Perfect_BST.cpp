#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 100000007
#define N 1e6 + 5
#define N2 1e10
#define INF 1e17
#define endl "\n"
#define all(v) v.begin(), v.end()
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define minus cout << "-1" << endl
#define zero cout << "0" << endl
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
int a, b;
vector<int> pp;
void pre2() {
    for (int i = 2; i * i <= N2; i++) {
        for (int j = i * i; j <= N2; j *= i) {
            pp.push_back(j);
        }
    }
    make_unique(pp);
}
int f(int x) {
    if (x == 0)
        return 0;
    return (nCr(2 * x, x) * binexp(x + 1, M - 2)) % M;
}
void marwan(int cs) {
    cin >> a >> b;
    int low = lower_bound(all(pp), a) - pp.begin(), high = upper_bound(all(pp), b) - pp.begin();
    cout << f(high - low) << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    pre();
    pre2();
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cout << "Case " << i << ": ";
        marwan(i);
    }
    return 0;
}