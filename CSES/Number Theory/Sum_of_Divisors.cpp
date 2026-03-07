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
int binexp(int a, int b, int m = M) {
    int ans = 1ll;
    while (b) {
        if (b & 1)
            ans = mod(ans * 1ll * a, m);
        a = mod(a * 1ll * a, m);
        b >>= 1ll;
    }
    return ans;
}
void marwan() {
    int n, ans = 1ll;
    cin >> n;
    map<int, int> mp;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            while (n % i == 0) {
                n /= i;
                mp[i]++;
            }
        }
    }
    if (n > 1) {
        mp[n]++;
    }
    for (auto [p, e] : mp) {
        int x = mod(mod(binexp(p, e + 1ll) - 1ll) * 1ll * mod(binexp(n - 1ll, M - 2)));
        ans = mod(ans * 1ll * x);
    }
    cout << ans << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}