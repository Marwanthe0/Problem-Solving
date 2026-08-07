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
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    vector<int> a(x), b(y);
    for (auto &vl : a)
        cin >> vl;
    for (auto &vl : b)
        cin >> vl;
    if (a[0] > b.back()) {
        int ans = 0ll;
        for (int i = x - 1, j = 0; i >= 0 && j < n; i--, j++) {
            ans += a[i];
        }
        for (int i = y - 1, j = 1; i >= 0 && j < m; j++) {
            ans += b[i];
        }
        cout << ans << endl;
    } else if (b[0] > a.back()) {
        swap(a, b);
        swap(x, y);
        int ans = 0ll;
        for (int i = x - 1, j = 0; i >= 0 && j < n; i--, j++) {
            ans += a[i];
        }
        for (int i = y - 1, j = 1; i >= 0 && j < m; j++) {
            ans += b[i];
        }
        cout << ans << endl;
    } else {
        map<int, int> mp;
        for (int vl : a)
            mp[vl] |= 1;
        for (int vl : b)
            mp[vl] |= 2;

        vector<pair<int, int>> tt;
        for (auto p : mp)
            tt.push_back({p.first, p.second});
        sort(tt.rbegin(), tt.rend());

        int ans = 0ll;
        int c1 = 0, c2 = 0, ctot = 0;

        for (auto p : tt) {
            int vl = p.first;
            int type = p.second;

            if (type == 1) {
                if (c1 < n && ctot < n + m - 1) {
                    c1++;
                    ctot++;
                    ans += vl;
                }
            } else if (type == 2) {
                if (c2 < m && ctot < n + m - 1) {
                    c2++;
                    ctot++;
                    ans += vl;
                }
            } else {
                if (ctot < n + m - 1) {
                    ctot++;
                    ans += vl;
                }
            }
        }
        cout << ans << endl;
    }
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