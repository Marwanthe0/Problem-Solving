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
    vector<int> a(n), b(n), x(n), y(n), xx(n), yx(n);
    for (auto &vl : a)
        cin >> vl;
    for (auto &vl : b)
        cin >> vl;
    int mn = INT_MAX, mx = INT_MIN;
    for (int i = 0; i < n; i++) {
        mn = min(mn, a[i]);
        mx = max(mx, a[i]);
        x[i] = mn, xx[i] = mx;
    }
    mn = INT_MAX, mx = INT_MIN;
    for (int j = n - 1; j >= 0; j--) {
        mn = min(mn, b[j]);
        mx = max(mx, b[j]);
        y[j] = mn, yx[j] = mx;
    }
    vector<pair<int, int>> ans(n);
    vector<int> tx(2 * n + 1, INT_MAX);
    for (int i = 0; i < n; i++) {
        int a = min(x[i], y[i]), b = max(xx[i], yx[i]);
        tx[a] = min(tx[a], b);
    }
    int answer = 0;
    mn = INT_MAX;
    for (int i = 2 * n; i >= 1; i--) {
        mn = min(mn, tx[i]);
        answer += (mn == INT_MAX) ? 0 : (2 * n - mn + 1);
    }
    cout << answer << endl;
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