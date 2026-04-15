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
    vector<int> v(n), t, k, fr(n + 1, 0);
    for (auto &vl : v) {
        cin >> vl;
        fr[vl]++;
    }
    t = v;
    int x = 1;
    for (int i = 2; i <= n; i++) {
        int l = 0, r = 0;
        unordered_map<int, int> m;
        multiset<int> ms;
        while (r < n) {
            if (m.count(t[r])) {
                ms.erase(ms.lower_bound(m[t[r]]));
            }
            m[t[r]]++;
            ms.insert(m[t[r]]);
            if (r - l + 1 == i) {
                if (*ms.begin() != 1) {
                    while (fr[x]) {
                        x++;
                        x %= n;
                        if (x == 0)
                            x = n;
                    }
                    fr[x]++;
                    fr[t[r]]--;
                    ms.erase(ms.lower_bound(m[t[r]]));
                    m[t[r]]--;
                    if (m[t[r]] > 0)
                        ms.insert(m[t[r]]);
                    else
                        m.erase(t[r]);
                    t[r] = x;
                    m[t[r]]++;
                    ms.insert(m[t[r]]);
                }
                ms.erase(ms.lower_bound(m[t[l]]));
                m[t[l]]--;
                if (m[t[l]] > 0)
                    ms.insert(m[t[l]]);
                else
                    m.erase(t[l]);
                l++;
            }
            r++;
        }
        for (auto vl : t)
            cerr << vl << " ";
        cerr << endl;
    }
    // cerr << endl;
    int ans = 0ll;
    for (int i = 0; i < n; i++) {
        ans += (v[i] != t[i]);
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