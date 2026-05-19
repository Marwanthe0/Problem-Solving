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
    int n, a, b;
    cin >> n >> a >> b;
    int ans = 0ll;
    if ((a * 3) <= b)
        ans = a * n, n = 0;
    else
        ans = (n / 3) * b, n %= 3;
    if (n) {
        if (n == 1)
            ans += min(a, b);
        else
            ans += min(2 * a, b);
    }
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