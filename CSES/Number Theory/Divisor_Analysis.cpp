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
int mod(int n, int m = M) { return n % m; }
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
void marwan() {
    int n;
    cin >> n;
    vector<pair<int, int>> v(n);
    bool even = true;
    int a = 1ll, b = 1ll, c = 1ll, t = 1ll;
    for (auto &[x, y] : v) {
        cin >> x >> y;
        if (y & 1)
            even = false;
        a = mod(a * 1ll * (y + 1));
        t = mod(t * 1ll * (y + 1), M - 1);
        int d = mod(mod((binexp(x, (y + 1)) - 1ll + M)) * 1ll * mod(binexp((x - 1), M - 2)));
        b = mod(b * 1ll * d);
    }
    if (even) {
        for (auto [x, y] : v) {
            y = mod(y / 2ll, M - 1);
            y = mod(y * 1ll * mod(t, M - 1), M - 1);
            c = mod(c * 1ll * binexp(x, y));
        }
    } else {
        int d = mod(t / 2ll, M - 1);
        
        }
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}