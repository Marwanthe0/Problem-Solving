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
bool check(string &s, string &x) {
    int sz = s.size(), idx = 0, m = x.size();
    if (idx == sz)
        return true;
    for (int i = 0; i < m; i++) {
        if (x[i] == s[idx])
            idx++;
        if (idx == sz)
            return true;
    }
    return false;
}

void marwan() {
    string a, b, x;
    cin >> a;
    cin >> b;
    cin >> x;
    string ta = "";
    int n = a.size();
    int ans = 0;
    int last = 0, xsz = x.size();
    auto ok = [&](int m, int start) {
        int idx = 0;
        for (int i = start; i < xsz; i++) {
            if (x[i] == b[idx])
                idx++;
            if (idx > m)
                return true;
        }
        return false;
    };
    for (int i = -1; i < n; i++) {
        if (i >= 0) {
            while (last < xsz) {
                if (x[last] == a[i]) {
                    last++;
                    break;
                }
                last++;
            }
            if (last == xsz) {
                // ans++;
                break;
            }
        }
        int l = 0, r = n - 1, lng = -1;
        while (l <= r) {
            int m = l + (r - l) / 2;
            cerr << m << ":::" << last << "::" << ok(m, last + 1) << endl;
            if (ok(m, last)) {
                lng = m, l = m + 1;
            } else
                r = m - 1;
        }
        lng++;
        cerr << i << " " << last << " " << lng << endl;
        ans += (lng + 1);
        cerr << "Done" << endl;
    }
    cerr << endl;
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