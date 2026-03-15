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
    vector<int> v(n);
    for (auto &vl : v)
        cin >> vl;
    int ans = (m * (m + 1) / 2) * n, cnt = 0, count = 0;
    map<int, multiset<int>> mp;
    // for (int i = 1; i <= n;i++) mp[i].insert(v[i - 1])
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        if (!mp.count(a)) {
            count += (mp.size() + 1);
        } else {
            ans += mp[a].size() - mp[a].count(b);
        }
        ans += count;
        mp[a].insert(b);
    }
    cerr << endl;
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