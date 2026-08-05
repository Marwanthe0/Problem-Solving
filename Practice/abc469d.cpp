#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define M 1000000007
#define N 1e6
#define INF 1e17
#define endl "\n"
#define all(v) v.begin(), v.end()
#define minus cout << "-1" << endl
#define zero cout << "0" << endl
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define make_unique(x) \
    sort(all((x)));    \
    (x).erase(unique(all((x))), (x).end())
void marwan() {
    int a, b;
    cin >> a >> b;
    vector<pair<int, int>> v(b);
    vector<int> m(a + 1, 0);
    map<pair<int, int>, int> t;
    for (int i = 0; i < b; i++) {
        cin >> v[i].first >> v[i].second;
        int x = min(v[i].first, v[i].second);
        int y = max(v[i].first, v[i].second);
        m[x]++, m[y]++;
        t[{x, y}]++;
    }
    int ans = 0;
    for (auto vl : t) {
        int i = vl.first.first, j = vl.first.second, k = vl.second;
        if (b + k == m[i] + m[j]) {
            // cerr << i << " " << j << endl;
            ans++;
        }
    }
    map<int, vector<int>> bmy;
    for (int i = 1; i <= a; i++) {
        bmy[b - m[i]].push_back(i);
    }
    vector<int> vis(a + 1, 0);
    for (int i = 1; i <= a; i++) {
        vis[i]++;
        for (auto vl : bmy[m[i]]) {
            if (vis[vl])
                continue;
            if (!t.count({min(i, vl), max(i, vl)})) {
                ans++;
            }
        }
    }
    cout << ans << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}