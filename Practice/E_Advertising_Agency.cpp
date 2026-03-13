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
#define minus cout << "-1" << endl
#define make_unique(x) \
    sort(all((x)));    \
    (x).erase(unique(all((x))), (x).end())
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
    return ans;
}
void fct() {
    fact[0] = 1ll;
    for (int i = 1; i <= N; i++)
        fact[i] = mod(fact[i - 1] * i);
    ifact[N] = binexp(fact[N], M - 2);
    for (int i = N; i > 0; i--)
        ifact[i - 1] = mod(ifact[i] * i);
}
int nCr(int n, int r) {
    return mod(mod(fact[n] * 1ll * ifact[r]) * 1ll * ifact[n - r]);
}
void marwan() {
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (auto &vl : v)
        cin >> vl;
    sort(all(v), greater<int>());
    int x = count(all(v), v[k - 1]), y = 0;
    while (y < n && v[y] > v[k - 1])
        y++;
    y = k - y;
    // cout << x << " " << y << endl;
    cout << nCr(x, y) << endl;
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