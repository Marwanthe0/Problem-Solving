#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define N 2500009
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
vector<int> fact(N), ifact(N);
void fct() {
    fact[0] = 1;
    for (int i = 1; i < N; i++) {
        fact[i] = mod(fact[i - 1] * i);
    }
    ifact[N - 1] = binexp(fact[N - 1], M - 2);
    for (int i = N - 1; i > 0; i--)
        ifact[i - 1] = mod(ifact[i] * 1ll * i);
}
int nCr(int n, int r) {
    return mod(mod(fact[n] * 1ll * ifact[r]) * 1ll * ifact[n - r]);
}
void marwan() {
    int a, b;
    cin >> a >> b;
    cout << nCr(a + b - 1, a - 1) << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    fct();
    marwan();
    return 0;
}