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
int mod(int n, int m = M) { return n % m; }
int binexp(int a, int b, int m) {
    int ans = 1ll;
    while (b) {
        if (b & 1)
            ans = mod(ans * 1ll * a, m);
        a = (mod(a * 1ll * a, m));
        b >>= 1;
    }
    return mod(ans, m);
}
void marwan() {
    int a, b, c;
    cin >> a >> b >> c;
    int x = binexp(b, c, M - 1);
    cout << binexp(a, x, M) << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        marwan();
    }
    return 0;
}