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
    vector<pair<pair<int, int>, int>> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].first.first >> v[i].first.second;
        v[i].second = i;
    }
    vector<int> t;
    sort(all(v), [&](pair<pair<int, int>, int> a, pair<pair<int, int>, int> b) {
        if (a.first.first == b.first.first)
            return a.first.second > b.first.second;
        else
            return a.first.first < b.first.first;
    });
    for (auto [x, y] : v) {
        // cerr << x.first << " " << x.second << endl;
        t.push_back(x.first);
    }
    // cerr << endl;
    int x = 0;
    vector<int> ans;
    while (1) {
        ans.push_back(v[x].second);
        int y = v[x].first.second;
        auto it = lower_bound(all(t), y);
        if (it == t.end())
            break;
        x = it - t.begin();
    }
    cout << ans.size() << endl;
    for (auto &vl : ans)
        cout << vl + 1 << " ";
    cout << endl;
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