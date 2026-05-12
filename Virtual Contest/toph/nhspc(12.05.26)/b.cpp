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
    vector<int> v(n), pf(n, 0ll);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        pf[i] = v[i];
        if (i)
            pf[i] += pf[i - 1];
    }
    int l = 0, r = n - 1;
    for (int tk = 0; tk < k; tk++) {
        int pr = 0ll, sf = pf[r] - (l ? pf[l - 1] : 0ll), mn = INT_MAX, pos, sin = 0;
        for (int i = l; i <= r; i++) {
            pr += v[i], sf -= v[i];
            if (abs(sf - pr) <= mn) {
                mn = min(mn, abs(sf - pr));
                pos = i;
                if (pr > sf)
                    sin = 1;
                else
                    sin = -1;
            }
        }
        if (sin > 0) {
            r = pos;
        } else {
            l = pos + 1;
        }
        if (l == r) {
            break;
        }
    }
    cout<< pf[r] - (l ? pf[l - 1] : 0) << endl;
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