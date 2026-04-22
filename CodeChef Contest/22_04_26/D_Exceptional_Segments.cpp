#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 998244353
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
int mod(int x, int m = M) { return x % m; }
void marwan() {
    int n, x;
    cin >> n >> x;
    x--;
    int aagezero = ((x + 1ll) / 4) + 1ll;
    int porezero = ((((n + 1ll) / 4) + 1ll) - aagezero);
    int aageone = ((x - 1ll) / 4) + (x >= 1ll);
    int poreone = ((n - 1ll) / 4) + (n >= 1ll) - aageone;
    // cerr << aagezero << " " << porezero << "::" << aageone << " " << poreone << endl;
    cout << mod(mod(mod(aagezero) * 1ll * mod(porezero)) + mod(mod(aageone) * mod(poreone))) << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // int x = 0;
    // for (int i = 0; i <= 100; i++) {
    //     x ^= i;
    //     cout << i << " " << x << endl;
    // }
    int t;
    cin >> t;
    while (t--) {
        marwan();
    }
    return 0;
}