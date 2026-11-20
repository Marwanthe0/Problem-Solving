#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define N 1000005
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
void marwan(int cs) {
    int n, m, q;
    cin >> n >> m >> q;
    vector<int> v(n);
    for (auto &vl : v)
        cin >> vl;
    vector<int> rev = v;
    reverse(all(rev));
    map<int, vector<int>> pos;
    int zr = 0;
    for (int i = 0; i < n - 1; i++) {
        if (i)
            v[i] += v[i - 1], rev[i] += rev[i - 1];
        pos[v[i] - rev[i]].push_back(i);
        zr += v[i] == rev[i];
    }
    auto f = [&](int l, int r, int val) {
        return upper_bound(all(pos[val]), r) - lower_bound(all(pos[val]), l);
    };

    while (q--) {
        int idx, val;
        cin >> idx >> val;
        idx--, val *= -1;
        int mirror = n - idx - 1;
        if (idx > mirror)
            swap(idx, mirror), val *= -1;
        int cnt = zr - f(idx, mirror - 1, 0) + f(idx, mirror - 1, val);
        cout << nCr(cnt, m - 1) << endl;
    }
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    pre();
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        marwan(i);
    }
    return 0;
}