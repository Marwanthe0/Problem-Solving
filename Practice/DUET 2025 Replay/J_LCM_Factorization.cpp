#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 998244353
#define N 3e5
#define INF 1e17
#define endl "\n"
#define all(v) v.begin(), v.end()
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define minus cout << "-1" << endl
#define zero cout << "0" << endl
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
vector<int> spf(N + 1, 0);
void prespf() {
    for (int i = 2; i <= N; i++) {
        if (!spf[i]) {
            for (int j = i; j <= N; j += i) {
                if (!spf[j])
                    spf[j] = i;
            }
        }
    }
}
void marwan() {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> v(n);
    map<int, int> m;
    int one = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        // cout << x << endl;
        if (x <= 1) {
            v[i].push_back(1);
            one++;
            continue;
        }
        while (x > 1) {
            v[i].push_back(spf[x]);
            x = x / spf[x];
        }
    }
    int sum = 0ll;
    for (int i = 0; i < n; i++) {
        make_unique(v[i]);
        for (auto vl : v[i]) {
            m[vl]++;
        }
    }
    int ans = 0ll, totalway = nCr(n, k);
    for (auto [x, y] : m) {
        int wayWithoutX = nCr(n - y, k);
        int wayWithX = (totalway - wayWithoutX + M) % M;
        if (x > 1)
            ans = mod(ans + mod(x * 1ll * wayWithX));
        // cerr << x << " " << y << " " << wayWithoutX << endl;
    }
    cout << ans % M << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    pre();
    prespf();
    int t;
    cin >> t;
    while (t--) {
        marwan();
    }
    return 0;
}