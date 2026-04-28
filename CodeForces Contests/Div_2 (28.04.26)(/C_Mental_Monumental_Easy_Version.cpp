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
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &vl : v) {
        cin >> vl;
    }
    int l = 0, r = n + 1, ans = 0;
    auto ok = [&](int m) {
        multiset<int> ms(all(v));
        vector<int> dk;

        for (int i = 0; i < m; i++) {
            auto it = ms.find(i);
            if (it != ms.end()) {
                ms.erase(it);
            } else {
                dk.push_back(i);
            }
        }
        for (int nd : dk) {
            auto it = ms.lower_bound((nd * 2) + 1);
            if (it == ms.end()) {
                return false;
            }
            ms.erase(it);
        }

        return true;
    };

    while (l <= r) {
        int m = l + (r - l) / 2;
        if (ok(m)) {
            ans = m;
            l = m + 1;
        } else {
            r = m - 1;
        }
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