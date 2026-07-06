#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define N 1e6
#define INF 1e17
#define endl "\n"
#define all(v) v.begin(), v.end()
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define minus cout << "-1" << endl
#define zero cout << "0" << endl
#define make_unique(x) \
    sort(all((x)));    \
    (x).erase(unique(all((x))), (x).end())
void marwan() {
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    map<int, int> m;
    for (auto &vl : v) {
        cin >> vl;
        m[vl]++;
    }
    multiset<int> t;
    int sum = 0;
    for (auto [x, y] : m) {
        t.insert(y);
        sum += y;
    }
    int ans = 0ll, sz = t.size(), count = 0;
    map<int, int> mt;
    while (!t.empty()) {
        int tsum = sum - (count * t.size());
        if (tsum <= k && (k - tsum) % t.size() == 0) {
            if (!mt.count(t.size()))
                mt[t.size()]++;
        }
        count++;
        while (!(t.empty()) && *t.begin() <= count) {
            sum -= *t.begin();
            t.erase(t.begin());
        }
    }
    for (auto [x, y] : mt) {
        // cout << x << ' ' << y << endl;
        ans += y;
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