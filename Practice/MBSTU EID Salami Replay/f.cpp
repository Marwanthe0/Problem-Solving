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
    vector<pair<int, int>> v(n);
    for (auto &[x, y] : v)
        cin >> x >> y;
    sort(all(v), [&](pair<int, int> a, pair<int, int> b) {
        long double aa = (long double)a.first / a.second, bb = (long double)b.first / b.second;
        return aa < bb;
    });
    cout << v[0].first << endl;
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