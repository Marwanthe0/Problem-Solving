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
    int n;
    cin >> n;
    vector<int> v(n);
    map<int, int> m;
    for (auto &vl : v) {
        cin >> vl;
        m[vl]++;
    }
    if (m.begin()->first) {
        minus;
        return;
    }
    int last = -1, lastelm = 0;
    vector<int> ans;
    for (auto [x, y] : m) {
        if (last != -1) {
            int cur = (x - last);
            if (cur % lastelm) {
                minus;
                return;
            }
            cur /= lastelm;
            ans.push_back(cur);
        }
        last = x;
        lastelm = y;
    }
    for (int i = 1; i < (int)(ans.size()); i++) {
        if (ans[i] <= ans[i - 1]) {
            minus;
            return;
        }
    }
    if (ans.empty()) {
        ans.push_back(1ll);
    } else {
        ans.push_back(ans.back() + 1ll);
    }
    map<int, int> tt;
    int idx = 0;
    for (auto [x, y] : m) {
        tt[x] = idx++;
    }
    for (int i = 0; i < n; i++) {
        cout << ans[tt[v[i]]] << " ";
    }
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