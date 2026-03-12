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
    if (n == 1) {
        cout << 1 << endl;
        return;
    }
    sort(all(v));
    int mn = v[0];
    int g = 0;
    for (auto &vl : v) {
        vl += (-mn);
        g = __gcd(g, vl);
    }
    int x = v.back();
    vector<int> v2(all(v));
    v2.push_back(v2.back() + g);
    for (int i = n - 1; i >= 0; i--) {
        if (x != v[i]) {
            v.push_back(x);
            break;
        }
        x -= g;
    }
    if (v.size() == n)
        v.push_back(x);
    sort(all(v));
    int ans = 0, ans2 = 0;
    // for (auto vl : v)
    //     cerr << vl << " ";
    // cerr << endl;
    // for (auto vl : v2)
    //     cerr << vl << " ";
    // cerr << endl;
    for (int i = n; i >= 0; i--) {
        ans += v.back() - v[i];
        ans2 += v2.back() - v2[i];
    }
    cout << min(ans, ans2) / g << endl;
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