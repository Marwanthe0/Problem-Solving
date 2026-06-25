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
    int n;
    cin >> n;
    vector<int> v(n);
    int mx = 0;
    map<int, int> m;
    int x = 0;
    for (auto &vl : v) {
        cin >> vl;
        m[vl]++;
        x = max(x, m[vl]);
        mx = max(mx, __lg(vl));
    }
    if (x >= 2) {
        zero;
        return;
    }
    multiset<int> col, col2;
    // for (auto vl : v) {
    //     for (int i = mx; i >= 0; i--) {
    //         cout << (1 & (vl >> i));
    //     }
    //     cout << endl;
    // }
    multiset<int> ans1, ans2;
    bool flag1 = true, flag2 = true;
    for (int i = mx; i >= 0; i--) {
        for (int j = 0; j < n; j++) {
            if (v[j] & (1 >> i)) {
                if (i == mx) {
                    col.insert(j);
                    continue;
                }
                if (col2.count(j)) {
                    col2.erase(col2.find(j));
                }
            } else {
                if (i == mx) {
                    col2.insert(j);
                    continue;
                }
                if (col.count(j)) {
                    col.erase(col.find(j));
                }
            }
            if (col.size() >= 2) {
                ans1 = col;
            } else
                flag1 = false;
            if (col2.size() >= 2) {
                ans2 = col2;
            } else
                flag2 = false;
            // for (auto vl : col)
            //     cerr << vl << " ";
            // cerr << endl;
            // for (auto vl : col2)
            //     cerr << vl << " ";
            // cerr << endl;
            // cerr << endl;
            if (flag1 == false && flag2 == false)
                break;
        }
    }
    int uttor = LONG_MAX;
    for (auto j : ans1) {
        for (auto k : ans1) {
            if (j != k)
                uttor = min(uttor, v[j] ^ v[k]);
        }
    }
    for (auto j : ans2) {
        for (auto k : ans2) {
            if (j != k)
                uttor = min(uttor, v[j] ^ v[k]);
        }
    }
    cout << uttor << endl;
    // cout << ans1.size() << " " << ans2.size() << endl;
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