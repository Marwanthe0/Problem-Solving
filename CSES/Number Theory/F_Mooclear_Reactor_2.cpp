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
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> v(n), t(m);
    int zr = INT_MIN;
    for (auto &[x, y] : v) {
        cin >> x >> y;
        if (!y)
            zr = max(zr, x);
    }
    for (auto &[x, y] : t)
        cin >> x >> y;
    sort(all(v), [&](pair<int, int> a, pair<int, int> b) {if(a.second == b.second) return a.first > b.first; return a.second < b.second; });
    multiset<int> ms;
    int sum = 0;
    vector<int> tt(n + 1, 0);
    int idx = n - 1;
    for (int i = n; i >= 1; i--) {
        while (idx >= 0 && v[idx].second == i) {
            ms.insert(v[idx].first);
            sum += v[idx].first;
            idx--;
        }
        while (ms.size() > i) {
            sum -= *ms.begin();
            ms.erase(*ms.begin());
        }
        tt[i] = sum;
    }
    // cerr << endl;
    int mx = tt[0];
    for (int i = 1; i <= n; i++) {
        mx = max(mx, tt[i]);
        tt[i] = mx;
        // cerr << i << " " << tt[i] << endl;
    }
    for (auto &[x, y] : t) {
        if (y)
            cout << tt[y] + x << " ";
        else
            cout << max(zr, x) << " ";
    }
    cout << endl;
    // cerr << endl;
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