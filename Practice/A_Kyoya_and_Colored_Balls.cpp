#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define N 10000
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
    return ans;
}
void fct() {
    fact[0] = 1;
    for (int i = 1; i <= N; i++)
        fact[i] = mod(fact[i - 1] * 1ll * i);
    ifact[N] = binexp(fact[N], M - 2);
    for (int i = N; i > 0; i--)
        ifact[i - 1] = mod(ifact[i] * 1ll * i);
}
int nCr(int n, int r) {
    return mod(mod(fact[n] * 1ll * ifact[r]) * 1ll * ifact[n - r]);
}
void marwan() {
    fct();
    int n;
    cin >> n;
    vector<int> c(n);
    int sum = 0, ans = 1ll, s = 0ll;
    for (auto &ci : c) {
        cin >> ci;
        int ck = nCr(s + ci - 1, ci - 1);
        ans = mod(ans * 1ll * ck);
        s += ci;
    }
    cout << ans << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}