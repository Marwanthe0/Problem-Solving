#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define N 1000005
#define INF 1e17
#define endl "\n"
#define all(v) v.begin(), v.end()
#define minus cout << "-1" << endl
#define zero cout << "0" << endl
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define make_unique(x) \
    sort(all((x)));    \
    (x).erase(unique(all((x))), (x).end())
int n, l;
map<int, int> m;
void marwan() {
    cin >> n >> l;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        m[x] = max(m[x], y);
    }
    if (m.count(0) == 0) {
        minus;
        return;
    }
    vector<pair<int, int>> v;
    vector<int> a, b;
    for (auto [x, y] : m) {
        v.push_back({x, y});
        a.push_back(x);
        b.push_back(y);
    }
    for (int i = 1; i < b.size(); i++)
        b[i] = max(b[i], b[i - 1]);
    // for (int i = 0; i < a.size(); i++)
    //     cerr << a[i] << " ";
    // cerr << endl;

    // for (int i = 0; i < a.size(); i++)
    //     cerr << b[i] << " ";
    // cerr << endl;
    int dist = 0, ans = 0;
    for (int i = 0; i < v.size();) {
        auto [x, y] = v[i];
        int mxy = dist;
        while (i < v.size() && v[i].first <= dist) {
            mxy = max(mxy, v[i++].second);
        }
        if (mxy == dist) {
            minus;
            return;
        }
        dist = mxy;
        ans++;
    }
    if (dist >= l)
        cout << ans << endl;
    else
        minus;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    marwan();
    return 0;
}