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
vector<int> fact(N + 5, 0), ifact(N + 5, 0);
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
void fct() {
    fact[0] = 1ll;
    for (int i = 1; i <= N; i++)
        fact[i] = mod(i * 1ll * fact[i - 1]);
    ifact[N] = binexp(fact[N], M - 2);
    for (int i = N; i > 0; i--)
        ifact[i - 1] = mod(ifact[i] * i);
}
bool good(int n, int a, int b) {
    while (n) {
        int x = n % 10;
        if (x == a || x == b)
            n /= 10;
        else
            return false;
    }
    return true;
}
int nCr(int n, int r) {
    return mod(mod(fact[n] * 1ll * ifact[r]) * 1ll * ifact[n - r]);
}
void marwan() {
    int a, b, n;
    cin >> a >> b >> n;
    int ans = 0ll;
    for (int i = 0; i <= n; i++) {
        int sum = (a * i) + b * (n - i);
        if (good(sum, a, b)) {
            ans = mod(ans + nCr(n, i));
            // cerr << i << " " << n - i << endl;
        }
    }
    cout << ans << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    fct();
    marwan();
    return 0;
}