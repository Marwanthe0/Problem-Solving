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
vector<int> fact(N + 9, 0), ifact(N + 9, 0);
int binexp(int a, int b) {
    int ans = 1ll;
    while (b) {
        if (b & 1)
            ans = (ans * 1ll * a) % M;
        a = (a * 1ll * a) % M;
        b >>= 1;
    }
    return ans % M;
}
void fct() {
    fact[0] = 1;
    for (int i = 1; i <= N; i++) {
        fact[i] = fact[i - 1] * i % M;
    }
    ifact[N] = binexp(fact[N], M - 2);
    for (int i = N; i > 0; i--)
        ifact[i - 1] = (ifact[i] * i) % M;
}
void marwan() {
    fct();
    int n;
    cin >> n;
    auto nCr = [&](int n, int r) {
        return (((fact[n] * 1ll * ifact[r]) % M) * ifact[n - r]) % M;
    };
    int ans = (2 * 1ll * (nCr((2ll * n) - 1, n - 1)));
    cout << (ans - n + M) % M << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}