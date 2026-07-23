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
void marwan() {
    int n, m;
    cin >> n >> m;
    if (m & 1) {
        minus;
        return;
    }
    if (n == 1) {
        cout << __builtin_popcount(m) << endl;
        return;
    }
    if (n >= m / 2) {
        cout << m / 2 << endl;
        return;
    }
    int x = m, ans = 0ll;
    for (int i = 2;; i *= 2) {
        int count = n;
        while (count > 0 && x % (count * i) != 0) {
            count--;
        }
        if (count == 0) {
            minus;
            return;
        }
        ans += count;
        x -= count * i;
        if (x <= 0)
            break;
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