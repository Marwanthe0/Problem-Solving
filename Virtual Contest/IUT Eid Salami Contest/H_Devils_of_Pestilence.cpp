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
    vector<int> temp;
    for (auto &[x, y] : v) {
        cin >> x;
    }
    for (auto &[x, y] : v)
        cin >> y;
    for (auto &[x, y] : t)
        cin >> x;
    for (auto &[x, y] : t)
        cin >> y;
    sort(all(v));
    sort(all(t));
    for (auto [x, y] : v)
        temp.push_back(x);
    int count = 0;
    for (int i = 0; i < m; i++) {
        if (t[i].first < v[0].first || t[i].first > v[n - 1].first)
            continue;
        int x = t[i].first, y = t[i].second;
        int pos = lower_bound(all(temp), x) - temp.begin();
        if (temp[pos] == x) {
            if (y <= v[pos].second)
                count++;
            continue;
        } else if (pos) {
            int l = v[pos - 1].second, r = v[pos].second;
            long double slope;
            slope = (long double)(r - l) / (long double)(v[pos].first - v[pos - 1].first);
            long double newpos = (long double)l + (slope * (long double)(x - v[pos - 1].first));
            if (newpos >= (long double)t[i].second) {
                count++;
                // cerr << i << " " << newpos << " ";
                // cerr << l << " " << r << " " << slope << endl;
            }
        }
    }
    // cerr << endl;
    cout << count << endl;
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