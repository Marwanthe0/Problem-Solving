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
    vector<int> v(n), pos(n + 1, 0), t;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    int xx = n;
    vector<int> xs;
    for (int i = n - 1; i > 0; i--) {
        if (xx == v[i]) {
            xs.push_back(v[i]);
            pos[v[i]] = 1;
            xx--;
        }
    }
    sort(all(xs));
    for (auto vl : v) {
        if (!pos[vl])
            t.push_back(vl);
    }
    v.clear();
    for (auto vl : t)
        v.push_back(vl);
    for (auto vl : xs)
        v.push_back(vl);
    // for (auto vl : t)
    //     cerr << vl << " ";
    // cerr << endl;
    int ans = 0, x = 1;
    set<int> ss;
    for (int i = 1; i <= n; i++) {
        if (v[i - 1] == x) {
            x++;
            continue;
        } else if (v[i - 1] < x) {
            continue;
        } else {
            x++, i--;
            ss.insert(v[i - 1]);
            ss.insert(x);
        }
    }
    cout << ss.size() << endl;
    // cout << ss.size() << endl;
    // int k = n;
    // int count = 0;
    // for (int i = 1; i <= n; i++) {
    //     if (v[i - 1] == i)
    //         count++, k--;
    //     else
    //         break;
    // }
    // int tt = n;
    // for (int i = n - 1; i > count; i--) {
    //     if (v[i] == tt) {
    //         tt--;
    //         k--;
    //     }
    // }
    // cout << min((int)ss.size(), k) << endl;
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