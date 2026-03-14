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
    vector<pair<double, double>> v(n);
    for (auto &[x, y] : v)
        cin >> x >> y;
    int last = 0;
    double ans = 0, s = 1.0;
    for (int i = n - 1; i >= 0; i--) {
        double nile = ans - (ans * (1.0 - v[i].second / 100.0));
        if (v[i].first > nile) {
            ans -= (ans * ((double)v[i].second / 100.0));
            ans += v[i].first;
        }

        // if (((ans * ((double)v[i].second / 100.0))) > v[i].first) {
        // } else {
        //     ans -= (ans * ((double)v[i].second / 100.0));
        //     ans += v[i].first;
        // }
    }
    cout << setprecision(10) << ans << endl;
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