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
    int n, x1, y1, xn, yn;
    cin >> n >> x1 >> y1 >> xn >> yn;
    vector<pair<int, int>> a(n), v;
    for (auto &vl : a)
        cin >> vl.first;
    for (auto &vl : a)
        cin >> vl.second;
    a.push_back({x1, y1});
    a.push_back({xn, yn});
    sort(all(a));
    for (int i = 0; i < a.size(); i++) {
        if (!i) {
            v.push_back({a[i].second, a[i].second});
        } else {
            if (a[i].first == a[i - 1].first) {
                v.back().first = min(v.back().first, a[i].second);
                v.back().second = max(v.back().second, a[i].second);
            } else
                v.push_back({a[i].second, a[i].second});
        }
    }
    // for (auto [x, y] : v)
    //     cerr << x << " " << y << endl;
    // cerr << endl;
    vector<vector<int>> dp(v.size() + 1, vector<int>(2, INT_MAX));
    dp[0][0] = dp[0][1] = 0;
    for (int i = 1; i < v.size(); i++) {

        dp[i][0] = min(dp[i - 1][0] + abs(v[i - 1].second - v[i].first), dp[i - 1][1] + abs(v[i - 1].first - v[i].first)) + abs(v[i].first - v[i].second);
        dp[i][1] = min(dp[i - 1][1] + abs(v[i - 1].first - v[i].second), dp[i - 1][0] + abs(v[i - 1].second - v[i].second)) + abs(v[i].first - v[i].second);
    }
    cout << min(dp[v.size() - 1][0], dp[v.size() - 1][1]) + (xn - x1) << endl;
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