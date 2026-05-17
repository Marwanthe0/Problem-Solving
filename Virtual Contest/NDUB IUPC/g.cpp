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
    int p, q;
    cin >> p >> q;
    vector<int> a, b;
    for (int i = 1; i * i <= p; i++) {
        if (p % i == 0) {
            a.push_back(i);
            if ((p / i) != i)
                a.push_back(p / i);
        }
    }
    for (int i = 1; i * i <= q; i++) {
        if (q % i == 0) {
            b.push_back(i);
            if ((q / i) != i)
                b.push_back(q / i);
        }
    }
    sort(all(a));
    sort(all(b));
    vector<int> v;
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < b.size(); j++) {
            v.push_back(a[i] * b[j]);
        }
    }
    make_unique(v);
    int pq = p * q;
    set<pair<int, int>> ans;
    for (auto vl : v) {
        int x = vl, y = pq / vl;
        ans.insert({x + p, y + q});
    }
    cout << ans.size() << endl;
    for (auto [x, y] : ans)
        cout << x << " " << y << endl;
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