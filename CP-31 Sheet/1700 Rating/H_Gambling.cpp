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
    map<int, vector<int>> m;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        m[v[i]].push_back(i);
    }
    int ans, mx = 0, l = 0, r = 0;
    for (auto &[x, y] : m) {
        int count = 1, mxc = 1, tr = y[0];
        // cerr << x << endl;
        for (int i = 1; i < y.size(); i++) {
            int dif = y[i] - y[i - 1];
            count = max(1ll, count - dif + 2);
            if (count >= mxc) {
                mxc = count, tr = y[i];
            }
            // cerr << y[i] << " " << count << endl;
        }
        if (mxc >= mx) {
            mx = mxc, ans = x, r = tr;
        }
        // cerr << endl;
    }
    // cerr << endl;
    int cnt = 0;
    // cerr << ans << " " << mx << " " << r << endl;
    for (int i = r; i >= 0; i--) {
        if (v[i] == ans)
            cnt++;
        else
            cnt--;
        if (cnt == mx)
            l = i;
    }
    cout << ans << " " << l + 1 << " " << r + 1 << endl;
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