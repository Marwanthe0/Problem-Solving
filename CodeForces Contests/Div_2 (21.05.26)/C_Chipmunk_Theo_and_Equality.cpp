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
    for (auto &vl : v)
        cin >> vl;
    bool flag = true;
    for (int i = 0; i < n; i++) {
        if (v[i] != v[0])
            flag = false;
    }
    if (flag) {
        cout << 0 << endl;
        return;
    }
    int ans = INT_MAX;
    unordered_map<int, int> m;
    for (int i = 0; i < n; i++) {
        int x = v[i];
        if (x == 1) {
            m[x]++, m[x + 1]++;
            continue;
        }
        m[x]++;
        while (x != 1) {
            if (x & 1)
                x++;
            else
                x /= 2;
            m[x]++;
        }
    }
    for (auto [x, y] : m) {
        if (y == n) {
            int temp = 0;
            // cerr << x << ":";
            for (auto vl : v) {
                int tx = vl;
                while (tx != x) {
                    if (tx & 1)
                        tx++;
                    else
                        tx /= 2;
                    temp++;
                }
            }
            // cerr << temp << endl;
            ans = min(ans, temp);
        }
    }
    cout << ans << endl;
    // cerr << endl;
    // cout << endl;
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