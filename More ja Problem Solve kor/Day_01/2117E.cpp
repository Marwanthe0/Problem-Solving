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
    vector<int> a(n), b(n);
    for (auto &vl : a)
        cin >> vl;
    for (auto &vl : b)
        cin >> vl;
    set<int> x, y, xx, yy;
    vector<int> xt, yt;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            xt.push_back(a[i]);
            yt.push_back(b[i]);
        } else {
            xt.push_back(b[i]), yt.push_back(a[i]);
        }
    }
    // for (auto vl : xt)
    //     cerr << vl << " ";
    // cerr << endl;
    // for (auto vl : yt)
    //     cerr << vl << " ";
    // cerr << endl;
    for (int i = n - 1; i >= 0; i--) {
        // cerr << xt[i] << " " << yt[i] << " " << y.count(xt[i]) << " " << x.count(yt[i]) << " " << xx.count(xt[i]) << " " << yy.count(yt[i]) << endl;
        if (a[i] == b[i] || y.count(xt[i]) || x.count(yt[i]) || xx.count(xt[i]) || yy.count(yt[i])) {
            cout << i + 1 << endl;
            return;
        }
        x.insert(xt[i]), y.insert(yt[i]);
        if (i + 1 < n)
            xx.insert(xt[i + 1]), yy.insert(yt[i + 1]);
    }
    cout << 0 << endl;
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