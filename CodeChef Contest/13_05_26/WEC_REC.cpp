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
    int n, lim, k;
    cin >> n >> lim >> k;
    map<int, int> m;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        m[x]++;
    }
    vector<pair<int, int>> v;
    for (auto [x, y] : m)
        v.push_back({x, y});
    sort(all(v), [&](pair<int, int> a, pair<int, int> b) {
        return a.first > b.first;
    });
    int count = 0;
    int ans = 0;
    for (auto [x, y] : v) {
        ans += y;
        count++;
        if (count == k)
            break;
    }
    cout << min(ans, lim) << endl;
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