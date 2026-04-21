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
    vector<pair<int, vector<int>>> v(n);
    for (int i = 0; i < n; i++) {
        v[i].first = 0ll;
        v[i].second.resize(m, 0);
        for (auto &vl : v[i].second)
            cin >> vl;
        for (int  j = 0; j < m; j++) {
            v[i].first += v[i].second[j];
        }
    }
    sort(all(v));
    reverse(all(v));
    int k = n * m, ans = 0ll;
    for (auto row : v) {
        for (auto vl : row.second) {
            // cerr << vl << " ";
            ans += k * vl;
            k--;
        }
        // cerr << endl;
    }
    cout << ans << endl;
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