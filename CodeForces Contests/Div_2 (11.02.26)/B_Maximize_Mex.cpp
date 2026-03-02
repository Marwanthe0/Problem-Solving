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
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    map<int, multiset<int>> m;
    for (auto &vl : v) {
        cin >> vl;
        m[vl % k].insert(-(vl / k));
    }
    for (int i = 0;; i++) {
        // cerr << i << endl;
        // for (auto [x, y] : m) {
        //     cerr << x << "::";
        //     for (auto vl : y)
        //         cerr << vl << " ";
        //     cerr << endl;
        // }
        // cerr << endl;
        bool flag = false;
        if (m.count(i % k)) {
            auto it = m[i % k].lower_bound(-(i / k));
            if (it != m[i % k].end()) {
                flag = true;
                m[i % k].erase(it);
            }
            if (m[i % k].size() <= 0)
                m.erase(i % k);
        }
        if (!flag) {
            cout << i << endl;
            return;
        }
    }
    // cerr << endl;
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