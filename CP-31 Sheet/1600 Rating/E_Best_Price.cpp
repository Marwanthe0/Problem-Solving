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
    vector<int> a(n), b(n);
    for (auto &vl : a)
        cin >> vl;
    for (auto &vl : b)
        cin >> vl;
    sort(all(a));
    sort(all(b));
    vector<int> t(all(a));
    for (auto vl : b)
        t.push_back(vl);
    make_unique(t);
    int ans = 0;
    for (auto vl : t) {
        int nibe = n - (lower_bound(all(b), vl) - b.begin());
        int nibena = n - nibe;
        int negative = lower_bound(all(a), vl) - a.begin();
        negative -= nibena;
        if (negative <= k) {
            ans = max(nibe * vl, ans);
        }
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