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
    int n, a, b, ans = 0ll;
    cin >> n >> a >> b;
    map<pair<int, int>, int> m1;
    vector<vector<int>> g1(n + 1), g2(n + 1);
    for (int i = 0; i < a; i++) {
        int l, r;
        cin >> l >> r;
        g1[l].push_back(r);
        g1[r].push_back(l);
        m1[{l, r}]++;
    }
    for (int i = 0; i < b; i++) {
        int l, r;
        cin >> l >> r;
        if (!m1.count({l, r}))
            ans++;
        else
            m1.erase({l, r});
    }
    cout << ans + m1.size() << endl;
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