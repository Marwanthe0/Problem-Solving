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
vector<int> vis(1e5, 0);
void marwan() {
    int n;
    cin >> n;
    vector<pair<int, int>> v(n);
    set<int> s;
    int sum = 0ll, mx = 0;
    for (int i = 1; i <= mx; i++)
        vis[i] = 0;
    for (int i = 0; i < n; i++) {
        cin >> v[i].first;
        s.insert(v[i].first);
        mx = max(mx, v[i].first);
    }
    for (int i = 0; i < n; i++) {
        cin >> v[i].second;
        sum += v[i].second;
    }
    vector<int> val(mx + 1, 0);
    sort(all(v));
    for (auto [x, y] : v) {
        val[x] += y;
    }
    int ans = sum;
    for (auto vl : s) {
        int cursum = 0ll;
        for (int i = vl; i <= mx; i += vl) {
            if (val[i])
                cursum += val[i];
        }
        ans = max(ans, vl * cursum);
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