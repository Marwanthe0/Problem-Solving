#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define N 1e6
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
void bits(int x) {
    int mx = __lg(x);
    for (int i = mx; i >= 0; i--)
        cerr << (1 & (x >> i));
    cerr << endl;
}
void marwan() {
    int n, k;
    cin >> n >> k;
    int ans = __builtin_popcount(n), i = 1;
    k = min(n, k);
    while (i * k <= n) {
        ans = max(ans, k * __builtin_popcount(i));
        i <<= 1;
        i++;
    }
    i >>= 1;
    int rem = n - (i * k);
    ans += rem / (i + 1);
    // bits(i + 1);
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