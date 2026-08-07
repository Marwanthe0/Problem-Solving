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
    vector<int> v(n), tt;
    map<int, int> m;
    int last = -1, sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        // ms.insert(v[i]);
        sum += v[i];
        m[v[i]]++;
    }
    vector<pair<int, int>> t;
    int mx = 0, mxval = 0;
    for (auto [x, y] : m) {
        if (y > mx)
            mx = y, mxval = x;
    }
    // sort(all(t));
    // reverse(all(t));
    if (mx <= (n + 1) / 2) {
        cout << sum << endl;
        return;
    } else {
        int cnt = n - mx, tsum = sum - (mx * 1ll * mxval);
        cout << tsum + ((cnt + 2) * mxval) << endl;
    }
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