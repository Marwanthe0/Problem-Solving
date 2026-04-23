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
void marwan() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (auto &vl : a)
        cin >> vl;
    for (auto &vl : b)
        cin >> vl;
    sort(all(a), greater<int>());
    sort(all(b));
    if (b.front() < a.front()) {
        cout << -1 << endl;
        return;
    }
    int ans = 0ll;
    bool flag = false;
    ans += accumulate(all(b), 0ll);
    if (b[0] == a[0]) {
        flag = true;
    } else {
        ans -= b[0];
        ans += a[0];
    }
    if (!flag)
        ans += b[0], ans += a[1] * (m - 1);
    for (int i = (flag ? 1 : 2); i < n; i++) {
        ans += m * a[i];
    }
    cout << ans << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}