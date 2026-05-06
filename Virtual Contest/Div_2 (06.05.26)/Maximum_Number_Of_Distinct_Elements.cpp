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
    vector<int> v(n);
    unordered_map<int, int> m;
    unordered_map<int, vector<int>> ans;
    for (auto &vl : v) {
        cin >> vl;
        m[vl]++;
    }
    vector<int> t(all(v));
    make_unique(t);
    reverse(all(t));
    vector<int> vis(n + 1, 0);

    // auto f = [&](int l, int r) {
    //     int idx = 0;
    //     while (l <= r) {
    //         int m = l + (r - l) / 2;
    //         if (!vis[m]) {
    //             idx = m, l = m + 1;
    //         } else
    //             r = m - 1;
    //     }
    //     return idx;
    // };
    int mn = n + 1;
    for (auto vl : t) {
        auto x = vl, y = m[vl];
        for (int i = 0; i < y; i++) {
            int idx = min(x - 1, mn);
            mn = idx;
            mn = max(0ll, mn - 1ll);
            ans[x].push_back(idx);
        }
    }
    vector<int> uttor(n);
    for (int i = n - 1; i >= 0; i--) {
        uttor[i] = ans[v[i]].back();
        ans[v[i]].pop_back();
    }
    for (auto vl : uttor)
        cout << vl << " ";
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