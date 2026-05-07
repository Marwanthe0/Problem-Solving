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
    vector<int> a(n), b(n);
    unordered_map<int, int> m;
    for (auto &vl : a)
        cin >> vl;
    for (auto &vl : b)
        cin >> vl;
    int flag = 1;
    if (n & 1)
        flag = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == b[i])
            flag++;
        if (flag >= 2) {
            minus;
            return;
        }
        m[a[i]] = b[i];
        if (m.count(b[i])) {
            if (m[b[i]] != a[i]) {
                minus;
                return;
            }
        }
    }
    if (!flag) {
        minus;
        return;
    }
    vector<pair<int, int>> ans;
    if (n & 1) {
        for (int i = 0; i < n; i++) {
            if (a[i] == b[i] && (i != (n / 2))) {
                ans.push_back({i + 1, (n + 1) / 2});
                swap(a[i], a[n / 2]);
                swap(b[i], b[n / 2]);
                break;
            }
        }
    }
    vector<int> posa(n + 1), posb(n + 1);
    for (int i = 0; i < n; i++) {
        posa[a[i]] = i;
        posb[b[i]] = i;
    }
    for (int i = 1; i <= n; i++) {
        int x = posa[i];
        int xb = (n - x) - 1;
        if (posb[i] == xb)
            continue;
        else {
            ans.push_back({xb + 1, posb[i] + 1});
            int e = xb, f = posb[i];
            swap(posa[a[e]], posa[a[f]]);
            swap(posb[b[e]], posb[b[f]]);
            swap(a[e], a[f]);
            swap(b[e], b[f]);
        }
    }
    cout << ans.size() << endl;
    for (auto [x, y] : ans)
        cout << min(x, y) << " " << max(x, y) << endl;
    // for (auto vl : a)
    //     cerr << vl << " ";
    // cerr << endl;
    // for (auto vl : b)
    //     cerr << vl << " ";
    // cerr << endl;
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