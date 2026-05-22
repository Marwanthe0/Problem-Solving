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
    vector<int> s;
    for (int i = 0; i < n; i++) {
        cin >> v[i].first >> v[i].second;
        s.push_back(v[i].second);
    }
    sort(all(v));
    make_unique(s);
    vector<int> pfmax(n, 0), pfmin(n, INT_MAX), sfmax(n, 0), sfmin(n, INT_MAX);
    for (int i = 0; i < n; i++) {
        pfmax[i] = pfmin[i] = v[i].second;
        if (i)
            pfmax[i] = max(pfmax[i], pfmax[i - 1]);
        if (i)
            pfmin[i] = min(pfmin[i], pfmin[i - 1]);
    }
    for (int i = n - 1; i >= 0; i--) {
        sfmax[i] = sfmin[i] = v[i].second;
        if (i != n - 1)
            sfmax[i] = max(sfmax[i], sfmax[i + 1]);
        if (i != n - 1)
            sfmin[i] = min(sfmin[i], sfmin[i + 1]);
    }
    int ans = 0ll;
    unordered_map<int, int> st;
    int count = 0;
    for (auto vl : s) {
        st[vl] = count;
        count++;
    }
    for (int i = 1; i + 1 < n; i++) {
        if (v[i].first == v[i + 1].first)
            continue;
        int mn = max(pfmin[i], sfmin[i + 1]), mx = min(pfmax[i], sfmax[i + 1]);
        int it = st[mx] - st[mn];
        ans += max(0ll, it);
    }
    cout << ans << endl;
    // pbds<int> pb;
    // sort(all(v));
    // for (auto [_, y] : v)
    //     pb.insert(y);
    // int age = 0, pore = n;
    // for (int i = 0; i < n; i++) {
    //     int x = v[i].first;
    //     while (i < n && v[i].first <= x) {

    //         i++;
    //     }
    //     i--;
    // }
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