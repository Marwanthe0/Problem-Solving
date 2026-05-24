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
    vector<int> a(n), b(n);
    for (auto &vl : a)
        cin >> vl;
    for (auto &vl : b)
        cin >> vl;
    vector<int> s(all(a));
    for (auto vl : b)
        s.push_back(vl);
    sort(all(s));
    int l = 0, r = s.size() - 1, ans = -1;
    auto ok = [&](int m) {
        vector<int> t;
        for (int i = 0; i < n; i++) {
            int x;
            if (a[i] < m && b[i] < m) {
                x = -1;
            } else if (a[i] < m || b[i] < m) {
                continue;
            } else
                x = 1;
            // cerr << x << " ";
            if (x == 1)
                t.push_back(1);
            else if (t.empty() || t.back() == 1)
                t.push_back(x);
        }
        // cerr << endl;
        int up = 0, down = 0;
        for (auto vl : t) {
            if (vl == 1)
                up++;
            else
                down++;
        }
        return up > down;
    };
    while (l <= r) {
        int m = l + (r - l) / 2;
        // cerr << s[m] << "endl" << endl;
        bool kk = ok(s[m]);
        // cerr << kk << endl;
        if (kk) {
            ans = s[m], l = m + 1;
        } else
            r = m - 1;
    }
    // cerr << endl;
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