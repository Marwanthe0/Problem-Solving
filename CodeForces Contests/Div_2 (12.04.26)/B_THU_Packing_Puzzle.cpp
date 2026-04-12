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
void marwan() {
    int t, h, u;
    cin >> t >> h >> u;
    int x = min(t, u);
    int ans = x * 1ll * 4;
    t -= x, u -= x;
    int z = min(t / 2, h);
    ans += 7 * 1ll * z;
    h -= z, t = t - (z * 2);
    int y = min(t, h);
    ans += y * 1ll * 5;
    t -= y, h -= y;
    ans += (h * 1ll * 3 + u * 1ll * 3);
    if (t)
        ans += 2 * 1ll * t + 1;
    cout << ans << endl;
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