#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define N 1e6
#define INF 1e17
#define endl "\n"
#define all(v) v.begin(), v.end()
#define minus cout << "-1" << endl
#define zero cout << "0" << endl
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define make_unique(x) \
    sort(all((x)));    \
    (x).erase(unique(all((x))), (x).end())
void marwan() {
    int n, q;
    cin >> n >> q;
    vector<int> v(n);
    int ans = 0, last = 0;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        if (i > 0 && v[i] != v[i - 1]) {
            last += i;
        }
        ans += (++last);
    }
    // cout << ans << endl;
    if (n == 1) {
        while (q--) {
            int x, y;
            cin >> x >> y;
            cout << ans << endl;
        }
        return;
    }
    while (q--) {
        int i, x;
        cin >> i >> x;
        i--;
        auto f = [&](int j) {
            if (j < 0 || j >= n - 1)
                return 0ll;
            if (v[j] == v[j + 1])
                return 0ll;
            return (j + 1) * 1ll * (n - j - 1);
        };
        ans -= (f(i - 1) + f(i));
        v[i] = x;
        ans += (f(i - 1) + f(i));
        cout << ans << endl;
    }
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}