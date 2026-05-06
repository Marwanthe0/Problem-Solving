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
#define minus cout << "-1" << endl
#define make_unique(x) \
    sort(all((x)));    \
    (x).erase(unique(all((x))), (x).end())
vector<int> fact(N + 1, 0), ifact(N + 1, 0);
int binexp(int a, int b) {
    int ans = 1;
    while (b) {
        if (b & 1)
            ans = (ans * 1ll * a) % M;
        a = (a * 1ll * a) % M;
        b >>= 1ll;
    }
    return ans;
}
void pre() {
    fact[0] = 1;
    for (int i = 1; i <= N; i++)
        fact[i] = (fact[i - 1] * i) % M;
    ifact[N - 1] = (binexp(fact[N - 1], M - 2)) % M;
    for (int i = N - 2; i >= 0; i--)
        ifact[i] = (ifact[i + 1] * (i + 1)) % M;
}
int nCr(int n, int r) {
    if (r < 0 || r > n)
        return 0;
    return (((fact[n] * ifact[r]) % M) * ifact[n - r]) % M;
}
void marwan() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &vl : v)
        cin >> vl;
    int ans = 0;
    n--;
    for (int i = 0; i <= n; i++) {
        if (nCr(n, i) & 1) {
            ans ^= v[i];
        }
    }
    // cout << endl;
    cout << ans << endl;
    // for (int i = 1; i <= 100; i++) {
    //     cout << fact[i] << " " << ifact[i] << endl;
    // }
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    pre();
    for (int i = 0; i <= 100; i++) {
        cout << i << endl;
        for (int j = __lg(i); j >= 0; j--) {
            cout << (1 & ((i) >> j));
        }
        cout << endl;
        for (int j = 0; j <= i; j++) {
            if (nCr(i, j) % 2 == 0)
                cout << j + 1 << " ";
            // cout << nCr(i, j) << " ";
        }
        cout << endl;
    }
    cout << endl;
    // int t;
    // cin >> t;
    // while (t--) {
    //     marwan();
    // }
    return 0;
}