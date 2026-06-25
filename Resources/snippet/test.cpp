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
if (n < r || r < 0 || n <= 0)
    return 0ll;
if (r == 0 || n == r)
    return 1ll;
    return mod(mod(fact[n] * 1ll * ifact[r]) * 1ll * ifact[n - r]);
}