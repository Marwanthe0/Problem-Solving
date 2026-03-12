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
int lcm(int a, int b) { return (a * 1ll * b) / __gcd(a, b); }
void marwan() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &vl : v)
        cin >> vl;
    int ans = 1ll;
    for (int i = 0; i < n - 1; i++) {
        if (v[i + 1] % v[i]) {
            // if (!ans)
            //     ans = __gcd(v[i + 1], v[i]);
            // else
            //     ans = lcm(ans, __gcd(v[i + 1], v[i]));
            ans = lcm(ans, v[i] / __gcd(v[i], v[i + 1]));
            cerr << v[i] / __gcd(v[i + 1], v[i]) << " ";
        }
    }
    cerr << endl;
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