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
void marwan() {
    int n;
    cin >> n;
    if (n == 1) {
        cout << 1 << " " << 0 << endl;
        return;
    }
    map<int, int> m;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            while (n % i == 0) {
                m[i]++;
                n /= i;
            }
        }
    }
    if (n > 1)
        m[n]++;
    int ans = 1ll, ans2 = 0;
    for (auto [x, y] : m) {
        // cout << x << " " << y << endl;
        ans = (ans * 1ll * x);
        ans2 = max(ans2, y);
    }
    bool flag = false;
    // for (int ans2 = 0; ans2 <= 8; ans2++) {
    int x = __lg(ans2) + 1;
    if (!(ans2 & (ans2 - 1)))
        x--;
    for (auto [_, y] : m) {
        if (y != (1 << x))
            flag = true;
    }
    cout << ans << " " << x + flag << endl;
    // }
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}